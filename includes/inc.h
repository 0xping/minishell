/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:32:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/10 03:43:00 by aait-lfd         ###   ########.fr       */
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

# define BG_COLOR_BLACK "\x1b[40m"
# define BG_COLOR_RED "\x1b[41m"
# define BG_COLOR_GREEN "\x1b[42m"
# define BG_COLOR_YELLOW "\x1b[43m"
# define BG_COLOR_BLUE "\x1b[44m"
# define BG_COLOR_MAGENTA "\x1b[45m"
# define BG_COLOR_CYAN "\x1b[46m"
# define BG_COLOR_WHITE "\x1b[47m"

// Text style macros
# define TEXT_BOLD "\x1b[1m"
# define TEXT_UNDERLINE "\x1b[4m"
# define TEXT_REVERSE "\x1b[7m"

# define REVERSE_TEXT "\x1b[7m"
# define RESET_ALL "\x1b[0m"

# include <fcntl.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
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
