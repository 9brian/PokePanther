#include "poke.hpp"
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iomanip>
using namespace std;

startPoke::startPoke()
{
  starterName = "Pokemom";
  starterType = "All";
  level = 1;
  health = 100.0;
}
void startPoke::setPoke(int starterNum)
{
  assert (starterNum >= 1 && starterNum <= 3);
  if (starterNum == 1){
    setStarterName("Bulbasaur");
    setType("Grass");
    setHealth(50);
  }
  else if(starterNum == 2)
  {
    setStarterName("Charmander");
    setType("Fire");
    setHealth(50);
  }
  else if(starterNum == 3)
  {
    setStarterName("Squirtle");
    setType("Water");
    setHealth(50);
  }
}
int startPoke::enemyPoke(){
  srand(time(0));
  randNum = rand() % 3 + 1;
  return randNum;
}
void startPoke::display()
{
  cout << "Which starter would you like? " << endl;
  cout << "1 - Bulbasaur" << endl;
  cout << "2 - Charmander" << endl;
  cout << "3 - Squirtle" << endl;
  cout << " " << endl;
  cout << "Enter Pokemon Number: ";
}