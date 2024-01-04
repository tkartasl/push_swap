/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:05:26 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/04 12:39:34 by tkartasl         ###   ########.fr       */
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

int	ft_find_smallest(t_stack **astackhead, int sizeb)
{
	int		i;
	int		size;
	t_stack	*current;
	
	i = 0;
	size = ft_lstsize_stack(*astackhead);
	current = (*astackhead);
	while (current->index != sizeb + 1)
	{
		current = current->next;
		i++;	
	}
	if (i <= size / 2)
		return (0);
	else
		return(1);	
}

void	ft_sort_mid(t_stack **astackhead, t_stack **bstackhead)
{
	int		sizeb;

	sizeb = 0;
	while (ft_is_sorted_a(astackhead) == 1)
	{
		sizeb = ft_lstsize_stack(*bstackhead);
		if((*astackhead)->index > (*astackhead)->next->index)
			ft_swap(astackhead, 'a');
		if(ft_find_smallest(astackhead, sizeb) == 0)
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

/*int	ft_get_pivot(t_stack **head)
{
	int		i;
	t_stack	*current;
	
	i = 0;
	while (i < 6)
	{
		current = current->next;	
		i++;
	}
	return (current->index);
}

void	ft_sort_big(t_stack **heada, t_stack **headb)
{
	int		pivot;
	t_stack	*current;
	t_stack	*second;

	while (ft_is_sorted_a(heada) == 1)
	{	
		current = *heada;
		second = *heada;
		while (ft_lstsize_stack(*heada) > 6 && ft_is_sorted_a(heada) == 1)
		{
			pivot = ft_get_pivot(heada);
			if (current->next->index < current->index)
				ft_swap(heada, 'a');
			second = second->next->next;
			if (second->index < pivot)
				current = current->next;
			if (current->index > second->index)
			{	
				ft_rotate(heada, 'a');
				ft_swap(heada, 'a');
			}		
		}
	
	}
}*/