/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:13:28 by skock             #+#    #+#             */
/*   Updated: 2024/12/21 05:03:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *lst_a)
{
	long	swap;

	if (!lst_a || lst_a->next == NULL)
		return ;
	swap = lst_a->value;
	lst_a->value = lst_a->next->value;
	lst_a->next->value = swap;
	ft_printf("sa\n");
}

void	ft_sb(t_list *lst_b)
{
	long	swap;

	if (!lst_b || lst_b->next == NULL)
		return ;
	swap = lst_b->value;
	lst_b->value = lst_b->next->value;
	lst_b->next->value = swap;
	ft_printf("sb\n");
}

void	ft_ss(t_list *lst_a, t_list *lst_b) // pas de ** car on modifie pas les tetes de listes.
{
	long	swap;

	if (!lst_a || lst_a->next == NULL || !lst_b || lst_b->next == NULL)
		return ;
	swap = lst_a->value;
	lst_a->value = lst_a->next->value;
	lst_a->next->value = swap;
	swap = lst_b->value;
	lst_b->value = lst_b->next->value;
	lst_b->next->value = swap;
	ft_printf("ss\n");
}

void	ft_pa(t_list **lst_a, t_list **lst_b) // ** car on modifie les tetes de listes.
{
	long	swap;
	t_list	*temp;
	t_list	*index_move;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	swap = (*lst_b)->value;
	ft_lst_addfront(lst_a, swap, 1);
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	if (*lst_b)
		(*lst_b)->prev = NULL;
	free(temp);
	index_move = *lst_b;
	while (index_move)
	{
		index_move->index -= 1;
		index_move = index_move->next;
	}
}


