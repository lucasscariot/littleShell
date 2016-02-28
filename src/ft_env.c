/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:54:49 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 01:12:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_separate(char *put)
{
	int		full;
	int		cont;
	char	**sep;

	if (!put)
		return (NULL);
	sep = (char **)malloc(sizeof(sep) * 2);
	full = ft_strlen(put);
	cont = ft_strlen(ft_strchr(put, '=')) - 1;
	sep[0] = ft_strndup(put, full - cont);
	sep[1] = ft_strdup(&put[full - cont]);
	return (sep);
}

t_env	*ft_save_env(t_env *var, char *put)
{
	t_env	*new;
	t_env	*tmp;
	char	**sep;

	new = malloc(sizeof(t_env));
	sep = ft_separate(put);
	if (!new)
		return (NULL);
	new->name = ft_strdup(sep[0]);
	new->content = ft_strdup(sep[1]);
	free(sep[0]);
	free(sep[1]);
	free(sep);
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
