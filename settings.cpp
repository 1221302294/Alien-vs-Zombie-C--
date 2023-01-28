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
#include "mainheader.h"
#include "helper.h"
#include "helper.cpp"

using namespace std;

void settings()
{
    int X = 19;
    int Y = 3;
    int zombies = 1;
    int dimX = 19, dimY = 3;
    char selection;
{
    while (true) {
        cout << "Default Game Settings: " << endl;
        cout << "Board Rows: " <<  dimX << endl;
        cout << "Board Columns:  " << dimY << endl;
        cout << "Zombies Count: " << zombies << endl;
        cout << "Do you wish to change the game settings? (y/n): " << endl;
        cin >> selection;
        cout << "" << endl;
        
        if (tolower(selection) == 'y'){

            cout << "Enter rows => " ;
            cin >> X;
            while (true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout <<"You have entered an invalid input, please enter odd number. " << endl;
                    cout << "Enter rows => ";
                    cin >> X;
                }
                else{
                    break;
                }
            }

            cout << "Enter columns => " ;
            cin >> Y;
            while (true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"You have entered an invalid input, please enter odd number. " << endl;
                    cout << "Enter columns => ";
                    cin >> Y;
                }
                else{
                    break;
                }
            }

            cout << "Enter number of zombies => ";
            cin >> zombies;
            while (true){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout <<"You have entered an invalid input, please enter odd number. " << endl;
                    cout << "Enter number of zombies => ";
                    cin >> zombies;
                }
                else{
                    break;
                }
            }

            cout << "Settings Updated" << endl;
          
        }

        else if (tolower(selection) == 'n'){

            cout << "Default settings will be applied";

            break;
        }

        else{
            cout << "You have entered an invalid input, please enter odd number."<< endl;
        }
       

            
        
    }

}
void quitGame();
}
   
int main(){
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
    settings();
}

    
