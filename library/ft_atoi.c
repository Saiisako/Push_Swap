/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:39 by skock             #+#    #+#             */
/*   Updated: 2024/12/21 02:03:14 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_verif(long result, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (ft_error(), 0);
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (ft_error(), 0);
	return (1);
}

int	ft_verif_hyphen(int next)
{
	if ((next == '-' || next == '+'))
		return (ft_error(), 1);
	return (0);
}

long	ft_atoi(char *str)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_iswhitespace(str[i]) == 1 || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_verif_hyphen(str[i + 1]);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ft_verif_hyphen(str[i + 1]);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	ft_verif(result * sign, str);
	return (result * sign);
}
