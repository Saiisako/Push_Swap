/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:41 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 14:37:17 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_list *lst_a, int order)
{
    t_list *temp;

    temp = lst_a->next;  // initialisation de temp correctement
    while (lst_a->next)  // tant que lst_a->next existe
    {
        if (lst_a->value > temp->value)
            return (0);  // si l'ordre est brisé, retourne 0
        lst_a = lst_a->next;
        temp = temp->next;  // déplace temp au même rythme que lst_a
    }

    // vérification de l'ordre
    if (order == 0) 
	{
        freelst(lst_a);  // attention, lst_a est modifié, cela pourrait causer un problème
        exit(1);
    }

    if (order == 1)
        return (1);  // liste triée dans l'ordre croissant
    return (0);  // en cas de problème, retourne 0
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
	check_sort(lst_a, 0);
	if (lst_size(&lst_a) == 3)
		algo_3(&lst_a);
	else if (lst_size(&lst_a) == 5)
		algo_5(&lst_a, &lst_b);
	else
		algo(&lst_a, &lst_b);
	freelst(lst_a);
	freelst(lst_b);
	return (0);
}
