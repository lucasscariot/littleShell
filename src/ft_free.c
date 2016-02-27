/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:10:39 by lucas             #+#    #+#             */
/*   Updated: 2016/02/27 22:16:29 by lucas            ###   ########.fr       */
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
