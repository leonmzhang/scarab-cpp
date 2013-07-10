#include <stdio.h>
#include <sys/mount.h>
#include <sys/param.h>

int get_disk_count()
{
  struct statfs sf;
  statfs("/", &sf);
  printf("f_bsize: %d\n", sf.f_bsize);
  printf("f_bfree: %d\n", sf.f_bfree);
}
