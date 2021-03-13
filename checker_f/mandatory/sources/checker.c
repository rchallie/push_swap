/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:49:57 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 22:27:41 by rchallie         ###   ########.fr       */
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

// Add test if already in arg
// Move to common
int check_arguments(char **argv)
{
	int count;
	int char_count;
	long tmp_cont;

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
		tmp_cont = ft_atol(argv[count]);
		if (tmp_cont < INT_MIN || tmp_cont > INT_MAX)
			return (ERROR);
		count++;
	}
	return (SUCCESS);
}

/*
** get_content_from_argument:
** --------------------------
**
**		Transform an argument from the command line
**	to the content of stack.
**
**	@param arg the argument to transform.
**	@return the content or NULL if malloc fail.
**
*/

// Move to common
int *get_content_from_argument(char *arg)
{
	int *content;

	content = NULL;
	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = ft_atoi(arg);
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
**
*/

// Move to common
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
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *instructions;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (check_arguments(argv) == ERROR
		|| push_arguments(argv, &a) == ERROR
		|| get_sequence(&instructions))
		return (error(&a, &b, &instructions));
	clear(&a, &b, &instructions);
	
	(void)argc;
	(void)a;
	(void)b;
	return (0);
}