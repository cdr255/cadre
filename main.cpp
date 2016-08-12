#include "cadre.hpp"
#include <unistd.h>


int main(int argc,char* argv[])
{
  Cadre::Character player("Leonora",7,5,9,1,2,3,4,5,6);
  if (player.writeout() == 0)
    std::cout << "File Written Successfully!\n";
  else
    std::cout << "Error. Files not Written.\n";
  Cadre::readin("Leonora.txt");
  return 0;
}
