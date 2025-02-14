/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefile.c                                  :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: andoitzcp <andoitzcp@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:01:15 by andoitzcp         #+#    #+#             */
/*   Updated: 2025/02/14 01:16:15 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_buildline(char **params, int j)
{
	int		i;
	void	*tmp;
	t_node	*p;

	i = 0;
	p = ft_defpoint(i, j, params[i]);
	p->l = NULL;
	while (params[++i])
	{
		tmp = p;
		p = p->r;
		p = ft_defpoint(i, j, params[i]);
		p->l = tmp;
	}
	ft_free2parray(params);
	while (p->l)
	{
		tmp = p;
		p = p->l;
		p->r = tmp;
	}
	return (p);
}

void	ft_storeline(t_node **head, char **params)
{
	int		j;
	t_node	*p;
	t_node	*tmp;

	if (!*head)
	{
		*head = ft_buildline(params, 0);
		return ;
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
}

void	ft_readfile(int fd, t_node **head)
{
	char	*sline;

	*head = NULL;
	sline = ft_gnl(fd);
	while (sline != NULL)
	{
		ft_storeline(head, ft_split(sline, ' '));
		free(sline);
		sline = ft_gnl(fd);
	}
}

t_node	**ft_parsefile(char *s)
{
	int		fd;
	t_node	**head;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		perror("Could not open data file\n");
		return (NULL);
	}
	head = (t_node **)malloc(sizeof(t_node **));
	if (!head)
	{
		perror("Could not allocate header pointer");
		return (NULL);
	}
	ft_readfile(fd, head);
	close(fd);
	return (head);
}
