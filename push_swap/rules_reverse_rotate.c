/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:53:03 by tkartasl          #+#    #+#             */
/*   Updated: 2023/12/20 11:45:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_reverse_rotate(t_list **head)
{
    t_list  *temp;
    t_list  *last;   
    t_list  *prev_last;
    t_list  *current;

    current = (*head);
    if (current == 0 || current->next == 0)
        return  ;
    prev_last = NULL;
    temp = (*head);
    last = (*head);
    while (last->next != 0)
    {
        prev_last = last;
        last = last->next;
    }
    current = last;
    current->next = temp;
    (*head) = current;
    prev_last->next = NULL;
}

void    ft_reverse_rotate_both(t_list **head1, t_list **head2)
{
    ft_reverse_rotate(&head1);
    ft_reverse_rotate(&head2);
}