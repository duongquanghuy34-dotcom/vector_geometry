#ifndef geomvector_
#define geomvector_
#include <vector>
#include <cstddef>

class VECTOR {
private:
    std::vector<double> vector;

public:
    VECTOR() = delete;
    // Disable default constructor (no empty vector allowed)

    // Return the dimension of the vector
    size_t geomVectorSize() const;

    // Read the value at index i
    double geomVectorRead(size_t i) const;

    // Modify the value at index i
    void geomVectorChange(size_t i, double a);

    // Compute the magnitude (length) of the vector
    double geomVectorLength() const;

    // Construct a vector from std::vector<double>
    explicit VECTOR(const std::vector<double>& v) : vector(v) {};
};

// Add two vectors
VECTOR geomVectorAdd(const VECTOR& a, const VECTOR& b);

// Subtract two vectors
VECTOR geomVectorSub(const VECTOR& a, const VECTOR& b);

// Compute dot product
double geomVectorDot(const VECTOR& a, const VECTOR& b);

// Multiply vector by a scalar
VECTOR geomVectorMult(const VECTOR& a, double b);

// Normalize vector
VECTOR geomVectorNlt(const VECTOR& a);

// Compute cross product (3D only)
VECTOR geomVectorCross(const VECTOR& a, const VECTOR& b);

#endif
