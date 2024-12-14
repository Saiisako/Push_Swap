/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:39 by skock             #+#    #+#             */
/*   Updated: 2024/12/14 14:06:05 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(char *str)
{
	long	result;
	long	sign;
	long	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_iswhitespace(str[i]) == 1 || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (ft_isalpha(str[i]) || str[i] == '-' || str[i] == '+')
		return (ft_error(), 0);
	return (result * sign);
}
