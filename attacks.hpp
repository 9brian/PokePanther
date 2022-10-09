#ifndef ATTACKS_H
#define ATTACKS_H
#include <string>
using namespace std;

// Done
class attackType
{
  public:
    attackType();
    attackType(string name, int quantity, int maxQuantity, int damage);

    string getName() const{return name;}
    int getQuantity() const{return quantity;}
    int getMaxQuantity() const{return maxQuantity;}
    int getDamage() const{return damage;}
    
    void setName(string name) {this->name = name;}
    void setQuantity(int quantity);
    void setMaxQuantity(int quantity);
    void setDamage(int damage);
    

    void display();
    void decreaseQty();
    bool isEmpty();

  private:
    string name;
    int quantity;
    int maxQuantity;
    int damage;
};

#endif