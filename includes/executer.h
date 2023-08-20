/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:20:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/18 18:51:51 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

void	executer(t_list *cmd_list);
void	set_redirections(t_list *cmd_list);
void	set_heredocs(t_list *cmd_list);
void	check_16_heredocs(t_list *cmd_list);
void	sig_handler(int sig);
void	set_signal_printing(void);
bool    is_builtins(char **cmd);
char	*get_path();

#endif