/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agamay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:26:23 by agamay            #+#    #+#             */
/*   Updated: 2024/12/02 17:30:29 by agamay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pslist
{
	int				data;
	struct s_pslist	*prev;
	struct s_pslist	*next;
}					t_pslist;

typedef struct s_best
{
	int	size_a;
	int	size_b;
	int	pos;
	int	target;
	int	moves;
}		t_best;

t_pslist	*parser(int ac, char **av);
void    	ft_error(void);
int 		ft_ofatoi(char *nbr);
void		swap_exec(t_pslist **stack);
void	    push(t_pslist **orig, t_pslist **dest, int s);
void    	swap(int s, ...);
void    	rot(int s, ...);
void    	revrot(int s, ...);
t_pslist	*ps_lstnew(int data);
void		ps_lstadd_front(t_pslist **lst, t_pslist *new);
void		ps_lstadd_back(t_pslist **lst, t_pslist *new);
int			ps_lstsize(t_pslist *lst);
t_pslist	*ps_lstlast(t_pslist *lst);
void		ps_lstdelone(t_pslist *lst);
void		ps_lstclear(t_pslist **lst);
#endif
