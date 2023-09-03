/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:31:50 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/22 03:24:09 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	g_core.exec_output = 0;
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		printf("You do not need to enter args...\n");
		return (0);
	}
	init_core(env);
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		g_core.cmd = readline("\033[0;34mminishell-> \033[0m");
		lexer();
		expander();
		parser();
		executer();
		add_history(g_core.cmd);
		exit_signal_check();
		free_for_loop();
	}
	free_core();
}
