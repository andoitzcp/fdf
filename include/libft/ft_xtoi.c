#include "libft.h"
#include <stdio.h>

int ft_xtoi(char *hex)
{
    int i;
    int j;
    int x;
    char *base;

    if (!hex)
        return (0);
    i = 0;
    if (ft_tolower(hex[0]) != '0' && ft_tolower(hex[1]) != 'x')
        return(perror("Not a valid hexadecimal string"), 0);
    base = ft_strdup("0123456789abcdef");
    i += 2;
    x = 0;
    while (hex[i] != '\0')
    {
        x *= 16;
        j = 0;
        while (ft_tolower(hex[i]) != base[j])
        {
            if (base[j] == '\0')
                return (free(base), 0);
            j++;
        }
        x += j;
        i++;
    }
    free(base);
    return (x);
}
