// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                       //
// Emails: 1221302637@student.mmu.edu.my | 1221302294@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                     //
// ************************************************************************** //
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "mainheader.h"
using namespace std;

	void displayMenu()
    {
       do {
			ClearScreen();
			std::cout <<  " -------------------------- " << std::endl;
			std::cout <<  " |    .:Alien VS Zombie:.   |" << std::endl;
			std::cout <<  " -------------------------- " << std::endl;
			std::cout <<  " 1.	PLAY      	           " << std::endl;
			std::cout <<  " 2.	CONTINUE      	       " << std::endl;
			std::cout <<  " 2.	HELP        	       " << std::endl;
			std::cout <<  " 3.	QUIT			       " << std::endl;
			std::cout << std::endl;
			std::cout <<  ">>> ENTER (1,2,3)=>		           " << std::endl;
			char enter;
			std::cin >> enter;
			
			switch(enter) 
            {
				case '1':
					playmenu();
					break;
				case '2':
					//add load game function
					break;
				case '3':
					controls();
					break;
				case '4':
					exit(0);
					break;
				default:
					std::cout << "Invalid! Try again";
					break;
			}
			
		} while (1); 
    }

    void gameover()
    {
        ClearScreen();
		std::cout << "\n\n\t\t\tGAME OVER.";
		Pause();
    }

    void controls() {
		ClearScreen();
		std::cout << std::endl;
		std::cout <<  " --------------------------------------------- " << std::endl;
		std::cout <<  "|               Alien VS Zombie               |" << std::endl;
		std::cout <<  " --------------------------------------------- " << std::endl;
		std::cout << std::endl;
		std::cout <<  "                  CONTROLS                     " << std::endl;          
		std::cout <<  "| up    //Alien to move up.                   |" << std::endl;
		std::cout <<  "| down  //Alien to move down.                 |" << std::endl; 
		std::cout <<  "| left  //Alien to move left.                 |" << std::endl; 
		std::cout <<  "| right //Alien to move right.                |" << std::endl; 
		std::cout <<  "| arrow //Switch the direction of             |" << std::endl; 
		std::cout <<  "|       //an arrow object in the game board.  |" << std::endl;
		std::cout <<  "| help  //List and describe the commands      |" << std::endl; 
		std::cout <<  "|       //that the player can use in the game.|" << std::endl;
		std::cout <<  "| save  //Save the current game to a file.    |" << std::endl; 
		std::cout <<  "| load  //Load a saved game from a file.      |" << std::endl; 
		std::cout <<  "| quit  //Quit the game while still in play.  |" << std::endl; 
		std::cout << std::endl;
		Pause();
	}
   
    void help()
    {
		ClearScreen();
        std::cout << std::endl;
		std::cout <<  " COMMAND " << std::endl;
		std::cout << std::endl;         
		std::cout << "1. up      - Move up." << std::endl;
        std::cout << "2. down    - Move down." << std::endl;
        std::cout << "3. left    - Move left." << std::endl;
        std::cout << "4. right   - Move right." << std::endl;
        std::cout << "5. arrow   - Change the direction of an arrow." << std::endl;
        std::cout << "6. help    - Display these user commands." << std::endl;
        std::cout << "7. save    - Save the game." << std::endl;
        std::cout << "8. quit    - Quit the game." << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
		std::cout << std::endl;
	}
    
    void playmenu()
    {
        ClearScreen();
		do 
		{
			ClearScreen();
			std::cout << " Default Game Settings " << std::endl;
			std::cout << "-----------------------" << std::endl;
			std::cout << " Board Rows     : " << getDimY() << std::endl; 
			std::cout << " Board Columns  : " << getDimX() << std::endl; 
			std::cout << " Zombie Count   : " << getZomB() << std::endl; 
			std::cout << std::endl;
			std::cout << " Do you wish to change the game settings (y/n)? =>" << std::endl;
			char input;
			std::cin >> input;

			switch(input) 
			{
				case 'n':
					Board();
					break;
				case 'y':
					changesetting();
					break;
				case 'b':
					displayMenu();
					break;
				default:
					cout << "Invalid! Try again" << endl;
					Pause();
					break;
			}
		} while (1);
	}