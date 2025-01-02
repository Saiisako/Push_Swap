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
			return (0);
		lst_a = lst_a->next;
		temp = temp->next;
	}
	if (order == 0)
	{
		freelst(lst_a);
		exit(1);
	}
	if (order == 1)
		return (1);
	if (order == 2)
	{
		freelst(lst_a);
		ft_printf("OK\n");
		exit(1);
	}
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	checker_recup_arguments(t_list **lst_a, t_list **lst_b, char *temp)
{
	read(0, temp, 4);
	if (ft_strncmp(temp, "sa", 2) == 0)
		sa(*lst_a, false);
	else if (ft_strncmp(temp, "sb", 2) == 0)
		sb(*lst_b, false);
	else if (ft_strncmp(temp, "ss", 2) == 0)
		ss(*lst_a, *lst_b);
	else if (ft_strncmp(temp, "pa", 2) == 0)
		pa(lst_a, false);
	else if (ft_strncmp(temp, "pb", 2) == 0)
		pb(lst_b, false);
	else if (ft_strncmp(temp, "ra", 2) == 0)
		ra(lst_a, false);
	else if (ft_strncmp(temp, "rb", 2) == 0)
		rb(lst_b, false);
	else if (ft_strncmp(temp, "rr", 2) == 0)
		rr(lst_a, lst_b);
	else if (ft_strncmp(temp, "rra", 3) == 0)
		rra(lst_a, false);
	else if (ft_strncmp(temp, "rrb", 3) == 0)
		rrb(lst_b, false);
	else if (ft_strncmp(temp, "rrr", 3) == 0)
		rrr(lst_a, lst_b);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**ntr;
	char	temp[4];

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
	while (1)
	{
		checker_recup_arguments(&lst_a, &lst_b, temp);
		if (check_sort(lst_a, 2) == 1)
			break ;
	}
	freelst(lst_a);
	freelst(lst_b);
}