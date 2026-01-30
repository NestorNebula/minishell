/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:09:35 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/07 14:01:12 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	is_negative;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	is_negative = *nptr == '-';
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	nbr = 0;
	while (ft_isdigit(*nptr))
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (is_negative)
		return (-nbr);
	return (nbr);
}
