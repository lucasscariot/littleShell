/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 16:36:14 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 16:56:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_swap_cpy(t_env *dest, t_env *src)
{
	dest->name = ft_strdup(src->name);
	dest->content = ft_strdup(src->content);
}

void	ft_swap_list(t_env *f, t_env *s)
{
	t_env	*tmp;

	if (!f && !s)
		return ;
	tmp = (t_env*)malloc(sizeof(t_env));
	ft_swap_cpy(tmp, s);
	ft_free_one(s);
	ft_swap_cpy(s, f);
	ft_free_one(f);
	ft_swap_cpy(f, tmp);
	ft_free_one(tmp);
	free(tmp);
}
