/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:41 by lucas             #+#    #+#             */
/*   Updated: 2016/02/28 12:02:03 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define FT_LS_H

# include "libft.h"

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

int					ft_cmd(char **line, t_env *var, char **test);

t_env				*ft_env(char **env);
void				ft_show_env(t_env *var);
void				ft_shlvl(t_env *var);
void				ft_prompt(t_env *var);

t_env				*ft_save_env(t_env *var, char *put);
int					ft_search_var(t_env *var, char *name);

void				ft_free_tab(char **tab);
void				ft_del_env(t_env *var, char *name);
void				ft_free_one(t_env *var);
void				ft_free_list(t_env *var);
#endif
