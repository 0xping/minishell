/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:25:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/30 02:03:40 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	throw_error(char *msg, int err_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(msg, 2);
	g_vars.exit_status = err_code;
}
