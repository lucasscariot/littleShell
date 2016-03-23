/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/23 12:22:33 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**sep;
	char	**test;
	t_env	*var;

	(void)av;
	(void)ac;
	signal(SIGINT, ft_wtf);
	var = ft_env(env);
	ft_prompt(var);
	while (get_next_line(0, &line) > 0)
	{
		test = ft_strsplit(line, '\t');
		sep = ft_strsplit(test[0], ' ');
		free(line);
		if (ft_cmd(sep, var))
			break ;
		ft_free_tab(sep);
		ft_prompt(var);
	}
	ft_free_list(var);
	return (0);
}
