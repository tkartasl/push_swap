/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:12:18 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:58 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_list
{
    int           number;
    int           index;
    struct s_list *next;
}                 stack_list;   

void    	ft_divide_stack(stack_list **astackhead, stack_list **bstackhead);
void 		ft_sort_a(stack_list **astackhead, stack_list **bstackhead);
void 		ft_sort_b(stack_list **astackhead, stack_list **bstackhead);
void 		ft_give_index(stack_list **head);
void	    ft_lstadd_back_stack(stack_list **lst, stack_list *new);
void        ft_reverse_rotate_both(stack_list **head1, stack_list **head2);
void        ft_reverse_rotate(stack_list **head);
void        ft_rotate_both(stack_list **head1, stack_list **head2);
void        ft_rotate(stack_list **head);
void        ft_swap_both(stack_list **head1, stack_list **head2);
void        ft_swap(stack_list **head);
void        ft_push(stack_list **head1, stack_list **head2);
void	    ft_lstclear_stack(stack_list **head);
long        ft_atol(const char *str);
int         ft_check_dup(stack_list **head, int number);
int	        ft_lstsize_stack(stack_list *head);
int	        ft_is_sorted_b(stack_list **head);
int	        ft_is_sorted_a(stack_list **head);
int 		ft_str_check(char **args);
stack_list	*ft_lstnew_stack(int number, int index);
stack_list 	*ft_make_stack(char **args, stack_list **head);
char    	**ft_make_array(char **argv, int argc);
char    	**ft_cpy_array(char **argv, int argc);

#endif
