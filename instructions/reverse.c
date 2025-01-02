/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:34:40 by skock             #+#    #+#             */
/*   Updated: 2024/12/26 11:04:28 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **lst_a, bool print)
{
	t_list	*node;
	t_list	*temp;

	if (!*lst_a || (*lst_a)->next == NULL)
		return ;
	temp = *lst_a;
	while (temp->next)
	{
		if (!temp->next->next)
			node = temp;
		temp = temp->next;
	}
	node->next = NULL;
	temp->next = *lst_a;
	(*lst_a)->prev = temp;
	(*lst_a) = temp;
	if (print == true)
		ft_printf("rra\n");
}

void	rrb(t_list **lst_b, bool print)
{
	t_list	*temp;
	t_list	*node;

	if (!*lst_b || (*lst_b)->next == NULL)
		return ;
	temp = *lst_b;
	while (temp->next)
	{
		if (!temp->next->next)
			node = temp;
		temp = temp->next;
	}
	node->next = NULL;
	temp->next = *lst_b;
	(*lst_b)->prev = temp;
	(*lst_b) = temp;
	if (print == true)
		ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, false);
	rrb(lst_b, false);
	ft_printf("rrr\n");
}
