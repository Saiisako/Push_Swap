/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:39 by skock             #+#    #+#             */
/*   Updated: 2024/12/30 17:54:11 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	ft_verif(t_list *lst, long result, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			freelst(lst);
			return (1);
		}
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
	{
		freelst(lst);
		return (1);
	}
	return (0);
}

int	ft_verif_hyphen(t_list *lst, int next)
{
	if ((next == '-' || next == '+'))
	{
		freelst(lst);
		return (1);
	}
	return (0);
}

long	result(char *str, t_list *lst, long sign, long result)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]) == 1 || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_verif_hyphen(lst, str[i + 1]) == 1)
			return (ERROR);
		if (str[i] == '-')
			sign = -1;
		if (!str[i + 1])
			return (ERROR);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (ft_verif_hyphen(lst, str[i + 1]) == 1)
			return (ERROR);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (ft_verif(lst, result * sign, str) == 1)
		return (ERROR);
	return (result * sign);
}

long	ft_atoi(t_list *lst, char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	return (result(str, lst, sign, res));
}
