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
#ifndef SWIG_DATA_INITIALIZER_WRAPPER_2D_H
#define SWIG_DATA_INITIALIZER_WRAPPER_2D_H

#include "core/globalDefs.h"
#include "atomicBlock/dataProcessorWrapper2D.h"
#include "multiBlock/multiDataProcessorWrapper2D.h"
#include "core/dynamics.h"
#include "plbWrapper/block/dataInitializerFunctional2D.h"

namespace plb {

/// Initialize scalar-field with the same constant value on each cell.
template<typename T>
void setToConstant(MultiNTensorField2D<T>& field, Box2D domain, T value);

/// Initialize scalar-field with the same constant value on each cell.
template<typename T>
void maskedSetToConstant(MultiNTensorField2D<T>& field, MultiNTensorField2D<int>& mask, Box2D domain, T value);

/// Initialize tensor-field with the same constant tensor/vector on each cell.
template<typename T>
void setToConstant( MultiNTensorField2D<T>& field, Box2D domain, T* in_value, int size );

/// Initialize tensor-field with the same constant tensor/vector on each cell.
template<typename T>
void maskedSetToConstant( MultiNTensorField2D<T>& field, MultiNTensorField2D<int>& mask, Box2D domain, T* in_value, int size );

/// Assign the component "index" of its space coordinate to each cell.
template<typename T>
void setToCoordinate(MultiNTensorField2D<T>& field, Box2D domain, plint index);

/// Assign the component "index" of its space coordinate to each cell.
template<typename T>
void maskedSetToCoordinate(MultiNTensorField2D<T>& field, MultiNTensorField2D<int>& mask, Box2D domain, plint index);

/// Assign its space coordinate to each cell.
template<typename T>
void setToCoordinates(MultiNTensorField2D<T>& field,  Box2D domain);

/// Assign its space coordinate to each cell.
template<typename T>
void maskedSetToCoordinates(MultiNTensorField2D<T>& field, MultiNTensorField2D<int>& mask, Box2D domain);

/// Assign scalar-field to one component of a tensor-field.
template<typename T>
void assignComponent(MultiNTensorField2D<T>& tensorField, int whichComponent,
                     MultiNTensorField2D<T>& scalarField, Box2D domain);

/// Assign scalar-field to one component of a tensor-field.
template<typename T>
void maskedAssignComponent(MultiNTensorField2D<T>& tensorField, int whichComponent,
                           MultiNTensorField2D<T>& scalarField, MultiNTensorField2D<int>& mask, Box2D domain);

}  // namespace plb

#endif  // SWIG_DATA_INITIALIZER_WRAPPER_2D_H
