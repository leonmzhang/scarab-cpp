#include "sc_base64.h"
#include <string.h>

int base64_encode(const char *ptr, int ptr_len, char *buf, int buf_len)
{
  int encode_len = ptr_len / 3 * 4 + (ptr_len % 3 == 0 ? 0 : 4);
  if(encode_len > buf_len)
  {
    return -1;
  }

  const char *p_src = ptr;
  char *p_des = buf;
  int loop_count = ptr_len / 3;
  int remainder = ptr_len % 3;
  
  for(int i = 0; i < loop_count; i++)
  {
    *p_des       = base64_map[(*p_src >> 2) & 0x3f];
    *(p_des + 1) = base64_map[((*p_src << 4) & 0x30) | ((*(p_src + 1) >> 4) & 0x0f)];
    *(p_des + 2) = base64_map[(*(p_src + 1) << 2 & 0x3c) | ((*(p_src + 2) >> 6) & 0x03)];
    *(p_des + 3) = base64_map[*(p_src + 2) & 0x3f];
    p_src += 3;
    p_des += 4;
  }
  
  if(remainder != 0)
  {
    char buf[3];
    memset(buf, 0, 3);
    memcpy(buf, p_src, remainder);
    *p_des       = base64_map[(*buf >> 2) & 0x3f];
    *(p_des + 1) = base64_map[((*buf << 4) & 0x30) | ((*(buf + 1) >> 4) & 0x0f)];
    *(p_des + 2) = base64_map[(*(buf + 1) << 2 & 0x3c) | ((*(buf + 2) >> 6) & 0x03)];
    *(p_des + 3) = base64_map[*(buf + 2) & 0x3f];
    p_src += remainder;
    p_des += 4;
  }

  p_des = p_des - (3 - remainder);
  for(int i = 0; i < (3 - remainder); i++)
  {
    *p_des++ = '=';
  }

  return p_des - buf;
}

int base64_decode(const char *ptr, int ptr_len, char *buf, int buf_len)
{
  int remainder = 0;
  char *p_src = ptr + ptr_len;
  while(*p_src == '=')
  {
    
  }
  
  int decode_len = ptr_len * 4 / 3;
}
