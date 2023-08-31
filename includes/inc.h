/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:32:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/31 20:09:44 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
# define INC_H

// Text color macros
# define COLOR_BLACK "\x1b[30m"
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_WHITE "\x1b[37m"
# define COLOR_RESET "\x1b[0m"

// Text style macros
# define TEXT_BOLD "\x1b[1m"

# define RESET_ALL "\x1b[0m"

#include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
/*---------*/
# include "./lib.h"
/*--------*/
# include "./minishell.h"
/*--------*/
# include "./builtins.h"
# include "./executer.h"
# include "./lexer.h"
# include "./parser.h"
# include "./utils.h"

#endif
