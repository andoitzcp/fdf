#include "fdf.h"

void ft_storeline(t_node **head, char **params)
{
    int i;
    int j;
    t_node *p;
    void *tmp;

    p = *head;
    i = 0;
    j = 0;
    printf("flag10:p: %p\n", p);
    while (p)
    {
        p = p->d;
        j++;
        printf("flag10.1:p: %p\tj:%d\n", p, j);
    }
    //p->l = NULL;
    printf("flag11:p: %p\n", p);
    tmp = NULL;
    while (params[i])
    {
        printf("flag11.1:i: %d\n", i);
        p = ft_defpoint(i, j, params[i]);
        p->l = tmp;
        printf("flag11.2:p: %p\n", p);
        tmp = p;
        printf("flag11.3:p: %p\n", p);
        p = p->r;
        printf("flag11.4:p: %p\n", p);
        printf("flag11.5:p: %p\n", p);
        i++;
    }
}

void ft_parsefile(char *s)
{
    int fd;
    char *sline;
    t_node **head;

    fd = open(s, O_RDONLY);
    printf("flag00:fd: %d name: %s\n", fd, s);
    if (!fd)
    {
        perror("Could not open data file\n");
        abort();
    }
    head = (t_node **)malloc(sizeof(t_node **));
    printf("flag01:head: %p\n", head);
    if (!head)
    {
        perror("Could not allocate header pointer");
        abort();
    }
    *head = NULL;
    printf("flag02:*head: %p\n", *head);
    sline = ft_gnl(fd);
    printf("flag03:sline: %p\n", sline);
    while (sline != NULL)
    {
        printf("flag04:sline: %s\n", sline);
        ft_storeline(head, ft_split(sline, ' '));
        free(sline);
        printf("flag05\n");
        sline = ft_gnl(fd);
    }
    db_printmatrix(head);
    close(fd);
}
