#include "fdf.h"

void *ft_buildline(char **params, int j)
{
    int i;
    void *tmp;
    t_node *p;

    i = 0;
    p = ft_defpoint(i, j, params[i]);
    //printf("flag21\n");
    p->l = NULL;
    //db_printpoint(p);
    while (params[++i])
    {
        //printf("flag21.1\n");
        //i++;
        tmp = p;
        p = p->r;
        p = ft_defpoint(i, j, params[i]);
        p->l = tmp;
        //db_printpoint(p);
    }
    //printf("flag22\n");
    while (p->l)
    {
        //printf("flag22.1\n");
        //db_printpoint(p);
        tmp = p;
        p = p->l;
        p->r = tmp;
    }
    //printf("flag23\n");
    //db_printpoint(p);
    return (p);
}

void *ft_storeline(t_node **head, char **params)
{
    int j;
    t_node *p;
    t_node *tmp;

    if (!*head)
    {
        *head = ft_buildline(params, 0);
        return (head);
    }
    p = *head;
    j = 0;
    while (p)
    {
        tmp = p;
        p = p->d;
        j++;
    }
    p = ft_buildline(params, j);
    while (p && tmp)
    {
        p->u = tmp;
        tmp->d = p;
        p = p->r;
        tmp = tmp->r;
    }
    return (head);
}

void ft_parsefile(char *s)
{
    int fd;
    char *sline;
    t_node **head;

    fd = open(s, O_RDONLY);
    if (!fd)
    {
        perror("Could not open data file\n");
        abort();
    }
    head = (t_node **)malloc(sizeof(t_node **));
    if (!head)
    {
        perror("Could not allocate header pointer");
        abort();
    }
    *head = NULL;
    sline = ft_gnl(fd);
    while (sline != NULL)
    {
        head = ft_storeline(head, ft_split(sline, ' '));
        free(sline);
        sline = ft_gnl(fd);
    }
    db_printmatrix(head);
    close(fd);
}
