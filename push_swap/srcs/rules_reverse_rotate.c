/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/19 09:34:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **head, char stack)
{
	t_stack	*last;
	t_stack	*prev_last;
	t_stack	*current;

	current = (*head);
	if (current == 0 || current->next == 0)
		return ;
	prev_last = NULL;
	last = (*head);
	while (last->next != 0)
	{
		prev_last = last;
		last = last->next;
	}
	current = last;
	current->next = (*head);
	(*head) = current;
	prev_last->next = NULL;
	if (stack == 'a')
		ft_printf("rra\n");
	if (stack == 'b')
		ft_printf("rrb\n");
}

void	ft_reverse_rotate_both(t_stack **head1, t_stack **head2)
{
	ft_reverse_rotate(head1, 'c');
	ft_reverse_rotate(head2, 'c');
	ft_printf("rrr\n");
}
