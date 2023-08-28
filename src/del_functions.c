/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:32:35 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/26 18:13:45 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

// free t_env content
void	del_env(void *content)
{
	t_env	*env;

	env = (t_env *)content;
	ft_free((void **)&env);
}

// free t_token content
void	del_tokens(void *content)
{
	t_token	*tokens;

	tokens = (t_token *)content;
	ft_free((void **)&tokens->value);
	ft_free((void **)&tokens);
}

void	del_files(void *content)
{
	t_file	*files;

	files = (t_file *)content;
	ft_free((void **)&files->name);
	ft_free((void **)&files);
}

// free t_command content
void	del_command(void *content)
{
	t_command	*commands;

	commands = (t_command *)content;
	ft_lstclear(&commands->lst_tokens, del_tokens);
	ft_lstclear(&commands->files, del_files);
	ft_free((void **)&commands->value);
	ft_free((void **)&commands->command);
	ft_free((void **)&commands->fd);
	ft_free((void **)&commands);
}
