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
#include <stdarg.h>

void    swap_exec(t_pslist **stack)
{
    t_pslist    *temp;

    temp = (*stack)->next;
    temp->prev = (*stack)->prev;
    (*stack)->next = temp->next;
    (*stack)->prev = temp;
    temp->next = *stack;
    *stack = temp;
}

void    push(t_pslist **orig, t_pslist **dest, int s)
{
    t_pslist    *temp;

    temp = (*orig)->next;
    (*orig)->next = *dest;
    (*orig)->prev = (*dest)->prev;
    (*dest)->prev->next = (*orig);
    (*dest)->prev = (*orig);
    *dest = *orig;
    *orig = temp;
    ft_printf("p%c\n", s);
}

void    swap(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    swap(va_arg(stack, t_pslist **));
    if (s != 's')
        ft_printf("s%c\n", s);
    else
    {
        swap(va_arg(stack, t_pslist **));
        ft_putstr_fd("ss\n", 1);
    }
    va_end(stack);
}

void    rot(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    va_arg(stack, t_pslist **);
    *stack = (*stack)->next;
    if (s != 's')
        ft_printf("r%c\n", s);
    else
    {
        va_arg(stack, t_pslist **);
        *stack = (*stack)->next;
        ft_putstr_fd("rr\n", 1);
    }
    va_end(stack);
}

void    revrot(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    va_arg(stack, t_pslist **);
    *stack = (*stack)->next;
    if (s != 's')
        ft_printf("rr%c\n", s);
    else
    {
        va_arg(stack, t_pslist **);
        *stack = (*stack)->next;
        ft_putstr_fd("rrr\n", 1);
    }
    va_end(stack);
}
