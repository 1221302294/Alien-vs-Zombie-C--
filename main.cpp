// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                         //
// Emails: 1221302637@student.mmu.edu.my | 1221302694@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                      //
// ************************************************************************** //

// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                       //
// Emails: 1221302637@student.mmu.edu.my | 1221302294@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                     //
// ************************************************************************** //

#include "subfile/mainheader.h"
#include <iostream>

using namespace std;

Enemy zombie;
movement alien;

vector<vector<char>> map_; // Gameboard vector
int dimX_ = 9, dimY_ = 3, zomB_ = 1;   // variables for the initial gameboard

char h, x;

void emptymap(int dX, int dY)
{
    map_.resize(dY); // create empty rows
    for (int i = 0; i < dY; ++i)
    {
        map_[i].resize(dX); // resize each row
    }
}

void init(int dimX, int dimY, int zomb)
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

    char zomBie[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};  
    int noOfObjects = 10;  // number of objects in the objects array

    // create dynamic 2D array using vector
    emptymap(dimX_, dimY_);

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
			h = randObject(x);
            map_[i][j] = h;
        }
    }

    // put random zombies into the vector array 
    for (int i = 0; i < zomB_; ++i)
    {
        int randY = rand() % dimY_;
        int randX = rand() % dimX_;
        map_[randY][randX] = zomBie[i];
    }

    // Alien in the middle of the gameboard
    int y = dimY_ / 2;
    int x = dimX_ / 2;
    char Alien[] = "A";
    map_[y][x] = Alien[0];

}

void display() 
{
    ClearScreen();
    cout << " ****************************** " << endl;
    cout << " *    .:'Alien vs Zombie':.   * " << endl;
    cout << " ****************************** " << endl;

    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

// set the number of column
int setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}
// set the number of row
int setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}
// set the object into map_
vector<vector<char>> setmap(int y, int x, char obj)
{
    map_[y][x] = obj;
    return map_;
}
// set the number of zombies
int setZomB(int z) 
{
    zomB_ = z;
    return zomB_;
}
// get the number of column
int getDimX() 
{
    return dimX_;
}
// get the number of row
int getDimY() 
{
    return dimY_;
}
// get the number of zombies
int getZomB() 
{
    return zomB_;
}
// get object from the map_
char getObject(int y, int x) 
{
    return map_[y][x];
}

// game setting screen
void changesetting()
{
    ClearScreen();
    int x, y, z;  
    cout << endl; // -> next line when input 'y/n' entered
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    cout << " Zombie Settings " << endl;
    cout << "-----------------" << endl;
    cout << " Enter number of zombies => ";
    cin >> z;
    cout << endl;

    if (x % 2 == 0 || y % 2 == 0) //restriction for only accepting odd numbers and range of zombies within 1 until 9
    {
        cout << "Rows and Columns must be odd numbers.\n\n";
    }

    else
    {
        if (z < 1 || z > 9)
        {
            cout << "Zombies can only within the range of 1 until 9. " << std::endl;
        }

        else
        {  
            setDimX(x);
            setDimY(y);
            setZomB(z); 
            cout << "z " ;
            cout << z << endl;
            init(x, y, z);
            display(); 
            int no = zomB_; 
            alien.alienstat();
			zombie.zombiegen(no); 
			play();
        }
    }
}

// initial gameboard initialization
void Board()
{
    ClearScreen();
    srand(1);
    display();
    int no = zomB_;
    alien.alienstat(); 
	zombie.zombiegen(no); 
	play();
}
// zombie display GUI
void zomdisplay(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
    }
    cout << endl;
}

int *getZomHP(int num)
{
    int numZ = num;
    static int Zhp[9];

    for (int i = 0; i < numZ; i++)
    {
        Zhp[i] = zombie.ZHpVec[i];
    }
    return Zhp;
}

int *getZomAtk(int numZom)
{
    int Zonum = numZom;
    static int Zatk[9];

    for (int i = 0; i < numZom; i++)
    {
        Zatk[i] = zombie.ZAtkVec[i];
    }
    return Zatk;
}

int *getZomRge(int numofZ)
{
    int Znumber = numofZ;
    static int Zrge[9];

    for (int i = 0; i < Znumber; i++)
    {
        Zrge[i] = zombie.ZRngVec[i];
    }
    return Zrge;
}

// Main function
int main() 
{
	init(dimX_, dimY_, zomB_);
	displayMenu();
}

//execution < g++ Sub\*.cpp main.cpp >
