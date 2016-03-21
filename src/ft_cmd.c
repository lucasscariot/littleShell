/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:31:23 by lucas             #+#    #+#             */
/*   Updated: 2016/03/21 16:19:01 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_absolute(void)
{
	char	buff[1000];
	char	*link;

	link = ft_strdup(getcwd(buff, 1000));
	return (link);
}

void	ft_exec(char *cmd, char **opt, t_env *var)
{
	char	*tmp;
	char	**conv;
	pid_t	proc;

	if (ft_isfile(cmd))
		tmp = ft_strdup(cmd);
	else
		tmp = ft_path(cmd, var);
	if (!tmp)
	{
		ft_error_cmd(cmd);
		return ;
	}
	proc = fork();
	if (proc == 0)
	{
		conv = ft_conv_env(var);
		execve(tmp, opt, conv);
		ft_free_tab(conv);
	}
	wait(NULL);
	free(tmp);
}

int		ft_cmd(char **line, t_env *var)
{
	int		i;

	i = 0;
	if (!line[0])
		return (0);
	else if (ft_strcmp(line[0], "env") == 0)
		ft_show_env(var);
	else if (ft_strcmp(line[0], "unsetenv") == 0)
		ft_del_env(var, line[1]);
	else if (ft_strcmp(line[0], "setenv") == 0)
		var = ft_set_env(var, line[1]);
	else if (ft_strcmp(line[0], "cd") == 0)
		ft_change_directory(var, line[1]);
	else if (ft_strcmp(line[0], "exit") == 0)
		return (1);
	else
		ft_exec(line[0], line, var);
	return (0);
}

void	ft_wtf(int i)
{
	(void)i;
}
