/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:43:29 by lucas             #+#    #+#             */
/*   Updated: 2016/03/02 22:21:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *cmd, t_env *var)
{
	char	**tmp;
	char	*der;
	int		i;
	char	*scm;

	i = 0;
	if (ft_isfile(cmd))
		return (ft_strdup(cmd));
	scm = ft_strjoin("/", cmd);
	tmp = ft_strsplit(ft_search_content(var, "PATH"), ':');
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		der = ft_strjoin(tmp[i], scm);
		if (ft_isfile(der))
		{
			free(scm);
			ft_free_tab(tmp);
			return (der);
		}
		free(der);
		i++;
	}
	free(scm);
	ft_free_tab(tmp);
	return (NULL);
}
