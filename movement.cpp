#include <iostream>
#include <vector>
using namespace std;

//to group datas
struct Character
{
   int row;
   int col;
   int health;
   int attack = 0; 
   int ranged;
};

//transform into array 
void setDimension(vector< vector<char> >& board, int& row, int& col, char element)
{
   board[row][col] = element;
}

//get the dimension from the array set earlier
char getDimension(vector< vector<char> > board, int row, int col)  
{
   return board[row][col];
}

void movementAbstract(Character alien, vector<Character> zombies)
{
   cout << endl;
   if (alien.health > 0)
   {
      cout << "Alien      :" << "Life   " << alien.health << ", " << "Attack   " << alien.attack << endl;

   }
   else if (alien.health <= 0)
   {
      cout << "Alien      :" << "DEAD   " << endl; 
   }

   for (int i = 0; i < zombies.size(); i++)
   {
      if (zombies.at(i).health > 0)
      {
         cout << "Zombie " << i+1 << "   :"<< "Life   " << zombies.at(i).health << ", " << "Attack   " << zombies.at(i).attack << ", " << "Range   " << zombies.at(i).ranged << endl;
      }
   }
   cout << endl;
}


void alienMovement(vector <vector<char>>& board, int rows, int cols, Character& alien, vector<Character>& zombies, string command) {                               

bool End = false;
int newRow = alien.row;
int newCol = alien.col; 
//add a constant so no error
const char Trail = '.';

while (!End)
    {
        system("CLS");
        
        movementAbstract(alien, zombies);

        setDimension(board, newRow, newCol, Trail);

        if ( command == "up")
        {
            newRow--;
        }

        else if (command == "down")
        {
            newRow++;
        }

        else if (command == "left")
        {
            newCol--;
        }

        else if (command =="right")
        {
            newCol++;
        }

    }
}

void zombiesMovement(vector< vector<char> >& board, int rows, int cols, Character& zombie, int counter)
{
   srand(time(0));
   int bias = rand() % 3;
   int newRow = zombie.row;
   int newCol = zombie.col;
   //add a constant here too so no error :D
   const char SPACE = ' ';

   setDimension(board, zombie.row, zombie.col, SPACE);

   if (bias == 0)   
      { 
         newRow--;
      } 
   else if (bias == 1)
      {
         newRow++;
      }
   else if (bias == 2)
      {
         newCol--;
      }
   else if (bias == 3)
      {
         newCol++;
      }
}