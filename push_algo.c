/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:04 by agamay            #+#    #+#             */
/*   Updated: 2025/01/18 15:20:12 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//best.pos is stack_1 distance from top. best.target is stack_2's.
void    exec_best(t_pslist **stack_1, t_pslist **stack_2, t_best best)
{
    while (best.moves--)
    {
        if (best.pos > 0 && best.target > 0)
            rot('s', stack_1, stack_2);
        else if (best.pos < 0 && best.target < 0)
            revrot('s', stack_1, stack_2);
        else if (best.pos > 0)
        {
            rot((*stack_1)->curr_stack, stack_1);
            best.pos--;
        }
        else if (best.pos < 0)
        { 
            revrot((*stack_1)->curr_stack, stack_1);
            best.pos++;
        }
        else if (best.target > 0)
        {  
            rot((*stack_2)->curr_stack, stack_2);
            best.target--; 
        }
        else if (best.target < 0)
        {
            revrot((*stack_2)->curr_stack, stack_2);
            best.target++;
        }
    }
    push(stack_1, stack_2, (*stack_2)->curr_stack);
}

//target[1] is position in stack 1, target[0] is position of target in stack 2.
void    isbestmove(int len1, int len2, int target[2], t_best *best)
{
    int moves;

    if (target[1] > len1 / 2)
        target[1] = -target[1] - ((len1 / 2) + 1);
    if (target[0] > len2 / 2)
        target[0] = -target[0] - ((len2 / 2) + 1);
    if ((len1 < 0 && len2 < 0) || (len1 > 0 && len2 > 0))
    {
        if (target[1] > target[0])
            moves = target[1] + 1;
        else
            moves = target[0] + 1;
    }
    else
        moves = target[1] + target[0] + 1;
    if (moves < best->moves)
    {
        best->pos = target[1];
        best->target = target[0];
        if (moves < 0)
            moves = -moves;
        best->moves = moves;
    }//probleme de valeur absolue quan moves est <0.
}

//finds where stack_a's top should be pushed. and if it's a new best.
void    find_target(t_pslist *stack_1, t_pslist *stack_2, int pos, t_best *best)
{
    int i;
    int target[2];
    int len;

    i = -1;
    len = ps_lstsize(stack_2);
    target[0] = 0;
    target[1] = stack_2->index;
    while (++i <= len)
    {
        if (stack_2->index > target[0] && stack_2->index < stack_1->index)
            target[0] = i;
        else if (stack_2->index > target[1])
            target[1] = i;
        stack_2 = stack_2->next;
    }
    if (!target[0])
        target[0] = target[1];
    target[1] = pos;
    isbestmove(ps_lstsize(stack_1), ps_lstsize(stack_2), target, best);
}

//for each node in stack_1: computes number of moves. picks best. 
void    algo(t_pslist **stack_1, t_pslist **stack_2)
{
    t_best      best;
    int         i;
    int         size;
    t_pslist    *stack;

    i = 0;
    stack = *stack_1;
    size = ps_lstsize(stack);
    find_target(stack, *stack_2, i, &best);
    while (i < size)
    {
        find_target(stack, *stack_2, i, &best);
        stack = stack->next;
        i++;
    }
    exec_best(stack_1, stack_2, best);
}

// deals with the stack size 3 situation.
void    algo_3(t_pslist **stack)
{
    if ((*stack)->index == 2 && (*stack)->next->index == 3
    && (*stack)->next->next->index == 1)
        rot('a', stack);
    if ((*stack)->index == 3 && (*stack)->next->index == 1
    && (*stack)->next->next->index == 2)
        revrot('a', stack);
    if ((*stack)->index == 2 && (*stack)->next->index == 1
    && (*stack)->next->next->index == 3)
        swap('a', stack);
    if ((*stack)->index == 1 && (*stack)->next->index == 3
    && (*stack)->next->next->index == 2)
    {
        rot('a', stack);
        swap('a', stack);
    }
    if ((*stack)->index == 3 && (*stack)->next->index == 2
    && (*stack)->next->next->index == 1)
    {
        revrot('a', stack);
        swap('a', stack);
    }
}
