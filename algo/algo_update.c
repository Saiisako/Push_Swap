/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:33:14 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 18:44:42 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_target_index(t_list *min_node, t_list *lst_a, bool rra, bool ra)
{
	int	len;

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
	int	len;

	len = lst_size(&lst_b);
	if (ra == true)
		min_node->index--;
	if (rra == true && min_node->index == len)
		min_node->index = 1;
	else if (rra == true)
		min_node->index++;
}
