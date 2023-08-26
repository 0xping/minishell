/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:33:35 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/26 18:32:45 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

void				del_command(void *content);
void				del_env(void *content);
void				rl_replace_line(const char *text, int clear_undo);
void				set_global_envp(void);
void				free_global_envp(void);

typedef struct s_global
{
	int				exit_status;
	int				heredoc_sig;
	pid_t			*pid;
	t_list			*env;
	const char		**envp;
}					t_global;

typedef enum token_type
{
	TK_REDIRECT_IN_OP,
	TK_REDIRECT_IN_FILE,
	TK_REDIRECT_OUT_OP,
	TK_REDIRECT_OUT_FILE,
	TK_APPEND_OP,
	TK_APPEND_FILE,
	TK_HEREDOC_OP,
	TK_HEREDOC_DEL,
	TK_WORD,
}					t_token_type;

typedef enum red_type
{
	RED_IN,
	RED_APPEND,
	RED_OUT,
	RED_HEREDOC
}					t_red_type;

typedef struct s_file
{
	char			*name;
	t_red_type		type;
}					t_file;

typedef struct s_command
{
	char			*value;
	t_list			*lst_tokens;
	struct s_tk_count
	{
		int			in_op;
		int			in_file;
		int			out_op;
		int			out_file;
		int			append_op;
		int			append_file;
		int			heredoc_op;
		int			heredoc_del;
	} tk_count;
	char			**command;
	t_list			*files;
	bool			file_error;
	int				*fd;
}					t_command;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}					t_token;

extern t_global		g_vars;

#endif
