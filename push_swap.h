/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:38 by skock             #+#    #+#             */
/*   Updated: 2025/01/02 12:35:07 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft.h"
# include <stdbool.h>

typedef struct s_lst
{
	int				value;
	int				index;
	int				pp;
	int				target_value;
	int				target_index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_list;

//INSTRUCTIONS/PUSH
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
//INSTRUCTIONS/REVERSE
void	rra(t_list **lst_a, bool print);
void	rrb(t_list **lst_b, bool print);
void	rrr(t_list **lst_a, t_list **lst_b);
//INSTRUCTIONS/ROTATE
void	ra(t_list **lst_a, bool print);
void	rb(t_list **lst_b, bool print);
void	rr(t_list **lst_a, t_list **lst_b);
//INSTRUCTIONS/SWAP
void	sa(t_list *lst_a, bool print);
void	sb(t_list *lst_b, bool print);
void	ss(t_list *lst_a, t_list *lst_b);
//LIST
t_list	*lstnew(int value, int index);
t_list	search_max(t_list *lst);
t_list	search_min(t_list *lst);
int		lst_fill(t_list **lst, char **av, int start_index);
int		lst_size(t_list **lst);
void	lst_addback(t_list **lst, t_list *new_node);
void	lst_index_update(t_list **lst);
void	freelst(t_list *lst);
void	print_list(t_list *lst_a, t_list *lst_b);
//ALGORITHMS
int		bubblesort(t_list *lst, int len);
int		check_sort(t_list *lst_a, int order);
void	algo_3(t_list **lst_a);
void	algo_5(t_list **lst_a, t_list **lst_b);
void	algo(t_list **lst_a, t_list **lst_b);

#endif