/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:56 by agamay            #+#    #+#             */
/*   Updated: 2024/12/02 17:52:26 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//args can have one symbol, then only digits, int limits.
static int	isargvalid(char *str)
{
	if	(!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		if (!*++str)
			return (1);
	}
	return (0);
}

//if there are no dups, we can add a new node for the arg
static void	checkdup(t_pslist **stack_a, int data)
{
	t_pslist	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (data == (*temp).data)
		{
			ps_lstclear(stack_a);
			ft_error();
		}
		temp = temp->next;
	}
	ps_lstadd_front(&stack_a, ps_lstnew(data));
}

//we check if we have only numbers as args.
//if we do, we put them in a db linked circular list, 
//ready to be sorted.
t_pslist	*parser(int ac, char **av)
{
	t_pslist	*stack_a;
	t_pslist	*lst_last;
	int			data;
	int			i;

	i = 0;
	while (i++ < ac)
	{
		if (!isargvalid(av[i]))
			ft_error();
	}
	while (--i)
	{
		data = ft_ofatoi(av[i]);
		checkdup(&stack_a, data);
	}
	lst_last = ps_lstlast(stack_a);
	lst_last->next = stack_a;
	stack_a->prev = lst_last;
	return (stack_a);
}
