/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:42 by agamay            #+#    #+#             */
/*   Updated: 2024/12/04 14:01:43 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    ft_error(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

static int	ft_isspace3(const char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

static long int ft_atol(char *nbr)
{
	int	        sign;
	long int    num;

	sign = 0;
	num = 0;
	while (ft_isspace3(*nbr))
		nbr++;
	if (*nbr == '-')
	{
		sign = 1;
		nbr++;
	}
	else if (*nbr == '+')
		nbr++;
	while (*nbr >= '0' && *nbr <= '9')
	{
		num = num * 10 + (*nbr - 48);
		nbr++;
	}
	if (sign == 1)
		return (-num);
	return (num);
}
int ft_ofatoi(char *nbr)
{
    long int    n;

    n = ft_atol(nbr);
    if (n <= 2147483647 && n >= -2147483648)
        return (n);
    ft_error();
    return(0);
}