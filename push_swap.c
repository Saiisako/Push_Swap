/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:41 by skock             #+#    #+#             */
/*   Updated: 2024/12/27 16:57:44 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sort(t_list *lst_a)
{
	t_list	*temp;

	temp = lst_a->next;
	while (lst_a->next)
	{
		if ((lst_a->value) > (temp->value))
			return ;
		lst_a = lst_a->next;
		temp = temp->next;
	}
	freelst(lst_a);
	printf("ALREADY SORT\n");
	exit(1);
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

void	print_list(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp;
	(void)lst_b;
	tmp = lst_a;
	ft_printf("liste A : \n\n");
	while (tmp)
	{
		printf("node [%d]: value = %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
	tmp = lst_b;
	ft_printf("liste B : \n\n");
	while (tmp)
	{
		printf("node [%d]: value = %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
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
		ntr = ft_split(av[1], " 	");
		if (lst_fill(&lst_a, ntr, 0) == 1)
		{
			freetab(ntr);
			return (ft_error());
		}
	}
	if (ac > 2)
		if (lst_fill(&lst_a, av, 1) == 1)
			return (ft_error());
	check_sort(lst_a);
	if (lst_size(&lst_a) == 3)
		algo_3(&lst_a);
	if (lst_size(&lst_a) == 5)
		algo_5(&lst_a, &lst_b);
	// else
	// 	algo(&lst_a, &lst_b);
	freelst(lst_a);
	freelst(lst_b);
	return (0);
}
