/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:52:58 by agamay            #+#    #+#             */
/*   Updated: 2024/12/03 12:29:10 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_pslist	*ps_lstnew(int data)
{
	t_pslist	*new_node;

	new_node = malloc(sizeof(t_pslist));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ps_lstadd_front(t_pslist **lst, t_pslist *new)
{
	if (!(lst && new))
		return ;
	new->next = *lst;
    (*lst)->prev = new;
	*lst = new;
}

void	ps_lstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*temp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
    new->prev = temp;
}
