// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#pragma once
#include "CalculatorEngine.h"
#include <type_traits>
#include <raylib.h>

void DrawResult()
{
    if (CalculatorEngine::GetMathSymbol() == MathSymbol::Count || CalculatorEngine::GetMathSymbol() == MathSymbol::Assign)
    {
        int number = CalculatorEngine::Instance().GetFirstValue();
        std::string tmp = std::to_string(number);
        char const* num_char = tmp.c_str();

        DrawText(num_char, 75, 75, 70, DARKBLUE);
    }
    else
    {
        int         number   = CalculatorEngine::Instance().GetSecondValue();
        std::string tmp      = std::to_string(number);
        char const* num_char = tmp.c_str();

        DrawText(num_char, 75, 75, 70, DARKBLUE);
    }
}
