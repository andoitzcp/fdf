#include "fdf.h"

void db_printpoint(t_node *p)
{
    static int i = 0;

    ft_printf("Node #%d:\n", i);
    ft_printf("\tx:%d,\ty:%d,\tz:%d,\tc:%x\n", p->x, p->y, p->z, p->c);
    ft_printf("\tup:\t%p\n", p->u);
    ft_printf("\tdown:\t%p\n", p->d);
    ft_printf("\tleft:\t%p\n", p->l);
    ft_printf("\tright:\t%p\n", p->r);
    i++;
}

void db_printline(t_node *p)
{
    while (p)
    {
        db_printpoint(p);
        p = p->r;
    }
}

void db_printmatrix(t_node **head)
{
    t_node *p;

    p = *head;
    while (p)
    {
        db_printline(p);
        p = p->d;
    }
}
