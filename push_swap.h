/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:38 by skock             #+#    #+#             */
/*   Updated: 2024/12/21 04:00:03 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft.h"

typedef struct s_lst
{
	long			value;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_list;

t_list	*ft_lstnew(long value, int index);
void	ft_lst_addfront(t_list **lst, long value, int index);
void	ft_lst_addback(t_list **lst, t_list *new_node);
void	ft_lst_fill(t_list **lst, char **av, int start_index);
void	ft_sa(t_list *lst_a);
void	ft_sb(t_list *lst_b);
void	ft_ss(t_list *lst_a, t_list *lst_b);
void	ft_pa(t_list **lst_a, t_list **lst_b);


#endif