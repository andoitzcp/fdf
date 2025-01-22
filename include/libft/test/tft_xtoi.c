#include "../libft.h"
#include <assert.h>
#include <string.h>

int main(void)
{
    printf("Testing ft_xtoi...\n");
    assert(ft_xtoi("0xFFFFFF") ==  16777215);
    assert(ft_xtoi("0xFFFF00") ==  16776960);
    assert(ft_xtoi("0xFF00FF") ==  16711935);
    assert(ft_xtoi("0x00FFFF") ==  65535);
    assert(ft_xtoi("0x00FF00") ==  65280);
    assert(ft_xtoi("0x000000") ==  0);
    assert(ft_xtoi("0xFF00") ==  65280);
    assert(ft_xtoi("0x00fF00") ==  65280);
    assert(ft_xtoi("0x") ==  0);
    assert(ft_xtoi("0x1234AC") ==  1193132);
    assert(ft_xtoi("xFFFFFF") ==  0);
    assert(ft_xtoi("0xFFFFFx") ==  0);
    printf("All test passed\n");
}
