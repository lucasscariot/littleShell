/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:17:16 by lucas             #+#    #+#             */
/*   Updated: 2016/02/29 11:14:27 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *var, char *path)
{
	int     hoo;

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
		var = var->next;
	free(var->content);
	var->content = ft_strdup(pwd->content);
}

void	ft_change_directory(t_env *var, char *path)
{
	if (ft_strcmp(path, "-") == 0)
	{
		free(path);
		path = ft_strdup(ft_search_content(var, "OLDPWD"));
	}
	if (chdir(path) == -1)
		ft_error_cd(path);
	else
	{
		ft_pwd(var, path);
		ft_oldpwd(var);
	}
}
