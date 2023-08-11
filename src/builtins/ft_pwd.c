/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:00:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/11 03:26:42 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_pwd(int fd)
{
	char	*path;

	path = getcwd(0, 0);
	ft_putendl_fd(path, fd);
	free(path);
}
