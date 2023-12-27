/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:24 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/27 16:43:22 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_list *ft_make_stack(char **args, stack_list **head)
{
    stack_list  *new;
    int         number;
    int         i;
    long        l;

    l = 0;
    i = 0;
    number = 0;
    new = NULL;
    while (args[i] != 0)
    {
        number = ft_atoi(&args[i][0]);
        l = ft_atol(&args[i][0]);       
        if (number != l || ft_check_dup(&head, number) == 1)
            return (0);
        new = ft_lstnew_stack(number, 1);
        if (new == 0)
            return (0); 
        ft_lstadd_back_stack(&head, new);
        i++;
    }
    ft_give_index(&head);
    return (head);
}

void ft_give_index(stack_list **head) 
{
    stack_list  *current;
    stack_list  *temp;

    current = (*head);
    temp = current->next;
    while (current->next != NULL)
    {
        while (temp != NULL)
        {
          if (current->number > temp->number)
              current->index = current->index + 1;
          if (current->number < temp->number)
              temp->index = temp->index + 1;
          temp = temp->next;    
        }
        current = current->next;
        temp = current->next;
    }
} 

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

int ft_check_dup(stack_list **head, int number)
{
    stack_list  *current;

    current = (*head);
    if (current == 0)
        return (0);
    while (current != 0)
    {
        if (current->number == number)
            return (1);
        current = current->next;
    }
    return (0);
}