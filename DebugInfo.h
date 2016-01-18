//
// Created by przemo on 18.01.16.
//

#ifndef HUMAN_DEBUGINFO_H
#define HUMAN_DEBUGINFO_H

#include <iostream>
#include <string>

class CDebugInfo
{
public:
    static void PrintDebug(std::string debug)
    {
        std::cout << debug << std::endl;
    }
};

#endif //HUMAN_DEBUGINFO_H
