#include <string>
#include <vector>

#include <string.h>

/**
 * 
 */
inline
int trim_str(char * pstr, const char trim_char)
{
  const char *p = pstr;
  if(0 == p)
  {
    return 0;
  }

  int start = 0;
  int end = 0;
  while(*p)
  {
    if((unsigned char)*p < 0x20 || trim_char  == *p)
    {
      if(end == 0)
      {
	start ++;
      }
    }
    else
    {
      end = (int)(p - pstr + 1);
    }
    p ++;
  }
  
  end > 0 ? pstr[end] = 0 : end = p - pstr;
  if(end == start)
  {
    pstr[0] = 0;
  }
  else if(start > 0)
  {
    memmove(pstr, pstr + start, end - start + sizeof(char));
  }

  return end - start;
}

