/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:54:49 by lucas             #+#    #+#             */
/*   Updated: 2016/03/21 14:06:29 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_separate(char *put)
{
	char	**sep;

	sep = ft_strsplit(put, '=');
	if (!sep[1] || !sep[0])
		return (NULL);
	return (sep);
}

t_env	*ft_set_env(t_env *var, char *put)
{
	int		hoo;
	char	**sep;

	if (!put)
		return (var);
	sep = ft_separate(put);
	if (!sep || !put)
		return (var);
	if ((hoo = ft_search_var(var, sep[0])) < 0)
	{
		ft_save_env(var, put);
	}
	else
	{
		while (hoo--)
			var = var->next;
		free(var->content);
		var->content = ft_strdup(sep[1]);
	}
	return (var);
}

t_env	*ft_save_env(t_env *var, char *put)
{
	t_env	*new;
	t_env	*tmp;
	char	**sep;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	sep = ft_separate(put);
	if (!sep)
		return (var);
	new->name = ft_strjoin(sep[0], "=");
	new->content = ft_strdup(sep[1]);
	ft_free_tab(sep);
	new->next = NULL;
	if (!var)
		return (new);
	else
	{
		tmp = var;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (var);
	}
	return (new);
}

t_env	*ft_env(char **env)
{
	t_env	*var;
	int		i;

	i = 0;
	var = NULL;
	while (env[i])
		var = ft_save_env(var, env[i++]);
	ft_shlvl(var);
	return (var);
}

void	ft_show_env(t_env *var)
{
	while (var != NULL)
	{
		ft_putstr(var->name);
		ft_putendl(var->content);
		var = var->next;
	}
}
