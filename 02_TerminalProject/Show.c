#include <ncurses.h>
#include <locale.h>

int main(const int argc, const char **argv)
{
    if (argc != 2) {
        return 0;
    }
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    printw("Файл : %s", argv[1]);
    refresh();
    WINDOW *win = newwin(LINES - 1, COLS, 1, 0);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    char *string;
    size_t buf;
    int x, y, len; 
    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL) {
        return 1;
    }
    for (int i = 0; i < 99999; ++i) {
        len = getline(&string, &buf, file);
        if (len == -1) {
            break;
        }
        getyx(win, x, y);
        if ((x + len/COLS + 1) >= LINES - 3){
            break;
        }
        wprintw(win, "%s", string);

    }
    int key;
    key = wgetch(win);
    while (key != 27) {
        if (getline(&string, &buf, file) != -1 && key == 32 ) {
            wprintw(win, "%s", string);
        }
        key = wgetch(win);
    }
    fclose(file);
    delwin(win);
    endwin();


    return 0;
}
