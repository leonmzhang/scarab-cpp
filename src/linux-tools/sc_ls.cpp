#include <iostream>
#include <dirent.h>

using namespace std;

void usage()
{
  cout << "usage" << endl;
}

int main(int argc, char *argv[])
{

  for(int i = 1; i < argc; i++)
  {
    cout << argv[i] << endl;
  }

  DIR *current_dir;
  current_dir = opendir(".");
  struct dirent *dir;
  if(current_dir)
  {
    while((dir = readdir(current_dir)) != NULL)
    {
      if(dir->d_name[0] == '.')
      {
	continue;
      }
      cout << dir->d_name << "\t";
    }
  }
  cout << endl;

  closedir(current_dir);
}
