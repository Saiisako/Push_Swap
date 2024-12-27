/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:38:10 by skock             #+#    #+#             */
/*   Updated: 2024/12/27 14:47:49 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	search_min(t_list *lst)
{
	t_list	min;
	min = *lst;
	while (lst)
	{
		if (lst->value < min.value)
			min = *lst;
		lst = lst->next;
	}
	return (min);
}

static t_list	search_max(t_list *lst)
{
	t_list	max;
	max = *lst;
	while (lst)
	{
		if (lst->value > max.value)
			max = *lst;
		lst = lst->next;
	}
	return (max);
}

void	push_extrememum(t_list **lst_a, t_list **lst_b, t_list min, t_list max)
{
	while ((*lst_a)->value != max.value)
	{
		if (max.index <= 3)
			ra(lst_a, true);
		else
			rra(lst_a, true);
	}
	pb(lst_a, lst_b);
	while ((*lst_a)->value != min.value)
	{
		if (min.index <= 3)
			ra(lst_a, true);
		else
			rra(lst_a, true);
	}
	pb(lst_a, lst_b);
}

void	pa_modified(t_list **lst_a, t_list **lst_b, t_list max)
{
	pa(lst_a, lst_b);
	if ((*lst_a)->value == max.value)
		ra(lst_a, true);
	pa(lst_a, lst_b);
	if ((*lst_a)->value == max.value)
		ra(lst_a, true);
}

void	algo_5(t_list **lst_a, t_list **lst_b)
{
	t_list	min;
	t_list	max;
	
	min = search_min(*lst_a);
	max = search_max(*lst_a);
	push_extrememum(lst_a, lst_b, min, max);
	algo_3(lst_a);
	pa_modified(lst_a, lst_b, max);
}
