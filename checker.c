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

void	print_list(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp;

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

int	check_sort(t_list *lst_a, int order)
{
	t_list	*temp;

	temp = lst_a->next;
	while (lst_a->next)
	{
		if (lst_a->value > temp->value)
		{
			printf("KO\n");
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
int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

static void	checker_recup_arguments(t_list **lst_a, t_list **lst_b)
{
	char *gnl = get_next_line(0);
	if (ft_strcmp(gnl, "sa\n") == 0)
		sa(*lst_a, false);
	else if (ft_strcmp(gnl, "sb\n") == 0)
		sb(*lst_b, false);
	else if (ft_strcmp(gnl, "ss\n") == 0)
		ss(*lst_a, *lst_b, false);
	else if (ft_strcmp(gnl, "pa\n") == 0)
		pa(lst_a, false);
	else if (ft_strcmp(gnl, "pb\n") == 0)
		pb(lst_b, false);
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
		ft_error();
	free(gnl);
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
	while (1)
	{
		checker_recup_arguments(&lst_a, &lst_b);
		if (get_next_line(0) == NULL)
			break ;
	}
	check_sort(lst_a, 2);
	freelst(lst_a);
	freelst(lst_b);
}

