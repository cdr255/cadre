#ifndef _CADRE_HPP_
#define _CADRE_HPP_
#include <iostream>
#include <fstream>
#include <string>

namespace Cadre
{
  class Character
  {
  private:
    std::string statname;
    int statforce, statskill, statwit; // Primary Stats
    int statstrength, statfortitude, statreaction, statgrace, stateducation, statintuition; // Secondary Stats
  public:
    // Getter Fuctions
    int force();
    int skill();
    int wit();
    int strength();
    int fortitude();
    int reaction();
    int grace();
    int education();
    int intuition();
    std::string name();
    // Constructor
    Character(std::string,int,int,int,int,int,int,int,int,int);
    // File Functions
    int writeout();
  };

  int readin(std::string);

}

#endif
