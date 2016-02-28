/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 16:25:32 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 16:26:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isfile(char *filename)
{
	struct stat state;

	if (lstat(filename, &state) == -1)
		return (0);
	return (1);
}
