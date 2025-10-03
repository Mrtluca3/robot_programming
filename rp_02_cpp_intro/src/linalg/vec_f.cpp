#include "vec_f.h"

#include <iostream>
#include <assert.h> 


using namespace std;

// read/write access to element at pos
float& VecF::at(int pos){
  return v[pos];
}
  // cosi returna una reference e non una copia!


// read access to element at pos
// const after () means that the method does not modify the invoking object
// dipende se crei la struct con const
const float& VecF::at(int pos) const {
  return v[pos];
}


// default ctor: return un tipo VecF
VecF::VecF():
  dim(0), //si chiama MEMBER INITIALIZER LIST, utile con const
  v(nullptr) {
}  //POTEVO FARE: VecF::VecF():{dim=0; v=nullptr;}

// ctor with dim
VecF::VecF(int dim_):
  dim(dim_),
  v(nullptr){
  if (dim) //cioè se !=0
    v=new float [dim]; //usa la heap! 
}

// copy ctor
VecF::VecF(const VecF& other):
 VecF(other.dim) //MIList con dimensioni di other
{
  for (int i=0; i<dim; ++i)
    v[i]=other.v[i];
}

// dtor destructor
VecF::~VecF() {
  if(dim)
    delete [] v; 
}

// op =, deep copy
VecF& VecF::operator =(const VecF& other) {
  if(dim!=other.dim) {
    delete [] v;
    v=0;
    dim=other.dim;
    if (! dim) //se other.dim==0
      return *this;
    v=new float[dim]; //senno prosegue e fa un nuovo vettore
  }
  for (int i=0; i<dim; ++i)
    v[i]=other.v[i];
  return *this;
}

// returns the sum this + other
VecF VecF::operator +(const VecF& other) const {
  assert(other.dim==dim && "dim mismatch");
   //stampa le due condizioni (false and true=false ora) se le dimensioni non combaciano 
  VecF dareturnare(*this); //use copyconstructor
  for (int i=0; i<dim; ++i)
    dareturnare.v[i]+=other.v[i];
  return dareturnare;
}

VecF VecF::operator -(const VecF& other) const {
  assert(other.dim==dim && "dim mismatch");
  VecF returned(*this);
  // TODO: fillme
  for (int i =0; i<dim; i++)
   returned.v[i]-=other.v[i];
  return returned;
}


// returns this*f
VecF VecF::operator *(float f) const {
  VecF pippo(*this);
   // TODO: fillme
  // no assert needed here!!
  for(int i=0; i<pippo.dim; i++)
   pippo.v[i]*=f;
  
  return pippo;
}


// returns the dot product (vecs should have the same size);
float VecF::operator *(const VecF& other) const {
  float acc=0.f;
  // TODO: fillme
  assert(dim==other.dim && "Not allowed: must have the same dimensions");
  for(int i=0; i<dim; i++)
   acc+=v[i]*other.v[i];
  
  return acc;
}

ostream& operator <<(ostream& os, const VecF& v) {
  os << "{ ptr: " << &v << " dim:" << v.dim << " vals: [ "; //v non è un puntatore ma una reference quindi stampa l'indirizzo se fai &v
  for (int i=0; i<v.dim; ++i)
    os << v.at(i) <<  " ";
  os << "] }";
  return os;
}
