/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:17:16 by lucas             #+#    #+#             */
/*   Updated: 2016/03/01 20:59:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *var, char *path)
{
	int     hoo;

	(void)path;
	if ((hoo = ft_search_var(var, "PWD")) < 0)
		return ;
	while (hoo--)
		var = var->next;
	free(var->content);
	var->content = ft_strdup(path);
}

void	ft_oldpwd(t_env *var)
{
	t_env	*pwd;
	int		hoo;
	int		hoo2;

	pwd = var;
	if ((hoo = ft_search_var(var, "OLDPWD")) < 0)
		return ;
	if ((hoo2 = ft_search_var(pwd, "PWD")) < 0)
		return ;
	while (hoo--)
		var = var->next;
	while (hoo2--)
		pwd = pwd->next;
	free(var->content);
	var->content = ft_strdup(pwd->content);
}

void	ft_change_directory(t_env *var, char *path)
{
	if (ft_strcmp(path, "-") == 0)
		path = ft_strdup(ft_search_content(var, "OLDPWD"));
	if (ft_strcmp(path, "-") == 0)
		ft_oldpwd(var);
	else if (chdir(path) == -1)
		ft_error_cd(path);
	else
	{
		ft_oldpwd(var);
		ft_pwd(var, path);
	}
}
