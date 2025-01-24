/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:39:33 by agamay            #+#    #+#             */
/*   Updated: 2025/01/24 12:40:26 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//puts smallest index on top of stack.
void	algo_end(t_pslist **stack)
{
	int			i;
	int			len;
	int			useless;
	t_pslist	*temp;

	i = 0;
	useless = 0;
	temp = *stack;
	len = ps_lstsize(*stack);
	while (temp->i != 1)
	{
		temp = temp->next;
		i++;
	}
	if (i < len / 2)
	{
		while (i--)
			rot(&useless, 'a', stack);
	}
	else
	{
		while (i++ < len)
			revrot(&useless, 'a', stack);
	}
}

// deals with the stack size 3 situation.
void	algo_3(t_pslist **s)
{
	int	useless;

	useless = 0;
	if ((*s)->i < (*s)->next->i && (*s)->i > (*s)->prev->i)
		revrot(&useless, 'a', s);
	if ((*s)->prev->i > (*s)->next->i && (*s)->prev->i < (*s)->i)
		rot(&useless, 'a', s);
	if ((*s)->i > (*s)->next->i && (*s)->i < (*s)->prev->i)
		swap('a', s);
	if ((*s)->prev->i < (*s)->next->i && (*s)->prev->i > (*s)->i)
	{
		revrot(&useless, 'a', s);
		swap('a', s);
	}
	if ((*s)->next->i < (*s)->i && (*s)->next->i > (*s)->prev->i)
	{
		rot(&useless, 'a', s);
		swap('a', s);
	}
}
