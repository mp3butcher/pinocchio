#ifndef __se3_model_hpp__
#define __se3_model_hpp__


#include "pinocchio/spatial/fwd.hpp"
#include "pinocchio/spatial/se3.hpp"
#include "pinocchio/spatial/inertia.hpp"
#include "pinocchio/spatial/motion.hpp"
#include "pinocchio/spatial/force.hpp"
#include "pinocchio/multibody/joint.hpp"
#include <iostream>

EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(se3::SE3)
EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(se3::Inertia)
EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(se3::Force)
EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(se3::Motion)
EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(Eigen::Matrix<double,6,Eigen::Dynamic>)

namespace se3
{
struct Model;
struct Data;

class Model
{
public:
    typedef int Index;

    /// Dimension of the configuration representation
    int nv;
    /// Dimension of the velocity vector space
    int nbody;
    /// Number of bodies (= number of joints + 1)
    int nq;
    /// Spatial inertias of the body <i> in the supporting joint frame <i>
    std::vector<Inertia> inertias;
    /// Placement (SE3) of the input of joint <i> in parent joint output <li>
    std::vector<SE3> jointPlacements;
    /// Model of joint <i>
    JointModelVector joints;
    /// Joint parent of joint <i>, denoted <li> (li==parents[i])
    std::vector<Index> parents;
    /// name of the body attached to the output of joint <i>
    std::vector<std::string> names;
    /// Spatial gravity
    Motion gravity;
    /// Default 3D gravity (=(0,0,9.81))
    static const Eigen::Vector3d gravity981;

    Model()
        : nq(0)
        , nv(0)
        , nbody(1)
        , inertias(1)
        , jointPlacements(1)
        , joints(1)
        , parents(1)
        , names(1)
        , gravity( gravity981,Eigen::Vector3d::Zero() )
    {
        names[0] = "universe";
    }
    ~Model() {} // std::cout << "Destroy model" << std::endl; }
    template<typename D>
    Index addBody( Index parent,const JointModelBase<D> & j,const SE3 & placement,
                   const Inertia & Y,const std::string & name = "" );
    Index getBodyId( const std::string & name ) const;
    bool existBodyName( const std::string & name ) const;
    const std::string& getBodyName( Index index ) const;
};

class Data
{
public:
    typedef Eigen::Matrix<double,6,Eigen::Dynamic> Matrix6x;
    typedef Eigen::Matrix<double,3,Eigen::Dynamic> Matrix3x;

public:
    ///refrence to model
    const Model& model;
    /// JointDataVector
    JointDataVector joints;
     /// Body acceleration
    std::vector<Motion> a;
    /// Body velocity
    std::vector<Motion> v;
    /// Body force
    std::vector<Force> f;
    /// Body absolute placement (wrt world)
    std::vector<SE3> oMi;
    /// Body relative placement (wrt parent)
    std::vector<SE3> liMi;
     /// Joint forces
    Eigen::VectorXd tau;

    /// Inertia of the sub-tree composit rigid body
    std::vector<Inertia> Ycrb;
    /// Joint Inertia
    Eigen::MatrixXd M;
    /// Spatial forces set, used in CRBA
    std::vector<Matrix6x> Fcrb;
    /// Index of the last child (for CRBA)
    std::vector<Model::Index> lastChild;
    /// Dimension of the subtree motion space (for CRBA)
    std::vector<int> nvSubtree;
    /// Joint Inertia square root (upper triangle)
    Eigen::MatrixXd U;
    /// Diagonal of UDUT inertia decomposition
    Eigen::VectorXd D;
    /// Temporary of size NV used in Cholesky
    Eigen::VectorXd tmp;
    /// First previous non-zero row in M (used in Cholesky)
    std::vector<int> parents_fromRow;
    ///
    std::vector<int> nvSubtree_fromRow;

    /// Jacobian of joint placement
    Eigen::MatrixXd J;
    /// Body placement wrt to algorithm end effector.
    std::vector<SE3> iMf;
    /// Subtree com position.
    std::vector<Eigen::Vector3d> com;
    /// Subtree total mass.
    std::vector<double> mass;
    /// Jacobian of center of mass.
    Eigen::Matrix<double,3,Eigen::Dynamic> Jcom;

    Data( const Model& ref );

private:
    void computeLastChild(const Model& model);
    void computeParents_fromRow(const Model& model);
};

const Eigen::Vector3d Model::gravity981 (0,0,-9.81);

} // namespace se3



/* --- Details -------------------------------------------------------------- */
/* --- Details -------------------------------------------------------------- */
/* --- Details -------------------------------------------------------------- */
namespace se3
{
std::ostream& operator<< ( std::ostream & os, const Model& model )
{
    os << "Nb bodies = " << model.nbody << " (nq="<< model.nq<<",nv="<<model.nv<<")" << std::endl;
    for(int i=0; i<model.nbody; ++i)
    {
        os << "  Joint "<<model.names[i] << ": parent=" << model.parents[i] << std::endl;
    }

    return os;
}

std::string random(const int len)
{
    std::string res;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i=0; i<len; ++i)
        res += alphanum[std::rand() % (sizeof(alphanum) - 1)];
    return res;
}

template<typename D>
Model::Index Model::addBody( Index parent,const JointModelBase<D> & j,const SE3 & placement,
                             const Inertia & Y,const std::string & name )
{
    assert( (nbody==(int)joints.size())&&(nbody==(int)inertias.size())
            &&(nbody==(int)parents.size())&&(nbody==(int)jointPlacements.size()) );
    assert( (j.nq()>=0)&&(j.nv()>=0) );

    Index idx = nbody ++;

    joints         .push_back(j.derived());
    boost::get<D&>(joints.back()).setIndexes(idx,nq,nv);

    inertias       .push_back(Y);
    parents        .push_back(parent);
    jointPlacements.push_back(placement);
    names          .push_back( (name!="")?name:random(8) );

    nq += j.nq();
    nv += j.nv();
    return idx;
}
Model::Index Model::getBodyId( const std::string & name ) const
{
    std::vector<std::string>::iterator::difference_type
    res = std::find(names.begin(),names.end(),name) - names.begin();
    assert( (res<INT_MAX) && "Id superior to int range. Should never happen.");
    assert( (res>=0)&&(res<nbody)&&"The body name you asked do not exist" );
    return int(res);
}
bool Model::existBodyName( const std::string & name ) const
{
    std::vector<std::string>::iterator::difference_type
    res = std::find(names.begin(),names.end(),name) - names.begin();
    return (res>=0)&&(res<nbody);
}

const std::string& Model::getBodyName( Model::Index index ) const
{
    assert( (index>=0)&&(index<nbody) );
    return names[index];
}

Data::Data( const Model& ref )
    :model(ref)
    ,joints(0)
    ,a(ref.nbody)
    ,v(ref.nbody)
    ,f(ref.nbody)
    ,oMi(ref.nbody)
    ,liMi(ref.nbody)
    ,tau(ref.nv)
    ,Ycrb(ref.nbody)
    ,M(ref.nv,ref.nv)
    ,Fcrb(ref.nbody)
    ,lastChild(ref.nbody)
    ,nvSubtree(ref.nbody)
    ,U(ref.nv,ref.nv)
    ,D(ref.nv)
    ,tmp(ref.nv)
    ,parents_fromRow(ref.nv)
    ,nvSubtree_fromRow(ref.nv)
    ,J(6,ref.nv)
    ,iMf(ref.nbody)
    ,com(ref.nbody)
    ,mass(ref.nbody)
    ,Jcom(3,ref.nv)
{
    for(int i=0; i<model.nbody; ++i)
        joints.push_back(CreateJointData::run(model.joints[i]));

    /* Init for CRBA */
    M.fill(NAN);
    for(int i=0; i<ref.nbody; ++i )
    {
        Fcrb[i].resize(6,model.nv);
        Fcrb[i].fill(NAN);
    }
    computeLastChild(ref);

    /* Init for Cholesky */
    U = Eigen::MatrixXd::Identity(ref.nv,ref.nv);
    computeParents_fromRow(ref);

    /* Init Jacobian */
    J.fill(0);
}

void Data::computeLastChild(const Model& model)
{
    typedef Model::Index Index;
    std::fill(lastChild.begin(),lastChild.end(),-1);
    for( int i=model.nbody-1; i>=0; --i )
    {
        if(lastChild[i] == -1) lastChild[i] = i;
        const Index & parent = model.parents[i];
        lastChild[parent] = std::max(lastChild[i],lastChild[parent]);

        nvSubtree[i]
            = idx_v(model.joints[lastChild[i]]) + nv(model.joints[lastChild[i]])
              - idx_v(model.joints[i]);
    }
}

void Data::computeParents_fromRow( const Model& model )
{
    for( int joint=1; joint<model.nbody; joint++)
    {
        const Model::Index & parent = model.parents[joint];
        const int nvj    = nv   (model.joints[joint]);
        const int idx_vj = idx_v(model.joints[joint]);

        if(parent>0) parents_fromRow[idx_vj] = idx_v(model.joints[parent])+nv(model.joints[parent])-1;
        else         parents_fromRow[idx_vj] = -1;
        nvSubtree_fromRow[idx_vj] = nvSubtree[joint];

        for( int row=1; row<nvj; ++row)
        {
            parents_fromRow[idx_vj+row] = idx_vj+row-1;
            nvSubtree_fromRow[idx_vj+row] = nvSubtree[joint]-row;
        }
    }
}

} // namespace se3

#endif // ifndef __se3_model_hpp__
