/*
Names: Brian Palomar, Nick Mederos, Vicente Valencia
Date: 5/14/22
Description: PokePanther - A pokemon game coded up through the use of inheritance, 
where the user/player is able to choose between three different pokemon, 
and is able to use attacks against the enemy pokemon.
*/
#include <iostream>
#include "attacks.hpp"
#include "pokemon.hpp"
#include "player.hpp"
#include "poke.hpp"
#include <string>
using namespace std;

int main() {
  
  startPoke myPokemon, enemyPokemon; // Pokemon
  pokeType myAttacks; // Attacks
  playerInfo ourPlayer, myPlayer("Name","Char"); // Player
  attackType att[2][2];
  string name, gender, eType, uType;
  int pickStarter = 0;
  int row, column, eStart;
  double eHealth = 50.0, uHealth = 50.0;

  // Asks the user for info
  myPlayer.intro();
  
  // Displays starters and sets starter
  myPokemon.display();
  cin >> pickStarter;
  myPokemon.setPoke(pickStarter); cout << endl;
  cout << "You chose " << myPokemon.getStarterName() << ", a " <<     
    myPokemon.getType() << " type! Magnificent choice!" << endl;
  uType = myPokemon.getType();
  cout << "Your " << myPokemon.getStarterName() << " has " 
    << myPokemon.getHealth() << " health.\n" << endl;

    // First Enemy
    cout << "\nLet's get right into it! \n";
    eStart = enemyPokemon.enemyPoke();
    enemyPokemon.setPoke(eStart);
    eType = enemyPokemon.getType();
    cout << "Your first competitor will be Utsab, he has a level "
      << enemyPokemon.getLevel() << " " 
      << enemyPokemon.getStarterName() << ". \nUtsab's "
      << enemyPokemon.getStarterName() << ", a " << enemyPokemon.getType()
      << " type has " << enemyPokemon.getHealth() << " health.\n" << endl;
  
    cout << "You get to attack first! " << endl;

  
  do{
    cout << "What's your next move? " << endl;
    myAttacks.displayAttacks();
    cout << "Attack Row: ";
    cin >> row;
    cout << "Attack Column: ";
    cin >> column;
  
    cout << endl;

    
    cout << myPokemon.getStarterName(); 
    eHealth = myAttacks.userAttack(row, 
    column, eHealth, eType, uType);     
    enemyPokemon.setHealth(eHealth);
    
    if(uHealth <= 0){
      cout << "Your " << myPokemon.getStarterName() << " fainted!\n";
      cout << "Thanks for playing!"  << endl;
      break;
    }
    else if(eHealth <= 0){
      cout << "Utsab's " << enemyPokemon.getStarterName() << " fainted!\n";
      cout << "Thanks for playing!"  << endl;
      break;
    }
  
    cout << "Utsab's " << enemyPokemon.getStarterName() << " has " 
      << enemyPokemon.getHealth() << " health.\n" << endl;
  
    cout << "Utsab's " << enemyPokemon.getStarterName();
    uHealth = myAttacks.enemyAttack(uHealth, eType, uType); 
    myPokemon.setHealth(uHealth);

    if(uHealth <= 0){
      cout << "Your " << myPokemon.getStarterName() << " fainted!\n";
      cout << "Thanks for playing!"  << endl;
      break;
    }
    else if(eHealth <= 0){
      cout << "Utsab's " << enemyPokemon.getStarterName() << " fainted!\n";
      cout << "Thanks for playing!"  << endl;
      break;
    }
  
    cout << "Your " << myPokemon.getStarterName() << " has " 
      << myPokemon.getHealth() << " health.\n" << endl;
    
  }while(uHealth > 0 || eHealth > 0);
  
  return 0;
}