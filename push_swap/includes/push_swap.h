/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:12:18 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/19 09:35:32 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	ft_give_index(t_stack **head);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void	ft_reverse_rotate_both(t_stack **head1, t_stack **head2);
void	ft_reverse_rotate(t_stack **head, char stack);
void	ft_rotate_both(t_stack **head1, t_stack **head2);
void	ft_rotate(t_stack **head, char stack);
void	ft_swap_both(t_stack **head1, t_stack **head2);
void	ft_swap(t_stack **head, char stack);
void	ft_push(t_stack **head1, t_stack **head2, char stack);
void	ft_get_stack(char **args, t_stack **heada, t_stack **headb, int argc);
void	ft_sort_three(t_stack **astackhead);
void	ft_sort_mid(t_stack **astackhead, t_stack **bstackhead);
void	ft_sort_big(t_stack **astackhead, t_stack **bstackhead);
void	ft_sort_big_a(t_stack **heada, t_stack **headb, int i);
void	ft_sort_big_b(t_stack **heada, t_stack **headb, int i);
void	ft_lstclear_stack(t_stack **head);
long	ft_atol(const char *str);
int		ft_find_smallest(t_stack **astackhead, int sizeb);
int		ft_check_dup(t_stack **head, int number);
int		ft_lstsize_stack(t_stack *head);
int		ft_is_sorted_a(t_stack **head);
int		ft_str_check(char **args);
t_stack	*ft_lstnew_stack(int number, int index);
t_stack	*ft_lstlast_stack(t_stack **lst);
int		ft_make_stack(char **args, t_stack **head);
char	**ft_make_array(char **argv, int argc);
char	**ft_cpy_array(char **argv, int argc);

#endif
