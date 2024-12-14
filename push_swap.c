/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:41 by skock             #+#    #+#             */
/*   Updated: 2024/12/14 17:37:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lstnew_and_fill(char **str)
// {

// }

int	main(int ac, char **av)
{
	char	**stock;

		if (ac == 2)
		{
			stock = ft_split(av[1], ' ');
			// ft_lstnew_and_fill(stock);
		}

	if (ft_limits(av) == 0)
		return (0);
	if (ft_has_duplicates(av))
		return (0);
	// if (ac == 2)
	// 	ft_push_swap(stock);
	// else if (ac > 2)
	// 	ft_push_swap(av);
	
	
	int i = 1;
	while (av[i])
	{
		printf("%ld\n", ft_atoi(av[i]));
		i++;
	}
	return (0);
}