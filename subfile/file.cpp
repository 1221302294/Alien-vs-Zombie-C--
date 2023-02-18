#include "MainHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string split(string stence, char del)
{
    string temp = "";

    for (int i = 0; i < stence.size(); i++)
    {
        if (stence[i] != del)
        {
            temp += stence[i];
        }
        else
        {
            cout << temp << " ";
            temp = "";
        }
    }
    return temp;
}

int fileExisting(string fileNme)
{
    ifstream gameFile;
    string fname;
    char oWrite;
    int i = 0;

    gameFile.open(".\\savefiles\\" + fileNme);
    if (gameFile)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string getFileName()
{
    string fileName;

    cout << "Name your file -> ";
    cin >> fileName;
    cout << endl;
    return fileName;
}

string getLoadFname()
{
    string loadName;

    cout << "Enter the file name to load -> ";
    cin >> loadName;
    cout << endl;
    return loadName;
}

void saveFile(string nameFile)
{
    fstream gameFile;
    string userFile;

    int dimY_ = getDimY();
    int dimX_ = getDimX();
    int Znum = getZomB();

    userFile = ".\\savefiles\\" + nameFile;
    gameFile.open(userFile, ios::out);
    if (gameFile.is_open())
    {
        gameFile << "Y" << dimY_ << "\nX" << dimX_;
        for (int i = 0; i < dimY_; ++i)

        {

            gameFile << "\n";
            gameFile << 'T';
            for (int j = 0; j < dimX_; ++j)
            {

                gameFile << map_[i][j];
            }
        }

        int *hp = getZomHP(Znum);
        int *atk = getZomAtk(Znum);
        int *rge = getZomRge(Znum);

        for (int i = 0; i < Znum; i++)
        {
            gameFile << '\n'
                     << "Z" << i + 1 << ", H" << hp[i] << ", A" << atk[i] << ", R" << rge[i];
        }
        gameFile.close();
        cout << "Game saved successfully." << endl;
    }
}
int loadDim(string Line, char dim)
{

    string content = split(Line, dim);
    int dimNum = stoi(content);

    return dimNum;
}

int getLoadDimX(string file)
{
    ifstream gameFile;
    int dim_x;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'X')
            {
                dim_x = loadDim(readL, 'X');
            }
        }
        gameFile.close();
    }
    return dim_x;
}

int getLoadDimY(string file)
{
    ifstream gameFile;
    int dim_y;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'Y')
            {
                dim_y = loadDim(readL, 'Y');
            }
        }
        gameFile.close();
    }
    return dim_y;
}

int getLoadZom(string file)
{
    ifstream gameFile;
    int numZom;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'Z')
            {
                numZom++;
            }
        }
        gameFile.close();
    }
    return numZom;
}

void loadmap()
{
    ifstream gameFile;
    string existFile, LoadFname;
    int testExist, i, j, strLength, nZom, dim_x, dim_y;
    char del = ':';
    i = 0;
    nZom = 0;
    dim_x = 0;
    dim_y = 0;

    LoadFname = getLoadFname();
    testExist = fileExisting(LoadFname);

    if (testExist == 1)
    {
        existFile = ".\\savefiles\\" + LoadFname;
        dim_x = getLoadDimX(existFile);
        dim_y = getLoadDimY(existFile);
        nZom = getLoadZom(existFile);
        init(dim_x, dim_y, nZom);
        map_.clear();
        emptymap(dim_x, dim_y);

        gameFile.open(existFile, ios::in); // read the file
        if (gameFile.is_open())
        {
            string readLine;
            while (getline(gameFile, readLine))
            {

                if (readLine[0] == 'T')
                {
                    if (i < dim_y)
                    {
                        for (int j = 0; j < dim_x; ++j)
                        {
                            char item = readLine[j + 1];
                            cout << item;
                            map_[i][j] = item;
                        }
                        ++i;
                    }
                }
            }
        }
        gameFile.close();
    }
    else
    {
        cout << "The file does not exist." << endl;
    }
}

int fileExist()
{
    ifstream gameFile;
    string fname, name;
    char oWrite;
    int i, Exist;

    name = getFileName();
    Exist = fileExisting(name);

    do
    {
        i = 0;
        if (Exist == 1)
        {
            cout << "The file is existed before. Do you want to overwrite the previous history?\n Y/N -->";
            cin >> oWrite;
            if (oWrite == 'Y' || oWrite == 'y')
            {
                saveFile(name);
            }
            else if (oWrite == 'N' || oWrite == 'n')
            {
                fileExist();
            }

            else
            {
                cout << "Invalid input. Please try again." << endl;
                i = 1;
            }
        }
        else
        {
            saveFile(name);
        }
    } while (i == 1);
    return 0;
}
