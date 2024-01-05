/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:24 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/05 13:36:50 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_make_stack(char **args, t_stack **head)
{
	t_stack	*new;
	int		number;
	int		i;
	long	l;

	*head = NULL;
	l = 0;
	i = 0;
	number = 0;
	new = NULL;
	while (args[i] != 0)
	{
		number = ft_atoi(&args[i][0]);
		l = ft_atol(&args[i][0]);
		if (number != l || ft_check_dup(head, number) == 1)
			return (1);
		new = ft_lstnew_stack(number, 1);
		if (new == 0)
			return (1);
		ft_lstadd_back_stack(head, new);
		i++;
	}
	ft_give_index(head);
	return (0);
}

void	ft_give_index(t_stack **head)
{
	t_stack	*current;
	t_stack	*temp;

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

t_stack	*ft_lstnew_stack(int number, int index)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == 0)
		return (0);
	new->number = number;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*current;
	t_stack	*last;

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

int	ft_check_dup(t_stack **head, int number)
{
	t_stack	*current;

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
