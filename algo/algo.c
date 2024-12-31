/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:38:23 by skock             #+#    #+#             */
/*   Updated: 2024/12/31 15:35:36 by skock            ###   ########.fr       */
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

void	update_global_pool_price(t_list **lst_a, t_list **lst_b, t_object object)
{
	t_list		*end_index;
	int			pos_mid_a;
	int			pos_mid_b;
	int			prize_b;
	int			prize_a;

	end_index = (*lst_b);
	while (end_index)
		end_index = end_index->next;
	pos_mid_a = lst_size(lst_b) / 2;
	pos_mid_b = lst_size(lst_b) / 2;
	while ((*lst_b))
	{
		if ((*lst_b)->index <= pos_mid_b)
			prize_b = (*lst_b)->index;
		else
			prize_b = pos_mid_b * 2 - (*lst_b)->index + 2;
		if (object.index_target <= pos_mid_a)
			prize_a = object.index_target - 1;
		else
			prize_a = pos_mid_a * 2 - object.index_target + 1;
		(*lst_b)->pp = prize_b + prize_a;
		(*lst_b) = (*lst_b)->next;
	}
}

t_object	update_obj(t_list **lst_a, t_list **lst_b)
{
	t_list		*src_node;
	t_list		*temp;
	t_object	obj;

	temp = *lst_a;
	obj.value = INT_MAX;
	obj.index_target = -1;
	src_node = (*lst_b);
	while (temp)
	{
		if (src_node->value < temp->value)
		{
			obj.value = temp->value;
			obj.index_target = temp->index;
		}
		temp = temp->next;
	}
	update_global_pool_price(lst_a, lst_b, obj);
	return (obj);
}
void pb_modified(t_list **lst_a, t_list **lst_b, int median)
{
	t_list *temp;
	int len;
	int pb_times;
	int pos_mid;

	pb_times = 0;
	len = lst_size(lst_a);
	pos_mid = len / 2;
	temp = *lst_a;
	while (pb_times < len / 2)
	{
		if ((*lst_a)->value > median)
		{
			pb(lst_a, lst_b);
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

void	algo(t_list **lst_a, t_list **lst_b)
{
	int			median;
	int			size;
	t_object	obj;

	size = lst_size(lst_a);
	median = bubblesort(*lst_a, size);
	while (size > 3)
	{
		send_smaller(lst_a, lst_b, median);
		size = lst_size(lst_a);
		median = bubblesort(*lst_a, size);
	}
	algo_3(lst_a);
	while (check_sort(*lst_a, 1) != 1)
	{
		obj = update_obj(lst_a, lst_b);
		printf("l'indice cible [%d]\n", obj.index_target);
		isworth(lst_b);
		while (obj.index_target != 1)
		{
			
		}
	}
}
