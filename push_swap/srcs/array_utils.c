/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:49:42 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/29 13:40:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_make_array(char **argv, int argc)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(&argv[1][0], ' ');
		if (args == 0 || ft_str_check(args) < 0)
			return (0);
	}
	else
	{
		args = ft_cpy_array(argv, argc);
		if (args == 0 || ft_str_check(args) < 0)
			return (0);
	}
	return (args);
}

char	**ft_cpy_array(char **argv, int argc)
{
	int		i;
	int		n;
	char	**array;

	array = malloc(argc * sizeof(char *));
	if (array == 0)
		return (0);
	n = 0;
	i = 1;
	while (n < (argc - 1))
	{
		array[n] = argv[i];
		n++;
		i++;
	}
	array[n] = 0;
	return (array);
}

int	ft_str_check(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i] != 0)
	{
		if (args[i][j] == '-')
			j++;
		while (args[i][j] != 0)
		{
			if (args[i][j] >= '0' && args[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		i++;
		j = 0;
	}
	return (1);
}
