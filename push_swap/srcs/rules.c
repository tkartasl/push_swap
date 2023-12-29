/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:13 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/29 14:20:36 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head, char stack)
{
	t_stack	*temp;
	t_stack	*third;

	temp = (*head);
	if (temp == 0 || temp->next == 0)
		return ;
	if (temp->next->next == 0)
		third = NULL;
	else
		third = temp->next->next;
	temp = temp->next;
	temp->next = (*head);
	temp->next->next = third;
	(*head) = temp;
	if (stack == 'a')
		ft_printf("sa\n");
	if (stack == 'b')
		ft_printf("sb\n");
}

void	ft_push(t_stack **head1, t_stack **head2, char stack)
{
	t_stack	*temp;
	t_stack	*current1;
	t_stack	*current2;

	current1 = (*head1);
	current2 = (*head2);
	if (current1 == 0)
		return ;
	temp = current2;
	current2 = current1;
	current1 = current1->next;
	current2->next = temp;
	(*head1) = current1;
	(*head2) = current2;
	if (stack == 'a')
		ft_printf("pa\n");
	if (stack == 'b')
		ft_printf("pb\n");
}

void	ft_swap_both(t_stack **head1, t_stack **head2)
{
	ft_swap(head1, 'c');
	ft_swap(head2, 'c');
	ft_printf("ss\n");
}

void	ft_rotate(t_stack **head, char stack)
{
	t_stack	*last;
	t_stack	*temp;
	t_stack	*current;

	current = (*head);
	if (current == 0 || current->next == 0)
		return ;
	temp = current->next;
	last = (*head);
	while (last->next != 0)
		last = last->next;
	last->next = current;
	(*head) = temp;
	last->next->next = NULL;
	if (stack == 'a')
		ft_printf("ra\n");
	if (stack == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_both(t_stack **head1, t_stack **head2)
{
	ft_rotate(head1, 'c');
	ft_rotate(head2, 'c');
	ft_printf("rr\n");
}
