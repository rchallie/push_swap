/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:55:12 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 22:52:45 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/*
** is_valid_instruction:
** ---------------------
**
**      Check is an instruction given exist and
**  is well formated.
**
**  @param instruction the instruction to check.
**  @return SUCCESS (0) if the instruction exist, ERROR (1) otherwise.
**
*/

static int is_valid_instruction(char *instruction)
{
	int count;
	char **valids;

	count = 0;
	valids = (char* [11]){"sa", "sb", "ss", "pa", "pb", "ra",
	"rb", "rr", "rra", "rrb", "rrr"};
	while (count < 11)
	{
		if (ft_strlen(valids[count]) == ft_strlen(instruction) &&
			ft_strncmp(valids[count], instruction,
			ft_strlen(valids[count]))== 0)
			return (SUCCESS);
		count++;
	}
	return (ERROR);
}

/*
** add_to_sequence:
** ----------------
**
**      Add an instruction given in the sequence.
**
**  @param instructions the sequence storage.
**  @param instruction the instruction to check.
**  @return ERROR (1) if a malloc fail, SUCCESS (0) otherwise.
**
*/

static int add_to_sequence(t_list **instructions, char *instruction)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (ERROR);
	tmp->next = NULL;
	tmp->content = instruction;
	ft_lstadd_back(instructions, tmp);
	return (SUCCESS);
}

/*
** get_sequence:
** -------------
**
**      Read in the standard input to get the instructions
**  to set in the sequences. Call all check to see if the
**  instructions are well formatted.
**
**  @param instructions the sequence.
**	@return ERROR (1) if an instruction is not well formatted or
**	if a malloc fail.
**
*/
 
int get_sequence(t_list **instructions)
{
	char buffer[4];
	char r_buffer;
	int count;

	count = 0;
	ft_bzero(&buffer, 4);
	while (read(0, &r_buffer, 1))
	{
		count++;
		if (count > 4)
			return (ERROR);
		else if (r_buffer == '\n')
		{
			if (is_valid_instruction(buffer) == SUCCESS)
			{
				if (add_to_sequence(instructions, ft_strdup(buffer)) == ERROR)
					return (ERROR);
			}
			else
				return (ERROR);
			count = 0;
			ft_bzero(&buffer, 4);
		}
		else
			buffer[count - 1] = r_buffer;
	}
	return (SUCCESS);
}