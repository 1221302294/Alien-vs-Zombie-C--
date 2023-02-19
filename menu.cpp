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

void getMenu() {
    while (true) {
        ClearScreen();
        cout << " -------------------------- " << endl;
        cout << "|     Alien VS Zombie     |" << endl;
        cout << " -------------------------- " << endl;
        cout << " 1. PLAY" << endl;
        cout << " 2. CONTINUE" << endl;
        cout << " 3. CONTROLS" << endl;
        cout << " 4. QUIT" << endl;
        cout << endl;
        cout << ">>> ENTER: ";
        char op;
        cin >> op;

        if (op == '1') {
            playmenu();
        } else if (op == '2') {

        } else if (op == '3') {
            controls();
        } else if (op == '4') {
            exit(0);
        } else {
            cout << "Invalid! Try again" << endl;
            Pause();
        }
    }
}

void controls() {
    ClearScreen();
    cout << endl;
    cout << " --------------------------------------------- " << endl;
    cout << "|               Alien VS Zombie               |" << endl;
    cout << " --------------------------------------------- " << endl;
    cout << endl;
    cout << "                  CONTROLS                     " << endl;
    cout << "| up    //Alien to move up.                   |" << endl;
    cout << "| down  //Alien to move down.                 |" << endl;
    cout << "| left  //Alien to move left.                 |" << endl;
    cout << "| right //Alien to move right.                |" << endl;
    cout << "| arrow //Switch the direction of             |" << endl;
    cout << "|       //an arrow object in the game board.  |" << endl;
    cout << "| help  //List and describe the commands      |" << endl;
    cout << "|       //that the player can use in the game.|" << endl;
    cout << "| save  //Save the current game to a file.    |" << endl;
    cout << "| load  //Load a saved game from a file.      |" << endl;
    cout << "| quit  //Quit the game while still in play.  |" << endl;
    cout << endl;
    Pause();
}

void help() {
    ClearScreen();
    cout << endl;
    cout << " Commands " << endl;
    cout << endl;
    cout << " up    - Move up. " << endl;
    cout << " down  - Move down. " << endl;
    cout << " left  - Move left. " << endl;
    cout << " right - Move right. " << endl;
    cout << " arrow - Switch the direction of an arrow. " << endl;
    cout << " help  - Display user commands. " << endl;
    cout << " save  - Save the game. " << endl;
    cout << " load  - Load a  game. " << endl;
    cout << " quit  - Quit the game. " << endl;
    cout << endl;
}

void playmenu() {
    while (true) {
        ClearScreen();
        cout << "     Game Settings     " << endl;
        cout << "-----------------------" << endl;
        cout << " Board Rows     : " << getDimY() << endl;
        cout << " Board Columns  : " << getDimX() << endl;
        cout << " Zombie Count   : " << getZomB() << endl;
	}
}