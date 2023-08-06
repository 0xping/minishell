/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:50:17 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/01 07:53:17 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    print_pwd(char *s, int fd, int n)
{
    int i;

    i = 0;
    if (n == 0)
        write(fd, "Your old path is : ", 15);
    else if (n == 1)
        write(fd, "Your path is : ", 15);
    while(s[i])
        write(fd, &s[i++], 1);
    write(fd, "\n", 1);
}

void    add_pwd(char *s, int n)
{
    if (n == 0)
    {
        while(my_env)
        {
            if(ft_strcmp(my_env->name, "PWD") == 0)
                my_env->value = s;
            my_env = my_env->next;
        }
    }
    else if (n == 1)
    {
        while(my_env)
        {
            if(ft_strcmp(my_env->name, "OLDPWD") == 0)
                my_env->value = s;
            my_env = my_env->next;
        }
    }
}

void    ft_cd(char **s, int fd)
{
    int i;
    char *cur_path;
    char *new_path;
    
    i = 0;
    cur_path = getcwd(cur_path, sizeof(cur_path));
    add_pwd(cur_path, 0);
    print_pwd(cur_path, fd, 1);
    if (chdir(s) == 0)
    {
        new_path = getcwd(new_path, sizeof(new_path));
        add_pwd(cur_path, 0);
        add_pwd(new_path, 1);
        print_pwd(cur_path, fd, 0);
        print_pwd(new_path, fd, 1);
    }
    else if (s == NULL)
    {
        chdir("/Users");
        new_path = getcwd(new_path, sizeof(new_path));
        add_pwd(cur_path, 0);
        add_pwd(new_path, 1);
        print_pwd(cur_path, fd, 0);
        print_pwd(new_path, fd, 1);
    }
    else
        write(fd, "ERROR\n", 6);
}
