/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:48:29 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/20 17:40:57 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_list	*ft_lstnew_stack(int number, int index)
{
	stack_list	*new;

	new = NULL;
	new = (stack_list *)malloc(sizeof(stack_list));
	if (new == 0)
		return (0);
	new->number = number;
    new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_stack(stack_list **lst, stack_list *new)
{
	stack_list	*current;
	stack_list	*last;

	last = NULL;
	if (!lst || !new)
		return ;
	if ((*lst) == 0)
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current != 0)
	{
		last = current;
		current = current->next;
	}
	last->next = new;
}