#include <iostream>
#include <cmath>
#include <stdexcept>
#include "geomvector.hpp"
#include "geomvectorPriv.hpp"

// Return the dimension of the vector
size_t VECTOR::Size() const noexcept{
    return vector.size();
}

// Read the value at index i
double VECTOR::operator()(size_t i) const{
    if(i >= Size()){
        throw std::invalid_argument("Index out of range");
    }
    return vector[i];
}

// Modify the value at index i
void VECTOR::operator()(size_t i, double a){
    if(i >= Size()){
        throw std::invalid_argument("Index out of range");
    }
    vector[i] = a;
}

// Check if two vectors have the same dimension
bool geomVectorCheckSize(const VECTOR& a, const VECTOR& b){
    return a.Size() == b.Size();
}

// Check if a vector is the zero vector
bool geomVectorCheckZero(const VECTOR& a){
    for(size_t i = 0; i < a.Size(); i++){
        if(a(i) != 0){
            return false;   // If any component is non-zero
        }
    }
    return true;
}
// Add two vectors
VECTOR operator+(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    std::vector<double> d(a.Size(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.Size(); i++){
        c(i, a(i) + b(i));
    }

    return c;
}

// Subtract two vectors
VECTOR operator-(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    std::vector<double> d(a.Size(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.Size(); i++){
        c(i, a(i) - b(i));
    }

    return c;
}

// Compute dot product of two vectors
double operator*(const VECTOR& a, const VECTOR& b){
    if(!geomVectorCheckSize(a, b)){
        throw std::invalid_argument("Vectors must have the same dimension");
    }

    double c = 0;

    for(size_t i = 0; i < a.Size(); i++){
        c += a(i) * b(i);
    }

    return c;
}

// Multiply a vector by a scalar
VECTOR operator*(const VECTOR& a, double b){
    std::vector<double> d(a.Size(), 0);
    VECTOR c(d);

    for(size_t i = 0; i < a.Size(); i++){
        c(i, a(i) * b);
    }

    return c;
}

// Compute the length (magnitude) of the vector
double VECTOR::Length() const{
    double c = 0;

    for(size_t i = 0; i < Size(); i++){
        c += std::pow(this->operator()(i), 2);
    }

    return std::sqrt(c);
}

// Normalize a vector
VECTOR VectorNormalize(const VECTOR& a){
    if(geomVectorCheckZero(a)){
        throw std::invalid_argument("Cannot normalize the zero vector");
    }

    double length = a.Length();

    std::vector<double> d;
    for(size_t i = 0; i < a.Size(); i++){
        d.push_back(a(i));
    }

    VECTOR e(d);

    for(size_t i = 0; i < a.Size(); i++){
        e(i, a(i) / length);
    }

    return e;
}

// Compute cross product (only for 3D vectors)
VECTOR VectorCross(const VECTOR& a, const VECTOR& b){
    if(a.Size() != 3 || b.Size() != 3){
        throw std::invalid_argument("Cross product is defined only for 3D vectors");
    }
    std::vector<double> d(3, 0);
    VECTOR c(d);
    c(0,a(1) * b(2) -a(2) * b(1));
    c(1,a(2) * b(0) -a(0) * b(2));
    c(2,a(0) * b(1) -a(1) * b(0));
    return c;
}
//vector comaprison
bool operator==(const VECTOR& a, const VECTOR& b){
    size_t x=a.Size();
    size_t y=b.Size();
    if(x != y){
        throw std::invalid_argument("Vectors must have the same dimension");
    }
    else{
        for(size_t i=0;i<x;i++){
            if(a(i) != b(i)){
                return false;
            }
        }
        return true;
    }
}
