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

void    ft_error(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
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

}
