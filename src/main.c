/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/02/27 18:20:54 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;

	(void)av;
	(void)ac;
	(void)env;
	while (42)
	{
		ft_putstr("lscariot");
		ft_putstr(" $> ");
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			break ;
		if (ft_strlen(line))
			ft_putendl(line);
		free(line);
	}
	free(line);
}
