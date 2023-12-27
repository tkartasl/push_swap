/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:05:33 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/27 16:41:56 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

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
    if (ft_is_sorted_a(&astackhead) == 0)
    {
        ft_lstclear_stack(&astackhead);
        return (0);
    }
    ft_divide_stack(&astackhead, &bstackhead);
    return (0);
}

void    ft_divide_stack(stack_list **astackhead, stack_list **bstackhead)
{
    int         size;
    int         i;

    i = 0;
    size = ft_lstsize_stack(astackhead);
    while (i < size && ft_is_sorted_a(astackhead) != 0)
    {
        if ((*astackhead)->index > (size / 2))
            ft_rotate(astackhead);
        else
        {
            if ((*astackhead)->index > (size / 2) - (size / 4))
                ft_push(astackhead, bstackhead);
            else
            {
                ft_push(astackhead, bstackhead);
                ft_rotate(bstackhead);
            }
        }
        i++;
    }
	ft_sort_a(astackhead, bstackhead);
	ft_sort_b(astackhead, bstackhead);
}

void ft_sort_a(stack_list **astackhead, stack_list **bstackhead)
{
    int 		bsize;
    int 		i;
	stack_list	*second;

	second = (*astackhead)->next;
    i = 0;
    bsize = ft_lstsize_stack(*bstackhead); 
    while (ft_is_sorted_a(astackhead) != 0)
    {
        if ((*astackhead)->index == bsize + 1)
            {
				ft_push(astackhead, bstackhead);
                i++;
                bsize++;
            }
		if ((*astackhead)->index > second->index)
			ft_swap(astackhead);	
		else
			ft_rotate(astackhead);
    }
	while (i > 0)
	{
        ft_push(bstackhead, astackhead);
        i--;
    }
}

void ft_sort_b(stack_list **astackhead, stack_list **bstackhead)
{
	int			size;
	stack_list	*second;

	second = (*bstackhead)->next;
	size = ft_lstsize_stack(*astackhead);
	while ((*bstackhead) != 0)
	{
		if ((*bstackhead)->index == size)
		{
			ft_push(bstackhead, astackhead);
			size--;
		}
		if ((*bstackhead)->index < second->index)
			ft_swap(bstackhead);
		else
			ft_rotate(bstackhead);
	}
    ft_lstclear_stack(astackhead);
    exit (0);
}