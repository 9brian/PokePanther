#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include "attacks.hpp"
#include "poke.hpp"
using namespace std;

class pokeType
{
  public:
    pokeType();
    attackType getAttack(int row, int column);
    double userAttack(int row, int column, double enemyHealth, string enemyType, string userType);
    double enemyAttack(double userHealth, string enemyType, string userType);
    void displayAttacks();

  private:
    attackType attacks[2][2];

};

#endif