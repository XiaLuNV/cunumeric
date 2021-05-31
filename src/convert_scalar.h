/* Copyright 2021 NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __NUMPY_CONVERT_SCALAR_H__
#define __NUMPY_CONVERT_SCALAR_H__

#include "convert.h"  // for ConvertOperation
#include "scalar_unary_operation.h"

namespace legate {
namespace numpy {
template <typename To, typename From>
class ConvertScalarTask
  : public ScalarUnaryOperationTask<ConvertScalarTask<To, From>, ConvertOperation<To, From>> {
};
}  // namespace numpy
}  // namespace legate

#endif  // __NUMPY_CONVERT_SCALAR_H__