/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:02:29 by marvin            #+#    #+#             */
/*   Updated: 2025/01/02 21:02:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *lst_a, int order)
{
	t_list	*temp;

	temp = lst_a->next;
	while (lst_a->next)
	{
		if (lst_a->value > temp->value)
		{
			ft_printf("KO\n");
			return (0);
		}
		lst_a = lst_a->next;
		temp = temp->next;
	}
	if (order == 1)
		return (1);
	if (order == 2)
		ft_printf("OK\n");
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

static void	checker_recup_arguments(t_list **lst_a, t_list **lst_b, char *gnl)
{
	if (ft_strcmp(gnl, "sa\n") == 0)
		sa(*lst_a, false);
	else if (ft_strcmp(gnl, "sb\n") == 0)
		sb(*lst_b, false);
	else if (ft_strcmp(gnl, "ss\n") == 0)
		ss(*lst_a, *lst_b, false);
	else if (ft_strcmp(gnl, "pa\n") == 0)
		pa(lst_a, lst_b, false);
	else if (ft_strcmp(gnl, "pb\n") == 0)
		pb(lst_a, lst_b, false);
	else if (ft_strcmp(gnl, "rra\n") == 0)
		rra(lst_a, false);
	else if (ft_strcmp(gnl, "rrb\n") == 0)
		rrb(lst_b, false);
	else if (ft_strcmp(gnl, "rrr\n") == 0)
		rrr(lst_a, lst_b, false);
	else if (ft_strcmp(gnl, "ra\n") == 0)
		ra(lst_a, false);
	else if (ft_strcmp(gnl, "rb\n") == 0)
		rb(lst_b, false);
	else if (ft_strcmp(gnl, "rr\n") == 0)
		rr(lst_a, lst_b, false);
	else
		free_lst_gnl_error(lst_a, lst_b, gnl);
}

void	check(t_list **lst_a, t_list **lst_b, char *gnl)
{
	if (lst_size(lst_a) == 1)
	{
		freelst(*lst_a);
		exit(1);
	}
	while (1)
	{
		gnl = get_next_line(0);
		if (!gnl)
		{
			free(gnl);
			break ;
		}
		checker_recup_arguments(lst_a, lst_b, gnl);
		free(gnl);
	}
	check_sort(*lst_a, 2);
	freelst(*lst_a);
	freelst(*lst_b);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**ntr;
	char	*gnl;

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
		freetab(ntr);
	}
	if (ac > 2)
		if (lst_fill(&lst_a, av, 1) == 1)
			return (ft_error());
	if (!lst_a)
		return (0);
	gnl = NULL;
	check(&lst_a, &lst_b, gnl);
}
