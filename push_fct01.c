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

void	swap_exec(t_pslist **stack)
{
	t_pslist	*temp;

	temp = (*stack)->next;
	temp->prev = (*stack)->prev;
	temp->next->prev = *stack;
	(*stack)->next = temp->next;
	(*stack)->prev->next = temp;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}

void	swap(int s, ...)
{
	va_list	stack;

	va_start(stack, s);
	swap_exec(va_arg(stack, t_pslist **));
	if (s != 's')
		ft_printf("s%c\n", s);
	else
	{
		swap_exec(va_arg(stack, t_pslist **));
		ft_putstr_fd("ss\n", 1);
	}
	va_end(stack);
}

void	push(t_pslist **orig, t_pslist **dest, int s)
{
	t_pslist	*temp;

	temp = (*orig);
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	if (*orig == (*orig)->next)
		*orig = NULL;
	else
		*orig = (*orig)->next;
	if (*dest)
	{
		temp->next = *dest;
		temp->prev = (*dest)->prev;
		(*dest)->prev->next = temp;
		(*dest)->prev = temp;
	}
	else
	{
		temp->next = temp;
		temp->prev = temp;
	}
	*dest = temp;
	(*dest)->curr_stack = s;
	ft_printf("p%c\n", s);
}

void	rot(int *decrement, int s, ...)
{
	va_list		arg;
	t_pslist	**stack;

	va_start(arg, s);
	stack = va_arg(arg, t_pslist **);
	*stack = (*stack)->next;
	if (s != 'r')
		ft_printf("r%c\n", s);
	else
	{
		stack = va_arg(arg, t_pslist **);
		*stack = (*stack)->next;
		ft_putstr_fd("rr\n", 1);
	}
	va_end(arg);
	(*decrement)--;
}

void	revrot(int *increment, int s, ...)
{
	va_list		arg;
	t_pslist	**stack;

	va_start(arg, s);
	stack = va_arg(arg, t_pslist **);
	*stack = (*stack)->prev;
	if (s != 'r')
		ft_printf("rr%c\n", s);
	else
	{
		stack = va_arg(arg, t_pslist **);
		*stack = (*stack)->prev;
		ft_putstr_fd("rrr\n", 1);
	}
	va_end(arg);
	(*increment)++;
}
