/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fct01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:02:15 by agamay            #+#    #+#             */
/*   Updated: 2024/12/02 23:02:18 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    swap(t_pslist **stack)
{
    t_pslist    *temp;

    temp = (*stack)->next;
    (*stack)->prev = temp;
    temp->prev = NULL;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}

void    push(t_pslist **orig, t_pslist **dest)
{
    t_pslist    *temp;

    (*dest)->prev = *orig;
    temp = *orig;
    *orig = (*orig)->next;
    temp->next = *dest;
    *dest = temp;
}

void    rot(t_pslist **stack)
{
    t_pslist    *temp;

    temp = ps_lstlast(*stack);
    temp->next = *stack;
    (*stack)->prev = temp;
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
}

void    revrot(t_pslist **stack)
{
    t_pslist    *temp;

    temp = ps_lstlast(*stack);
    temp->next = *stack;
    temp->prev->next = NULL;
    temp->prev = NULL;
    *stack = temp;
}