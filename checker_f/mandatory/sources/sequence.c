/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:55:12 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/13 22:31:28 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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