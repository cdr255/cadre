#ifndef _CADRE_HPP_
#define _CADRE_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    // Constructors
    Character(std::string);
    Character(std::string,int,int,int,int,int,int,int,int,int);
    // File Functions
    int writeout();
    int writeout(std::string);
  };

  class Quest
  {
  private:
    std::string qname,reqname;
    int reqamount;
    Cadre::Character* character;
  public:
    // Getter Functions
    std::string name();
    
    // Constructors
    Quest(std::string, std::string, int, Cadre::Character*);
    Quest(std::string);
    // Operators
    bool forcecheck(bool);
    bool skillcheck(bool);
    bool witcheck(bool);
  };

}

#endif
