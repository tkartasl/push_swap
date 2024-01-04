/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/04 15:35:38 by tkartasl         ###   ########.fr       */
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
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_get_stack(args, &astackhead, &bstackhead);
	return (0);
}

void	ft_get_stack(char** args, t_stack **astackhead , t_stack **bstackhead)
{
	int i;

	i = ft_make_stack(args, astackhead);
	if (i == 1)
	{
		write(2, "Error\n", 6);
		free (args);
		ft_lstclear_stack(astackhead);
		exit (0);
	}
	free (args);
	if (ft_is_sorted_a(astackhead) == 0)
	{
		ft_lstclear_stack(astackhead);
		exit (0);
	}
	if (ft_lstsize_stack(*astackhead) <= 3)
		ft_sort_three(astackhead);
	if (ft_lstsize_stack(*astackhead) <= 50)
		ft_sort_mid(astackhead, bstackhead);
	else		
		ft_divide_stack(astackhead, bstackhead);

}

void	ft_divide_stack(t_stack **astackhead, t_stack **bstackhead)
{
	int	size;
	int	i;

	i = 2;
	size = ft_lstsize_stack(*astackhead);
	while (ft_is_sorted_a(astackhead) == 1 && (*bstackhead) == 0)
	{
		
		while ((*astackhead) != 0)
		{
			if ((*astackhead)->index > (*astackhead)->next->index)
				ft_swap(astackhead, 'a');
			if ((*astackhead)->index >= size / i)
				ft_push(astackhead, bstackhead, 'b');
			else
			{
				ft_push(astackhead, bstackhead, 'b');
				ft_rotate(bstackhead, 'b');
			}	
		}
		i = i + 1;
		while ((*bstackhead) != 0)
		{
			if ((*bstackhead)->index < (*bstackhead)->next->index)
				ft_swap(bstackhead, 'b');
			if ((*bstackhead)->index <= size / i)
				ft_push(bstackhead, astackhead, 'a');
			else
			{
				ft_push(bstackhead, astackhead, 'a');
				ft_rotate(astackhead, 'a');
			}	
		}
		i = i + 1;
	}
	ft_lstclear_stack(astackhead);
	exit (0);
}
