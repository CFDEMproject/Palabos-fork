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
 * Interface to NumPy -- generic code.
 */
#ifndef NUMPY_INTERFACE_3D_HH
#define NUMPY_INTERFACE_3D_HH

#include "plbWrapper/block/numPyInterface3D.h"
#include "core/serializer.h"
#include "parallelism/mpiManager.h"
#include "io/parallelIO.h"

namespace plb {

/* *************** Class NTensorField2NumPy3D ************************************ */

template<typename T>
NTensorField2NumPy3D<T>::NTensorField2NumPy3D(MultiNTensorField3D<T>& field_)
    : field(field_),
      domain(field.getBoundingBox())
{ }

template<typename T>
NTensorField2NumPy3D<T>::NTensorField2NumPy3D(MultiNTensorField3D<T>& field_, Box3D const& domain_)
    : field(field_),
      domain(domain_)
{ }

template<typename T>
void NTensorField2NumPy3D<T>::execute(T* array, int size) {
    serializerToSink (
            field.getBlockSerializer(domain, IndexOrdering::forward),
            new WriteToSerialArray<T>(array, (pluint)size)
    );
    global::mpi().bCast(array, size);
}

template<typename T>
int NTensorField2NumPy3D<T>::getSize() const {
    return (int) (domain.nCells() * field.getNdim());
}


/* *************** Class NumPy2NTensorField3D ************************************ */

template<typename T>
NumPy2NTensorField3D<T>::NumPy2NTensorField3D(MultiNTensorField3D<T>& field_)
    : field(field_),
      domain(field.getBoundingBox())
{ }

template<typename T>
NumPy2NTensorField3D<T>::NumPy2NTensorField3D(MultiNTensorField3D<T>& field_, Box3D const& domain_)
    : field(field_),
      domain(domain_)
{ }

template<typename T>
void NumPy2NTensorField3D<T>::execute(T* array, int size) {
    sourceToUnSerializer (
            new ReadFromSerialArray<T>(array, (pluint)size),
            field.getBlockUnSerializer(domain, IndexOrdering::forward)
    );
}

template<typename T>
int NumPy2NTensorField3D<T>::getSize() const {
    return (int) (domain.nCells() * field.getNdim());
}

}  // namespace plb

#endif  // NUMPY_INTERFACE_3D_HH
