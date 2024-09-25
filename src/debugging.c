#include "fdf.h"

void db_printpoint(t_node *p)
{
    static int i = 0;

    printf("Node #%d: %p\n", i, p);
    printf("\tx:%d,\ty:%d,\tz:%d,\tc:%x\n", p->x, p->y, p->z, p->c);
    printf("\tcarx:%d,\tcary:%d\n", p->carx, p->cary);
    printf("\tup:\t%p\n", p->u);
    printf("\tdown:\t%p\n", p->d);
    printf("\tleft:\t%p\n", p->l);
    printf("\tright:\t%p\n", p->r);
    i++;
}

void db_printline(t_node *p)
{
    t_node *tmp;

    tmp = p;
    while (tmp)
    {
        db_printpoint(tmp);
        tmp = tmp->r;
    }
}

void db_printmatrix(t_node **head)
{
    t_node *p;
    t_node *tmp;

    tmp = *head;
    while (tmp)
    {
        p = tmp;
        db_printline(p);
        tmp = tmp->d;
    }
}

void db_printparams(char **params)
{
    int i;

    i = 0;
    while (params[i])
    {
        printf("p[%d]: %s\n", i, params[i]);
        i++;
    }
}
