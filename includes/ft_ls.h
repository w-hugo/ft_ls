/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:40:16 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 19:19:55 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/syslimits.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft.h"

# define MALLOC_FAIL 1001
# define ILLEGAL_OPT 1002
# define EPERM_SINGLE 1003
# define MAX_PATH 2048

typedef struct			s_options
{
	int					a;
	int					d;
	int					f;
	int					l;
	int					g;
	int					big_g;
	int					r;
	int					big_r;
	int					t;
	int					u;
}						t_options;

typedef struct			s_filelist
{
	char				*full_path;
	char				*d_name;
	unsigned char		d_type;
	struct stat			stat;
	struct timespec		time;
	int					single;
	int					from_arg;
	struct s_filelist	*next;
}						t_filelist;

typedef struct			s_env
{
	struct s_options	*options;
	int					exit_status;
	int					nb_dirs;
	size_t				total;
	int					depth;
}						t_env;

/*
**  FILE SET_ENV.C
*/
void					init_env(t_env *e);
void					free_env(t_env *e);

/*
**  FILE PARSE.C
*/
void					handle_directory(t_env *e, char *path);
void					parse_args(t_env *e, int ac, char **av);

/*
**  FILE PATH_CONCAT.C
*/
char					*strjoin_path(char *old_path, char *d_name);
char					*get_file_path(char *path);
char					*get_dir_path(char *path, int single);

/*
**  FILE HANDLE_ERRORS.C
*/
void					*print_err(const char *err, int err_no, int quit);

/*
**  FILE ARGS_TO_LIST.C
*/
int						args_to_list(t_filelist **dirlist, char *path);

/*
**  FILE FILE_LISTS.C
*/
void					free_file_list(t_filelist **files);
void					reverse_list(t_filelist **head_ref);
t_filelist				*new_file(struct dirent *file, char *path,\
	size_t *total, int single);
void					add_file(t_filelist **filelist, t_filelist *new);

/*
**  FILE SWAP_FILES.C
*/
void					file_swap(t_filelist **a, t_filelist **b);
int						file_cmp(t_options *opt, t_filelist *a, t_filelist *b);

/*
**  FILE MERGE_SORT.C
*/
void					sort_files(t_env *e, t_filelist **to_sort);
void					bubble_sort(t_env *e, t_filelist **to_sort);
t_filelist				*merge_sorted_list(t_env *e, t_filelist *a,\
	t_filelist *b);
void					split_list(t_filelist *source,\
	t_filelist **front, t_filelist **back);

/*
**  FILE PRINT_FILES.C
*/
void					print_file(t_env *e, t_filelist *file_list);

/*
**  FILE PRINT_LONG.C
*/
void					print_long_format(t_env *e, t_filelist *file);
void					put_color(t_options *opt, t_filelist *file);

/*
**  FILE HANDLE_ACL.C
*/
int						print_acl(t_filelist *file);
void					print_permissions(t_filelist *file);

/*
**  FILE MAIN.C
*/
t_filelist				*read_dir(t_env *e, char *path, char *fname,\
	int flag);
void					queue_dir(t_env *e, char *path, t_filelist *print,\
	int single);
void					queue_next_dir(t_env *e, t_filelist *head, char *path);

#endif
