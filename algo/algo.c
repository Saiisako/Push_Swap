/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:38:23 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 16:59:32 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_lst_b_empty(t_list *lst_b)
{
	if (lst_b == NULL)
		return 1;  // La liste est vide
	return 0;      // La liste contient au moins un élément
}

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
			prize_a = pos_mid_a * 2 - temp->target_index  + 1;
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

void	update_target_index(t_list *min_node, t_list *lst_a, bool rra, bool ra)
{
	int len;

	len = lst_size(&lst_a);
	if (ra == true)
		min_node->target_index--;
	if (rra == true && min_node->target_index == len)
		min_node->target_index = 1;
	else if (rra == true)
		min_node->target_index++;
}

void	update_min_index(t_list *min_node, t_list *lst_b, bool rra, bool ra)
{
	int len;

	len = lst_size(&lst_b);
	if (ra == true)
		min_node->index--;
	if (rra == true && min_node->index == len)
		min_node->index = 1;
	else if (rra == true)
		min_node->index++;
}

void	algo(t_list **lst_a, t_list **lst_b)
{
	int			median;
	int			size;
	t_list		*min_node;

	size = lst_size(lst_a);
	median = bubblesort(*lst_a, size);
	while (size > 3)
	{
		send_smaller(lst_a, lst_b, median);
		size = lst_size(lst_a);
		median = bubblesort(*lst_a, size);
	}
	algo_3(lst_a);
	// print_list(*lst_a, *lst_b);
	while (1)
	{
		update_obj(lst_a, lst_b);
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
		if (is_lst_b_empty(*lst_b) == 1)
		{
			while (check_sort(*lst_a, 1) != 1)
				rra(lst_a, true);
			break ;
		}
	}
}
