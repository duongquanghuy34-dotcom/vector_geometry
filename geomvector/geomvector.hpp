#ifndef geomvector_
#define geomvector_
#include <vector>
#include <cstddef>
class VECTOR{
private:
    std::vector<double> vector;
public:
    VECTOR()=delete;                                    //không cho tạo vector rỗng
    size_t geomVectorSize() const;                              //kích thước vector
    double geomVectorRead(size_t i) const;                      //đọc thông tin vector
    void geomVectorChange(size_t i,double a);                   //sửa thông tin vector
    double geomVectorLength() const;                            //tính chiều dài vector
    explicit VECTOR(std::vector<double>& v): vector(v) {};
};
VECTOR geomVectorAdd(const VECTOR& a, const VECTOR& b);      //hàm cộng vector
VECTOR geomVectorSub(const VECTOR& a, const VECTOR& b);      //hàm trừ vector
double geomVectorDot(const VECTOR& a,const VECTOR& b);       //tích vô hướng vector
VECTOR geomVectorMult(const VECTOR& a, double b);            //nhân vector với 1 số
VECTOR geomVectorNlt(const VECTOR& a);                       //chuẩn hoá vector
VECTOR geomVectorCross(const VECTOR&a, const VECTOR& b);     //tích có hướng
#endif

