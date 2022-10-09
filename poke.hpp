#ifndef POKE_H
#define POKE_H
#include <string>
using namespace std;

class startPoke
{
  public:
    startPoke();

    string getStarterName() const {return starterName;}
    string getType() const {return starterType;}
    double getHealth() const {return health;}
    int getLevel() const {return level;}

    void setStarterName(string starterName) {this->starterName = starterName;}
    void setType(string starterType) {this->starterType = starterType;}
    void setHealth(double health) {this->health = health;}
    void setLevel(int level) {this->level = level;}

    void setPoke(int starterNum);
    int enemyPoke();
    void display();

  private:  
    string starterName;
    string starterType;
    int starterNum;
    double health;
    int level;
    int randNum;

};

#endif