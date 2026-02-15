# Vector Geometry Library (C++)

A lightweight C++ vector algebra library implementing dynamic-dimension vectors 
with operator overloading, validation, and common geometric operations.

---

## 🚀 Features

### 📐 Basic Vector Operations
- Vector addition (`operator+`)
- Vector subtraction (`operator-`)
- Addition assignment (`operator+=`)
- Subtraction assignment (`operator-=`)
- Dot product (`operator*`)
- Scalar multiplication (`vector * scalar`)
- Cross product (3D only)

### 📏 Geometry Functions
- Length (magnitude)
- Normalize
- Angle between two vectors (radians)

### 🔎 Utility
- Dimension checking
- Zero vector checking
- Element access via `operator()`
- Vector comparison (`==`, `!=`)
- Exception handling for invalid operations

---

## 📦 Project Structure
vector_geometry/
│
├── geomvector/
│ ├── geomvector.hpp
│ ├── geomvectorPriv.hpp
│ └── geomvector.cpp
│
└── geomvector.xcodeproj

---

## 🧠 Example Usage
```cpp
#include "geomvector.hpp"

int main() {
    VECTOR a({1, 2, 3});
    VECTOR b({4, 5, 6});

    VECTOR c = a + b;           // addition
    VECTOR d = a - b;           // subtraction
    double dot = a * b;         // dot product
    VECTOR cross = VectorCross(a, b);  // cross product
    double angle = VectorAngle(a, b);  // angle (radians)

    return 0;
}
⚠️ Error Handling
-The library throws std::invalid_argument when:
+ Vector dimensions do not match
+ Index is out of range
+ Trying to normalize the zero vector
+ Cross product is used on non-3D vectors

📐 Mathematical Definitions
Length:
|v| = sqrt(v₁² + v₂² + ... + vₙ²)

Dot product:
a · b = Σ (aᵢ bᵢ)

Angle between vectors:
θ = arccos( (a · b) / (|a||b|) )
🛠 Build
Using g++:g++ geomvector.cpp -std=c++17
