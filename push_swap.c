/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:41 by skock             #+#    #+#             */
/*   Updated: 2024/12/21 05:50:18 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*tmp;
	t_list	*tmp_2;
	
	lst_a = NULL;
	lst_b = NULL;
	if (ac == 2)
		ft_lst_fill(&lst_a, ft_split(av[1], ' '), 0);
	if (ac > 2)
	{
		ft_lst_fill(&lst_a, av, 1);
		ft_lst_fill(&lst_b, av, 1); // pour les test
	} 
	
	/////////////////////////////////////////////////////////
	tmp = lst_a;
	ft_pa(&lst_a, &lst_b);
	printf("liste A : \n\n");
	while (tmp)
	{
		printf("node [%d]: value = %ld\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
	
	
	tmp_2 = lst_b;
	printf("\nliste B :\n\n");
	while (tmp_2)
	{
		printf("node [%d]: value = %ld\n", tmp_2->index, tmp_2->value);
		tmp_2 = tmp_2->next;
	}
	return (0);
	///////////////////////////////////////////////////////////
}