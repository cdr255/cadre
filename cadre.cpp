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

int Cadre::Character::writeout()
{
  std::string outfile = statname + ".txt";
  std::ofstream file;
  file.open(outfile);
  file << statname << "," << statforce << "," << statskill << "," << statwit << "," << statstrength << "," << statfortitude << "," << statreaction << "," << statgrace << "," << stateducation << "," << statintuition << "\n";
  return 0;
}

int Cadre::readin(std::string filename)
{
  std::string entry;
  std::ifstream file(filename);
  if(file.is_open())
    {
      while ( std::getline(file,entry,',') )
	{
	  std::cout << entry << "\n";
	}
      file.close();
      return 0;
    }
  else
    {
      std::cout << "Unable to open file '" << filename << "'.";
      return 1;
    }
}
