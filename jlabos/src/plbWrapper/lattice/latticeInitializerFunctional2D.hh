/* This file is part of the Palabos library.
 *
 * The Palabos softare is developed since 2011 by FlowKit-Numeca Group Sarl
 * (Switzerland) and the University of Geneva (Switzerland), which jointly
 * own the IP rights for most of the code base. Since October 2019, the
 * Palabos project is maintained by the University of Geneva and accepts
 * source code contributions from the community.
 * 
 * Contact:
 * Jonas Latt
 * Computer Science Department
 * University of Geneva
 * 7 Route de Drize
 * 1227 Carouge, Switzerland
 * jonas.latt@unige.ch
 *
 * The most recent release of Palabos can be downloaded at 
 * <https://palabos.unige.ch/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/** \file
 * Functionals for domain initialization -- generic implementation.
 */
#ifndef SWIG_LATTICE_INITIALIZER_FUNCTIONAL_2D_HH
#define SWIG_LATTICE_INITIALIZER_FUNCTIONAL_2D_HH

#include "plbWrapper/block/dataInitializerFunctional2D.h"
#include "core/cell.h"
#include "latticeBoltzmann/geometricOperationTemplates.h"
#include "latticeBoltzmann/roundOffPolicy.h"
#include "atomicBlock/blockLattice2D.h"

namespace plb {

/* ************* Class MaskedIniDynamicsFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
MaskedIniDynamicsFunctional2D<T,Descriptor>::MaskedIniDynamicsFunctional2D (
        Dynamics<T,Descriptor>* dynamics_)
    : dynamics(dynamics_)
{ }

template<typename T, template<typename U> class Descriptor>
MaskedIniDynamicsFunctional2D<T,Descriptor>::MaskedIniDynamicsFunctional2D (
        MaskedIniDynamicsFunctional2D<T,Descriptor> const& rhs )
    : dynamics(rhs.dynamics->clone())
{ }

template<typename T, template<typename U> class Descriptor>
MaskedIniDynamicsFunctional2D<T,Descriptor>&
    MaskedIniDynamicsFunctional2D<T,Descriptor>::operator= (
        MaskedIniDynamicsFunctional2D<T,Descriptor> const& rhs )
{
    delete dynamics; dynamics = rhs.dynamics->clone();
    return *this;
}

template<typename T, template<typename U> class Descriptor>
MaskedIniDynamicsFunctional2D<T,Descriptor>::~MaskedIniDynamicsFunctional2D() {
    delete dynamics;
}

template<typename T, template<typename U> class Descriptor>
void MaskedIniDynamicsFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<int>& mask )
{
    PLB_PRECONDITION( mask.getNdim()==1 );
    Dot2D offset = computeRelativeDisplacement(lattice, mask);
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            if (*mask.get(iX+offset.x, iY+offset.y)) {
                lattice.attributeDynamics(iX,iY, dynamics->clone());
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT MaskedIniDynamicsFunctional2D<T,Descriptor>::appliesTo() const {
    // Dynamics needs to be instantiated everywhere, including envelope.
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void MaskedIniDynamicsFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
MaskedIniDynamicsFunctional2D<T,Descriptor>*
    MaskedIniDynamicsFunctional2D<T,Descriptor>::clone() const 
{
    return new MaskedIniDynamicsFunctional2D<T,Descriptor>(*this);
}

/* ************* Class N_IniBoundaryVelocityFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void N_IniBoundaryVelocityFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<T>& velocity )
{
    PLB_PRECONDITION( velocity.getNdim()==2 );
    Dot2D offset = computeRelativeDisplacement(lattice, velocity);
    Array<T,2> velocityArray;
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            velocityArray.from_cArray(velocity.get(iX+offset.x, iY+offset.y));
            lattice.get(iX,iY).defineVelocity(velocityArray);
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT N_IniBoundaryVelocityFunctional2D<T,Descriptor>::appliesTo() const {
    // Dynamics needs to be instantiated everywhere, including envelope.
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void N_IniBoundaryVelocityFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
N_IniBoundaryVelocityFunctional2D<T,Descriptor>*
    N_IniBoundaryVelocityFunctional2D<T,Descriptor>::clone() const 
{
    return new N_IniBoundaryVelocityFunctional2D<T,Descriptor>(*this);
}


/* ************* Class Masked_N_IniBoundaryVelocityFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<T>& velocity,
                      NTensorField2D<int>& mask )
{
    PLB_PRECONDITION( velocity.getNdim()==2 );
    PLB_PRECONDITION( mask.getNdim()==1 );
    Dot2D offset = computeRelativeDisplacement(lattice, velocity);
    Dot2D maskOfs = computeRelativeDisplacement(lattice, mask);
    Array<T,2> velocityArray;
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            if (*mask.get(iX+maskOfs.x,iY+maskOfs.y)) {
                velocityArray.from_cArray(velocity.get(iX+offset.x, iY+offset.y));
                lattice.get(iX,iY).defineVelocity(velocityArray);
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>::appliesTo() const {
    // Dynamics needs to be instantiated everywhere, including envelope.
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
    modified[2] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>*
    Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>::clone() const 
{
    return new Masked_N_IniBoundaryVelocityFunctional2D<T,Descriptor>(*this);
}

/* ************* Class N_IniEquilibriumFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void N_IniEquilibriumFunctional2D<T,Descriptor>::processGenericBlocks (
            Box2D domain, std::vector<AtomicBlock2D*> blocks)
{
    BlockLattice2D<T,Descriptor>& lattice =
        dynamic_cast<BlockLattice2D<T,Descriptor>&>(*blocks[0]);
    NTensorField2D<T>& density =
        dynamic_cast<NTensorField2D<T>&>(*blocks[1]);
    PLB_PRECONDITION( density.getNdim()==1 );
    NTensorField2D<T>& velocity =
        dynamic_cast<NTensorField2D<T>&>(*blocks[2]);
    PLB_PRECONDITION( velocity.getNdim()==2 );
    Dot2D densityOfs = computeRelativeDisplacement(lattice, density);
    Dot2D velocityOfs = computeRelativeDisplacement(lattice, velocity);
    Array<T,2> j;
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            T rho = *density.get(iX+densityOfs.x, iY+densityOfs.y);
            T rhoBar = Descriptor<T>::rhoBar(rho);
            j.from_cArray(velocity.get(iX+velocityOfs.x, iY+velocityOfs.y));
            j *= rho;
            T jSqr = VectorTemplate<T,Descriptor>::normSqr(j);
            for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                lattice.get(iX,iY)[iPop] =
                    lattice.get(iX,iY).computeEquilibrium(iPop, rhoBar, j, jSqr);
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT N_IniEquilibriumFunctional2D<T,Descriptor>::appliesTo() const {
    // Spare the effort of communication by writing directly to envelope.
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void N_IniEquilibriumFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;   // Lattice
    modified[1] = modif::nothing;  // Density
    modified[2] = modif::nothing;  // Velocity
}

template<typename T, template<typename U> class Descriptor>
N_IniEquilibriumFunctional2D<T,Descriptor>*
    N_IniEquilibriumFunctional2D<T,Descriptor>::clone() const 
{
    return new N_IniEquilibriumFunctional2D<T,Descriptor>(*this);
}


/* ************* Class Masked_N_IniEquilibriumFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniEquilibriumFunctional2D<T,Descriptor>::processGenericBlocks (
            Box2D domain, std::vector<AtomicBlock2D*> blocks)
{
    BlockLattice2D<T,Descriptor>& lattice =
        dynamic_cast<BlockLattice2D<T,Descriptor>&>(*blocks[0]);
    NTensorField2D<T>& density =
        dynamic_cast<NTensorField2D<T>&>(*blocks[1]);
    PLB_PRECONDITION( density.getNdim()==1 );
    NTensorField2D<T>& velocity =
        dynamic_cast<NTensorField2D<T>&>(*blocks[2]);
    PLB_PRECONDITION( velocity.getNdim()==2 );
    NTensorField2D<int>& mask =
        dynamic_cast<NTensorField2D<int>&>(*blocks[3]);
    PLB_PRECONDITION( mask.getNdim()==1 );
    Dot2D densityOfs = computeRelativeDisplacement(lattice, density);
    Dot2D velocityOfs = computeRelativeDisplacement(lattice, velocity);
    Dot2D maskOfs = computeRelativeDisplacement(lattice, mask);
    Array<T,2> j;
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            if (*mask.get(iX+maskOfs.x, iY+maskOfs.y)) {
                T rho = *density.get(iX+densityOfs.x, iY+densityOfs.y);
                T rhoBar = Descriptor<T>::rhoBar(rho);
                j.from_cArray(velocity.get(iX+velocityOfs.x, iY+velocityOfs.y));
                j *= rho;
                T jSqr = VectorTemplate<T,Descriptor>::normSqr(j);
                for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                    lattice.get(iX,iY)[iPop] =
                        lattice.get(iX,iY).computeEquilibrium(iPop, rhoBar, j, jSqr);
                }
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT Masked_N_IniEquilibriumFunctional2D<T,Descriptor>::appliesTo() const {
    // Spare the effort of communication by writing directly to envelope.
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniEquilibriumFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;   // Lattice
    modified[1] = modif::nothing;  // Density
    modified[2] = modif::nothing;  // Velocity
    modified[3] = modif::nothing;  // Mask
}

template<typename T, template<typename U> class Descriptor>
Masked_N_IniEquilibriumFunctional2D<T,Descriptor>*
    Masked_N_IniEquilibriumFunctional2D<T,Descriptor>::clone() const 
{
    return new Masked_N_IniEquilibriumFunctional2D<T,Descriptor>(*this);
}

/* ************* Class N_IniPopulationsFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void N_IniPopulationsFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<T>& populations )
{
    PLB_PRECONDITION( populations.getNdim()==Descriptor<T>::q );
    Dot2D offset = computeRelativeDisplacement(lattice, populations);
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            Cell<T,Descriptor>& cell = lattice.get(iX,iY);
            T const* pop = populations.get(iX+offset.x, iY+offset.y) ;
            for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                cell[iPop] = fBar<T,Descriptor>(pop[iPop],iPop);
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT N_IniPopulationsFunctional2D<T,Descriptor>::appliesTo() const {
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void N_IniPopulationsFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
N_IniPopulationsFunctional2D<T,Descriptor>*
    N_IniPopulationsFunctional2D<T,Descriptor>::clone() const 
{
    return new N_IniPopulationsFunctional2D<T,Descriptor>(*this);
}


/* ************* Class Masked_N_IniPopulationsFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniPopulationsFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<T>& populations,
                      NTensorField2D<int>& mask )
{
    PLB_PRECONDITION( populations.getNdim()==Descriptor<T>::q );
    PLB_PRECONDITION( mask.getNdim()==1 );
    Dot2D offset = computeRelativeDisplacement(lattice, populations);
    Dot2D maskOfs= computeRelativeDisplacement(lattice, mask);
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            if (*mask.get(iX+maskOfs.x,iY+maskOfs.y)) {
                Cell<T,Descriptor>& cell = lattice.get(iX,iY);
                T const* pop = populations.get(iX+offset.x, iY+offset.y) ;
                for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                    cell[iPop] = fBar<T,Descriptor>(pop[iPop],iPop);
                }
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT Masked_N_IniPopulationsFunctional2D<T,Descriptor>::appliesTo() const {
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniPopulationsFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
    modified[2] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
Masked_N_IniPopulationsFunctional2D<T,Descriptor>*
    Masked_N_IniPopulationsFunctional2D<T,Descriptor>::clone() const 
{
    return new Masked_N_IniPopulationsFunctional2D<T,Descriptor>(*this);
}


/* ************* Class N_IniConstPopulationsFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
N_IniConstPopulationsFunctional2D<T,Descriptor>::N_IniConstPopulationsFunctional2D (
        std::vector<T> const& pop_ )
    : pop(pop_)
{
    PLB_ASSERT( pop.size() == (pluint) Descriptor<T>::q );
}

template<typename T, template<typename U> class Descriptor>
void N_IniConstPopulationsFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice )
{
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            Cell<T,Descriptor>& cell = lattice.get(iX,iY);
            for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                cell[iPop] = fBar<T,Descriptor>(pop[iPop],iPop);
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT N_IniConstPopulationsFunctional2D<T,Descriptor>::appliesTo() const {
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void N_IniConstPopulationsFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
}

template<typename T, template<typename U> class Descriptor>
N_IniConstPopulationsFunctional2D<T,Descriptor>*
    N_IniConstPopulationsFunctional2D<T,Descriptor>::clone() const 
{
    return new N_IniConstPopulationsFunctional2D<T,Descriptor>(*this);
}


/* ************* Class Masked_N_IniConstPopulationsFunctional2D ************************ */

template<typename T, template<typename U> class Descriptor>
Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>::Masked_N_IniConstPopulationsFunctional2D (
        std::vector<T> const& pop_ )
    : pop(pop_)
{
    PLB_ASSERT( pop.size() == (pluint) Descriptor<T>::q );
}

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>::process (
        Box2D domain, BlockLattice2D<T,Descriptor>& lattice,
                      NTensorField2D<int>& mask )
{
    PLB_PRECONDITION( mask.getNdim()==1 );
    Dot2D maskOfs= computeRelativeDisplacement(lattice, mask);
    for (plint iX=domain.x0; iX<=domain.x1; ++iX) {
        for (plint iY=domain.y0; iY<=domain.y1; ++iY) {
            if (*mask.get(iX+maskOfs.x,iY+maskOfs.y)) {
                Cell<T,Descriptor>& cell = lattice.get(iX,iY);
                for (plint iPop=0; iPop<Descriptor<T>::q; ++iPop) {
                    cell[iPop] = fBar<T,Descriptor>(pop[iPop],iPop);
                }
            }
        }
    }
}

template<typename T, template<typename U> class Descriptor>
BlockDomain::DomainT Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>::appliesTo() const {
    return BlockDomain::bulkAndEnvelope;
}

template<typename T, template<typename U> class Descriptor>
void Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>::getTypeOfModification (
        std::vector<modif::ModifT>& modified ) const
{
    modified[0] = modif::staticVariables;
    modified[1] = modif::nothing;
}

template<typename T, template<typename U> class Descriptor>
Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>*
    Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>::clone() const 
{
    return new Masked_N_IniConstPopulationsFunctional2D<T,Descriptor>(*this);
}

}  // namespace plb

#endif  // SWIG_LATTICE_INITIALIZER_FUNCTIONAL_2D_HH
