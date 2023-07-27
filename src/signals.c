/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:04:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/27 20:30:03 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int sigint)
{
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sigint;
}

void	set_signal_printing(void)
{
	struct termios	new_term;

	tcgetattr(0, &new_term);
	// Disable printing signals (disable ISIG flag) and disable character echoing (disable ECHO flag)
	new_term.c_lflag &= ~(ISIG | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}
