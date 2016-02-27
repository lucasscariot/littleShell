/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/02/27 22:25:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*var;

	(void)av;
	(void)ac;
	var = ft_env(env);
	while (42)
	{
		ft_putcolor("[Dieu]", YELLOW);
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (ft_cmd(line, var))
			break ;
		free(line);
	}
	ft_free_list(var);
	free(line);
	return (0);
}
