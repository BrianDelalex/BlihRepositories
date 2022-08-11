/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

/* C INCLUDES */
#include "color.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

#include "cmp_macro.h"

extern char **environ;

typedef struct list_a
{
    struct list_a   *prev;
    int             data;
    struct list_a   *next;
} list;

typedef struct info_t
{
    int iter;
    int size;
    int bol;
    int nbr_null;
} info_t;

typedef struct control_s
{
    int redirect;
    int rtn;
}control_t;

typedef struct pip_red_t
{
    int pipe;
    int red;
    int chev;
    int pipefd[2];
    pid_t pid1;
    pid_t pid2;
} pip_red_t;

/* BUILT IN */
void initialisation_struct(pip_red_t *pr);
int cmp_redirection(char *inp, int nbr, int chev);
int red(char *inp, char ***environ, pip_red_t *pr);
void close_all(int *pfd, int fd);
void wait_and_close(pid_t pid, char *bin, int *fd);
void exec_inf(char **com, char ***env, char *file, pip_red_t *pr);
void exec_sup(char **com, char ***env, char *file, pip_red_t *pr);
int redirections_exec(char **com, char ***environ, char *bin, pip_red_t *pr);
int command_not_found(char *);
int call_complete(char *str);
int check_exit(char *input);
void redirections(char *inp, char ***environ, int chev, pip_red_t *pr);
int loop_command_tab(char ***environ, char **com, char **cur_dir, size_t s);
int exec_with_pipe(char *, char ***env, char **com, pip_red_t *pipe);
void wait_return(int pid, char *path_binary);
char *regex_space(char *str);
void pipe_exec(char *com, char ***environ, pip_red_t *pr);
char *strconcat(char *s1, char *s2);
int strncp(char *, char *, int);
int unset_use_value(char *, char ***);
int check_valid(char *, char **);
char *cd_option_more(char ***, char *, char *);
int check_f_d(char *);
char *find_bin(char **, char *);
int well_line(char *);
char *cut_arguments(char *);
int check_system_binary(char *, char ***, pip_red_t *pr);
char *cd_home(char ***);
char *give_path(char **);
int find_env(char **, char *);
void check_command(char *, char ***, pip_red_t *pr);
int check_command_more(char *, char ***, pip_red_t *pr);
char *oldpwd_path(char *, char ***);
int check_dir(char *);
void change_env_oldpwd(char ***, int);
char *change_env_pwd(char *);
char **real_command(char *);
char *binary_system(char *, char ***, int);
char *cut_path(char *);
int check_name(char *, char *);
char *cut_command(char *);
int check_nbr_arg(char *);
char **my_setenv(char *, char **);
char **my_unsetenv(char *, char **);
char *cd_function(char *, char *, char ***);
void loop_minishell(void);
int echo_function(char *input);
char **cut_input_to_tab(char *input);
int exec_and_redirect_in_file(char **input, int i, int end);
int check_redirect_char(char *str);
int check_stat(struct stat *st, char **path, char **env);
int check_exec_right(struct stat st, char *path);
char **cut_bin(char *input);
char *remove_char_from_str(char *str);
char get_last_char_str(char *str);
char *my_strconcat(char *str1, char *str2);
char *my_strdup(char *src);
int my_strstr2(char *str1, char *str2);
int exec_buffering_bin(char **input, int i);
int env_var_exist(char **env, char const *var);
int exec_with_modified_input(char **input_tab, int i);
int exec_pipe(char **input, int i);
int exec_bin(char **environ, char *input);
void display_bin_error(int wstatus);
int is_a_builtin(char *cmd, char ***environ);
char *give_curent_dir(char ***environ);
int start_command_line(char **cmds, char ***environ);
control_t *set_control(void);
int free_control(control_t *ctrl);
void free_input_ressources(char *input, char **com);
char ***initiate_env(char ***env, char *cur_dir);

/* LIB */
void free_tab(char **);
char *get_next_line(int);
char *int_to_char(int);
void puterror(char *);
int my_strcmp(char *s1, char *s2);
int len_tab(char **);
list *my_params_to_list(char **argv, int argc);
char **str_to_tab(char *, char);
int nbr_char_str(char *, char);
list *circle_double_list(char **, int);
char **pars_file(char **);
int my_printf(char const *, ...);
char **fill_in_pars(char const *, char **);
void switch_type_1(char **, int, va_list);
void function_flags(char **, int);
void oct_convert(int);
char *helping_flag(char **, int, int, char *);
void hexa_convert(long);
char *call_hex_convert(int, char *, int);
void case_c(va_list);
void case_x(va_list);
void case_o(va_list);
void case_s(va_list);
void case_ss(va_list, int);
void case_b(va_list);
void case_p(va_list);
void case_u(va_list);
void case_d(va_list);
void case_pourcent();
int my_getnbr(char const *);
int my_put_nbr(int);
void my_put_tab(char **);
char *my_revstr(char *);
int my_strlen(char const *);
char *my_strcpy(char *, char *);
char *my_strcopy(char *, char *);
char *my_strstr(char  *, char *);
void my_putstr(char *);
void my_putchar(char);


#endif
