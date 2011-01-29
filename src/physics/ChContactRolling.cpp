///////////////////////////////////////////////////
//
//   ChContact.cpp
//
// ------------------------------------------------
// 	 Copyright:Alessandro Tasora / DeltaKnowledge
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////
 
  
#include "physics/ChContactRolling.h"
#include "physics/ChSystem.h"

#include "core/ChMemory.h" // must be last include (memory leak debugger). In .cpp only.


namespace chrono
{


using namespace collision;
using namespace geometry;


ChContactRolling::ChContactRolling ()
{ 
	Rx.SetRollingConstraintU(&Ru);
	Rx.SetRollingConstraintV(&Rv);
	Rx.SetNormalConstraint(&Nx);
}

ChContactRolling::ChContactRolling (collision::ChCollisionModel* mmodA,	///< model A
						collision::ChCollisionModel* mmodB,	///< model B
						const ChLcpVariablesBody* varA, ///< pass A vars
						const ChLcpVariablesBody* varB, ///< pass B vars
						const ChFrame<>* frameA,		  ///< pass A frame
						const ChFrame<>* frameB,		  ///< pass B frame
						const ChVector<>& vpA,		  ///< pass coll.point on A
						const ChVector<>& vpB,		  ///< pass coll.point on B
						const ChVector<>& vN, 		  ///< pass coll.normal, respect to A
						double mdistance,		  ///< pass the distance (negative for penetration)
						float* mreaction_cache,	  ///< pass the pointer to array of N,U,V reactions: a cache in contact manifold. If not available=0.
						float mfriction,		  ///< friction coeff.
						float  mrollfriction,			///< rolling friction
						float  mspinningfriction,			///< spinning friction
						float  cohesion					///< cohesion
				)
{ 
	Rx.SetRollingConstraintU(&Ru);
	Rx.SetRollingConstraintV(&Rv);
	Rx.SetNormalConstraint(&Nx);

	Reset(	mmodA, mmodB,
			varA, ///< pass A vars
			varB, ///< pass B vars
			frameA,		  ///< pass A frame
			frameB,		  ///< pass B frame
			vpA,		  ///< pass coll.point on A
			vpB,		  ///< pass coll.point on B
			vN, 		  ///< pass coll.normal, respect to A
			mdistance,		  ///< pass the distance (negative for penetration)
			mreaction_cache,	  ///< pass the pointer to array of N,U,V reactions: a cache in contact manifold. If not available=0.
			mfriction,			  ///< friction coeff.
			mrollfriction,
			mspinningfriction,
			cohesion					
				);
}

ChContactRolling::~ChContactRolling ()
{

}

void ChContactRolling::Reset(	collision::ChCollisionModel* mmodA,	///< model A
						collision::ChCollisionModel* mmodB,	///< model B
					    const ChLcpVariablesBody* varA, ///< pass A vars
						const ChLcpVariablesBody* varB, ///< pass B vars
						const ChFrame<>* frameA,		  ///< pass A frame
						const ChFrame<>* frameB,		  ///< pass B frame
						const ChVector<>& vpA,		  ///< pass coll.point on A
						const ChVector<>& vpB,		  ///< pass coll.point on B
						const ChVector<>& vN, 		  ///< pass coll.normal, respect to A
						double mdistance,		  ///< pass the distance (negative for penetration)
						float* mreaction_cache,	  ///< pass the pointer to array of N,U,V reactions: a cache in contact manifold. If not available=0.
						float mfriction,			  ///< friction coeff.
						float  mrollfriction,			///< rolling friction
						float  mspinningfriction,			///< spinning friction
						float  cohesion					///< cohesion
				)
{
	// Base method call:
	ChContact::Reset(	mmodA, mmodB,
			varA, ///< pass A vars
			varB, ///< pass B vars
			frameA,		  ///< pass A frame
			frameB,		  ///< pass B frame
			vpA,		  ///< pass coll.point on A
			vpB,		  ///< pass coll.point on B
			vN, 		  ///< pass coll.normal, respect to A
			mdistance,		  ///< pass the distance (negative for penetration)
			mreaction_cache,	  ///< pass the pointer to array of N,U,V reactions: a cache in contact manifold. If not available=0.
			mfriction,			  ///< friction coeff.
			cohesion					///< cohesion
				);

	Rx.SetVariables(const_cast<ChLcpVariablesBody*>(varA),const_cast<ChLcpVariablesBody*>(varB));
	Ru.SetVariables(const_cast<ChLcpVariablesBody*>(varA),const_cast<ChLcpVariablesBody*>(varB));
	Rv.SetVariables(const_cast<ChLcpVariablesBody*>(varA),const_cast<ChLcpVariablesBody*>(varB));

	Rx.SetRollingFrictionCoefficient(mrollfriction);
	Rx.SetSpinningFrictionCoefficient(mspinningfriction);

	ChMatrix33<> Jx1, Jx2, Jr1, Jr2;

	Jr1.MatrTMultiply(this->contact_plane, *(const_cast<ChFrame<>*>(frameA)->GetA()));
	Jr2.MatrTMultiply(this->contact_plane, *(const_cast<ChFrame<>*>(frameB)->GetA()));
	Jr1.MatrNeg();

	Rx.Get_Cq_a()->PasteClippedMatrix(&Jx1, 0,0, 1,3, 0,0);
	Ru.Get_Cq_a()->PasteClippedMatrix(&Jx1, 1,0, 1,3, 0,0);
	Rv.Get_Cq_a()->PasteClippedMatrix(&Jx1, 2,0, 1,3, 0,0);
	Rx.Get_Cq_a()->PasteClippedMatrix(&Jr1, 0,0, 1,3, 0,3);
	Ru.Get_Cq_a()->PasteClippedMatrix(&Jr1, 1,0, 1,3, 0,3);
	Rv.Get_Cq_a()->PasteClippedMatrix(&Jr1, 2,0, 1,3, 0,3);

	Rx.Get_Cq_b()->PasteClippedMatrix(&Jx2, 0,0, 1,3, 0,0);
	Ru.Get_Cq_b()->PasteClippedMatrix(&Jx2, 1,0, 1,3, 0,0);
	Rv.Get_Cq_b()->PasteClippedMatrix(&Jx2, 2,0, 1,3, 0,0);
	Rx.Get_Cq_b()->PasteClippedMatrix(&Jr2, 0,0, 1,3, 0,3);
	Ru.Get_Cq_b()->PasteClippedMatrix(&Jr2, 1,0, 1,3, 0,3);
	Rv.Get_Cq_b()->PasteClippedMatrix(&Jr2, 2,0, 1,3, 0,3);

	react_torque = VNULL;

}




 


void ChContactRolling::InjectConstraints(ChLcpSystemDescriptor& mdescriptor)
{
	// base behaviour too
	ChContact::InjectConstraints(mdescriptor);

	mdescriptor.InsertConstraint(&Rx);
	mdescriptor.InsertConstraint(&Ru);
	mdescriptor.InsertConstraint(&Rv); 
}

void ChContactRolling::ConstraintsBiReset()
{
	// base behaviour too
	ChContact::ConstraintsBiReset();

	Rx.Set_b_i(0.);
	Ru.Set_b_i(0.);
	Rv.Set_b_i(0.);
}
 
void ChContactRolling::ConstraintsBiLoad_C(double factor, double recovery_clamp, bool do_clamp)
{
	// base behaviour too
	ChContact::ConstraintsBiLoad_C(factor,recovery_clamp,do_clamp);
	
	// Assume no residual ever, do not load in C
}

void ChContactRolling::ConstraintsFetch_react(double factor)
{
	// base behaviour too
	ChContact::ConstraintsFetch_react(factor);

	// From constraints to react torque:
	react_torque.x = Rx.Get_l_i() * factor;  
	react_torque.y = Ru.Get_l_i() * factor;
	react_torque.z = Rv.Get_l_i() * factor;
}


void  ChContactRolling::ConstraintsLiLoadSuggestedSpeedSolution()
{
	// base behaviour too
	ChContact::ConstraintsLiLoadSuggestedSpeedSolution();

	// [Note: no persistent cache used for rolling multipliers - do nothing]
}

void  ChContactRolling::ConstraintsLiLoadSuggestedPositionSolution()
{
	// base behaviour too
	ChContact::ConstraintsLiLoadSuggestedPositionSolution();

	// [Note: no persistent cache used for rolling multipliers - do nothing]
}

void  ChContactRolling::ConstraintsLiFetchSuggestedSpeedSolution()
{
	// base behaviour too
	ChContact::ConstraintsLiFetchSuggestedSpeedSolution();

	// [Note: no persistent cache used for rolling multipliers - do nothing]
}

void  ChContactRolling::ConstraintsLiFetchSuggestedPositionSolution()
{
	// base behaviour too
	ChContact::ConstraintsLiFetchSuggestedPositionSolution();

	// [Note: no persistent cache used for rolling multipliers - do nothing]
}












} // END_OF_NAMESPACE____

