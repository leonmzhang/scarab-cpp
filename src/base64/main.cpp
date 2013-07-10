#include "sc_base64.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *ptr = "this is a test";
  char *buf = new char[1024];
  memset(buf, 0, 1024);
  
  int len = base64_encode(ptr, strlen(ptr), buf, 1024);

  printf("%s\t%d\n", buf, len);
  delete[] buf;
}
