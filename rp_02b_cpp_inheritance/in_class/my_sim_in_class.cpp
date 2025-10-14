#include <iostream>

using namespace std;
using Scalar=float;

struct Vec2f {
    static constexpr int Dim=2; //I do so known at compile time 
    // constexpr= evalueated at compiled time: constant expression 
    // I will relaxed the dimension, i will just have to change that.

    Scalar values[Dim]; 
    inline Vec2f& operator+=(const Vec2f& src){
        for(int i=0; i<Dim; ++i)
         values[i]+=src.values[i];
        return *this;
    };
    inline Vec2f& operator-=(const Vec2f& src){
        for(int i=0; i<Dim; ++i)
         values[i]-=src.values[i];
        return *this;
    };
    inline void fill(const Scalar v=Scalar(0)){ //Scalar(0) is the default value!
        for(int i=0; i<Dim; ++i)
         values[i]=v;
        
    }
    inline Scalar dot(const Vec2f& src) const { //non change of this
        Scalar acc=Scalar(0); //prodotto scalare
        for(int i=0; i<Dim; ++i)
         acc+=values[i]*src.values[i];
        return acc;
    
    };
    // inline for compiler dont ha ve to call conventions, it is faster, compiler! just expand this part of code 
};

ostream& operator << (ostream& os, const Vec2f& src){
    os << "V2 ["<< &src << "] [ ";
    for(int i=0; i<Vec2f::Dim; ++i)
    {
      //scooping operator
      os <<src.values[i]<< " ";  
    }
    os << "]" << endl;
    return os;
    //redifine << operator. if called with a vec2f prints that
}
struct Rotation2f{

    static constexp int Dim=2;
    Scalar R[dim][dim];
    void setIdentity();

    Rotation2f inverse() const;
    Rotation2f operator*(const Rotation2f & other) const; //if I put & i can compose rotation
    Scalar toAngle() const;
    void setAngle(Scalar angle);
    Vec2f operator*(const Vec2f& src);

    void inverseInPlace();
};
struct Isometry2f {
    static constexp int Dim=2;
    Scalar t[Dim];
    Scalar R[Dim][Dim];

    void setIdentity()
    {  t=0 R=_Identity

    }
    Isometry2f inverse() const{
       return Rtranspose 
       return -Rr transposed t

    }
    Isometry2f operator *(const Isometry2f& src) //to compose isometries
    {

    }


    Vec2f operator *(const Vec2f& src)
    {

    }

};

int main(void){ 
 Vec2f v1;
 v1.fill();
 cout << v1;
 Vec2f v2=v1;
 cout << v2;
 v2.fill(0.1);
 cout << v2;
 cout << (v1-=v2);
}
