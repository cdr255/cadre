#include "cadre.hpp"

Cadre::Character::Character(std::string n, int f, int s, int w, int st, int fo, int re, int gr, int ed, int in):
  statname(n),statforce(f),statskill(s),statwit(w),statstrength(st),statfortitude(fo),statreaction(re),statgrace(gr),stateducation(ed),statintuition(in)
{
  std::cout << "Loaded Character " << statname << ".\n";
}

int Cadre::Character::force()
{
  return statforce;
}

int Cadre::Character::skill()
{
  return statskill;
}

int Cadre::Character::wit()
{
  return statwit;
}
int Cadre::Character::strength()
{
  return statstrength;
}

int Cadre::Character::fortitude()
{
  return statfortitude;
}

int Cadre::Character::reaction()
{
  return statreaction;
}
int Cadre::Character::grace()
{
  return statgrace;
}

int Cadre::Character::education()
{
  return stateducation;
}

int Cadre::Character::intuition()
{
  return statintuition;
}
