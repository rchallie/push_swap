/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:49:57 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 18:31:35 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/*
** check_arguments :
** -----------------
**
**      Check if an argument given in the command line
**  is valid or not. An argument can be invalid if it isn't
**  a integer (string or more/less than INT_MAX/INT_MIN).
**
**  @param argv the arguments given in the command line.
**  @return SUCCESS (0) or ERROR (1).
** 
*/

int check_arguments(char **argv)
{
	int count;
	int char_count;

	count = 1;
	while (argv[count])
	{
		char_count = 0;
		while (argv[count][char_count])
		{
			if (!ft_isdigit(argv[count][char_count]))
				return (ERROR);
			char_count++;
		}
		count++;
	}
	return (SUCCES);
}



int *get_content_from_argument(char *arg)
{
	int *content;
	long tmp_cont;

	content = NULL;
	tmp_cont = ft_atol(arg);
	if (tmp_cont < INT_MIN || tmp_cont > INT_MAX)
		return (NULL);
	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = (int)tmp_cont;
	return (content);
}

/*
** push_arguments:
** ---------------
**
**		Push the arguments given in the command line
**	in the "a" stack. The first argument is on the top
**	of the stack, each argument after is pushed after
**	the previously pushed.
**
**  @param argv the arguments given in the command line.
**	@param a the "a" stack.
**	@return SUCCESS (0) or ERROR (1).
*/

int push_arguments(char **argv, t_list **a)
{
	int count;
	t_list *tmp;
	int *content;
	
	count = 1;
	while (argv[count])
	{
		tmp = NULL;
		content = get_content_from_argument(argv[count]);
		if (content == NULL)
			return (ERROR);
		tmp = malloc(sizeof(t_list));
		if (!tmp)
		{
			free(content);
			return (ERROR);
		}
		tmp->next = NULL;
		tmp->content = content;
		ft_lstadd_back(a, tmp);
		count++;
	}
	return (SUCCES);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (check_arguments(argv) == ERROR
		|| push_arguments(argv, &a) == ERROR)
		return (error(&a, &b));
	clear(&a, &b);
	
	(void)argc;
	(void)a;
	(void)b;
	return (0);
}