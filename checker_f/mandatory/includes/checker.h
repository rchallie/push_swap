/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:49:13 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 18:29:56 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define SUCCES 0
# define ERROR 1

# define INT_MIN -2147483648
# define INT_MAX 2147483647

#include <libft.h>

int     error(t_list **a, t_list **b);
void    clear(t_list **a, t_list **b);

#endif