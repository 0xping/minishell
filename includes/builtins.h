/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:50:46 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/11 03:25:19 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_env
{
	char	*name;
	char	*value;
	bool	is_set;
}			t_env;

void		ft_pwd(void);
void		ft_echo(char **args);

/*------------------------------------- ENV -------------------------------------*/
t_env		*new_env_node(char *name, char *value);
t_env		*get_env_by_name(char *value);
void		upsert_env_node(char *name, char *value, bool concat_value);
t_list		*create_env_list(const char *envp[]);
void		ft_env(int fd);
/*-------------------------------------------------------------------------------*/

#endif
