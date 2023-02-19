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
#include <iostream> 

using namespace std;

void Enemy::zombiegen(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        int randhp = rand() % 2 + 1;
        int randatk = rand() % 2 + 1;
        int randrng = rand() % 4 + 1;
        int ZHp = 100 + (randhp * 50);
        int ZAtk = 5 + (randatk  * 5);
        int ZRng = randrng ;

        ZHpVec.push_back(GetLoad() == 1 ? ZB_atrr[i][0] : ZHp);
        ZAtkVec.push_back(GetLoad() == 1 ? ZB_atrr[i][1] : ZAtk);
        ZRngVec.push_back(GetLoad() == 1 ? ZB_atrr[i][2] : ZRng);

        cout << "\n  Zombie " << i + 1 << "  Life :" << ZHpVec[i] << "  Attack :" << ZAtkVec[i] << "  Range :" << ZRngVec[i];
    }
    cout << endl;
}



