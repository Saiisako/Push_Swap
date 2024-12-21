/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:03:09 by skock             #+#    #+#             */
/*   Updated: 2024/12/21 05:35:27 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_addfront(t_list **lst, long value, int index)
{
	t_list	*new_node;
	t_list	*temp;
	
	new_node = ft_lstnew(value, index);
	if (!new_node)
		return ;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp)
		{
			temp->index = index + 1;
			temp = temp->next;
		}
		new_node->next = *lst;
		(*lst)->prev = new_node;
		*lst = new_node;
	}
}

int	ft_has_duplicates(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		while (temp)
		{
			if (temp->value == lst->value)
				return (ft_error(), 1);
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_lstnew(long value, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lst_addback(t_list **lst, t_list *new_node)
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

void	ft_lst_fill(t_list **lst, char **av, int start_index)
{
	int	i;

	i = start_index;
	while (av[i])
	{
		ft_lst_addback(lst, ft_lstnew(ft_atoi(av[i]), i));
		i++;
	}
	ft_has_duplicates(*lst);
}
