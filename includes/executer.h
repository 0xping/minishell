/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:20:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/01 08:48:52 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

void	executer(t_list *cmd_list);
void	set_redirections(t_list *cmd_list);
void	set_heredocs(t_list *cmd_list);
void	sigint_handler(int sigint);
char	*get_path(char *cmd, int fd);

#endif