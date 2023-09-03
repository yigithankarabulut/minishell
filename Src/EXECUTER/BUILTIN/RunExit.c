/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunExit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:27:37 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/21 19:41:19 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

int	is_all_numeric(char *text)
{
	while (text && *text)
	{
		if (!(*text >= '0' && *text <= '9'))
			return (0);
		text++;
	}
	return (1);
}

void	run_exit(t_cmdlist *cmd_node)
{
	int	array_len;

	array_len = get_array_len(&cmd_node->path[1]);
	if (array_len > 1)
	{
		print_error("bash: exit: too many arguments\n", NULL, NULL);
		g_core.exec_output = 1;
		return ;
	}
	else if (array_len == 1)
	{
		if (is_all_numeric(cmd_node->path[1]))
			g_core.exec_output = ft_atoi(cmd_node->path[1]);
		else
		{
			print_error("bash: exit: ",
				cmd_node->path[1], ": numeric argument required\n");
			g_core.exec_output = 255;
		}
	}
	else
		g_core.exec_output = 0;
	free_for_loop();
	free_core();
	exit(g_core.exec_output % 256);
}
