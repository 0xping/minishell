/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 18:03:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*input;
	char	*prompt;

	// char	**tokens;
	// char	*trimmed_input;
	prompt = get_prompt();
	while (1)
	{
		input = readline(prompt);
		// trimmed_input = ft_strtrim(input, " \n\v\f\r\t");
		// free(input);
		// input = trimmed_input;
		// if (!input[0])
		// {
		// 	free(input);
		// 	continue ;
		// }
		// newline_handler(&input);
		// tokens = lexer(input);
		free(input);
	}
	return (0);
}
