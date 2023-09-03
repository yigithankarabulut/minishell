/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunProcess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:28:42 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/21 19:42:16 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	run_process(t_cmdlist *cmd_list, int *fd, int fd_index)
{
	if (cmd_list->infile != SSTDERR && cmd_list->outfile != SSTDERR)
		exec_command(cmd_list, fd, fd_index);
	else
		clear_pipe(fd);
	free_for_loop();
	free_core();
	exit(g_core.exec_output);
}

void	wait_all(void)
{
	t_cmdlist	*cmd_list;

	cmd_list = g_core.cmd_table;
	while (cmd_list)
	{
		if (!cmd_list->next)
			waitpid(cmd_list->pid, &g_core.exec_output, 0);
		else
			waitpid(cmd_list->pid, 0, 0);
		cmd_list = cmd_list->next;
	}
	g_core.exec_output = WEXITSTATUS(g_core.exec_output);
}
