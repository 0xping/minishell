/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:32:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 21:34:33 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
# define INC_H

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
