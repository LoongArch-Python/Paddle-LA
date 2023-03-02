// Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#if defined(PADDLE_WITH_CUDA) || defined(PADDLE_WITH_HIP)
#include "paddle/phi/core/cuda_stream.h"
#else
namespace phi {
class CUDAStream {};
}  // namespace phi
#endif

namespace py = pybind11;

namespace paddle {
namespace platform {
#if defined(PADDLE_WITH_CUDA) || defined(PADDLE_WITH_HIP)
phi::CUDAStream* get_current_stream(int device_id = -1);
phi::CUDAStream* set_current_stream(phi::CUDAStream* stream);
#endif
}  // namespace platform
namespace pybind {

void BindCudaStream(py::module* m);

}  // namespace pybind
}  // namespace paddle
