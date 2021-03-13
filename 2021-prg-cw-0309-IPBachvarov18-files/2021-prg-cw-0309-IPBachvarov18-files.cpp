#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <errno.h>
#include "tools.h"

using namespace std;


bool doesFileExist(string fileName)
{
    ifstream file;

    file.open(fileName, ios::in | ios::_Nocreate);

    if (file.is_open())
    {
        file.close();
        return true;
    }

    return false;
}

bool createFile(string fileName)
{
    ofstream file;

    file.open(fileName, ios::out | ios::trunc);

    if (file.is_open())
    {
        file.close();
        return true;
    }

    return false;
}

bool deleteFile(string fileName)
{
    int result = remove(fileName.c_str());

    if (result != 0)
    {
        return errno;
    }

    return 0;
}

bool renameFile(string oldFileName, string newFileName)
{
    int result = rename(oldFileName.c_str(), newFileName.c_str());

    if (result != 0)
    {
        return errno;
    }

    return 0;
}

bool copyTextFile(string sourceFileName, string destinationFileName)
{
    ifstream inFile;
    ofstream outFile;

    inFile.open(sourceFileName);
    if (inFile.is_open())
    {
        string line;

        outFile.open(destinationFileName, ios::out | ios::trunc);

        if (outFile.is_open())
        {
            while (getline(inFile, line))
            {
                outFile << line << endl;
            }

            outFile.close();
        }

        inFile.close();
    }
}
int main()
{
    string fileName = "example.txt";

    if (createFile(fileName))
    {
        deleteFile("example.txt");
    }
}