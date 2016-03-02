/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:06:55 by lucas             #+#    #+#             */
/*   Updated: 2016/03/02 17:26:46 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shlvl(t_env *var)
{
	int tmp;

	while (var && ft_strcmp(var->name, "SHLVL=") != 0)
		var = var->next;
	if (!var || ft_strcmp(var->name, "SHLVL=") != 0)
		return ;
	tmp = ft_atoi(var->content);
	free(var->content);
	var->content = ft_itoa(tmp + 1);
}

char	*ft_search_content(t_env *var, char *name)
{
	char	*tmp;

	if (!name)
		return (NULL);
	tmp = ft_strjoin(name, "=");
	while (var && ft_strcmp(var->name, tmp) != 0)
		var = var->next;
	free(tmp);
	if (!var)
		return (NULL);
	return (var->content);
}

int		ft_search_var(t_env *var, char *name)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!name)
		return (-1);
	if (name[ft_strlen(name) - 1] != '=')
		tmp = ft_strjoin(name, "=");
	else
		tmp = ft_strdup(name);
	while (var && ft_strcmp(var->name, tmp) != 0)
	{
		var = var->next;
		i++;
	}
	free(tmp);
	if (!var)
		return (-1);
	return (i);
}

void	ft_del_env(t_env *var, char *name)
{
	char	*tmp;
	t_env	*save;
	int		hoo;

	if ((hoo = ft_search_var(var, name)) < 0 || !name)
		return ;
	if (hoo == 0)
	{
		ft_swap_list(var, var->next);
		ft_del_env(var, name);
		return ;
	}
	hoo--;
	tmp = ft_strjoin(name, "=");
	while (hoo--)
		var = var->next;
	if (!var || ft_strcmp(var->next->name, tmp) != 0)
		return ;
	save = var->next;
	var->next = var->next->next;
	ft_free_one(save);
	free(save);
	free(tmp);
}

char	**ft_conv_env(t_env *var)
{
	t_env	*tmp;
	char	**conv;
	int		i;

	i = 0;
	tmp = var;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	conv = malloc(sizeof(conv) * i + 1);
	i = 0;
	while (var != NULL)
	{
		conv[i++] = ft_strjoin(var->name, var->content);
		var = var->next;
	}
	conv[i] = NULL;
	return (conv);
}
