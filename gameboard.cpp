// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                       //
// Emails: 1221302637@student.mmu.edu.my | 1221302294@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                     //
// ************************************************************************** //
#include "mainheader.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 
using namespace std;

    gameBoard::gameBoard(int dimX, int dimY, int zomb)
{
    init(dimX, dimY, zomb);
}

void gameBoard::init(int dimX, int dimY, int zomb)
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

    char objects[] = {'^', 'v', '<', '>', ' ', ' ', 'h', 'r', 'p',' '};
    char zomBie[] = {'1','2','3','4','5','6','7','8','9'};
    int NObjects = 10;

    // create dynamic 2D array using vector
    map_.resize(dimY_);
    for(int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }
    // put random characters into the vector array
    for(int i = 0; i < dimY_; ++i)
    {
        for(int j = 0; j < dimX_; ++j)
        {
            int objno = rand() % NObjects;
            map_[i][j] = objects[objno];
        }
    }

    // put random character into the vector array 
    for (int i = 0; i < zomB_; ++i)
    {

        int randY = rand() % dimY_;
        int randX = rand() % dimX_;
        map_[randY][randX] = zomBie[i];
    }

    int y = dimY_ / 2;
    int x = dimX_ / 2;
    char Alien[] = {"A"};
    map_[y][x] = Alien[0];

    char Zombie[] = {};
}

void gameBoard::display()
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "      .: Alien vs Zombie :.     " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    
    //for each row
    for(int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        //display row number
        int rown = (i+1);
        cout << setw(2) << rown;

        //display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if(digit == 0)
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
    cout << endl << endl;
}

int gameBoard::setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}

int gameBoard::setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}

int gameBoard::setZomB(int z) 
{
    zomB_ = z;
    return zomB_;
}

int gameBoard::getDimX() const
{
    return dimX_;
}

int gameBoard::getDimY() const
{
    return dimY_;
}
int gameBoard ::getZomB() const 
{
    return zomB_;
}

char gameBoard::getObject(int x, int y) const
{
    return map_[dimY_-y][x-1];
}

void changesetting()
{
    gameBoard board;
    int x, y, z;  
    cout << endl; // next line when input 'y/n' entered
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    cout << " Enter zombies => "; 
    cin >> z;
    cout << endl;

    if (x % 2 == 0 || y % 2 == 0) //accepting odd numbers and range of zombies within 1 until 9
    {
        cout << "Rows and Columns must be odd numbers.\n\n";
    }

    else
    {
        if (z < 1 || z > 9)
        {
            cout << "Zombies can only within the range of 1 until 9. " << endl;
        }

        else
        {
            board.setDimX(x);
            board.setDimY(y);
            board.setZomB(z);
            board.init(x, y, z);
            board.display();
        }
    }
}
void program()
{
    gameBoard board;
    board.display();
}

int main()
{
    srand(time(NULL));

    program();
}

