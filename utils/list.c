/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:04 by skock             #+#    #+#             */
/*   Updated: 2025/01/04 11:33:42 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_index_update(t_list **lst)
{
	t_list	*temp;
	int		update;

	update = 1;
	temp = *lst;
	while (temp)
	{
		temp->index = update;
		temp = temp->next;
		update++;
	}
}

int	has_duplicates(t_list *lst)
{
	t_list	*temp;
	t_list	*free;

	free = lst;
	while (lst)
	{
		temp = lst->next;
		while (temp)
		{
			if (temp->value == lst->value)
			{
				freelst(free);
				return (1);
			}
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*lstnew(int value, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->pp = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_addback(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (!new_node)
		return ;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

int	lst_fill(t_list **lst, char **av, int start_index)
{
	int		i;
	long	value;

	i = start_index;
	while (av[i])
	{
		value = ft_atoi(*lst, av[i]);
		if (value == ERROR)
			return (1);
		lst_addback(lst, lstnew(value, i));
		i++;
	}
	if (has_duplicates(*lst) == 1)
		return (1);
	return (0);
}
