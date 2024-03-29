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

#include "plbWrapper/lattice/numPyInterface3D.h"
#include "core/serializer.h"
#include "parallelism/mpiManager.h"
#include "io/parallelIO.h"

namespace plb {

/* *************** Class Lattice2NumPy3D ************************************ */

template<typename T, template<typename U> class Descriptor>
Lattice2NumPy3D<T,Descriptor>::Lattice2NumPy3D(MultiBlockLattice3D<T,Descriptor>& lattice_)
    : lattice(lattice_),
      domain(lattice.getBoundingBox())
{ }

template<typename T, template<typename U> class Descriptor>
Lattice2NumPy3D<T,Descriptor>::Lattice2NumPy3D(MultiBlockLattice3D<T,Descriptor>& lattice_, Box3D const& domain_)
    : lattice(lattice_),
      domain(domain_)
{ }

template<typename T, template<typename U> class Descriptor>
void Lattice2NumPy3D<T,Descriptor>::execute(T* array, int size) {
    serializerToSink (
            lattice.getBlockSerializer(domain, IndexOrdering::forward),
            new WriteToSerialArray<T>(array, (plint)size)
    );
    global::mpi().bCast(array, size);
}

template<typename T, template<typename U> class Descriptor>
int Lattice2NumPy3D<T,Descriptor>::getSize() const {
    return (int) (domain.nCells() * lattice.sizeOfCell()/sizeof(T));
}


/* *************** Class NumPy2Lattice3D ************************************ */

template<typename T, template<typename U> class Descriptor>
NumPy2Lattice3D<T,Descriptor>::NumPy2Lattice3D(MultiBlockLattice3D<T,Descriptor>& lattice_)
    : lattice(lattice_),
      domain(lattice.getBoundingBox())
{ }

template<typename T, template<typename U> class Descriptor>
NumPy2Lattice3D<T,Descriptor>::NumPy2Lattice3D(MultiBlockLattice3D<T,Descriptor>& lattice_, Box3D const& domain_)
    : lattice(lattice_),
      domain(domain_)
{ }

template<typename T, template<typename U> class Descriptor>
void NumPy2Lattice3D<T,Descriptor>::execute(T* array, int size) {
    sourceToUnSerializer (
            new ReadFromSerialArray<T>(array, (plint)size),
            lattice.getBlockUnSerializer(domain, IndexOrdering::forward)
    );
}

template<typename T, template<typename U> class Descriptor>
int NumPy2Lattice3D<T,Descriptor>::getSize() const {
    return (int) (domain.nCells());
}

}  // namespace plb

#endif  // NUMPY_INTERFACE_3D_HH
