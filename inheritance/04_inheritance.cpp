#include <iostream> // we will discover this later
#ifndef  firstprint
#define  firstprint 1
#endif
using namespace std; // we will discover this later

// classes (and structs) can be extended
int i=0; 
struct A {
  int my_value; //this is an element of the struct, NOT the Member initializer list

  A(int v) //constructor
  { 
    i++;
    cerr << "Ho costruito A [" << this << "]" << " ctor" << ". Iterazione n" << i <<endl;
    my_value=v;
  }

  ~A(){

    cerr << "A [" << this << "]" << " dtor" << endl;
  }

  void print() {
    cerr << "A::print() [" << this << "]: my_value=" << my_value << endl;
  }
};


struct B: public A {
  int my_other_value;
  int stupid_value=1;
  // use the MEMBER_initializer_list between the parameter list and the {
  // it would not be possible to initialize
  // objects whose default ctor has been deleted
  B():      //this has no type since it is the constructor!

    A(0),  // base class initialization
    my_other_value(-100) //IT IS EQUAL TO: MY_OTHER_VALUE = -100 "DIRECT ASSIGN"
  {
    i++;
    cerr << "Ho costruito B [ " << this << "] ctor " << ". Iterazione n" << i <<endl;
  }

  ~B(){
    cerr << "B [" << this << "]" << " dtor" << endl;
  }
  
  void print() { 
    cerr << "\n !!this is a B printing!! \n";
    
    if (firstprint) //if do not use it it prints anyway the other value!
     A::print(); // call method of the base class using SCOPING!! <classname>::<method_or_variable>
    cerr << "B::print() [" << this << "]: my_other_value=" << my_other_value << endl;
    cerr << "NOW I change my_value, defined as attributes of A in = old % 7 + 13\n";
    my_value= my_value % 7 +13;
    if (firstprint) 
     A::print();

  }

};

int main(int argc, char** argv) {
  for (int i=0; i<argc; ++i) {
    cerr << i << ":" << argv[i] << endl;
  }
  
  cerr << endl;
  cerr << "create A " << endl;
  A a(3);
  a.print();
  
  cerr << "\ncreate B " << endl;
  B b;
  b.print();

  // legal assignment a is base class of b, only common member vars are copied
  A a1=b; 
  cerr << "\nI would like that it prints B instead it prints as A\n";
  a1.print();
  cerr << "Now distruct everything IN THE REVERSE ORDER";
}

