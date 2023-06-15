/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:13:48 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 17:59:03 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//  cat <<eof >file1 && cat file1 && abc || wc <file1 | cat >file2

// todo
// 1 - split command with pipes (ignore pipes inside quotes) (DONE)

void	lexer(char *cmd)
{
	char	**cmd_pipes;
	int		i;

	cmd_pipes = pipe_splitter(cmd);
	i = 0;
	while (cmd_pipes[i])
	{
		i++;
	}
}
