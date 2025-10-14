#include <iostream> // we will discover this later
#include <cassert>  // assert.h
#include <string>   // string from stl
using namespace std; // we will discover this later


// in c++ late binding applies only to the methods that are declared
// virtual!
// late binding might be expensive, so c++ restricts late binding
// only to those methods that really need it

// simple (non late binding example)
class A {
public:
  A(int value_): 
    _value(value_)  //in this case I am doing member_initializer_list because I am defining with :
    {
  }
  void print() 
  {
    cerr << "THIS IS A PRINTING: [" << this << "], value: " << _value << endl;
  }
protected:
  int _value;
};

class B: 
 public A //indica che tipo di ereditarietà di A voglio: in questo caso pubblica
 //es se protected: i membri public di A diventano protected in B, allora da fuori non potresti più usare i metodi pubblici di A tramite un oggetto di tipo B.
  {
   public: //di default sarebbero private, è la visbilità di B!
   B(int value_):
    A(value_) {}
   void print()
   {
    cerr << "THIS IS B PRINTING: [" << this << "], value: " << _value << endl;
    //cerr<< "I AM NOT USING A.PRINT() METHODS, through A::PRINT(); BUT I REDEFINE EXNOVO\n";
   }
  };



// simple (late binding example)
class A_lb {
public:
  A_lb(int value_):
    _value(value_) //member_initializer list
    { 
  }
  virtual void print() { //i USE VIRTUALE
    cerr << "nTHIS IS A PRINTING: I have used virtual here" <<endl;
    cerr << "A_lb: [" << this << "], value: " << _value << endl;
  }
protected:
  int _value;  //non posso accedere da fuori cioè: int main() { A a(10); cerr << a._value << endl;  // ❌ Errore! _value è protected}

};

class B_lb: 
 public A_lb { //qua potrei modificare _value perché è ereditata, prviamo:
 public:
  B_lb(int value_):
    A_lb(value_) //nella member initialaizer list I use il ctor di A 
     {_value *= 2;} //ctor di B
  void print() override
     {

       cerr << "THIS IS B PRINTING override:\nB_lb: [" << this << "], value: " << _value << endl;
     }
};

class C_lb:
 public B_lb
 {
  public: //here we want : 
  // { NON CI VANNO
  C_lb(int val): B_lb(val) //member init list
   {}

 


  // } NON CI VANNO


 };
  
int main(int argc, char ** argv) {
  // cerr <<  "no late binding" << endl;
  // {
  //   B b(10);
  //   A a(200);
  //   A& a_ref=b;
  //   A a_copied=b;
  //   cerr << "b object:\n";
  //   b.print();
  //   cerr << "\n NOTHING BELOW PRINTS AS B OBJECT\n";
  //   cerr << "a_ref object: reference of B of type a\n";
  //   a_ref.print();
  //   cerr << "a object:\n";
  //   a.print();
  //   cerr << "a_copied object: A copy of B\n";
  //   a_copied.print();
    
  // }

  cerr <<  "late binding" << endl;
    {
    B_lb b(10);
    A_lb a(200);
    A_lb& a_ref=b;
    A_lb a_copied(b); // DIRECT ASSIGN
    C_lb c(135);
    B_lb b_copied(c);
    B_lb& b_ref=c;
    cerr << "b object:\n";
    b.print();
    cerr << "\nBELOW PRINTS AS B OBJECT??\n";
    cerr << "1) a_ref object: reference of B of type a FINALLY PRINTS AS B"<< endl;
    a_ref.print();
    cerr << "2) a object: PRINT AS A"<< endl;
    a.print();
    cerr << "3) a_copied object: A copy of: B PRINT AS A"<< endl;
    a_copied.print();
    cerr << "4) c object: HOW DOES IT PRINT?: PRINT AS B"<< endl;
    c.print();
    cerr << "5) b_ref object: HOW DOES IT PRINT?: PRINT AS B"<< endl;
    b_ref.print();    
    cerr << "6) b_copied: HOW DOES IT PRINT?: PRINT AS B"  << endl;
    b_copied.print();    
    
  }


  
}
