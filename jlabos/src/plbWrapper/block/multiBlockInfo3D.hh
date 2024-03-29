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
 * Helper functions for domain initialization -- header file.
 */

#ifndef SWIG_MULTI_BLOCK_INFO_3D_HH
#define SWIG_MULTI_BLOCK_INFO_3D_HH

#include "plbWrapper/block/multiBlockInfo3D.h"

namespace plb {

template<typename T>
MultiNTensorInfo3D<T>::MultiNTensorInfo3D(MultiNTensorField3D<T> const& multiBlock)
    : nx(),
      ny(),
      nz(),
      numBlocks(),
      numAllocatedCells()
{
    getMultiBlockInfo(multiBlock, nx, ny, nz, numBlocks,
                      smallest, largest, numAllocatedCells);
}

template<typename T>
plint MultiNTensorInfo3D<T>::getNx() const {
    return nx;
}

template<typename T>
plint MultiNTensorInfo3D<T>::getNy() const {
    return ny;
}

template<typename T>
plint MultiNTensorInfo3D<T>::getNz() const {
    return nz;
}

template<typename T>
plint MultiNTensorInfo3D<T>::getNumBlocks() const {
    return numBlocks;
}

template<typename T>
plint MultiNTensorInfo3D<T>::getNumAllocatedCells() const {
    return numAllocatedCells;
}

template<typename T>
Box3D MultiNTensorInfo3D<T>::getSmallestBlock() const {
    return smallest;
}

template<typename T>
Box3D MultiNTensorInfo3D<T>::getLargestBlock() const {
    return largest;
}

}  // namespace plb

#endif  // SWIG_MULTI_BLOCK_INFO_3D_HH
