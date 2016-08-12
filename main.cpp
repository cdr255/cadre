#include "cadre.hpp"
#include <unistd.h>

void testbasic();
void printhelp();

int main(int argc,char* argv[])
{
  int optnum;
  std::string outputname, inputname;
  bool output, input, testing = false;
  while ((optnum = getopt(argc, argv, "ho:r:t")) != -1)
    {
      switch (optnum) {
      case 'h':
	printhelp();
	break;
      case 'o':
	outputname = optarg;
	output=true;
	break;
      case 'r':
	inputname = optarg;
	input=true;
	break;
      case 't':
	testbasic();
	break;
      default:
	break;
      }
    }

  if (input == true)
    {
      Cadre::Character player(inputname);
      if (output == true)
	{
	  if (player.writeout(outputname) == 0)
	  std::cout << "File Written Successfully!\n";
	else
	  std::cout << "Error. File not Written.\n";
	}
    }
  
  return 0;
}


void testbasic()
{ 
  	Cadre::Character player("Leonora",7,5,9,1,2,3,4,5,6);
	if (player.writeout() == 0)
	  std::cout << "File Written Successfully!\n";
	else
	  std::cout << "Error. Files not Written.\n";
	Cadre::readin("Leonora.txt");
}

void printhelp()
{
  std::cout << "Usage: cadre [-hort]\n\nAvailable Options:\n\n";
  std::cout << "   -h: Display this help.\n   -o <file>: Write character to <file>.\n   -r <file>: Read character from <file>.\n   -t: Run Default Test.\n";
}
