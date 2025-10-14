#include <iostream>
#include <math.h>
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
    } //non serve se è definito e dichiarato insieme;
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
    static constexpr int Dim=2;
    Scalar R[Dim][Dim];
    Rotation2f(){};
    Rotation2f(Scalar angle){
        this->setAngle(angle);
    };


    void setIdentity()
    {
       for(int i=0; i<Dim; ++i){
        for(int j=0; j<Dim; ++j){
         if (i==j) R[i][j]=1;
         else R[i][j]=0;
       }
       }

    };
    bool check_orthogonality() const{
        Scalar prod=0;
        for (int i=0; i<Dim; ++i)
        {
            for(int j=i+1; j<Dim; ++j) //columns
             {
                for(int k=0; k<Dim; ++k) //lines
                  {prod+= R[k][i]*R[k][j];}
             }
        }
        return (prod==0);
    }


    Rotation2f inverse() const{
        Rotation2f other= *this;
        for(int i=0; i<Dim; ++i){
         for(int j=0; j<Dim; ++j){
          other.R[j][i]=R[i][j];
       }
       }
       return other;
    }
    Rotation2f operator*(const Rotation2f & other) const
    {
      Rotation2f res(*this);
      for(int k=0; k<Dim; ++k){  
       for(int i=0; i<Dim; ++i){
         res.R[k][i]=0;
         for(int j=0; j<Dim; ++j){
            res.R[k][i]+=R[k][j]*other.R[j][i];
         }
       }
      } 
       return res;
    } //if I put & i can compose rotation
    
    Rotation2f operator=(const Scalar& f)
    {
        this->setAngle(f);
        return *this;
    }   

    Scalar angle() const{
      if (! this->check_orthogonality()) 
        {
            cerr << "This is not a rotational matrix";
            return 0;
        }
      if (R[0][0]==0)
      {
        if (R[1][0]==1)
         return M_PI;
        else if (R[1][0]==-1)
         return -M_PI;
      }
      if (R[0][0]>0)
        return atan(R[1][0]/R[0][0]);
      else if (R[0][0]<0)
        {
            if (R[1][0]>=0)
             return atan(R[1][0]/R[0][0])+M_PI;
            if (R[1][0]<0)
             return atan(R[1][0]/R[0][0])-M_PI; 
        }
      return 0;
    } //or toAngle??
    
    void setAngle(Scalar angle)
    {
        R[0][0]=cos(angle);
        R[1][1]=cos(angle);
        R[1][0]=sin(angle);
        R[0][1]=(-sin(angle));
    }
 
    Vec2f operator*(const Vec2f& src){
      Vec2f vet;
      vet.fill();
      for(int i=0; i<Dim; ++i){
         for(int j=0; j<Dim; ++j){
          vet.values[i]+=R[i][j]* src.values[j];
       }
    }
      return vet; 
    }

    // void inverseInPlace();
};

ostream& operator <<(ostream& os, const Rotation2f& src){
    os << "["<< &src<<"]"<< endl;
    os << "[";
    for(int i=0; i<src.Dim; ++i){
     os << "["; //non si fa scooping su src::Dim, but su Rotation2f::Dim
     for(int j=0; j<src.Dim; ++j){
        os << src.R[i][j];
        if (j !=src.Dim-1) os << " ";
     }
     os << "]";
     if (i !=src.Dim-1) os << endl;
    }
    os << "]"<<endl;
    return os;
}

// struct Isometry2f {
//     static constexp int Dim=2;
//     Scalar t[Dim];
//     Scalar R[Dim][Dim];

//     void setIdentity()
//     {  t=0 R=_Identity

//     }
//     Isometry2f inverse() const{
//        return Rtranspose 
//        return -Rr transposed t

//     }
//     Isometry2f operator *(const Isometry2f& src) //to compose isometries
//     {

//     }


//     Vec2f operator *(const Vec2f& src)
//     {

//     }

// };

int main(void){ 
//  Vec2f v1;
//  v1.fill();
//  cout << v1;
//  Vec2f v2=v1;
//  cout << v2;
//  v2.fill(0.1);
//  cout << v2;
//  cout << (v1-=v2);




  Rotation2f rot1;
  //done
//   cout << "created" << endl;
//   cout << rot1;
  rot1.setIdentity();
//   rot1.R[1][1]=2;
//   Rotation2f rotinv(rot1.inverse());
//   cout << rotinv*rot1;
//   cout << rot1*rotinv;
//   cout << rotinv;
//   cout << rot1*rot1*rot1;

//  



//   cout << "setAngle" << endl;
//   rot1.setAngle(M_PI/2);

//   cout << rot1.angle() << endl << rot1;
//   rotinv=rot1.inverse();
//   cout << rotinv.angle() << endl << rotinv;
//   cout << "Moltiplication" << endl;
//   cout << rotinv*rot1;
//   cout << rot1*rotinv;



//   Rotation2f rot_acc;
//   rot_acc.setIdentity();
//   Rotation2f rot_inc;
//   rot_inc.setAngle(M_PI/180.f);


//   for (int i=0; i<360; ++i) {
//     rot_acc=rot_acc*rot_inc; // group structure check strarts from pi/180 *pi/180 = 2 pi /180
//     float angle_in_radians=rot_acc.angle();
//     cout << "i: " << i << " alpha in °: " << angle_in_radians*180.f/M_PI << endl;
//   }





  Rotation2f r_boh(0.5);
  cout << r_boh << endl << r_boh*r_boh.inverse() << endl;


  cout << "*************************" <<endl;
  Vec2f v_mult;
  v_mult.values[0]=20;
  v_mult.values[1]=5;

  cout << v_mult;
  
  v_mult = r_boh*v_mult;
  cout << v_mult;

  cout << r_boh.inverse()*v_mult;
  



}
