/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:22:12 by skock             #+#    #+#             */
/*   Updated: 2024/12/27 11:00:07 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_b)
		return ;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	if (*lst_b)
		(*lst_b)->prev = NULL;
	temp->next = *lst_a;
	*lst_a = temp;
	lst_index_update(lst_a);
	lst_index_update(lst_b);
	ft_printf("pa\n");
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_a)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	if (*lst_a)
		(*lst_a)->prev = NULL;
	temp->next = *lst_b;
	*lst_b = temp;
	if (lst_size(lst_b) > 1)
		(*lst_b)->next->prev = *lst_b;
	lst_index_update(lst_a);
	lst_index_update(lst_b);
	ft_printf("pb\n");
}
