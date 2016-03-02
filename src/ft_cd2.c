/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:43:19 by lscariot          #+#    #+#             */
/*   Updated: 2016/03/02 14:11:01 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_ret_content(t_env *var, char *name)
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
