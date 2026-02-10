#include <iostream>
#include <cmath>
#include <stdexcept>
#include "geomvector.hpp"
#include "geomvectorPriv.hpp"
//constructor của class vector
//tính toán số chiều của vector
size_t VECTOR::geomVectorSize() const{
    return vector.size();
}
//đọc thông tin vector
double VECTOR::geomVectorRead(size_t i) const{
    if(i>=geomVectorSize()){
        throw std::invalid_argument("truy cập sai");
    }
    else{
        return vector[i];
    }
}
//sửa thông tin vector
void VECTOR::geomVectorChange(size_t i,double a){
    if(i>=geomVectorSize()){
        throw std::invalid_argument("truy cập sai");
    }
    else{
        vector[i]=a;
    }
}
//hàm kiểm tra số chiều của 2 vector
bool geomVectorCheckSize(const VECTOR& a,const VECTOR& b){
    if(a.geomVectorSize() != b.geomVectorSize()){
        return false;
    }
    else{
        return true;
    }
}
//hàm kiểm tra vector 0
bool geomVectorCheckZero(const VECTOR& a){
    for(size_t i=0;i<a.geomVectorSize();i++){    //kiểm tra từng phần tử của vector
        double c=a.geomVectorRead(i);
        if(c!=0){                               //chỉ cần 1 thành phần vector khác 0 là vector khác 0
            return false;
        }
    }
    return true;
}
//hàm cộng 2 vector
VECTOR geomVectorAdd (const VECTOR& a,const VECTOR& b){
    if(geomVectorCheckSize(a,b)){
        std::vector<double> d(a.geomVectorSize(),0);
        VECTOR c(d);
        for(size_t i=0; i<a.geomVectorSize();i++){                              //vòng lặp cộng vector
            c.geomVectorChange(i,a.geomVectorRead(i)+b.geomVectorRead(i));        //a(a1,a2,a3,...)+b(b1,b2,b3,...)
            }                                                                  //=c(a1+b1,a2+b2,a3+b3,...)
            return c;
        }
    else{
        throw std::invalid_argument("lỗi,2 vector không cùng kích thước");
    }
}
//hàm trừ 2 vector
VECTOR geomVectorSub(const VECTOR& a,const VECTOR& b){
    if(geomVectorCheckSize(a,b)){
        std::vector<double> d(a.geomVectorSize(),0);
        VECTOR c(d);
        for(size_t i=0; i<a.geomVectorSize();i++){                           //vòng lặp trừ vector
            c.geomVectorChange(i,a.geomVectorRead(i)-b.geomVectorRead(i));     //a(a1,a2,a3,...)-b(b1,b2,b3,...)
            }                                                               //=c(a1-b1,a2-b2,a3-b3,...)
            return c;
        }
    else{
        throw std::invalid_argument("lỗi,2 vector không cùng kích thước");
    }
}
//hàm tích vô hướng 2 vector
double geomVectorDot(const VECTOR& a,const VECTOR& b){
    if(geomVectorCheckSize(a,b)){
        double c=0;                                                     //tạo biến TẠM chứa giá trị của tích vô hướng
        for(size_t i=0;i<a.geomVectorSize();i++){                        //a(a1,a2,a3,...).b(b1,b2,b3,...)
            c+=a.geomVectorRead(i)*b.geomVectorRead(i);                   //=a1*b1+a2*b2+a3*b3+...
        }
        return c;
        }
    else{
        throw std::invalid_argument("lỗi,2 vector không cùng kích thước");
    }
}
//hàm nhân vector và số
VECTOR geomVectorMult(const VECTOR& a, double b){
    std::vector<double> d(a.geomVectorSize(),0);
    VECTOR c(d);
    for(size_t i=0;i<a.geomVectorSize();i++){
        c.geomVectorChange(i,a.geomVectorRead(i)*b);        //v(a,b,c,...)*d=e(a*d,b*d,c*d,...)
    }
    return c;
}
//hàm tính chiều dài vector
double VECTOR::geomVectorLength() const{
    double c=0;
    for(size_t i=0;i<geomVectorSize();i++){
        c+=std::pow(geomVectorRead(i),2);                   //chiều dài^2=tổng bình phương các kích thước
    }
    return sqrt(c);
}
//hàm chuẩn hoá vector
VECTOR geomVectorNlt(const VECTOR& a){
    if(geomVectorCheckZero(a)){
        throw std::invalid_argument("lỗi,vector đang là vector 0");
    }
    else{
        double c=a.geomVectorLength();                       //chiều dài của a
        std::vector <double> d;                              //tạo 1 mảng vector giống mảng của a
        for(size_t i=0;i<a.geomVectorSize();i++){
            d.push_back(a.geomVectorRead(i));
        }
        VECTOR e(d);
        for(size_t i=0;i<a.geomVectorSize();i++){
            double f=a.geomVectorRead(i)/c;                  //vector chuẩn hoá bằng vector gốc/chiều dài vector
            e.geomVectorChange(i,f);
        }
        return e;
    }
}
//tính tích có hướng
VECTOR geomVectorCross(const VECTOR&a, const VECTOR& b){
    if(a.geomVectorSize()!=3 || b.geomVectorSize()!=3){
        throw std::invalid_argument("tích có hướng chỉ áp dụng cho vector 3D");
    }
    else{
        std::vector<double> d(3,0);
        VECTOR c(d);
        c.geomVectorChange(0,a.geomVectorRead(1)*b.geomVectorRead(2)-a.geomVectorRead(2)*b.geomVectorRead(1));
        c.geomVectorChange(1,a.geomVectorRead(2)*b.geomVectorRead(0)-a.geomVectorRead(0)*b.geomVectorRead(2));
        c.geomVectorChange(2,a.geomVectorRead(0)*b.geomVectorRead(1)-a.geomVectorRead(1)*b.geomVectorRead(0));
        return c;
    }
}

