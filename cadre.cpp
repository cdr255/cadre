#include "cadre.hpp"

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
}
