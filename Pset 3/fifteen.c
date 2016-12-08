/**
 * fifteen.c
 *
 * CS50 AP
 * Name: Olivia Brown
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 */

// necessary for usleep
#define _XOPEN_SOURCE 500

// libraries to include
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// globally declared board
int board[DIM_MAX][DIM_MAX];

// globally declared board dimension
int d;
int y;
int x;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // Calls greet function to welcome player
    greet();
    
    // Ends program if number of arguments is incorrect in call
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    
    // Ends program if dimension provided is invalid
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    else
    {
        x = (d - 1);
        y = (d - 1);
    }
 
    // open log file to record moves
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }
    
    // Calls init function to make array
    init();
    
    // accept moves until game is won
    while (true)
    {
        // Calls clear function to clear screen
        clear();
        
        // Calls draw function to draw board
        draw();
        
        // Log current state of the board
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        
        // Notifies the player that s/he has won
        if (won())
        {
            printf("You won!\n");
            break;
        }
        
        // Asks the user for which tile to move and collects it as a var
        printf("Tile to move: ");
        int tile = GetInt();
        
        // Quit if user inputs 0
        if (tile == 0)
        {
            break;
        }
        
        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);
        
        // Notifies user if a move is not allowed
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        
        // Suspends processing for 500000 microseconds
        usleep(500000);
    }
    
    // close log
    fclose(file);
    
    // Ends program if successfully completed
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the board with tiles numbered 1 through d*d - 1
void init(void)
{
    int n = 0;
    int dSquared = (d * d);
    
    // Iterate through row and through columns
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Initialize array counting from largest number down to dSquared-1
            n = n + 1;
            board[i][j] = (dSquared - n);
        }
    }
    // If d is even, switch 1 and 2 so that game can be won
    if ((d % 2) == 0)
    {
        int tempBoard = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = tempBoard;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    
    // Iterate over rows
    for (int i = 0; i < d; i++)
    {
        // Iterate over columns
        for (int j = 0; j < d; j++)
        {
            
            // Print number of tile except for 0 tile
            if (board[i][j] > 0)
            {
                printf("| %2d ", board[i][j]);
            }
            
            // For 0 tile, print space for tiles to move
            if (board[i][j] == 0)
            {
                printf("| __ ");
            }
        }
        // Print two lines after each row to construct board
        printf("|\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // Iterate through rows to find tile
    for (int i = 0; i < d; i++) 
    {
        // Iterate through columns to find tile
        for (int j = 0; j < d; j++) 
        {
            // If valid tile
            if (tile == board[i][j]) 
            {
                int blankspace = 0;       
 
                // Check if tile is next to blankspace
                if (((x == (i - 1)) && (j == y)) || ((x == (i + 1)) && (j == y))
                || ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
                {
                    // Swap tile if allowed
                    board[x][y] = tile;
                    board[i][j] = blankspace;
                    x = i;
                    y = j;
                    
                    return true;
                }   
            } 
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int finish = d * d - 1;
    int check = 1;
  
    // Iterate over board
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Checks if counting up from 1
            if (board[i][j] == check && check <= finish)
            {
                check = check + 1;
        }
            // Successfully iterated over entire board
            else if (check > finish)
            {
                return true;
            }
        }
  }
    // Check failed
    return false;
}