/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:52:11 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 15:33:47 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion.h"
#include "libft.h"

static int	expand_arg(char *arg, t_dll **arg_lst, t_shell *shell);

static int	handle_split(char *expanded, t_dll **arg_lst);

static int	handle_no_split(char *unquoted, t_dll **arg_lst);

static char	**get_expanded_args(t_dll **arg_lst);

char	**expand_args(t_command *command, t_shell *shell)
{
	char	**args;
	t_dll	*arg_lst;
	size_t	i;

	if (command->args == NULL)
		return (NULL);
	arg_lst = NULL;
	i = 0;
	while (command->args[i] != NULL)
	{
		if (expand_arg(command->args[i], &arg_lst, shell) == -1)
		{
			clear_dll(&arg_lst, free);
			return (NULL);
		}
		i++;
	}
	args = get_expanded_args(&arg_lst);
	if (args == NULL)
		clear_dll(&arg_lst, free);
	else
		clear_dll(&arg_lst, NULL);
	return (args);
}

static int	expand_arg(char *arg, t_dll **arg_lst, t_shell *shell)
{
	int		rc;
	char	*expanded;
	char	*unquoted;

	expanded = expand_string(arg, shell);
	if (expanded == NULL)
		return (-1);
	unquoted = remove_quotes(expanded);
	if (unquoted == NULL)
	{
		free(expanded);
		return (-1);
	}
	if (ft_strncmp(expanded, unquoted, ft_strlen(expanded) + 1) == 0)
		rc = handle_split(expanded, arg_lst);
	else
		rc = handle_no_split(unquoted, arg_lst);
	free(expanded);
	free(unquoted);
	return (rc);
}

static int	handle_split(char *expanded, t_dll **arg_lst)
{
	t_dll	*node;
	char	**splitted;
	size_t	i;

	splitted = ft_split(expanded, ' ');
	if (splitted == NULL)
		return (-1);
	i = 0;
	while (splitted[i] != NULL)
	{
		node = new_dll(splitted[i]);
		if (node == NULL)
		{
			free(splitted);
			return (-1);
		}
		add_dll(arg_lst, node);
		i++;
	}
	free(splitted);
	return (0);
}

static int	handle_no_split(char *unquoted, t_dll **arg_lst)
{
	t_dll	*node;
	char	*dup;

	dup = ft_strdup(unquoted);
	if (dup == NULL)
		return (-1);
	node = new_dll(dup);
	if (node == NULL)
	{
		free(dup);
		return (-1);
	}
	add_dll(arg_lst, node);
	return (0);
}

static char	**get_expanded_args(t_dll **arg_lst)
{
	char	**args;
	size_t	args_size;
	size_t	i;
	t_dll	*tmp;

	args_size = dll_size(*arg_lst);
	args = malloc(sizeof(char *) * (args_size + 1));
	if (args == NULL)
		return (NULL);
	i = 0;
	tmp = *arg_lst;
	while (i < args_size && tmp != NULL)
	{
		args[i++] = tmp->data;
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}
