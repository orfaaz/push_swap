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

//!\ av[1] must be at the top of the stack: Head == stack top.
// once sorted, the smallest n is at the top of the stack.
int	main(int ac, char **av)
{
    t_pslist    *stack_a;
    t_pslist    *stack_b;
    //If no parameters are specified, the program must not display 
    //anything and give the prompt back
    if (ac == 1)
        return (0);
    stack_a = parser(ac, av);
    is_sorted(stack_a);
    //start algo. if A>5, we push to B w turk method until A==3.
    if (ac > 4)
    {
        push(&stack_a, &stack_b, 'b');
        if (ac > 5)
            push(&stack_a, &stack_b, 'b');
    }
    while (ac-- > 4)
        algo(&stack_a, &stack_b);
    //when A=3. we sort in the least amount of moves, then reverse algo
    algo_3(&stack_a);
    while (stack_b)
        algo(&stack_b, &stack_a);
    ps_lstclear(&stack_a);
}
