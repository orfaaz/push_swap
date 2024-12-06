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

void    exec_best(t_pslist **stack_a, t_pslist **stack_b, t_best best)
{

}

int countmoves(t_pslist *stack_a, t_pslist *stack_b, int pos, t_best *best)
{

}

void    algo_start(t_pslist *stack_a, t_pslist *stack_b, int size)
{
    t_best      best;
    int         i;

    i = 0;
    countmoves(stack_a, stack_b, i, &best);
    while (i < size && !countmoves(stack_a, stack_b, i, &best))
    {
        i++;
    }
    exec_best(&stack_a, &stack_b, best);
    
}

void    algo_end(t_pslist *stack_a, t_pslist *stack_b)
{

}

//!\ av[1] must be at the top of the stack: Head == stack top.
// once sorted, the smallest n is at the top of the stack.
int	main(int ac, char **av)
{
    t_pslist    *stack_a;
    t_pslist    *stack_b;
    //If no parameters are specified, the program must not display 
    //anything and give the prompt back
    if (ac == 1)
        return (??);
    stack_a = parser(ac, av);
    //start algo. if A>5, we push to B w turk method until A==3.
    if (ac > 5)
    {
        push(&stack_a, &stack_b, 'b');
        push(&stack_a, &stack_b, 'b');
    }
    while (ps_lstsize(stack_a) > 3)
        algo_start(stack_a, stack_b, ac - 1);
    //when A=3. we sort in the least amount of moves, then pA till B mt
    algo_end(stack_a);
    while (stack_b)
        push(stack_b, stack_a, 'a');
    ps_lstclear(stack_a);
}
