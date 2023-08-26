/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:20:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/25 16:31:05 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

typedef struct executer
{
	int			rd;
	int			wr;
	t_command	*cmd;
	int			i;
	int			**pipe_fd;
}				t_executer;

int				executer(t_list *cmd_list);
void			set_redirections(t_list *cmd_list);
void			set_heredocs(t_list *cmd_list);
void			check_16_heredocs(t_list *cmd_list);
void			sig_handler(int sig);
struct termios	*set_signal_printing(void);
bool			is_builtins(char **cmd);
char			*get_path(char **cmd);

/*--------------------------exc_utils.c---------------------------------*/

void			child(t_executer *ex);
int				exec_builtins(char **cmd, int wr);
int				open_redirection_and_heredocs(t_list *cmd_list);
void			handle_single_builtin(t_executer *executer);
void			setup_pipe_and_fds(t_executer *executer, t_list *current);
void			handle_fd(t_executer *executer);
void			cleanup_pipe_and_fds(t_executer *executer, t_list *current);

/*----------------------------------------------------------------------*/

#endif