/****************************************************************************
 * sudoku.h
 *
 * CS50 AP
 * Sudoku (Part 1)
 *
 * Compile-time options for the game of Sudoku.
 ***************************************************************************/

// game's author
#define AUTHOR "Olivia Brown"

// game's title
#define TITLE "Sudoku"

// banner's colors
#define FG_BANNER COLOR_CYAN
#define BG_BANNER COLOR_WHITE

// grid's colors
#define FG_GRID COLOR_CYAN
#define BG_GRID COLOR_WHITE

// border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_CYAN

// logo's colors
#define FG_LOGO COLOR_WHITE
#define BG_LOGO COLOR_BLACK

// digits's colors
#define FG_DIGITS COLOR_CYAN
#define BG_DIGITS COLOR_WHITE

// nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_DIGITS };
