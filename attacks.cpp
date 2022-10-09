#include "attacks.hpp"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Done
attackType::attackType(){
  name = "yes";
  damage = 50;
  quantity = 10;
}
attackType::attackType(string name, int quantity, int maxQuantity, int damage){
  setName(name);
  setDamage(damage);
  setQuantity(quantity);
  setMaxQuantity(maxQuantity);
}
void attackType::setQuantity(int quantity){
  assert(quantity > 0);
  this->quantity = quantity;
}
void attackType::setDamage(int damage){
  assert(damage >= 0);
  this->damage = damage;
}
void attackType::setMaxQuantity(int maxQuantity){
  assert(maxQuantity > 0);
  this->maxQuantity = quantity;
}
void attackType::display(){
  cout << name; 
  cout << " [" << damage << "] ";
  cout << "(" << quantity << "/" << maxQuantity << ")" << endl;
}
void attackType::decreaseQty(){
  assert(quantity > 0);
  if(quantity > 0)
  {
    quantity = quantity - 1;
  }
}
bool attackType::isEmpty(){  
  assert(quantity >= 0);
  if(quantity == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}