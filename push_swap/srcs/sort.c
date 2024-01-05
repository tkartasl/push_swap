/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:05:26 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/05 13:51:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **astackhead)
{
	t_stack	*last;
	t_stack	*second;

	second = (*astackhead)->next;
	last = ft_lstlast_stack(astackhead);
	while (ft_is_sorted_a(astackhead) == 1)
	{
		if (last->index > (*astackhead)->index)
		{
			ft_swap(astackhead, 'a');
			last = ft_lstlast_stack(astackhead);
		}
		else if ((*astackhead)->index < second->index)
			ft_reverse_rotate(astackhead, 'a');
		else
			ft_rotate(astackhead, 'a');
		last = ft_lstlast_stack(astackhead);
		second = (*astackhead)->next;
	}
	ft_lstclear_stack(astackhead);
	exit (0);
}

void	ft_sort_mid(t_stack **astackhead, t_stack **bstackhead)
{
	int		sizeb;

	sizeb = 0;
	while (ft_is_sorted_a(astackhead) == 1)
	{
		sizeb = ft_lstsize_stack(*bstackhead);
		if ((*astackhead)->index > (*astackhead)->next->index)
			ft_swap(astackhead, 'a');
		if (ft_find_smallest(astackhead, sizeb) == 0)
		{
			while ((*astackhead)->index != sizeb + 1)
				ft_rotate(astackhead, 'a');
			ft_push(astackhead, bstackhead, 'b');
		}
		else
		{
			while ((*astackhead)->index != sizeb + 1)
				ft_reverse_rotate(astackhead, 'a');
			ft_push(astackhead, bstackhead, 'b');
		}
	}
	while ((*bstackhead) != 0)
		ft_push(bstackhead, astackhead, 'a');
	ft_lstclear_stack(astackhead);
	exit (0);
}

void	ft_sort_big_a(t_stack **heada, t_stack **headb, int i)
{
	if ((((*heada)->index >> i) & 1) == 0)
		ft_push(heada, headb, 'b');
	else
		ft_rotate(heada, 'a');
}

void	ft_sort_big_b(t_stack **heada, t_stack **headb, int i)
{
	if ((((*headb)->index >> i) & 1) == 0 && ft_is_sorted_a(heada) == 1)
		ft_rotate(headb, 'b');
	else
		ft_push(headb, heada, 'a');
}

void	ft_sort_big(t_stack **heada, t_stack **headb)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (ft_is_sorted_a(heada) == 1 || (*headb) != 0)
	{
		size = ft_lstsize_stack(*heada);
		while (size > 0 && ft_is_sorted_a(heada) == 1)
		{
			ft_sort_big_a(heada, headb, i);
			size--;
		}
		i++;
		size = ft_lstsize_stack(*headb);
		while (size > 0)
		{
			ft_sort_big_b(heada, headb, i);
			size--;
		}
	}
	ft_lstclear_stack(heada);
	exit (0);
}
