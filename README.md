# FDF

## Usage

Movement:
- h = left
- j = Down
- k = Up
- l = right

Zoom:
- u = zoom in
- m = zoom out

Other:
- c = toggle image mode (instead of drawing pixel by pixel)
- ESC = end the program

## Norminette

Exclude norminette for the minilibx includes.

1. Execute the following command:
`norminette | grep -v "Error:" | grep -v "Notice:" | grep -v "OK!" | awk -F "/" '{print $1 "/" $2}' | sort | uniq`
2. Check that nothing else than the following line is returned

``` sh
$ >  norminette | grep -v "Error:" | grep -v "Notice:" | grep -v "OK!" | awk -F "/" '{print $1 "/" $2}' | sort | uniq
include/minilibx-linux
```

