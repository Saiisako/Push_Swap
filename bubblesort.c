/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:14:41 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 18:39:19 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bubblesort_algo(int *tab, int len)
{
	int		i;
	bool	swapped;
	int		temp;
	int		j;

	j = 0;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		i = 0;
		while (i < len - j - 1)
		{
			if (tab[i] > tab[i + 1] && i < len)
			{
				swapped = true;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	return (tab);
}

int	bubblesort(t_list *lst, int len)
{
	int		*tab;
	int		i;
	t_list	*temp;
	int		median;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	temp = lst;
	i = 0;
	while (temp)
	{
		tab[i] = temp->value;
		temp = temp->next;
		i++;
	}
	i = 0;
	tab = bubblesort_algo(tab, len);
	median = tab[len / 2 - 1];
	free(tab);
	return (median);
}
