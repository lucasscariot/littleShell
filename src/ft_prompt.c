/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:41:33 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 01:49:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwdfolder(t_env *var)
{
	int	i;

	while (var != NULL && ft_strcmp(var->name, "PWD=") != 0)
		var = var->next;
	if (!var && ft_strcmp(var->name, "PWD=") != 0)
		return ;
	i = ft_strlen(var->content);
	while (var->content[i] != '/')
		i--;
	ft_putcolor(&var->content[i + 1], YELLOW);
	return ;
}

void	ft_prompt(t_env *var)
{
	ft_putcolor("[", YELLOW);
	ft_pwdfolder(var);
	ft_putcolor("]", YELLOW);
	ft_putstr("$> ");
}
