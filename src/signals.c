/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:04:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/09 17:31:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

void	sig_handler(int sig)
{
	char	*prmpt;

	g_vars.exit_status = 130;
	if (sig == SIGINT && !g_vars.is_child)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		prmpt = get_prompt();
		printf("\r%s", prmpt);
		free(prmpt);
	}
}

void	sigquit_handler(int sig)
{
	char	*prmpt;

	sig += 0;
	if (g_vars.is_child && g_vars.pid)
		g_vars.exit_status = 131;
	else
	{
		rl_redisplay();
		prmpt = get_prompt();
		printf("\r%s%s",prmpt, rl_line_buffer);
		free(prmpt);
	}
}

void	heredoc_sigint_handler(int sigint)
{
	close(0);
	g_vars.heredoc_sig = 1;
	g_vars.exit_status = 130;
	printf("\n");
	(void)sigint;
}

struct termios	*set_signal_printing(void)
{
	struct termios	*def;
	struct termios	new;

	def = ft_calloc(sizeof(struct termios), 1);
	tcgetattr(0, def);
	tcgetattr(0, &new);
	new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &new);
	return (def);
}
