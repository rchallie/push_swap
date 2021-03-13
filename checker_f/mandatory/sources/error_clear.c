/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:25:06 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 18:29:39 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/*
** clear:
** ------
**
**		Clear allocated things ("a & b" stacks, ...).
**
**	@param a the "a" stack.
**	@param b the "b" stack.
**
*/

void clear(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

/*
** error:
** ------
**
**		Call to clear allocated things and print "Error" in
**	the error output.
**
**	@param a the "a" stack.
**	@param b the "b" stack.
**	@return ERROR (1).
**
*/

int error(t_list **a, t_list **b)
{
	clear(a, b);
	ft_putstr_fd("Error\n", 2);
	return (ERROR);
}