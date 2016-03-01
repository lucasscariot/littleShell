/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/01 20:40:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**sep;
	t_env	*var;

	(void)av;
	(void)ac;
	var = ft_env(env);
	while (42)
	{
		ft_prompt(var);
		get_next_line(0, &line);
		sep = ft_strsplit(line, ' ');
		if (ft_cmd(sep, var))
			break ;
		free(line);
		ft_free_tab(sep);
	}
	free(line);
	ft_free_tab(sep);
	ft_free_list(var);
	return (0);
}
