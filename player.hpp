#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class playerInfo
{
  public:
    playerInfo();
    playerInfo(string firstName, string starter);
  
    string getFirstName() const {return firstName;}
    string getStarter() const {return starter;}
  
    void setFirstName(string firstName) {this->firstName =     
    firstName;}
    void setStarter(string starter) {this->starter = starter;}

    void intro();
    void display();

  private:
    string firstName;
    double time; 
    int level;
    string starter;
  
};

#endif