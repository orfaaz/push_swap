/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:20:30 by agamay            #+#    #+#             */
/*   Updated: 2025/01/18 15:20:32 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = parser(ac, av);
	is_sorted(stack_a);
	stack_b = NULL;
	if (ac > 4)
	{
		push(&stack_a, &stack_b, 'b');
		if (ac > 5)
			push(&stack_a, &stack_b, 'b');
	}
	while (ps_lstsize(stack_a) > 3)
		algo(&stack_a, &stack_b);
	algo_3(&stack_a);
	while (stack_b)
		algo(&stack_b, &stack_a);
	ps_lstclear(&stack_a, ps_lstsize(stack_a));
}
