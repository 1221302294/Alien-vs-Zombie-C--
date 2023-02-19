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
#include <string>
#include <vector>
#include <cmath>
#include <cfenv>
#include <cstdlib> 
#include <ctime>   
#include <iomanip> 

#ifndef MAINHEADER_H
#define MAINHEADER_H

using namespace std;

    int ClearScreen();
    int Pause();

    extern vector<vector<char>> map_;
    extern vector<int> ZomY_;
    extern vector<int> ZomX_;
    extern vector<vector<int>> ZB_atrr;
    void emptymap(int dX, int dY);
    void getMenu();
    void controls();
    void help();
    void gameover();
    void playmenu();
    char randObject(char x);
    char refreshObj(char x);
    void ranobjupdate();
    void rockobjupdate(int y, int x);
    void changesetting(); // liEn
    void Board(); // liEn
    void zomdisplay(int no);
    void play();


        void init(int dimX, int dimY, int zomb);
        void display();
        int setDimX(int x);
        int setDimY(int y);
        int setZomB(int z);
        int setZomY(int num, int newnum);
        int setZomX(int num, int newnum);
        void setZomHP(int num, int Zhp);

        std::vector<std::vector<char>> setmap(int y, int x, char obj);

        int getDimX();  
        int getDimY();
        int getZomB();
        int getZomY(int num);
        int getZomX(int num);
        int getZHP(int num);
        int getZATK(int num);
        int getZRNG(int num);
        char getObject(int dimX, int dimY);   

    int *getZomHP(int num);
    int *getZomAtk(int numZom);
    int *getZomRge(int numofZ);
    int fileExist();
    void loadmap();
    int GetLoad();
    int GetAlienX();
    int GetAlienY();
    int GetAlienHP();
    int GetAlienATK();
    void saveHP(int hp);
    void saveATK(int atk);

class Enemy 
{
    public:
        vector<int> ZHpVec;
        vector<int> ZAtkVec;     
        vector<int> ZRngVec;
        void zombiegen(int no);

};

class movement : public Enemy
{
    public:
        int alhp_ = 100;
        int alatk_ = 0;
        int AlienX_;
        int AlienY_;
        vector<int> zomXVec;
        vector<int> zomYVec;

        void Alienturn();
        void alienstat();
        int getalhp_();
        int setalhp_(int hp);
        int getalatk_();
        int setalatk_(int atk);
        int resetatk_();
        void podatk(int podY, int podX);

        int setalienX_(int x);
        int setalienY_(int y);
        int getalienX_() const;
        int getalienY_() const;

        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void move_arrow(int y, int x, string z);
        void zommove();
};

#endif
