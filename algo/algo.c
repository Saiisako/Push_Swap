/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:38:23 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 18:46:04 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_lst_b_empty(t_list *lst_b)
{
	if (lst_b == NULL)
		return (1);
	return (0);
}

void	send_smaller(t_list **lst_a, t_list **lst_b, int median)
{
	t_list	*temp;

	while (verif_value(*lst_a, median) > 0)
	{
		temp = *lst_a;
		if (lst_size(lst_a) == 3)
			break ;
		if (temp->value >= median)
			ra(lst_a, true);
		else
			pb(lst_a, lst_b);
	}
}

void	rotate_in_a(t_list **lst_a, t_list **lst_b, t_list *min_node)
{
	while (min_node->target_index != 1)
	{
		if (min_node->target_index < (lst_size(lst_a) / 2))
		{
			ra(lst_a, true);
			update_target_index(min_node, *lst_a, false, true);
		}
		else
		{
			rra(lst_a, true);
			update_target_index(min_node, *lst_a, true, false);
		}
	}
	pa(lst_a, lst_b);
}

void	global_rotate(t_list **lst_a, t_list **lst_b)
{
	t_list	*min_node;

	min_node = isworth(lst_b);
	while (min_node->index != 1)
	{
		if (min_node->index < (lst_size(lst_b) / 2))
		{
			rb(lst_b, true);
			update_min_index(min_node, *lst_b, false, true);
		}
		else
		{
			rrb(lst_b, true);
			update_min_index(min_node, *lst_b, true, false);
		}
	}
	rotate_in_a(lst_a, lst_b, min_node);
}

void	algo(t_list **lst_a, t_list **lst_b)
{
	int			median;
	int			size;

	size = lst_size(lst_a);
	median = bubblesort(*lst_a, size);
	while (size > 3)
	{
		send_smaller(lst_a, lst_b, median);
		size = lst_size(lst_a);
		median = bubblesort(*lst_a, size);
	}
	algo_3(lst_a);
	while (1)
	{
		update_obj(lst_a, lst_b);
		global_rotate(lst_a, lst_b);
		if (is_lst_b_empty(*lst_b) == 1)
		{
			while (check_sort(*lst_a, 1) != 1)
				rra(lst_a, true);
			break ;
		}
	}
}
