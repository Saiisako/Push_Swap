/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:13:28 by skock             #+#    #+#             */
/*   Updated: 2024/12/26 11:33:37 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list *lst_a, bool print)
{
	int	swap;

	if (!lst_a || lst_a->next == NULL)
		return ;
	swap = lst_a->value;
	lst_a->value = lst_a->next->value;
	lst_a->next->value = swap;
	if (print == true)
		ft_printf("sa\n");
}

void	sb(t_list *lst_b, bool print)
{
	int	swap;

	if (!lst_b || lst_b->next == NULL)
		return ;
	swap = lst_b->value;
	lst_b->value = lst_b->next->value;
	lst_b->next->value = swap;
	if (print == true)
		ft_printf("sb\n");
}

void	ss(t_list *lst_a, t_list *lst_b)
{
	sa(lst_a, false);
	sb(lst_b, false);
	ft_printf("ss\n");
}
