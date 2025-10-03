#include "btree.h"


TreeNodeInt::TreeNodeInt(int value_,
                         TreeNodeInt* left_, //I DEFAULT VALUES SONO DICHIARATI NELL'HEADER
                         TreeNodeInt* right_):
  value(value_),// THIS IS MEMBER_INITIALIZER_LIST
  left(left_),
  right(right_){}

TreeNodeInt::~TreeNodeInt(){
  if (left)
    delete left;
  if (right)
    delete right;
}

TreeNodeInt* TreeNodeInt::find(int value_) { //return 0 se non ci sta, sennò returna il valore se lo trova
  if (value==value_)
    return this; //returna un puntatore infatti
  if (value_<value) {
    if (!left) //solo se left è 0
     return 0;
    return left->find(value_); 
    //accede alla funzione, al metodo find del nodo puntata dal puntatore left, che returnerà un puntatore
   
    // TODO: fill here
    // if there is a left child, continue the search in the left, otherwise return null
  }
  if (value_>value) {
    // if there is a right child, continue the search in the right, otherwise return null
    if (! right)
      return 0;
    return right->find(value_);
  }
  return 0;
}
  
bool TreeNodeInt::add(int value_) {
  if (value==value_)
    return false;
  if (value_<value) {
    if (! left) {
      left=new TreeNodeInt(value_); //alloca nuova memoria
      return true;
    }
    return left->add(value_); //sennò accede a quello dopo tramite il metodo add di left node
  }
  if (value_>value) {
    if (! right) {
      right=new TreeNodeInt(value_); //alloca nuova memoria
      return true;
    }
    return right->add(value_);
  }
  return false;
}

std::ostream& operator <<(std::ostream& os, const TreeNodeInt& node) {
  if (node.left)
    os << *(node.left);
  os << node.value << " ";
  if (node.right)
    os << *(node.right);
  return os;
}
