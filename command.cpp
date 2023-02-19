// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                       //
// Emails: 1221302637@student.mmu.edu.my | 1221302294@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                     //
// ************************************************************************** //

#include "MainHeader.h"
using namespace std;

// Command of the game
void play()
{
    // Initialize the movement object
    movement move;

    // Check if there is a saved game to load
    int ChkLoadSta = GetLoad();

    // If a saved game exists, get the alien's coordinates from the saved game
    int x, y;
    if (ChkLoadSta == 1)
    {
        x = GetAlienX();
        y = GetAlienY();
    }
    // Otherwise, set the alien's coordinates to the center of the game board
    else
    {
        x = getDimX() / 2;
        y = getDimY() / 2;
    }
    move.setalienX_(x);
    move.setalienY_(y);

    // Loop indefinitely to accept player commands
    while(true)
    {
        // Get the player's command
        string con;
        cout << " Command " ;
        cin >> con ;

        // Move the alien based on the player's command
        if (con == "up") move.move_up();
        else if (con == "down") move.move_down();
        else if (con == "left") move.move_left();
        else if (con == "right") move.move_right();
        else if (con == "arrow")
        {
            // Get the arrow's coordinates and direction from the player
            cout << "Please input based on the format, x y direction(up/down/left/right)";
            int arY, arX;
            string ardir;
            cin >> arX >> arY >> ardir;
            move.move_arrow(arX, arY, ardir);
        }
        else if (con == "help")
        {
            // Display the help menu
            help();
            Pause();
            display(); 
            int no = getZomB(); 
            move.alienstat();
            zomdisplay(no);
        }
        else if (con == "save")
        {
            // Save the current game state
            fileExist();
        }
        else if (con == "load")
        {
            // Load a saved game state
            loadmap();
            Board();
        }
        else if (con == "quit")
        {
            // Quit the game
            exit(0);
        }
        else
        {
            // Invalid command
            cout << "Invalid input" << endl;
        }
    }
}
