/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:43:29 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 19:51:21 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *cmd, t_env *var)
{
	char	**tmp;
	char	*der;
	int		hoo;
	int		i;

	i = 0;
	if ((hoo = ft_search_var(var, "PATH")) < 0)
		return (NULL);
	while (hoo--)
		var = var->next;
	tmp = ft_strsplit(var->content, ':');
	while (tmp[i])
	{
		der = ft_strjoin(tmp[i], cmd);
		if (ft_isfile(der))
		{
			ft_free_tab(tmp);
			return (der);
		}
		free(der);
		i++;
	}
	ft_free_tab(tmp);
	return (NULL);
}
