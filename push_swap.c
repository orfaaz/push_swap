/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:04 by agamay            #+#    #+#             */
/*   Updated: 2024/12/02 17:45:15 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    algo_start(t_pslist *stack_a, int size)
{
    t_pslist    *stack_b;
    int         best[3];
    int         i;

    push(&stack_a, &stack_b, b);
    push(&stack_a, &stack_b, b);
    i = 0
    while (i++ < size)
    {
        best[2] = countmoves(stack_a, )
        if (best[2] < best[1])
            best[1] = best[2];
            best[0] = i;
    }
    exec_best(&stack_a, &stack_b, best);
    
}

//!\ av[1] must be at the top of the stack: Head == stack top.
// once sorted, the smallest n is at the top of the stack.
int	main(int ac, char **av)
{
    t_pslist    *stack_a;
    //If no parameters are specified, the program must not display 
    //anything and give the prompt back
    if (ac == 1)
        return (??);
    stack_a = parser(ac, av);
    algo_start(stack_a, ac - 1);
    ps_lstclear(stack_a);
}
