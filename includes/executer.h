/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:20:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/10 02:37:24 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

void	executer(t_list *cmd_list);
void	set_redirections(t_list *cmd_list);
void	set_heredocs(t_list *cmd_list);
void	check_16_heredocs(t_list *cmd_list);
void	sigint_handler(int sigint);

#endif