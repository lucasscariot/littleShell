/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:17:16 by lucas             #+#    #+#             */
/*   Updated: 2016/03/03 11:02:56 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *var)
{
	int		hoo;

	if ((hoo = ft_search_var(var, "PWD")) < 0)
		return ;
	while (hoo--)
		var = var->next;
	free(var->content);
	var->content = ft_get_absolute();
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
	char	*tmp;

	if (!path)
		tmp = ft_strdup(ft_search_content(var, "HOME"));
	else if (ft_strcmp(path, "-") == 0)
		tmp = ft_strdup(ft_search_content(var, "OLDPWD"));
	else if (ft_strcmp(path, "~") == 0 || ft_strcmp(path, "--") == 0)
		tmp = ft_strdup(ft_search_content(var, "HOME"));
	else
		tmp = ft_strdup(path);
	if (chdir(tmp) == -1)
		ft_error_cd(tmp);
	else
	{
		ft_oldpwd(var);
		ft_pwd(var);
		free(tmp);
	}
}
