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

//puts smallest index on top of stack.
void    algo_end(t_pslist **stack)
{
    int         i;
    int         len;
    int         useless;
    t_pslist    *temp;

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
        while (i++ > len)
            revrot(&useless, 'a', stack);
    }
}

//best.pos is stack_1 distance from top. best.target is stack_2's.
void    exec_best(t_pslist **stack_1, t_pslist **stack_2, t_best best)
{
    int useless;

    useless = 0;
    while (best.moves--)
    {
        if (best.pos > 0 && best.target > 0)
            rot(&useless, 's', stack_1, stack_2);
        else if (best.pos < 0 && best.target < 0)
            revrot(&useless, 's', stack_1, stack_2);
        else if (best.pos > 0)
            rot(&best.pos, (*stack_1)->curr_stack, stack_1);
        else if (best.pos < 0)
            revrot(&best.pos, (*stack_1)->curr_stack, stack_1);
        else if (best.target > 0)
            rot(&best.target, (*stack_2)->curr_stack, stack_2);
        else if (best.target < 0)
            revrot(&best.target, (*stack_2)->curr_stack, stack_2);
    }
    push(stack_1, stack_2, (*stack_2)->curr_stack);
}

//target[1] is position in stack 1, target[0] is position of target in stack 2.
void    isbestmove(int len1, int len2, int target[2], t_best *best)
{
    int moves;

    if (target[1] > len1 / 2)
        target[1] = target[1] - len1;
    if (target[0] > len2 / 2)
        target[0] = target[0] - len2;
    if (best->push_dir == 'a')//worked propely (1st part) before this.
        target[0]++;
    if ((target[0] < 0 && target[1] < 0) || (target[0] > 0 && target[1] > 0))
    {
        if (target[1] > target[0])
            moves = ft_abs(target[1]);
        else
            moves = ft_abs(target[0]);
    }
    else
        moves = ft_abs(target[1]) + ft_abs(target[0]);
    if (moves < best->moves)
    {
        best->pos = target[1];
        best->target = target[0];
        best->moves = moves;
    }
}

//finds where stack_a's top should be pushed. and if it's a new best.
void    find_target(t_pslist *stack_1, t_pslist *stack_2, int pos, t_best *best)
{
    int i;
    int max[2];
    int target[2];

    i = -1;
    max[0] = 0;
    max[1] = 0;
    target[0] = 0;
    while (++i < ps_lstsize(stack_2))
    {
        if (stack_2->i > max[0] && stack_2->i < stack_1->i)
        {
            max[0] = stack_2->i;
            target[0] = i;
        }
        else if (stack_2->i > max[1])
        {
            max[1] = stack_2->i;
            target[1] = i;
        }
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
    best.push_dir = (*stack_2)->curr_stack;
    while (i < size)
    {
        find_target(stack, *stack_2, i, &best);
        stack = stack->next;
        i++;
    }
    exec_best(stack_1, stack_2, best);
    if (!*stack_1)
        algo_end(stack_2);
}

// deals with the stack size 3 situation.
void    algo_3(t_pslist **s)
{
    int useless;

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

