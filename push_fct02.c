/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fct02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:26:28 by agamay            #+#    #+#             */
/*   Updated: 2024/12/03 17:26:30 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdarg.h>

void    call_switch(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    if (s != 's')
    {
        swap(va_arg(stack, t_pslist **));
        ft_printf("s%c\n", s);
    }
    else
    {
        swap(va_arg(stack, t_pslist **));
        swap(va_arg(stack, t_pslist **));
        ft_putstr_fd("ss\n", 1);
    }
    va_end(stack);
}

void    call_push(t_pslist **orig, t_pslist **dest, int s)
{
    push(orig, dest);
    ft_printf("p%s\n", s);
}

void    call_rot(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    if (s != 's')
    {
        rot(va_arg(stack, t_pslist **));
        ft_printf("r%c\n", s);
    }
    else
    {
        rot(va_arg(stack, t_pslist **));
        rot(va_arg(stack, t_pslist **));
        ft_putstr_fd("rr\n", 1);
    }
    va_end(stack);
}

void    call_revrot(int s, ...)
{
    va_list stack;

    va_start(stack, s);
    if (s != 's')
    {
        revrot(va_arg(stack, t_pslist **));
        ft_printf("rr%c\n", s);
    }
    else
    {
        revrot(va_arg(stack, t_pslist **));
        revrot(va_arg(stack, t_pslist **));
        ft_putstr_fd("rrr\n", 1);
    }
    va_end(stack);
}
