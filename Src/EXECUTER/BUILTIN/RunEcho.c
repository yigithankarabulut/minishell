/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunEcho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:27:27 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/21 19:41:04 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	run_echo(t_cmdlist *cmd_node)
{
	char	**path;
	int		is_n;

	is_n = 0;
	path = &cmd_node->path[1];
	if (*path && str_compare(*path, "-n"))
	{
		is_n = 1;
		path++;
	}
	while (*path)
	{
		if (*path)
			write(cmd_node->outfile, *path, ft_strlen(*path));
		if (*(++path))
			write(cmd_node->outfile, " ", 1);
	}
	if (!is_n)
		write(cmd_node->outfile, "\n", 1);
	g_core.exec_output = 0;
}
