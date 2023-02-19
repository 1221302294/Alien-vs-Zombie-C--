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
#include <cstdlib> 

using namespace std;

int ClearScreen() {
#if defined(_WIN32)
  return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
  return std::system("clear");
#endif
}

int Pause() {
#if defined(_WIN32)
  return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
  return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

char RandObject() {
  int Num = rand() % 11 + 1;
  switch (Num) {
    case 1:
      return '^';
    case 2:
      return 'v';
    case 3:
      return '<';
    case 4:
      return '>';
    case 5:
      return 'h';
    case 6:
      return 'p';
    case 7:
      return 'r';
    default:
      return ' ';
  }
}

char RefreshObj() {
  int Num = rand() % 6 + 1;
  switch (Num) {
    case 1:
      return 'h';
    case 2:
      return 'p';
    default:
      return ' ';
  }
}

void UpdateRockObj(int y, int x) {
  if (map_[y][x] == 'r') {
    map_[y][x] = RandObject();
  }
}

void UpdateRandomObj() {
  int dimY = getDimY();
  int dimX = getDimX();
  for (int i = 0; i < dimY; ++i) {
    for (int j = 0; j < dimX; ++j) {
      if (map_[i][j] == '.') {
        map_[i][j] = RandObject();
      }
    }
  }
}


