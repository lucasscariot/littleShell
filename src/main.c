/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/02 17:08:46 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**sep;
	t_env	*var;

	signal(SIGINT, ft_wtf);
	(void)av;
	(void)ac;
	var = ft_env(env);
	ft_prompt(var);
	while (get_next_line(0, &line) > 0)
	{
		sep = ft_strsplit(line, ' ');
		if (ft_cmd(sep, var))
			break ;
		free(line);
		ft_free_tab(sep);
		ft_prompt(var);
	}
	ft_strdel(&line);
	if (sep)
		ft_free_tab(sep);
	if (var)
		ft_free_list(var);
	return (0);
}
