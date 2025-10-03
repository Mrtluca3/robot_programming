#include <iostream>
#include "mat_f.h"
using namespace std;

int main() {
  VecF v1(3); //usiamo vec qua perché importato dentro mat_f.h
  v1.at(0)=1;
  v1.at(1)=2;
  v1.at(2)=3;
  cout << v1 << endl;

  MatF m(3,3);
  m.fill(0.);
  cout << m;
  MatF mdumb(m);
  mdumb.fill(5.);
  cout << mdumb;
  MatF m2(3,3);
  m2.fill(0);
  m2.at(0,0)=1;
  m2.at(1,1)=2;
  m2.at(2,2)=3;

  cout << m2 << endl;
  cout << m + m2 << endl;
  MatF m3=m + m2;
  cout << "m3: " << m3 << endl;

  cout << "es 1: "<<m + m2 << endl;
  cout  <<  "es 2: "<<m3-m2 << endl;
  cout  <<  "es 3: "<<m * v1 << endl;
  cout  <<  "es 4: OSSERVA CHE SONO TUTTI CON STESSO INDIRIZZO PERCHE CANCELLATO E SOVRASCRITTO"<< endl <<m3 * v1 << endl;

  MatF m4(3,4);
  cerr << "m4 " << m4.dimension << endl;
  m4.fill(1);
  cout << m4 << endl;
  cout << m3*m4<< endl;
  cout << (m3*m4).transpose() << endl;

  MatF m5(3,4);
  m5.randFill();
  cout << m5 << endl;
  
  cout << m5*m5.transpose() << endl;

  m.randFill();
  cout << m << endl;

  cout << m-m5*m5.transpose() << endl;
  cout << "DONE" << endl;
}
