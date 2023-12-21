/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/21 16:11:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include "libft.h"

int main (int argc, char *argv[])
{
    char        **args;
    stack_list  *astackhead;
    stack_list  *bstackhead;

    if (argc == 1 || (argc == 2 && argv[1][0] == 0))
        return (0);
    args = ft_make_array(argv, argc);
    if (args == 0)
        return (0);
    astackhead = ft_make_stack(args, &astackhead);
    if (astackhead == 0)
    {
        ft_printf("Error\n");
        free (args);
        ft_lstclear_stack(&astackhead);
        return (0);
    }
    free (args);

    return (0);
}

