/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:30:48 by skock             #+#    #+#             */
/*   Updated: 2025/01/04 15:21:45 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*isworth(t_list **lst_b)
{
	t_list	*temp;
	t_list	*min_node;

	temp = (*lst_b);
	min_node = temp;
	while (temp)
	{
		if (temp->pp < min_node->pp)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

void	update_global_pool_price(t_list **lst_a, t_list **lst_b)
{
	int			pos_mid_a;
	int			pos_mid_b;
	int			prize_b;
	int			prize_a;
	t_list		*temp;

	pos_mid_a = lst_size(lst_a) / 2;
	pos_mid_b = lst_size(lst_b) / 2;
	temp = *lst_b;
	while (temp)
	{
		if (temp->index <= pos_mid_b)
			prize_b = temp->index;
		else
			prize_b = pos_mid_b * 2 - temp->index + 2;
		if (temp->target_index <= pos_mid_a)
			prize_a = temp->target_index - 1;
		else
			prize_a = pos_mid_a * 2 - temp->target_index + 1;
		temp->pp = prize_b + prize_a;
		temp = temp->next;
	}
}

void	update_obj(t_list **lst_a, t_list **lst_b)
{
	t_list		*temp_a;
	t_list		*temp_b;

	temp_b = *lst_b;
	while (temp_b)
	{
		temp_a = *lst_a;
		temp_b->target_value = INT_MAX;
		while (temp_a)
		{
			if (temp_a->value > temp_b->value)
			{
				if (temp_b->target_value > temp_a->value)
				{
					temp_b->target_value = temp_a->value;
					temp_b->target_index = temp_a->index;
				}
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
	update_global_pool_price(lst_a, lst_b);
	return ;
}

void	pb_modified(t_list **lst_a, t_list **lst_b, int median)
{
	t_list	*temp;
	int		len;
	int		pb_times;
	int		pos_mid;

	pb_times = 0;
	len = lst_size(lst_a);
	pos_mid = len / 2;
	temp = *lst_a;
	while (pb_times < len / 2)
	{
		if ((*lst_a)->value > median)
		{
			pb(lst_a, lst_b, true);
			pb_times++;
		}
		else
		{
			if (temp->index > pos_mid)
				rra(lst_a, true);
			else
				ra(lst_a, true);
		}
		temp = *lst_a;
	}
}

int	verif_value(t_list *lst, int median)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp)
	{
		if (temp->value < median)
		{
			count++;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (count);
}
