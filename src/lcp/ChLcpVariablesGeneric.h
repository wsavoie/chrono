#ifndef CHLCPVARIABLESGENERIC_H
#define CHLCPVARIABLESGENERIC_H

//////////////////////////////////////////////////
//
//   ChLcpVariablesGeneric.h
//
//    Specialized class for representing a N-DOF item for a
//   LCP system, that is an item with mass matrix and
//   associate variables.
//    Specialized class for representing a mass matrix
//   and associate variables for a generic item
//   with a normal (uncompressed) mass matrix, to be
//   used in a LCP problem of the type:
//
//    | M -Cq'|*|q|- | f|= |0| ,  c>0, l>0, l*r=0;
//    | Cq  0 | |l|  |-b|  |c|
//
//
//   HEADER file for CHRONO HYPEROCTANT LCP solver
//
// ------------------------------------------------
// 	 Copyright:Alessandro Tasora / DeltaKnowledge
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////


#include "ChLcpVariables.h"
#include "core/ChMemory.h" // must be after system's include (memory leak debugger).


namespace chrono
{

///    Specialized class for representing a N-DOF item for a
///   LCP system, that is an item with mass matrix and
///   associate variables.
///    The main difference from the base class ChLcpVariables
///   is that the base class does not create any mass matrix,
///   while this minimal specialization at least creates a
///   NxN mass matrix. Of course a generic (uncompressed) NxN
///   matrix is used. This means that, for example, this
///   class could  be used for 3D rigid bodies if N=6, however
///   it would be better to implement a more optimized class
///   which does not create a full 6x6 matrix (since only few
///   elements on the diagonal would be different from 0 in case
///   of rigid bodies), so use the ChLcpVariablesBody in this case..


class ChApi ChLcpVariablesGeneric :  public ChLcpVariables
{
	CH_RTTI(ChLcpVariablesGeneric, ChLcpVariables)

private:
			//
			// DATA
			//
				/// the data (qb, variables and fb, forces, already defined in base class)

			ChMatrixDynamic<>* Mmass;
			ChMatrixDynamic<>* inv_Mmass;
			int ndof;

public:

			//
			// CONSTRUCTORS
			//
	ChLcpVariablesGeneric(int m_ndof= 1)
							: ChLcpVariables(m_ndof)
				{
					ndof = m_ndof;
					Mmass = new ChMatrixDynamic<>(ndof, ndof);
					Mmass->SetIdentity();
					inv_Mmass = new ChMatrixDynamic<>(ndof, ndof);
					inv_Mmass->SetIdentity();
				};

	virtual ~ChLcpVariablesGeneric()
				{
					if (Mmass) delete Mmass; Mmass= NULL;
					if (inv_Mmass) delete inv_Mmass; inv_Mmass= NULL;
				};


				/// Assignment operator: copy from other object
	ChLcpVariablesGeneric& operator=(const ChLcpVariablesGeneric& other);


			//
			// FUNCTIONS
			//

				/// Access the inertia matrix
	ChMatrix<>& GetMass() {return *Mmass;}

				/// Access the inverted inertia matrix
	ChMatrix<>& GetInvMass() {return *inv_Mmass;}


				// IMPLEMENT PARENT CLASS METHODS


				/// The number of scalar variables in the vector qb
				/// (dof=degrees of freedom)
	virtual int Get_ndof() {return this->ndof;};


				/// Computes the product of the inverse mass matrix by a
				/// vector, and add to result: result = [invMb]*vect
	virtual void Compute_invMb_v(ChMatrix<float>& result, const ChMatrix<float>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result = (*inv_Mmass)*vect;
					};
	virtual void Compute_invMb_v(ChMatrix<double>& result, const ChMatrix<double>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result = (*inv_Mmass)*vect;
					};

				/// Computes the product of the inverse mass matrix by a
				/// vector, and increment result: result += [invMb]*vect
	virtual void Compute_inc_invMb_v(ChMatrix<float>& result, const ChMatrix<float>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result += (*inv_Mmass)*vect;
					};
	virtual void Compute_inc_invMb_v(ChMatrix<double>& result, const ChMatrix<double>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result += (*inv_Mmass)*vect;
					};

				/// Computes the product of the mass matrix by a
				/// vector, and set in result: result = [Mb]*vect
	virtual void Compute_Mb_v(ChMatrix<float>& result, const ChMatrix<float>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result = (*Mmass)*vect;
					};
	virtual void Compute_Mb_v(ChMatrix<double>& result, const ChMatrix<double>& vect)
					{
						assert (result.GetRows() == vect.GetRows());
						assert (vect.GetRows()   == Get_ndof());
						result = (*Mmass)*vect;
					};

				/// Build the mass matrix (for these variables) storing
				/// it in 'storage' sparse matrix, at given column/row offset.
				/// This function is used only by the ChLcpSimplex solver (iterative 
				/// solvers don't need to know mass matrix explicitly).
	virtual void Build_M(ChSparseMatrix& storage, int insrow, int inscol)
					{
						storage.PasteMatrix(Mmass, insrow, inscol);
					};

};




} // END_OF_NAMESPACE____


#include "core/ChMemorynomgr.h" // back to default new/delete/malloc/calloc etc. Avoid conflicts with system libs.


#endif  // END of ChLcpVariablesGeneric.h