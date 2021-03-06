/*
 * Copyright 2013 Cepheid
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
*/
#include "Vector3.hpp"

namespace io {
  Vector3 Vector3::operator*(const Matrix& matrix) const {
    float x = getX();
    float y = getY();
    float z = getZ();
    float w = 1.0f;

    float outX = (x * matrix.get(0, 0)) +
                 (y * matrix.get(0, 1)) +
                 (z * matrix.get(0, 2)) +
                 (w * matrix.get(0, 3));

    float outY = (x * matrix.get(1, 0)) +
                 (y * matrix.get(1, 1)) +
                 (z * matrix.get(1, 2)) +
                 (w * matrix.get(1, 3));

    float outZ = (x * matrix.get(2, 0)) +
                 (y * matrix.get(2, 1)) +
                 (z * matrix.get(2, 2)) +
                 (w * matrix.get(2, 3));

    return Vector3(outX, outY, outZ);
  }
}
