#include <iostream>
#include <cmath>
#include <stdexcept>
#include "geomvector.hpp"
#include "geomvectorPriv.hpp"

// Return the dimension of the vector
size_t VECTOR::geomVectorSize() const{
    return vector.size();
}

// Read the value at index i
double VECTOR::geomVectorRead(size_t i) const{
    if(i >= geomVectorSize()){
        throw std::invalid_argument("Index out of range");
    }
    return vector[i];
}

// Modify the value at index i
void VECTOR::geomVectorChange(size_t i, double a){
    if(i >= geomVectorSize()){
        throw std::invalid_argument("Index out of range");
    }
    vector[i] = a;
}

// Check if two vectors have the same dimension
bool geomVectorCheckSize(const VECTOR& a, const VECTOR& b){
    return a.geomVectorSize() == b.geomVectorSize();
}

// Check if a vector is the zero vector
bool geomVectorCheckZero(const VECTOR& a){
    for(size_t i = 0; i < a.geomVectorSize(); i++){
        if(a.geomVectorRead(i) != 0){
            return false;   // If any component is non-zero
        }
    }
    return true;
}

// Add two vectors
VECTOR geomVectorAdd(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    std::vector<double> d(a.geomVectorSize(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.geomVectorSize(); i++){
        c.geomVectorChange(i, a.geomVectorRead(i) + b.geomVectorRead(i));
    }

    return c;
}

// Subtract two vectors
VECTOR geomVectorSub(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    std::vector<double> d(a.geomVectorSize(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.geomVectorSize(); i++){
        c.geomVectorChange(i, a.geomVectorRead(i) - b.geomVectorRead(i));
    }

    return c;
}

// Compute dot product of two vectors
double geomVectorDot(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    double c = 0;

    for(size_t i = 0; i < a.geomVectorSize(); i++){
        c += a.geomVectorRead(i) * b.geomVectorRead(i);
    }

    return c;
}

// Multiply a vector by a scalar
VECTOR geomVectorMult(const VECTOR& a, double b){
    std::vector<double> d(a.geomVectorSize(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.geomVectorSize(); i++){
        c.geomVectorChange(i, a.geomVectorRead(i) * b);
    }

    return c;
}

// Compute the length (magnitude) of the vector
double VECTOR::geomVectorLength() const{
    double c = 0;

    for(size_t i = 0; i < geomVectorSize(); i++){
        c += std::pow(geomVectorRead(i), 2);
    }

    return std::sqrt(c);
}

// Normalize a vector
VECTOR geomVectorNlt(const VECTOR& a){
    if(geomVectorCheckZero(a)){
        throw std::invalid_argument("Cannot normalize the zero vector");
    }

    double length = a.geomVectorLength();

    std::vector<double> d;
    for(size_t i = 0; i < a.geomVectorSize(); i++){
        d.push_back(a.geomVectorRead(i));
    }

    VECTOR e(d);

    for(size_t i = 0; i < a.geomVectorSize(); i++){
        e.geomVectorChange(i, a.geomVectorRead(i) / length);
    }

    return e;
}

// Compute cross product (only for 3D vectors)
VECTOR geomVectorCross(const VECTOR& a, const VECTOR& b){
    if(a.geomVectorSize() != 3 || b.geomVectorSize() != 3){
        throw std::invalid_argument("Cross product is defined only for 3D vectors");
    }

    std::vector<double> d(3, 0);
    VECTOR c(d);

    c.geomVectorChange(0,
        a.geomVectorRead(1) * b.geomVectorRead(2) -
        a.geomVectorRead(2) * b.geomVectorRead(1));

    c.geomVectorChange(1,
        a.geomVectorRead(2) * b.geomVectorRead(0) -
        a.geomVectorRead(0) * b.geomVectorRead(2));

    c.geomVectorChange(2,
        a.geomVectorRead(0) * b.geomVectorRead(1) -
        a.geomVectorRead(1) * b.geomVectorRead(0));

    return c;
}

