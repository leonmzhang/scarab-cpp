#include "sc_base64.h"
#include <string.h>
#include <stdio.h>

int base64_encode(const char *ptr, int ptr_len, char *buf, int buf_len)
{
  int encode_len = ptr_len / 3 * 4 + (ptr_len % 3 == 0 ? 0 : 4);
  if(ptr == NULL)
  {
    return -1;
  }

  if(buf == NULL)
  {
    return encode_len;
  }
  else if(encode_len > buf_len)
  {
    return -1;
  }

  const char *p_src = ptr;
  char *p_des = buf;
  int loop_count = ptr_len / 3;
  int remainder = ptr_len % 3;
  
  for(int i = 0; i < loop_count; i++)
  {
    *p_des       = base64_encode_map[(*p_src >> 2) & 0x3f];
    *(p_des + 1) = base64_encode_map[((*p_src << 4) & 0x30) | ((*(p_src + 1) >> 4) & 0x0f)];
    *(p_des + 2) = base64_encode_map[(*(p_src + 1) << 2 & 0x3c) | ((*(p_src + 2) >> 6) & 0x03)];
    *(p_des + 3) = base64_encode_map[*(p_src + 2) & 0x3f];
    p_src += 3;
    p_des += 4;
  }
  
  if(remainder != 0)
  {
    char inner_buf[3];
    memset(inner_buf, 0, 3);
    memcpy(inner_buf, p_src, remainder);
    *p_des       = base64_encode_map[(*inner_buf >> 2) & 0x3f];
    *(p_des + 1) = base64_encode_map[((*inner_buf << 4) & 0x30) | ((*(inner_buf + 1) >> 4) & 0x0f)];
    *(p_des + 2) = base64_encode_map[(*(inner_buf + 1) << 2 & 0x3c) | ((*(inner_buf + 2) >> 6) & 0x03)];
    *(p_des + 3) = base64_encode_map[*(inner_buf + 2) & 0x3f];
    p_src += remainder;
    p_des += 4;
	p_des = p_des - (3 - remainder);
	for(int i = 0; i < (3 - remainder); i++)
	{
		*p_des++ = '=';
	}
  }

  return p_des - buf;
}

int base64_decode(const char *ptr, int ptr_len, char *buf, int buf_len)
{
  int remainder = 0;
  const char *p_src = ptr + ptr_len - 1;
  while(*p_src == '=')
  {
    p_src--;
  }
  remainder = ptr_len - 1 - (p_src - ptr);
  int decode_len = (((ptr_len - 4) / 4 * 3) + (3 - remainder));
  if(decode_len > buf_len)
  {
    return -1;
  }
  if(ptr_len % 4 != 0)
  {
    return -1;
  }

  p_src = ptr;
  char *p_des = buf;
  int loop_count = ptr_len / 4 - 1;
  for(int i = 0; i < loop_count; i++)
  {
    *p_des = ((base64_decode_map[*p_src - 43] << 2) & 0xfc) 
      | ((base64_decode_map[*(p_src + 1) - 43] >> 4) & 0x03);
    *(p_des + 1) = ((base64_decode_map[*(p_src + 1) - 43] << 4) & 0xf0)
      | ((base64_decode_map[*(p_src + 2) - 43] >> 2) & 0x0f);
    *(p_des + 2) = ((base64_decode_map[*(p_src + 2) - 43] << 6) & 0xc0)
      | (base64_decode_map[*(p_src + 3) - 43] & 0x3f);
    p_src += 4;
    p_des += 3;
  }

  char inner_buf[4];
  memcpy(inner_buf, p_src, 4);
  for(int i = 0; i < remainder; i++)
  {
    inner_buf[4 - i - 1] = '\0';
  }

  *p_des = ((base64_decode_map[inner_buf[0] - 43] << 2) & 0xfc) 
    | ((base64_decode_map[inner_buf[1] - 43] >> 4) & 0x03);
  *(p_des + 1) = ((base64_decode_map[inner_buf[1] - 43] << 4) & 0xf0) 
    | ((base64_decode_map[inner_buf[2] - 43] >> 2) & 0x0f);
  *(p_des + 2) = ((base64_decode_map[inner_buf[2] - 43] << 6) & 0xc0) 
    | (base64_decode_map[inner_buf[3] - 43] & 0x3f);
  p_src += 4;
  p_des += 3 - remainder;

  return p_des - buf;
}
