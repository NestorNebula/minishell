/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:09:23 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/19 07:09:13 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*expand_string(char *str, t_shell *shell)
{
	char	*result;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
		{
			quote = str[i++];
			result = append_char(result, str[i++]);
		}
		else if (str[i] == quote)
		{
			quote = 0;
			result = append_char(result, str[i++]);
		}
		else if (str[i] == '$' && quote != '\'')
			result = expand_dollar(result, str, &i, shell);
		else
			result = append_char(result, str[i++]);
	}
	return (result);
}

char	*expand_dollar(char *result, char *str, int *i, t_shell *shell)
{
	char	*key;
	char	*value;

	(*i)++;
	if (str[*i] == '?')
	{
		value = ft_itoa(shell->last_status);
		result = append_str(result, value);
		free(value);
		(*i)++;
		return (result);
	}
	if (!str[*i] || !(ft_isalpha(str[*i]) || str[*i] == '_'))
		return (append_char(result, '$'));
	key = read_var_name(str, i);
	value = get_env_value(shell, key);
	if (value)
		result = append_str(result, value);
	free(key);
	return (result);
}

char	*read_var_name(char *str, int *i)
{
	int	start;

	start = *i;
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}
