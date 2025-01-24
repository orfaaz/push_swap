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

int	ps_lstsize(t_pslist *lst)
{
	t_pslist	*temp;
	int			len;

	if (!lst)
		return (0);
	len = 1;
	temp = lst;
	while (temp->next != lst)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

t_pslist	*ps_lstlast(t_pslist *lst)
{
	t_pslist	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (lst->next != temp)
		lst = lst->next;
	return (lst);
}

void	ps_lstclear(t_pslist **lst, int len)
{
	void	*temp;
	int		i;

	if (!lst || !*lst)
		return ;
	i = 0;
	temp = *lst;
	while (i++ < len)
	{
		*lst = (*lst)->next;
		free(temp);
		temp = *lst;
	}
}
