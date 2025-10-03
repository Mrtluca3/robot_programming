#include <iostream>
#include "btree.h"

using namespace std;

int main() {
  TreeNodeInt* n=new TreeNodeInt();
  // n->add(10);
  // n->add(1);
  // n->add(2);
  // n->add(4);
  // n->add(3);
  // n->add(4);
  for (int i=1, j=1; i<100; i++)
    {
      j=(int)((225*j+i) % 100);
      (*n).add(j);
    }
  cerr << "ok here" << endl;
  cout << "PRINT CONTENT OF *N= NODE " << *n << endl;

  cerr << "address of obj 4: " << n->find(4) << endl;
}
