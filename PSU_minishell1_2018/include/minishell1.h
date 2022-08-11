/*
** EPITECH PROJECT, 2019
** minishell1.h
** File description:
** header for minishell1
*/

#ifndef MINISHELL1_H_
#define MINISHELL1_H_

extern char **environ;

typedef struct s_ctrl
{
    char **fctn;
    char *pwd;
}t_ctrl;

void find_function(t_ctrl *ctrl, char *input);
t_ctrl *set_control(void);
char *use_getline(void);
int my_putstr(char const *str);
int my_strlen(char const *str);
char **add_char_to_tab(char *str, char **str_tab);
int my_strstr(char *str1, char *str2);
char **remove_str_to_tab(char **tab, int index);
void my_puttab(char **tab);
void exec_cd(char ***environ, char *input, t_ctrl *ctrl);
int my_putstr(char const *str);
char *remove_char_from_str(char *str);
void free_values(t_ctrl *ctrl);
void exec_exit(t_ctrl *ctrl);
char *my_strconcat(char *str1, char *str2);
void exec_setenv(char ***environ, char *input);
void exec_unsetenv(char ***environ, char *input);
int my_strcmp(char *str1, char *str2);
char **my_str_to_tab(char *str, char c);
char *my_tab_to_str(char **tab, char c);
int exec_bin(char **environ, char *input);
char *cut_repetitiv_char(char *str, char c);
int my_puterror(char const *str);
int my_printf(char *str, ...);
void my_putnbr(int i);
char *cut_tab(char *str);
void go_root(char ***env, t_ctrl *ctrl);
void handle_one_char_cd_path(char *input, char ***environ, t_ctrl *ctrl);
void go_home(char ***environ, t_ctrl *ctrl);
char get_last_char_str(char *str);

#endif
