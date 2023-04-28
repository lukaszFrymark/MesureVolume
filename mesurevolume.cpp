#include "mesurevolume.h"

const std::array<string, MesureVolume::NUMBER_OF_INDEXES> MesureVolume::equation =
{
    "3>5 3>5 R3", //1
    "5>3 R5",     //2
    "+3",         //3
    "*1 +3",      //4
    "+5",         //5
    "3x2",        //6
    "*2 +5",      //7
    "+8",         //8
    "3x3",        //9
    "5x2",        //10
    "+8 +3",      //11
    "3x4",        //12
    "+8 +5",      //13
    "*6 +8",      //14
    "5x3",        //15
    "8x2",        //16
};

void MesureVolume::decode(const string& part)
{
    if (part.size() < 2)
        return;

    if (part[0] == '+')
        cout << "Add full " << part[1] << "L container. ";
    else if (part[1] == 'x')
        cout << "Add full " << part[0] << "L container " << part[2] << " times. ";
    else if (part[1] == '>')
        cout << "Transfer from " << part[0] << "L container to " << part[2] << "L container. ";
    else if (part[0] == 'R')
        cout << "Use the rest from " << part[1] << "L container. ";
    else if (part[0] == '*')
    {
        try
        {
            int index = stoi(part.substr(1));
            // Reuse solution for lower volume
            solve(index);
        }
        catch (exception& err)
        {
            cout << "Error while resolving equation\n" << err.what() << "\n";
        }
    }
}

void MesureVolume::solution(int volume)
{
    cout << "To mesure " << volume << "L:\n";
    solve(volume);
    cout << "\n";
}

void MesureVolume::solve(int volume)
{
    //double check index range
    if (volume < 1 || volume > MesureVolume::NUMBER_OF_INDEXES)
        return;

    string part;
    stringstream ss(equation[volume - 1]);

    while (getline(ss, part, ' '))
    {
        decode(part);
    }
}
