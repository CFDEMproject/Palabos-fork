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

#include "boundaryCondition/neumannCondition3D.h"
#include "boundaryCondition/neumannCondition3D.hh"
#include "latticeBoltzmann/nearestNeighborLattices3D.h"
#include "latticeBoltzmann/nearestNeighborLattices3D.hh"

namespace plb {

    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, -1>;
    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, +1>;
    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  1, -1>;
    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  1, +1>;
    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  2, -1>;
    template class CopyUnknownPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  2, +1>;

    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,+1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1, 0>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,-1>;
    template class CopyAllPopulationsFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,+1>;

    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,+1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1, 0>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,-1>;
    template class CopyVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,+1>;

    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,+1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1, 0>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,-1>;
    template class CopyTangentialVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,+1>;

    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,+1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1, 0>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,-1>;
    template class CopyNormalVelocityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,+1>;

    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0, 0,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,-1,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D,  0,+1,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1, 0,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,-1,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, -1,+1,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1, 0,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,-1,+1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1, 0>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,-1>;
    template class CopyDensityFunctional3D<FLOAT_T, descriptors::DESCRIPTOR_3D, +1,+1,+1>;

}

#endif  // COMPILE_3D
