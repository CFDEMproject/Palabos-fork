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
 * A collection of dynamics classes (e.g. BGK) with which a Cell object
 * can be instantiated -- template instantiation.
 */
#ifdef COMPILE_2D

#include "core/dynamics.h"
#include "core/dynamics.hh"
#include "latticeBoltzmann/nearestNeighborLattices2D.h"
#include "latticeBoltzmann/nearestNeighborLattices2D.hh"
#include "latticeBoltzmann/mrtLattices.h"
#include "latticeBoltzmann/mrtLattices.hh"

namespace plb {

    template class Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class BasicBulkDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class CompositeDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class PreparePopulationsDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class BulkCompositeDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class BounceBack<FLOAT_T, descriptors::DESCRIPTOR_2D>;
    template class NoDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>;

#if NUMBIT_2D == 9
    template class BasicBulkDynamics<FLOAT_T, descriptors::MRTD2Q9Descriptor>;
#endif

    template void constructIdChain<FLOAT_T, descriptors::DESCRIPTOR_2D> (
            Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const& dynamics, std::vector<int>& chain );

    template Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const&
        getBottomMostDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> (
                Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const& dynamics );

    template Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>*
        cloneAndReplaceBottomDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> (
                Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const& dynamics,
                Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>* newBottom );

    template Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>*
        cloneAndInsertAtTopDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> (
                Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const& dynamics,
                CompositeDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>* newTop );

    template void serialize<FLOAT_T, descriptors::DESCRIPTOR_2D> (
            Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> const& dynamics,
            std::vector<char>& data );

    template void serialize<FLOAT_T, descriptors::DESCRIPTOR_2D> (
            std::vector<Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>*> const& dynamics,
            std::vector<char>& data );

    template pluint unserialize<FLOAT_T, descriptors::DESCRIPTOR_2D> (
            Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>& dynamics,
            std::vector<char> const& data, pluint serializerPos );

    template void generateAndUnserializeDynamics<FLOAT_T, descriptors::DESCRIPTOR_2D> (
            std::vector<char> const& data,
            std::vector<Dynamics<FLOAT_T, descriptors::DESCRIPTOR_2D>*>& dynamics );

}

#endif  // COMPILE_2D
