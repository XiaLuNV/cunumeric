/* Copyright 2022 NVIDIA Corporation
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

#pragma once

#include "cunumeric/scan/scan_local_util.h"
#include "cunumeric/cunumeric_task.h"

namespace cunumeric {

struct ScanLocalArgs {
  legate::Store out;
  legate::Store in;
  legate::Store sum_vals;
  ScanCode op_code;
  bool nan_to_identity;
};

class ScanLocalTask : public CuNumericTask<ScanLocalTask> {
 public:
  static const int TASK_ID = CUNUMERIC_SCAN_LOCAL;

 public:
  static void cpu_variant(legate::TaskContext context);
#if LegateDefined(LEGATE_USE_OPENMP)
  static void omp_variant(legate::TaskContext context);
#endif
#if LegateDefined(LEGATE_USE_CUDA)
  static void gpu_variant(legate::TaskContext context);
#endif
};

}  // namespace cunumeric
