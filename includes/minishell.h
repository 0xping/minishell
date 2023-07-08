/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:58:47 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/08 14:38:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <signal.h>
# include "./lib.h"

typedef struct s_global
{
	int			exit_status;
}				t_global;

typedef enum
{
	TK_REDIRECT_IN_OP,
	TK_REDIRECT_OUT_OP,
	TK_APPEND_OP,
	TK_HEREDOC_OP,
	TK_REDIRECT_IN_FILE,
	TK_REDIRECT_OUT_FILE,
	TK_APPEND_FILE,
	TK_HEREDOC_DEL,
	TK_WORD,
}				token_type;

typedef enum
{
	RED_IN,
	RED_APPEND,
	RED_OUT,
	RED_HEREDOC
}				red_type;

typedef struct s_file
{
	char		*name;
	red_type	type;
}				t_file;

typedef struct s_command
{
	char		*value;
	t_list		*lst_tokens;
	struct
	{
		int		in_op;
		int		in_file;
		int		out_op;
		int		out_file;
		int		append_op;
		int		append_file;
		int		heredoc_op;
		int		heredoc_del;
	} tk_count;
	char		**command;
	t_list		*files;
	int			*fd;
}				t_command;

typedef struct s_token
{
	char		*value;
	token_type	type;
}				t_token;

extern t_global	g_vars;

# include "./utils.h"
# include "./builtins.h"
# include "./lexer.h"
# include "./parser.h"
#include "./executer.h"

#endif


