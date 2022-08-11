/*
** EPITECH PROJECT, 2019
** netcode
** File description:
** color
*/

#ifndef _COLOR_H_
#define	_COLOR_H_

/* NORMAL COLORS */

#define BLACK		"\033[0;30m"
#define RED		    "\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define PURPLE		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define GREY		"\033[0;37m"
#define WHITE		"\033[0;38m"
#define DEFAULT 	"\033[0;m"

/* BOLD COLORS */

#define BLACK_B		"\033[1;30m"
#define RED_B		"\033[1;31m"
#define GREEN_B		"\033[1;32m"
#define YELLOW_B	"\033[1;33m"
#define BLUE_B		"\033[1;34m"
#define PURPLE_B	"\033[1;35m"
#define CYAN_B		"\033[1;36m"
#define GREY_B		"\033[1;37m"
#define WHITE_B		"\033[1;38m"

/* UNDERLINED COLORS */

#define BLACK_U		"\033[4;30m"
#define RED_U		"\033[4;31m"
#define GREEN_U		"\033[4;32m"
#define YELLOW_U	"\033[4;33m"
#define BLUE_U		"\033[4;34m"
#define PURPLE_U	"\033[4;35m"
#define CYAN_U		"\033[4;36m"
#define GREY_U		"\033[4;37m"
#define WHITE_U		"\033[4;38m"

/* TWINKLING COLORS */

#define BLACK_T		"\033[5;30m"
#define RED_T		"\033[5;31m"
#define GREEN_T		"\033[5;32m"
#define YELLOW_T	"\033[5;33m"
#define BLUE_T		"\033[5;34m"
#define PURPLE_T	"\033[5;35m"
#define CYAN_T		"\033[5;36m"
#define GREY_T		"\033[5;37m"
#define WHITE_T		"\033[5;38m"

/* COLORS IN FONT */

#define BLACK_F		"\033[7;30m"
#define RED_F		"\033[7;31m"
#define GREEN_F		"\033[7;32m"
#define YELLOW_F	"\033[7;33m"
#define BLUE_F		"\033[7;34m"
#define PURPLE_F	"\033[7;35m"
#define CYAN_F		"\033[7;36m"
#define GREY_F		"\033[7;37m"
#define WHITE_F		"\033[7;38m"

#define OK_G	GREEN_B"OK\n"DEFAULT_COLOR

#endif /* _COLOR_H_ */