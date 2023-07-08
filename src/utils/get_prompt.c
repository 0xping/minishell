/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:00:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/08 13:04:07 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_prompt(void)
{
	// TODO
	// parse the PS1 env variable
	/*
	\a: ASCII bell character (BEL).
	\d: Current date in "Weekday Month Day" format (e.g., "Mon Sep 20").
	\e: ASCII escape character.
	\h: Hostname of the machine.
	\H: Complete hostname (up to the first dot).
	\j: Number of jobs currently managed by the shell.
	\l: Basename of the terminal device.
	\n: Newline character.
	\r: Carriage return character.
	\s: Name of the shell executable (e.g., "bash", "zsh").
	\t: Current time in 24-hour format (hh:mm:ss).
	\T: Current time in 12-hour format (hh:mm:ss).
	\@: Current time in 12-hour format with am/pm indicator (hh:mm am/pm).
	\A: Current time in 24-hour format without seconds (hh:mm).
	\u: Username of the current user.
	\v: Version of the Bash shell.
	\V: Release version of the Bash shell.
	\w: Current working directory.
	\W: Basename of the current working directory.
	\!: History number of the current command.
	\#: Command number of the current command.
	\$: Prompt symbol ($ for regular users, # for root/superuser).
	*/

	return ("minishell:$ ");
	//	return ("user@hostname:~/current_directory$ ");
}