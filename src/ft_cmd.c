/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:31:23 by lucas             #+#    #+#             */
/*   Updated: 2016/02/27 22:26:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cmd(char	*line, t_env *var)
{
	if (ft_strcmp(line, "env") == 0)
		ft_show_env(var);
	else if (ft_strcmp(line, "exit") == 0)
		return (1);
	return (0);
}
