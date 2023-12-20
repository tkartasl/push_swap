/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:13 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/20 11:45:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_swap(t_list **head)
{
    t_list  *temp;
    t_list  *third;

    temp = (*head);
    if (temp == 0 || temp->next == 0)
        return ;
    third = temp->next->next;
    temp = temp->next
    temp->next = (*head); 
    temp->next->next = third;
    (*head) = temp;
}

void    ft_push(t_list **head1, t_list **head2)
{
    t_list  *temp;
    t_list  *current1;
    t_list  *current2;

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

void    ft_swap_both(t_list **head1, t_list **head2)
{
    ft_swap(&head1);
    ft_swap(&head2);
}

void    ft_rotate(t_list **head)
{
    t_list  *last;    
    t_list  *temp;
    t_list  *current;

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

void    ft_rotate_both(t_list **head1, t_list **head2)
{
    ft_rotate(&head1);
    ft_rotate(&head2);
}