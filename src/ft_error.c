/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:33:25 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 19:38:02 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_cmd(char *cmd)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd);
}

void	ft_error_cd(char *path)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(path);
}
