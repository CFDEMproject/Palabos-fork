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

#ifdef COMPILE_3D

#include "plbWrapper/lattice/latticeInitializerWrapper3D.h"
#include "plbWrapper/lattice/latticeInitializerWrapper3D.hh"
#include "latticeBoltzmann/nearestNeighborLattices3D.h"
#include "latticeBoltzmann/nearestNeighborLattices3D.hh"

namespace plb {

template void pypalDefineDynamics<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        Box3D domain, Dynamics<FLOAT_T,descriptors::DESCRIPTOR_3D>* dynamics);
template void maskedDefineDynamics<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice, MultiNTensorField3D<int>& mask,
        Box3D domain, Dynamics<FLOAT_T,descriptors::DESCRIPTOR_3D>* dynamics);
template void setBoundaryVelocity<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice,
        FLOAT_T* velocity, int numDimIs2, Box3D domain );
template void setBoundaryVelocity<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& velocity, Box3D domain );
template void maskedSetBoundaryVelocity<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& velocity,
        MultiNTensorField3D<int>& mask, Box3D domain );
template void initializeAtEquilibrium<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice, FLOAT_T rho,
        FLOAT_T* velocity, int numDimIs2, Box3D domain );
template void initializeAtEquilibrium<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& density,
        MultiNTensorField3D<FLOAT_T>& velocity,
        Box3D domain );
template void maskedInitializeAtEquilibrium<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T, descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& density,
        MultiNTensorField3D<FLOAT_T>& velocity,
        MultiNTensorField3D<int>& mask,
        Box3D domain );
template void setExternalVector<FLOAT_T, descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        int vectorStartsAt, FLOAT_T* externalVector, int numDimIs2,
        Box3D domain);
template void setPopulations<FLOAT_T,descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        FLOAT_T* populations, int numDimIsQ, Box3D domain );
template void setPopulations<FLOAT_T,descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& populations, Box3D domain );
template void maskedSetPopulations<FLOAT_T,descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        FLOAT_T* populations, int numDimIsQ,
        MultiNTensorField3D<int>& mask, Box3D domain );
template void maskedSetPopulations<FLOAT_T,descriptors::DESCRIPTOR_3D> (
        MultiBlockLattice3D<FLOAT_T,descriptors::DESCRIPTOR_3D>& lattice,
        MultiNTensorField3D<FLOAT_T>& velocity,
        MultiNTensorField3D<int>& mask, Box3D domain );

}  // namespace plb

#endif  // COMPILE_3D
