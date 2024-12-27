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
	int		swap;
	t_list	*temp;

	if (!*lst_a || (*lst_a)->next == NULL)
		return ;
	temp = *lst_a;
	while (temp->next)
		temp = temp->next;
	swap = temp->value;
	while (temp->prev)
	{
		temp->value = temp->prev->value;
		temp = temp->prev;
	}
	temp->value = swap;
	if (print == true)
		ft_printf("rra\n");
}

void	rrb(t_list **lst_b, bool print)
{
	int		swap;
	t_list	*temp;

	if (!*lst_b || (*lst_b)->next == NULL)
		return ;
	temp = *lst_b;
	while (temp->next)
		temp = temp->next;
	swap = temp->value;
	while (temp->prev)
	{
		temp->value = temp->prev->value;
		temp = temp->prev;
	}
	temp->value = swap;
	if (print == true)
		ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, false);
	rrb(lst_b, false);
	ft_printf("rrr\n");
}
