#include "pokemon.hpp"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

pokeType::pokeType()
{
  attacks[0][0] = attackType("Scratch", 15, 15, 10);
  attacks[0][1] = attackType("Tackle", 20, 20, 15);
  attacks[1][0] = attackType("Bite", 15, 15, 15);
  attacks[1][1] = attackType("Growl", 15, 15, 0);
}
attackType pokeType::getAttack(int row, int column){
  cout << row << " " << column << endl;
}
double pokeType::userAttack(int row, int column, double enemyHealth, string enemyType, string userType){
  assert(attacks[row][column].getQuantity() > 0);
  double attackAmp;
  // If user has type advantage
  if(userType == "Fire" && enemyType == "Grass")
  {
    attackAmp = attacks[row][column].getDamage() + (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      cout << enemyHealth << " " << attackAmp << endl;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
  else if(userType == "Grass" && enemyType == "Water")
  {
    attackAmp = attacks[row][column].getDamage() + (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
  else if(userType == "Water" && enemyType == "Fire")
  {
    attackAmp = attacks[row][column].getDamage() + (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }

  // If user has type disadvantage
  else if(enemyType == "Fire" && userType == "Grass")
  {
    attackAmp = attacks[row][column].getDamage() - (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
  else if(enemyType == "Grass" && userType == "Water")
  {
    attackAmp = attacks[row][column].getDamage() - (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
  else if(enemyType == "Water" && userType == "Fire")
  {
    attackAmp = attacks[row][column].getDamage() - (attacks[row][column].getDamage() * .10);
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
  
  // Does this account for If player poke is the same type as enemy poke?
  else 
  {
    attackAmp = attacks[row][column].getDamage();
    cout << " used " << attacks[row][column].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(enemyHealth > 0)
    {
      enemyHealth = enemyHealth - attackAmp;
      attacks[row][column].decreaseQty();
      return enemyHealth;
    }
  }
}
double pokeType::enemyAttack(double userHealth, string enemyType, string userType){
  // Randomizer for attacks
  int rowNum, colNum;
  double attackAmp;
  srand(time(0));
  
  rowNum = rand() % 2;
  colNum = rand() % 2;

  // If enemy has type advantage
  if(enemyType == "Fire" && userType == "Grass")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() + (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  else if(enemyType == "Grass" && userType == "Water")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() + (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  else if(enemyType == "Water" && userType == "Fire")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() + (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }

  // if enemy has type disadvantage
  else if(userType == "Fire" && enemyType == "Grass")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() - (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  else if(userType == "Grass" && enemyType == "Water")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() - (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  else if(userType == "Water" && enemyType == "Fire")
  {
    attackAmp = attacks[rowNum][colNum].getDamage() - (attacks[rowNum][colNum].getDamage() * .10);
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  // Accounts for if player poke is the same type as enemy poke?
  else 
  {
    attackAmp = attacks[rowNum][colNum].getDamage();
    cout << " used " << attacks[rowNum][colNum].getName() << endl;
  cout << "It did " << attackAmp << " damage!" << endl;
    
    if(userHealth > 0)
    {
      userHealth = userHealth - attackAmp;
      return userHealth;
    }
  }
  
}
void pokeType::displayAttacks(){
  cout << "[0][0] " << attacks[0][0].getName() << " [" <<  
    attacks[0][0].getDamage() << "] (" << 
    attacks[0][0].getQuantity() << "/" << 
    attacks[0][0].getMaxQuantity() << ")        ";

  cout << "[0][1] " << attacks[0][1].getName() << " [" <<  
    attacks[0][1].getDamage() << "] (" << 
    attacks[0][1].getQuantity() << "/" << 
    attacks[0][1].getMaxQuantity() << ")";
  
  cout << endl;

  cout << "[1][0] " << attacks[1][0].getName() << "    [" <<  
    attacks[1][0].getDamage() << "] (" << 
    attacks[1][0].getQuantity() << "/" << 
    attacks[1][0].getMaxQuantity() << ")        ";

  cout << "[1][1] " << attacks[1][1].getName() << "  [" <<  
    attacks[1][1].getDamage() << "]  (" << 
    attacks[1][1].getQuantity() << "/" << 
    attacks[1][1].getMaxQuantity() << ")" << endl;
}