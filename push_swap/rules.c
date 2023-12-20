/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:13 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/20 17:40:57 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(stack_list **head)
{
    stack_list  *temp;
    stack_list  *third;

    temp = (*head);
    if (temp == 0 || temp->next == 0)
        return ;
    third = temp->next->next;
    temp = temp->next
    temp->next = (*head); 
    temp->next->next = third;
    (*head) = temp;
}

void    ft_push(stack_list **head1, stack_list **head2)
{
    stack_list  *temp;
    stack_list  *current1;
    stack_list  *current2;

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
} 

void    ft_swap_both(stack_list **head1, stack_list **head2)
{
    ft_swap(&head1);
    ft_swap(&head2);
}

void    ft_rotate(stack_list **head)
{
    stack_list  *last;    
    stack_list  *temp;
    stack_list  *current;

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
}

void    ft_rotate_both(stack_list **head1, stack_list **head2)
{
    ft_rotate(&head1);
    ft_rotate(&head2);
}