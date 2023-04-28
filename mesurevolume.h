#ifndef MESUREVOLUME_H
#define MESUREVOLUME_H

#include <iostream>
#include <sstream>
#include <array>

using namespace std;

class MesureVolume
{
public:
    static const int NUMBER_OF_INDEXES = 16;
    static const std::array<string, NUMBER_OF_INDEXES> equation;
    void decode(const string& part);
    void solve(int volume);
    void solution(int volume);
};

#endif // MESUREVOLUME_H
