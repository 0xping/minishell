/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:32:35 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/27 19:37:31 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// free t_token content
void	del_tokens(void *content)
{
	t_token	*tokens;

	tokens = (t_token *)content;
	ft_free(tokens->value);
	ft_free(tokens);
}

void	del_files(void *content)
{
	t_file	*files;

	files = (t_file *)content;
	ft_free(files->name);
	ft_free(files);
}

// free t_command content
void	del_command(void *content)
{
	t_command *commands;

	commands = (t_command *)content;
	ft_lstclear(&commands->lst_tokens, del_tokens);
	ft_lstclear(&commands->files, del_files);
	ft_free(commands->value);
	ft_free(commands->command);
	ft_free(commands->fd);
	ft_free(commands);
}