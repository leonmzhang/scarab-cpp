#include "sc_base64.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *ptr = "this is a test";
  char *buf = new char[1024];
  memset(buf, 0, 1024);
  int len = base64_encode(ptr, strlen(ptr), buf, 1024);

  char *ptr2 = "dGhpcyBpcyBhIHRlc3Q=";
  char *buf2 = new char[1024];
  memset(buf2, 0, 1024);
  int len2 = base64_decode(ptr2, strlen(ptr2), buf2, 1024);

  printf("%s\t%d\n", buf2, len2);
  delete[] buf;
  delete[] buf2;
}
