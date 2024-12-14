/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:38 by skock             #+#    #+#             */
/*   Updated: 2024/12/14 14:36:41 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft.h"

typedef struct		s_lst
{
	int				value;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;


int		ft_limits(char **argv);
int		ft_has_duplicates(char **av);

// void	ft_lstadd_back(t_lst **lst, t_lst *new);
// t_lst	*ft_lstnew();

#endif
