/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/28 18:00:08 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

// void	print(t_list *cmds)
// {
// 	t_command	*cmd_cnt;

// 	// t_token		*token_cnt;
// 	for (t_list *i = cmds; i; i = i->next)
// 	{
// 		printf("---------   command   ---------\n");
// 		cmd_cnt = (t_command *)i->content;
// 		// printf("==> %s\n   tokens :\n", cmd_cnt->value);
// 		// for (t_list *j = cmd_cnt->lst_tokens; j; j = j->next)
// 		// {
// 		// 	token_cnt = (t_token *)j->content;
// 		// 	printf("%s, ", token_cnt->value);
// 		// }
// 		printf("command:\t");
// 		for (int i = 0; cmd_cnt->command && cmd_cnt->command[i]; i++)
// 			printf("%s  ", cmd_cnt->command[i]);
// 		printf("\nfiles:\t");
// 		for (t_list *i = cmd_cnt->files; i; i = i->next)
// 			printf("%s[%d] ", ((t_file *)i->content)->name,
// 				((t_file *)i->content)->type);
// 		printf("\n\n\n");
// 	}
// }

t_global	g_vars;

void	init(const char *envp[])
{
	g_vars.exit_status = 0;
	g_vars.heredoc_sig = 0;
	g_vars.is_child = 0;
	g_vars.env = create_env_list(envp);
	set_global_envp();
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sigquit_handler);
}

void	clean_input(char **input)
{
	char	*trim;
	char	*spread;

	trim = ft_strtrim(*input, " \n\v\f\r\t");
	spread = spread_tokens(trim);
	ft_free((void **)&trim);
	ft_free((void **)input);
	*input = spread;
}

char	*_readline(char **input_ptr)
{
	char	*prompt;

	prompt = get_prompt();
	*input_ptr = readline(prompt);
	ft_free((void **)&prompt);
	return (*input_ptr);
}

int	main(int ac, char const *av[], char const *envp[])
{
	char			*input;
	t_list			*commands;
	struct termios	*def_termios;

	ac += 0;
	av += 0;
	init(envp);
	def_termios = set_signal_printing();
	while (_readline(&input))
	{
		(*input) && (add_history(input), 1);
		clean_input(&input);
		if (!input[0])
		{
			ft_free((void **)&input);
			continue ;
		}
		commands = lexer(input);
		(parser(commands)) && (executer(commands), 1);
		ft_lstclear(&commands, del_command);
		ft_free((void **)&input);
	}
	tcsetattr(0, TCSANOW, def_termios);
	return (printf("exit\n"), exit(g_vars.exit_status), 0);
}
