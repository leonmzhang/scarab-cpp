#include "include/sc_utils.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  //  char * str = "\tthis is a test\t";
  char * str = "";
  char * pstr = new char[1024];
  memset(pstr, 0, 1024);
  memcpy(pstr, str, strlen(str) + 1);
  trim_str(pstr, 't');

  cout << "#" << pstr << "#" << endl;
  cout << strlen(pstr) << endl;

  return 0;
}
