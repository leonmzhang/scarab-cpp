#include "include/sc_utils.h"
#include "include/max.hpp"
#include "include/hardware.h"
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int main_trim(int argc, char *argv[])
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

int main_max(int argc, char *argv[])
{
  int a = 3;
  int b = 5;
  cout << max(a, b) << endl;
  return 0;
}

void hello_01()
{
  for(int i = 0; i < 5; i++)
  {
    sleep(2);
    cout << "thread_01" << endl;
  }
}

void hello_02()
{
  for(int i = 0; i < 5; i++)
  {
    sleep(2);
    cout << "thread_02" << endl;
  }
}

int main(int argc, char *argv[])
{
  int disk_count = get_disk_count();
  return 0;
}
