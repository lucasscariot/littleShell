/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:33:25 by lucas             #+#    #+#             */
/*   Updated: 2016/03/24 14:54:05 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split(char *s, int f)
{
	char	**tab;
	char	**esp;
	char	**res;
	int		i;
	int		j;

	i = 0;
	f = 0;
	tab = ft_strsplit(s, '\t');
	res = malloc(sizeof(char*) * 15);
	while (tab[i])
	{
		esp = ft_strsplit(tab[i], ' ');
		j = 0;
		while (esp[j])
			res[f++] = ft_strtrim(esp[j++]);
		ft_free_tab(esp);
		i++;
	}
	res[f] = NULL;
	ft_free_tab(tab);
	return (res);
}

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
