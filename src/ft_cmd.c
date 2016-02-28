/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:31:23 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 12:06:43 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char *cmd, char **opt, char **env)
{
	pid_t	proc;

	(void)cmd;
	proc = fork();
	if (proc == 0)
		execve("/bin/ls", opt, env);
	wait(NULL);
}

void	ft_change_directory(t_env *var)
{
	int		hoo;

	if ((hoo = ft_search_var(var, "PWD")) < 0)
		return ;
	while (hoo--)
		var = var->next;
	free(var->content);
	var->content = ft_strdup("/Users/lucas/42");
	ft_putcolor(var->content, BLUE);
	ft_putchar('\n');
}

int		ft_cmd(char	**line, t_env *var, char **test)
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
		ft_change_directory(var);
	else if (ft_strcmp(line[0], "ls") == 0)
		ft_exec(line[0], line, test);
	else if (ft_strcmp(line[0], "exit") == 0)
		return (1);
	return (0);
}
