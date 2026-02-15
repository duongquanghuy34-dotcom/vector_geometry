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

    // Add two vectors
    VECTOR operator+(const VECTOR& b) const;

    // Subtract two vectors
    VECTOR operator-(const VECTOR& b) const;

    // Compute dot product
    double operator*(const VECTOR& b) const;

    // Multiply vector by a scalar
    VECTOR operator*(double b) const;
    
    //vector comparison
    bool operator==(const VECTOR& b) const;
    bool operator!=(const VECTOR& b) const;
    
    //vector addition assignment operator
    void operator+=(const VECTOR& b);
    
    //subtraction assignment operator
    void operator-=(const VECTOR& b);
    
    // Construct a vector from std::vector<double>
    explicit VECTOR(const std::vector<double>& v) : vector(v) {};
};
// Normalize vector
VECTOR VectorNormalize(const VECTOR& a);

// Compute cross product (3D only)
VECTOR VectorCross(const VECTOR& a, const VECTOR& b);

//angle between 2 vectors(radian)
double VectorAngle(const VECTOR& a, const VECTOR& b);
#endif
