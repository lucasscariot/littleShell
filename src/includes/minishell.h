/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:41 by lucas             #+#    #+#             */
/*   Updated: 2016/03/24 00:13:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/stat.h>
# include <signal.h>
# include "libft.h"

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

int					ft_cmd(char **line, t_env *var);
t_env				*ft_env(char **env);
void				ft_show_env(t_env *var);
void				ft_shlvl(t_env *var);
void				ft_change_directory(t_env *var, char *path);
void				ft_prompt(t_env *var);
t_env				*ft_save_env(t_env *var, char *put);
int					ft_search_var(t_env *var, char *name);
char				*ft_search_content(t_env *var, char *name);
void				ft_free_tab(char **tab);
void				ft_del_env(t_env *var, char *name);
t_env				*ft_set_env(t_env *var, char *put);
void				ft_free_one(t_env *var);
void				ft_free_list(t_env *var);
void				ft_wtf(int i);
int					ft_isfile(char *filename);
void				ft_swap_list(t_env *f, t_env *s);
char				*ft_path(char *cmd, t_env *var);
void				ft_error_cmd(char *cmd);
void				ft_error_cd(char *path);
char				**ft_conv_env(t_env *var);
char				*ft_get_absolute(void);
char				**ft_split(char *s, int f);

#endif




