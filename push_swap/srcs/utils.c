/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:27:38 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/29 13:54:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atol(const char *str)
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

void	ft_lstclear_stack(t_stack **head)
{
	t_stack	*temp;
	t_stack	*current;

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

int	ft_is_sorted_a(t_stack **head)
{
	t_stack	*current;
	t_stack	*second;

	current = (*head);
	second = current->next;
	while (second != 0)
	{
		if (current->index > second->index)
			return (1);
		current = current->next;
		second = current->next;
	}
	return (0);
}

int	ft_lstsize_stack(t_stack *head)
{
	int		count;
	t_stack	*current;

	current = head;
	count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
