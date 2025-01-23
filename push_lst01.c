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

//!\needs update for circulat list
t_pslist	*ps_lstnew(int data)
{
	t_pslist	*new_node;

	new_node = malloc(sizeof(t_pslist));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->i = -1;
	new_node->curr_stack = 'a';
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ps_lstadd_front(t_pslist **lst, t_pslist *new)
{
	t_pslist	*last;

	if (!(lst && new))
		return ;
	last = NULL;
	if (*lst)
		last = ps_lstlast(*lst);
	else
		*lst = new;
	new->next = *lst;
    (*lst)->prev = new;
	if (last)
		last->next = new;
	*lst = new;
}

void	ps_lstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*last;

	if (!lst)
		return ;
	last = NULL;
	if (*lst)
		last = ps_lstlast(*lst);
	else
		last = new;
	last->next = new;
    new->prev = last;
	new->next = *lst;
}
