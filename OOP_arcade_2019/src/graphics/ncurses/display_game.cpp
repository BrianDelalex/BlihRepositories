#include "my_ncurses.hpp"
#include <fstream>
#include <vector>

extern WINDOW *win;

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

extern "C" int display_game(arcd::render *rd)
{
    int key = 0;
	wclear(win);
    draw_map(rd->map);
    draw_player(*rd->ply);
	draw_ennemies(rd->ennemies);
	draw_texts(rd->texts);
	wrefresh(win);
    key = getch();
    return (key);
}

// int main(void)
// {
//     int starty = 1, startx = 1;
    

//     std::ifstream file;
//     std::string str;
//     std::vector<std::string> map;
//     file.open("/home/bdelalex/delivery/OOP/OOP_arcade_2019/ressources/games/pacman/map0.txt");
//     if (!file.is_open())
//         std::cout << "ERROR WHILE READING: /home/bdelalex/delivery/OOP/OOP_arcade_2019/ressources/games/map0.txt\n";

//     while (std::getline(file, str, '\n'))
//     {
//         std::cout << str << std::endl;
//         map.push_back(str);
//     }
//     initscr();
//     cbreak();
//     noecho();
//     refresh();
//     win = create_window(LINES, COLS, 0, 0);
//     mvwprintw(win, 0, 10, "PacMan");
//     wrefresh(win);
//     draw_map(win, &map);
//     while ((key = getch()) != 32) {
//     }
//     endwin();
//     return (0);
// }