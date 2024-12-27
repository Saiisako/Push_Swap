/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:32:15 by skock             #+#    #+#             */
/*   Updated: 2024/12/26 11:10:54 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **lst_a, bool print)
{
	int		swap;
	t_list	*temp;

	if (!*lst_a || (*lst_a)->next == NULL)
		return ;
	temp = *lst_a;
	swap = (*lst_a)->value;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = swap;
	if (print == true)
		ft_printf("ra\n");
}

void	rb(t_list **lst_b, bool print)
{
	int		swap;
	t_list	*temp;

	if (!*lst_b || (*lst_b)->next == NULL)
		return ;
	temp = *lst_b;
	swap = (*lst_b)->value;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = swap;
	if (print == true)
		ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, false);
	rb(lst_b, false);
	ft_printf("rr\n");
}
