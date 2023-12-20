/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/20 11:45:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include "libft.h"

int main (int argc, char *argv[])
{
    char    **args;

    if (argc = 1 || argc == 2 && !argv[1][0])
        return (0);
    if (argc == 2)
    {   
        args = ft_split(&argv[1], ' ');
        if (ft_str_check(args) < 0)
        {
            free(args);
            ft_printf("Error\n");
            return (0);
        }
    }
    else    
    {
        args = &argv[1];
        if (ft_str_check(args) < 0)
        {
                ft_printf("Error\n");
                return (0);
        }
    }
    ft_create_stack(args)
    return (0);
}

int ft_str_check(char **args)
{
    int i;
    int j;

    i = 0:
    j = 0:
    while (*args[i] != 0)
    {
        if (args[i][j] == '-')
                j++;
        while (args[i][j] != 0)
        {
            if (ft_isdigit(&args[i][j] == 1))
                j++;
            if (ft_isdigit(&args[i][j] == 0))
                return (-1);
            i++;
            j = 0;        
        }
    }
    return (1);
}

t_list *ft_create_stack(char *args[])
{
    t_list  *astackhead;
    t_list  *new;
    t_list  *index;
    int     number;
    int     i;

    i = 0;
    number = 0;
    
    while (args[i] != 0)
    {
        number = ft_atoi(&args[i]);
        if (number > 2147483647)
        {
            ft_printf("Error\n");
            return (0);
        }              
        new = ft_lstnew(number);
        ft_lstadd_back(&astackhead, new);
        i++;
    }
    new = (*head);
    new->index = 1;
    index = new->next;
    while (new != NULL)
    {    
        if( new->number > index->number)
            new->index = new->index + 1;
        new = new->next;  
    }
} 
