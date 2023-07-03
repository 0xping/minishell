/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 20:25:28 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print(t_list *cmds)
{
	t_command	*cmd_cnt;
	t_token		*token_cnt;

	for (t_list *i = cmds; i; i = i->next)
	{
		printf("------------command-----------------\n");
		cmd_cnt = (t_command *)i->content;
		printf("==> %s\n   tokens :\n", cmd_cnt->value);
		for (t_list *j = cmd_cnt->lst_tokens; j; j = j->next)
		{
			token_cnt = (t_token *)j->content;
			printf("          %s\n", token_cnt->value);
		}
		printf("--------------------------------------\n\n\n");
	}
}

int	main(void)
{
	char	*input;
	char	*prompt;
	t_list	*commands;
	int		i;
	char	*tmp;

	i = 0;
	prompt = get_prompt();
	while (1)
	{
		input = readline(prompt);
		tmp = ft_strtrim(input, " \n\v\f\r\t");
		ft_free(input);
		input = tmp;
		tmp = spread_tokens(input);
		ft_free(input);
		input = tmp;
		if (!input[0])
		{
			ft_free(input);
			continue ;
		}
		commands = lexer(input);
		print(commands);
		ft_lstclear(&commands, del_command);
		ft_free(input);
	}
	return (0);
}
