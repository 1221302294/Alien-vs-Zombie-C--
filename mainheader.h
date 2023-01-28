// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT1L                                                               //
// Names : CHOO CHEE CHOONG              | TAN TING LI                        // 
// IDs   : 1221302637                    | 1221302294                       //
// Emails: 1221302637@student.mmu.edu.my | 1221302294@student.mmu.edu.my      //
// Phones: 010-2675333                   | 017-9325346                     //
// ************************************************************************** //
#include <vector> 
#ifndef MAINHEADER_H
#define MAINHEADER_H


    void ClearScreen(); // (from tutorial)
    void Pause(); // (from tutorial)
    void displayMenu(); // cc (from tutorial)
    void controls(); // cc (from tutorial)
    void gameover(); // tingli
    void help(); // cc
    void playmenu(); // cc
    void changesetting(); // tingli
    void Board(); // cc
    void zombiestat(int no); // tingli
    void alienstat(); // tingli
    void settings();
    void defplay();
    void play();

//Class-----------------------------------------------------------------------------------------

class gameBoard // cc&tingli (from tutorial)
{
    private:  
        int dimX_, dimY_;   // to indicate private data
    
    public:
        std::vector<std::vector<char>> map_; // convention to put trailing underscore
        int zomB_;

        gameBoard(int dimX = 19, int dimY = 3, int zomb = 1); 
        void init(int dimX, int dimY, int zomb); 
        void display(); 
        int setDimX(int x); 
        int setDimY(int y); 
        int setZomB(int z);
        std::vector<std::vector<char>> setmap(int y, int x, char NObjects);

        int getDimX() const; 
        int getDimY() const;
        int getZomB() const; 
        char getObject(int dimX, int dimY) const;
};

class Zombie : public gameBoard
{
    public:
        int hp_; 
        int atk_; 
        int rng_; 
        int noobj = 3; 

        void data();
        int hpgen(int* hp);
        int atkgen(int* atk); 
        int rnggen(int* rng);
};

class movement : public gameBoard
{
    public:
        int AX_;
        int AY_;

        int setaX_(int x);
        int setaY_(int y);

        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void move_arrow();
        void get_arrow();
};

//Class-----------------------------------------------------------------------------------------

#endif