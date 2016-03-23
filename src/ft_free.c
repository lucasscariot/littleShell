/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:10:39 by lucas             #+#    #+#             */
/*   Updated: 2016/03/23 15:48:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_one(t_env *var)
{
	free(var->name);
	free(var->content);
}

void	ft_free_list(t_env *var)
{
	t_env	*next;

	while (var != NULL)
	{
		next = var->next;
		ft_free_one(var);
		free(var);
		var = next;
	}
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
