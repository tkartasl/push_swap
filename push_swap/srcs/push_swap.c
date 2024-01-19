/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/19 09:34:30 by tkartasl         ###   ########.fr       */
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
	ft_get_stack(args, &astackhead, &bstackhead, argc);
	return (0);
}

static void	ft_free(char **arr)
{
	int	n;

	n = 0;
	while (arr[n] != 0)
	{
		free(arr[n]);
		n++;
	}
	free(arr);
}

void	ft_get_stack(char **args, t_stack **heada, t_stack **headb, int argc)
{
	int	i;

	i = ft_make_stack(args, heada);
	if (i == 1)
	{
		write(2, "Error\n", 6);
		free (args);
		ft_lstclear_stack(heada);
		exit (0);
	}
	if (argc == 2)
		ft_free(args);
	else
		free (args);
	if (ft_is_sorted_a(heada) == 0)
	{
		ft_lstclear_stack(heada);
		exit (0);
	}
	if (ft_lstsize_stack(*heada) <= 3)
		ft_sort_three(heada);
	if (ft_lstsize_stack(*heada) <= 50)
		ft_sort_mid(heada, headb);
	else
		ft_sort_big(heada, headb);
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
		return (1);
}
