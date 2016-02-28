/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:31:23 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 20:24:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char *cmd, char **opt, t_env *var)
{
	char	*tmp;
	char	*scm;
	pid_t	proc;

	scm = ft_strjoin("/", cmd);
	tmp = ft_path(scm, var);
	free(scm);
	if (!tmp)
	{
		ft_error_cmd(cmd);
		return ;
	}
	proc = fork();
	if (proc == 0)
		execve(tmp, opt, NULL);
	wait(NULL);
	free(tmp);
}

int		ft_cmd(char	**line, t_env *var)
{
	int i;

	i = 0;
	if (!line[0])
		return (0);
	else if (ft_strcmp(line[0], "env") == 0)
		ft_show_env(var);
	else if (ft_strcmp(line[0], "unsetenv") == 0)
		ft_del_env(var, line[1]);
	else if (ft_strcmp(line[0], "setenv") == 0)
		var = ft_save_env(var, line[1]);
	else if (ft_strcmp(line[0], "cd") == 0)
		ft_change_directory(var, line[1]);
	else if (ft_strcmp(line[0], "exit") == 0)
		return (1);
	else
		ft_exec(line[0], line, var);
	return (0);
}
