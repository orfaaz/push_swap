/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:29:18 by agamay            #+#    #+#             */
/*   Updated: 2024/12/03 12:29:21 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//!\needs update for circulat list
int	ps_lstsize(t_pslist *lst)
{
	int		len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

//!\needs update for circulat list
t_pslist	*ps_lstlast(t_pslist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//!\not used
void	ps_lstdelone(t_pslist *lst)
{
	if (!lst)
		return ;
	free(lst);
}

//!\needs update for circulat list
void	ps_lstclear(t_pslist **lst)
{
	void	*temp;

	if (!lst || !*lst )
		return ;
	temp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(temp);
		temp = *lst;
	}
}
