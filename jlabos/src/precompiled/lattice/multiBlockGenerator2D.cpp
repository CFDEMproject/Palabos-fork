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
 * A 2D multiblock lattice -- template instantiation.
 */

#ifdef COMPILE_2D

#include "multiBlock/multiBlockGenerator2D.h"
#include "multiBlock/multiBlockGenerator2D.hh"
#include "latticeBoltzmann/nearestNeighborLattices2D.h"
#include "latticeBoltzmann/nearestNeighborLattices2D.hh"

namespace plb {

template std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > 
 defaultGenerateMultiBlockLattice2D< FLOAT_T,descriptors::DESCRIPTOR_2D > (
        MultiBlockManagement2D const& management, plint unnamedDummyArg );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > clone<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D>& originalLattice,
        Box2D const& subDomain, bool crop );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > generateMultiBlockLattice<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlock2D const& originalBlock, Box2D const& intersection,
        bool crop );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > generateIntersectMultiBlockLattice<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlock2D const& originalBlock1,
        MultiBlock2D const& originalBlock2, bool crop );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > generateIntersectMultiBlockLattice<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlock2D const& originalBlock1,
        MultiBlock2D const& originalBlock2,
        Box2D const& intersection, bool crop );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > generateJoinMultiBlockLattice<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlock2D const& originalBlock1,
        MultiBlock2D const& originalBlock2 );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > extend<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D>& originalBlock, Box2D const& addedBlock );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D> > except<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T,descriptors::DESCRIPTOR_2D>& originalBlock,
        Box2D const& exceptedBlock );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> > redistribute<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> const& originalBlock,
        SparseBlockStructure2D const& newBlockStructure );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> > redistribute<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> const& originalBlock,
        SparseBlockStructure2D const& newBlockStructure,
        Box2D const& intersection, bool crop );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> > align<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> const& originalBlock,
        MultiBlock2D const& partnerBlock );

template
std::unique_ptr<MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> > reparallelize<FLOAT_T, descriptors::DESCRIPTOR_2D> (
        MultiBlockLattice2D<FLOAT_T, descriptors::DESCRIPTOR_2D> const& originalBlock );

}

#endif  // COMPILE_2D
