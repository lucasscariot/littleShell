/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:41:33 by lucas             #+#    #+#             */
/*   Updated: 2016/03/02 12:16:04 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwdfolder(t_env *var)
{
	int		hoo;

	if ((hoo = ft_search_var(var, "PWD")) < 0)
	{
		ft_putcolor("unknow", RED);
		return ;
	}
	while (hoo--)
		var = var->next;
	ft_putcolor(var->content, YELLOW);
	return ;
}

void	ft_prompt(t_env *var)
{
	(void)var;
	ft_putcolor("[", YELLOW);
	ft_pwdfolder(var);
	ft_putcolor("]", YELLOW);
	ft_putstr("$> ");
}
