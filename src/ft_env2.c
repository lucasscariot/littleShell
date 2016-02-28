/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:06:55 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 01:49:44 by lucas            ###   ########.fr       */
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
