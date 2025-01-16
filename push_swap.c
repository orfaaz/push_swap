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

void    isbestmove(int len1, int len2, int target[2], t_best *best)
{

}

void    find_target(t_pslist stack_1, t_pslist *stack_2, int pos, t_best *best)
{
    int i;
    int target[2];
    int len;

    i = -1;
    len = ps_lstsize(stack_2);
    target[0] = 0;
    target[1] = stack_2->index;
    while(++i > len)
    {
        if(stack_2->index > target[0] && stack_2->index < stack_1->index)
            target[0] = i;
        else if(stack_2->index > target[1])
            target[1] = i;
        stack_2 = stack_2->next;
    }
    if(!target[0])
        target[0] = target[1];
    target[1] = pos;
    isbestmove(stack_1_len, stack_2_len, target, best);
}

void    algo_start(t_pslist *stack_1, t_pslist *stack_2, int size)
{
    t_best      best;
    int         i;
    int         size;

    i = 0;
    size = ps_lstsize(stack_1);
    find_target(stack_1, stack_2, i, &best);
    while (i < size)
    {
        find_target(stack_1, stack_2, i, &best);
        stack_1 = stack_1->next;
        i++;
    }
    exec_best(&stack_1, &stack_2, best);
}

// deals with the stack size 3 situation.
void    algo_3(t_pslist *stack_a)
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
        return (??);//improve ft_printf to print **
    stack_a = parser(ac, av);
    //start algo. if A>5, we push to B w turk method until A==3.
    if (ac > 5)
    {
        push(&stack_a, &stack_b, 'b');
        push(&stack_a, &stack_b, 'b');
    }
    while (ac-- > 4)
        algo_start(stack_a, stack_b);
    //when A=3. we sort in the least amount of moves, then reverse algo
    algo_3(stack_a);
    while (stack_b)
        push(stack_b, stack_a, 'a');
    ps_lstclear(stack_a);
}
