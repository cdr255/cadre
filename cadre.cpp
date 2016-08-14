#include "cadre.hpp"

/********************

CHARACTER DEFINITIONS

********************/

Cadre::Character::Character(std::string n, int f, int s, int w, int st, int fo, int re, int gr, int ed, int in):
  statname(n),statforce(f),statskill(s),statwit(w),statstrength(st),statfortitude(fo),statreaction(re),statgrace(gr),stateducation(ed),statintuition(in)
{
  std::cout << "Loaded Character " << statname << ".\n";
}

Cadre::Character::Character(std::string filename){
  std::string entry,name;
  std::vector<int> stats;
  std::ifstream file(filename);
  if(file.is_open())
    {
      int entry_counter = -1;
      while ( std::getline(file,entry,',') )
	{
	  if (entry_counter == -1)
	    {
	      name = entry;
	    }
	  else
	    {
	      stats.push_back(stoi(entry));
	    }
	  
	  entry_counter++;
	}
      file.close();
      statname = name;
      statforce = stats[0];
      statskill = stats[1];
      statwit = stats[2];
      statstrength = stats[3];
      statfortitude = stats[4];
      statreaction = stats[5];
      statgrace = stats[6];
      stateducation = stats[7];
      statintuition = stats[8];
      std::cout << "Loaded Character " << statname << ".\n";
    }
  else
    {
      std::cout << "Unable to open file '" << filename << "'.";
    }
}

std::string Cadre::Character::name()
{
  return statname;
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

int Cadre::Character::writeout(std::string filename)
{
  std::ofstream file;
  file.open(filename);
  file << statname << "," << statforce << "," << statskill << "," << statwit << "," << statstrength << "," << statfortitude << "," << statreaction << "," << statgrace << "," << stateducation << "," << statintuition << "\n";
  return 0;  
}

/****************

QUEST DEFINITIONS

****************/

Cadre::Quest::Quest(std::string n, std::string r, int a, Cadre::Character* c):
  qname(n),
  reqname(r),
  reqamount(a),
  character(c)
{
  generator.seed(rd());
  std::cout << "Lucky Number: " << roll(10) << "!\n\n";
  std::cout << "| " << character->name() << " embarks on the basic quest " << name() << "! |\n\n";
}

std::string Cadre::Quest::name()
{
  return qname;
}

bool Cadre::Quest::forcecheck(bool dice)
{
  std::cout << character->name() << " needs to be forceful!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->force())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::skillcheck(bool dice)
{
  std::cout << character->name() << " needs to be skilled!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->skill())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::witcheck(bool dice)
{
  std::cout << character->name() << " needs to be witty!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->wit())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::strengthcheck(bool dice)
{
  std::cout << character->name() << " needs to be strong!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->strength())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::fortitudecheck(bool dice)
{
  std::cout << character->name() << " needs to be tough!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->fortitude())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::reactioncheck(bool dice)
{
  std::cout << character->name() << " needs to be quick!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->reaction())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::gracecheck(bool dice)
{
  std::cout << character->name() << " needs to be graceful!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->grace())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::educationcheck(bool dice)
{
  std::cout << character->name() << " needs to be well-read!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->education())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

bool Cadre::Quest::intuitioncheck(bool dice)
{
  std::cout << character->name() << " needs to be intuitive!\n";
  std::cout << "  ( >" << reqamount << " needed.)\n...\n";
  if (reqamount <= character->intuition())
    {
      std::cout << "SUCCESS!\n";
      return true;
    }
  else
    {
      std::cout << "FAILURE!\n";
      return false;
    }
}

int Cadre::Quest::roll(int x)
{
  std::uniform_int_distribution<int> distribution(1,x);
  return distribution(generator);
}
