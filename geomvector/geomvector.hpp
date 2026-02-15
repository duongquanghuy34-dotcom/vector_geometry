#ifndef geomvector_
#define geomvector_
#include <vector>
#include <cstddef>

class VECTOR {
private:
    std::vector<double> vector;

public:
    // Disable default constructor (no empty vector allowed)
    VECTOR() = delete;
    
    // Return the dimension of the vector
    size_t Size() const noexcept;

    // Read the value at index i
    double operator()(size_t i) const;

    // Modify the value at index i
    void operator()(size_t i, double a);

    // Compute the magnitude (length) of the vector
    double Length() const;

    // Construct a vector from std::vector<double>
    explicit VECTOR(const std::vector<double>& v) : vector(v) {};
};
// Add two vectors
VECTOR operator+(const VECTOR& a, const VECTOR& b);

// Subtract two vectors
VECTOR operator-(const VECTOR& a, const VECTOR& b);

// Compute dot product
double operator*(const VECTOR& a, const VECTOR& b);

// Multiply vector by a scalar
VECTOR operator*(const VECTOR& a, double b);

// Normalize vector
VECTOR VectorNormalize(const VECTOR& a);

// Compute cross product (3D only)
VECTOR VectorCross(const VECTOR& a, const VECTOR& b);

//vector comparison
bool operator==(const VECTOR& a, const VECTOR& b);
#endif
