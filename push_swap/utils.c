/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:27:38 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/21 16:11:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long    ft_atol(const char *str)
{
	int		neg;
	long	temp;

	temp = 0;
	neg = 1;
	while (*str != 0 && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		if (temp + (*str - 48) > (LONG_MAX / 10) && neg == -1)
			return (0);
		temp = temp * 10 + (*str - 48);
		str++;
	}
	if (temp == (LONG_MIN + 1))
		return (-1);
	return (temp * neg);
}

void	ft_lstclear_stack(stack_list **head)
{
	t_list	*temp;
	t_list	*current;

	if (!head)
		return ;
	current = *head;
	temp = NULL;
	while (current != 0)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}

void	ft_is_sorted(stack_list **head)
{
	stack_list	*current;
	stack_list	*second;

	current = (*head);
	second = current->next;
	while (current != 0)
	{
		while (second != 0)
		{
			if (current->index > second->index)
				return ;
			second = second->next;
		}
		current = current->next;
		second = current->next;
	}
	exit (0);	
}