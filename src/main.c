/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/11 17:18:27 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

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
			printf("%s  ", cmd_cnt->command[i]);
		printf("\nfiles:\t");
		for (t_list *i = cmd_cnt->files; i; i = i->next)
			printf("%s[%d] ", ((t_file *)i->content)->name,
				((t_file *)i->content)->type);
		printf("\n\n\n");
	}
}

t_global	g_vars;

void	init_global_vars(const char *envp[])
{
	g_vars.exit_status = 0;
	g_vars.heredoc_sig = 0;
	g_vars.pid = getpid();
	g_vars.env = create_env_list(envp);
}

int	main(int ac, char const *av[], char const *envp[])
{
	char	*input;
	char	*prompt;
	t_list	*commands;
	int		i;
	char	*tmp;

	ac += 0;
	av += 0;
	i = 0;
	init_global_vars(envp);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	// set_signal_printing();
	prompt = get_prompt();
	while (1)
	{
		input = readline(get_prompt());
		if (!input || *input)
		{
			if (!input)
				break ;
			add_history(input);
		}
		tmp = ft_strtrim(input, " \n\v\f\r\t");
		ft_free((void **)&input);
		input = tmp;
		tmp = spread_tokens(input);
		ft_free((void **)&input);
		input = tmp;
		if (!input[0])
		{
			ft_free((void **)&input);
			continue ;
		}
		commands = lexer(input);
		if (parser(commands))
		{
			// execute
			executer(commands);
		}
		// print(commands);
		ft_lstclear(&commands, del_command);
		ft_free((void **)&input);
		// system("leaks minishell");
		// system("lsof minishell");
	}
	return (0);
}
