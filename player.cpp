#include "player.hpp"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

playerInfo::playerInfo()
{
  firstName = "Joe";
  starter = "Char";
}
playerInfo::playerInfo(string firstName, string starter)
{
  setFirstName(firstName);
  setStarter(starter);
}
void playerInfo::intro()
{
  cout << "======Welcome to the CSS 2022 world of Pokemon!====== " << endl;
  cout << endl;
  cout << "First things first, What's your name?: ";
  cin >> firstName; cout << endl;
  setFirstName(firstName);

  cout << "Hi, " << getFirstName() << "! " << endl;
  cout << "We have provided the first generation starters to start your journey! \n" << endl;
}
void playerInfo::display(){
  cout << "First name: " << firstName << endl;
  cout << "Starter: " << starter << endl;
}