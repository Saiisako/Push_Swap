/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:41:28 by skock             #+#    #+#             */
/*   Updated: 2024/12/14 17:42:30 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_has_duplicates(char **av)
{
	int	i = 0;
	while (av[i])
	{
		int j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (ft_error(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_limits(char **argv)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb <= -2147483648 || nb > 2147483647)
			return (ft_error(), 0);
		i++;
	}
	return (1);
}