#include "libft.h"

int     ft_ischars(char *src, char *content)
{
  size_t  len;

  len = ft_strlen(content);
  while (*src)
  {
    while (*content)
    {
      if (*src == *content)
        return (1);
    }
  }

}
