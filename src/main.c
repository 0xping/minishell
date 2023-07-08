/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/08 14:19:05 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print(t_list *cmds)
{
	t_command	*cmd_cnt;
	// t_token		*token_cnt;

	for (t_list *i = cmds; i; i = i->next)
	{
		printf("---------------------------------   command   ---------------------------------\n");
		cmd_cnt = (t_command *)i->content;
		// printf("==> %s\n   tokens :\n", cmd_cnt->value);
		// for (t_list *j = cmd_cnt->lst_tokens; j; j = j->next)
		// {
		// 	token_cnt = (t_token *)j->content;
		// 	printf("%s, ", token_cnt->value);
		// }
		printf("command:\t");
		for (int i = 0; cmd_cnt->command && cmd_cnt->command[i]; i++)
			printf("%s  ",cmd_cnt->command[i]);

		printf("\nfiles:\t");
		for (t_list *i = cmd_cnt->files ; i; i = i->next)
			printf("%s[%d] ",((t_file *)i->content)->name,((t_file *)i->content)->type);

		printf("\n\n\n");
	}
}

t_global g_vars;

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
		add_history(input);
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
		if(parser(commands))
		{
			//execute
			executer(commands);
		}
		//print(commands);
		ft_lstclear(&commands, del_command);
		ft_free(input);
		//system("leaks minishell");
	}
	return (0);
}
