/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/29 14:32:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args;
	t_stack	*astackhead;
	t_stack	*bstackhead;

	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
		return (0);
	args = ft_make_array(argv, argc);
	if (args == 0)
		return (0);
	ft_make_stack(args, &astackhead);
	if (astackhead == 0)
	{
		ft_printf("Error\n");
		free (args);
		ft_lstclear_stack(&astackhead);
		return (0);
	}
	free (args);
	if (ft_is_sorted_a(&astackhead) == 0)
	{
		ft_lstclear_stack(&astackhead);
		return (0);
	}
	ft_divide_stack(&astackhead, &bstackhead);
	return (0);
}

void	ft_divide_stack(t_stack **astackhead, t_stack **bstackhead)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize_stack(*astackhead);
	while (i < size && ft_is_sorted_a(astackhead) != 0)
	{
		if ((*astackhead)->index > (size / 2))
			ft_rotate(astackhead, 'a');
		else
		{
			if ((*astackhead)->index > (size / 2) - (size / 4))
				ft_push(astackhead, bstackhead, 'b');
			else
			{
				ft_push(astackhead, bstackhead, 'b');
				ft_rotate(bstackhead, 'b');
			}
		}
		i++;
	}
	ft_sort_a(astackhead, bstackhead);
	ft_sort_b(astackhead, bstackhead);
}

void	ft_sort_a(t_stack **astackhead, t_stack **bstackhead)
{
	int		bsize;
	t_stack	*second;

	second = (*astackhead)->next;
	bsize = ft_lstsize_stack(*bstackhead);
	while (ft_is_sorted_a(astackhead) == 1)
	{
		if ((*astackhead)->index == (bsize + 1))
		{
			ft_push(astackhead, bstackhead, 'b');
			bsize++;
		}
		else if ((*astackhead)->index > second->index)
			ft_swap(astackhead, 'a');
		else
			ft_rotate(astackhead, 'a');
		if (*astackhead != 0)
			second = (*astackhead)->next;
	}
	if (*bstackhead == 0)
	{
		ft_lstclear_stack(astackhead);
		exit (0);
	}
}

void	ft_sort_b(t_stack **astackhead, t_stack **bstackhead)
{
	int		size;
	t_stack	*second;

	second = (*bstackhead)->next;
	size = ft_lstsize_stack(*bstackhead);
	while ((*bstackhead) != 0)
	{
		if ((*bstackhead)->index == size)
		{
			ft_push(bstackhead, astackhead, 'a');
			size--;
		}
		else if ((*bstackhead)->index < second->index)
			ft_swap(bstackhead, 'b');
		else
			ft_rotate(bstackhead, 'b');
		if (*bstackhead != 0)
			second = (*bstackhead)->next;
	}
	ft_lstclear_stack(astackhead);
	exit (0);
}
