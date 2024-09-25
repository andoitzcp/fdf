#include "fdf.h"

t_params *ft_setinitparams(t_node **head)
{
    unsigned int i;
    unsigned int j;
    t_node *p;
    t_params *par;

    p = *head;
    i = 1;
    while ((p = p->r) != NULL)
        i++;
    p = *head;
    j = 1;
    while ((p = p->d) != NULL)
        j++;
    par = (t_params *)malloc(sizeof(t_params));
    if (j > i)
        par->i = j;
    else
        par->i = i;
    par->angle = (double)(M_PI_4);
    par->width = SCRN_WIDTH;
    par->heigh = SCRN_HEIGH;
    par->xoffset = (double)SCRN_WIDTH / (double)2;
    par->yoffset = SCRN_HEIGH / 3.5;
    return (par);
}

t_node *ft_defpoint(int x, int y, char *param)
{
    t_node *p;
    char **handc;

    p = (t_node *)malloc(sizeof(t_node));
    if (!p)
    {
        perror("Could not allocate node pointer\n");
        abort();
    }
    handc = ft_split(param, ',');
    p->x = x;
    p->y = y;
    p->z = ft_atoi(handc[0]);
    if (!handc[1])
        p->c = MIN_COLOR + p->z * (0xFF0000 - MIN_COLOR);// + p->z * (0x0000FF - MIN_COLOR);
    else
        p->c = ft_xtoi(handc[1]);
    ft_free2parray(handc);
    p->is_printed = 0;
    p->u = NULL;
    p->d = NULL;
    p->r = NULL;
    return (p);
}

t_node *ft_relocpoint(t_node *p, t_params *par, unsigned int mod)
{
    double isox;
    double isoy;

    isox = (double)p->x;
    isoy = (double)p->y;


    p->carx = (isox * cos(par->angle) - isoy * sin(par->angle)) * mod;
    p->cary = (isox * sin(par->angle) + isoy * cos(par->angle)) * mod;
    p->carx += par->xoffset;
    p->cary += par->yoffset - p->z; //SCRN_HEIGH / 3 - p->z;
    return (p);
}

t_node **ft_recalcgrid(t_node **head, t_params *par)
{
    t_node *p;
    t_node *tmp;
    unsigned int mod;

    mod = par->width / par->i / 2;
    printf("mod: %d", mod);
    p = *head;
    while (p)
    {
        tmp = p;
        while (tmp)
        {
            tmp = ft_relocpoint(tmp, par, mod);
            tmp = tmp->r;
        }
        p = p->d;
    }
    return (head);
}
