/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:41 by skock             #+#    #+#             */
/*   Updated: 2025/01/04 18:19:37 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_all(t_list **lst_a, t_list **lst_b)
{
	check_sort(*lst_a, 0);
	if (lst_size(lst_a) == 3)
		algo_3(lst_a);
	else if (lst_size(lst_a) == 5)
		algo_5(lst_a, lst_b);
	else
		algo(lst_a, lst_b);
}

int	check_sort(t_list *lst_a, int order)
{
	t_list	*temp;
	t_list	*free;

	free = lst_a;
	temp = lst_a->next;
	while (lst_a->next)
	{
		if (lst_a->value > temp->value)
			return (0);
		lst_a = lst_a->next;
		temp = temp->next;
	}
	if (order == 0)
	{
		freelst(free);
		freelst(lst_a);
		exit(1);
	}
	if (order == 1)
		return (1);
	return (0);
}

int	lst_size(t_list **lst)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = *lst;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**ntr;

	lst_a = NULL;
	lst_b = NULL;

	if (ac == 2)
	{
		ntr = ft_split(av[1], ' ');
		if (lst_fill(&lst_a, ntr, 0) == 1)
		{
			freetab(ntr);
			return (ft_error());
		}
	}
	if (ac > 2)
		if (lst_fill(&lst_a, av, 1) == 1)
			return (ft_error());
	algo_all(&lst_a, &lst_b);
	freelst(lst_a);
	freelst(lst_b);
}
