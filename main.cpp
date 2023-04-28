#include <iostream>
#include "mesurevolume.h"

using namespace std;

void helpMsg()
{
    cout << "Enter the volume of fluid You want to mesure.\n"
         "Program will print a solution using 3 containers - 3L, 5L and 8L\n\n"
         "Type an integer from 1 to 16:\n";
}

int toInt(const string& str)
{
    int result = -1;
    try
    {
        result = stoi(str);
    }
    catch (...)
    {
        cout << "Value was not an integer.\n";
    }
    if (result < 1 || result > 16)
    {
        cout << "Type an integer from 1 to 16: \n";
        result = -1;
    }

    return result;
}

int getInput()
{
    string line;
    int input = -1;
    while (input == -1)
    {
        getline(cin, line);
        input = toInt(line);
    }
    return input;
}

int main()
{
    helpMsg();
    int input = getInput();
    MesureVolume mv = MesureVolume();
    mv.solution(input);
    return 0;
}
