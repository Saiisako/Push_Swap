/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:37:40 by skock             #+#    #+#             */
/*   Updated: 2024/12/29 12:54:47 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_3(t_list **lst_a)
{
	int	first;
	int	second;
	int	last;

	first = (*lst_a)->value;
	second = (*lst_a)->next->value;
	last = (*lst_a)->next->next->value;
	if (second < first && first < last)
		sa(*lst_a, true);
	else if (last < second && second < first)
	{
		sa(*lst_a, true);
		rra(lst_a, true);
	}
	else if (last < first && first < second)
		rra(lst_a, true);
	else if (first < last && last < second)
	{
		sa(*lst_a, true);
		ra(lst_a, true);
	}
	else if (second < last && last < first)
		ra(lst_a, true);
}
