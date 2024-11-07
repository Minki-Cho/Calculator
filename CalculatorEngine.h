// Minki.cho Seongryul.park 
// Class Project
// CS225, Fall & 2022.

#pragma once
#include "MathSymbol.h"
#include <memory>

class CalculatorEngine
{
public:
    static CalculatorEngine& Instance()
    {
        static CalculatorEngine instance;
        return instance;
    }

    static MathSymbol& GetMathSymbol() { return Instance().mathSymbol; }
    static int&                         GetFirstValue() { return Instance().firstValue; }
    static int&                         GetSecondValue() { return Instance().secondValue; }

private:
    CalculatorEngine() : mathSymbol(MathSymbol::Count), firstValue(0), secondValue(0) {}

    MathSymbol mathSymbol;
    int        firstValue;
    int        secondValue;
};