/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:35:52 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/28 07:37:52 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define DEF_SIZE 4

static char	*update_line(t_content	*cont)
{
	char	*new;
	size_t	new_size;

	if (cont->line_len + cont->buf_len + 1 > cont->line_size)
	{
		new_size = cont->line_size * 2 + 1;
		if (new_size < cont->line_len + cont->buf_len + 1)
			new_size += cont->line_len + cont->buf_len + 1;
		new = (char *) malloc(sizeof(char) * new_size);
		if (new == NULL)
		{
			free(cont->line);
			return (NULL);
		}
		ft_strcpy(new, cont->line);
		free(cont->line);
		cont->line = new;
		cont->line_size = new_size;
	}
	cont->line_len += ft_strcpy(cont->line + cont->line_len, cont->buf);
	return (cont->line);
}

static int	find_new_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

static char	*handle_read(int fd, t_content *cont)
{
	int		n_read;

	cont->line = (char *) malloc(sizeof(char) * DEF_SIZE);
	if (cont->line == NULL)
		return (NULL);
	cont->line_len = 0;
	cont->line_size = DEF_SIZE;
	cont->line[0] = '\0';
	cont->line = update_line(cont);
	while (cont->line != NULL && find_new_line(cont->line) == -1)
	{
		n_read = read(fd, cont->buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(cont->line);
			return (NULL);
		}
		cont->buf[n_read] = '\0';
		cont->buf_len = n_read;
		if (n_read == 0)
			return (cont->line);
		cont->line = update_line(cont);
	}
	return (cont->line);
}

static char	*handle_result(t_content *cont)
{
	int	new_line;

	new_line = find_new_line(cont->line);
	if (new_line != -1)
	{
		cont->buf_len = ft_strcpy(cont->buf, cont->line + new_line + 1);
		cont->line[new_line + 1] = '\0';
	}
	else
	{
		cont->buf[0] = '\0';
		cont->buf_len = 0;
		if (cont->line[0] == '\0')
		{
			free(cont->line);
			return (NULL);
		}
	}
	return (cont->line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst = NULL;
	t_gnl_list			*node;

	if (BUFFER_SIZE < 0 || fd == -1)
	{
		gnl_lst_free(lst, true);
		lst = NULL;
		return (NULL);
	}
	node = gnl_lst_find(lst, fd);
	if (node == NULL)
	{
		node = gnl_lst_new(fd);
		if (node == NULL)
			return (NULL);
		gnl_lst_add(&lst, node);
	}
	if (!handle_read(fd, &node->cont) || !handle_result(&node->cont))
	{
		if (node == lst)
			lst = node->next;
		gnl_lst_free(node, false);
		return (NULL);
	}
	return (node->cont.line);
}
