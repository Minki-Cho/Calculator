// Minki.cho Seongryul.park 
// Class Project
// CS225, Fall & 2022.

#pragma once
#include "Button.h"

#include <memory>
#include <vector>
#include <string>

class ButtonManager
{
public:
    void Add(std::shared_ptr<Button> button);
    void Add(std::initializer_list<std::shared_ptr<Button>> buttons);

    // P .1 : Express ideas directly in code
    void UpdateAll(); // Good naming. I can know what is doing!
    void DrawAll();   // Good naming. I can know what is doing!
    void SetSymbol();

template <typename buttonType>
    std::shared_ptr<buttonType>& GetButton()
    {
        for (std::shared_ptr<Button>& button : buttons)
        {
            std::shared_ptr<buttonType>& ptr = std::dynamic_pointer_cast<buttonType> & (button);
            if (ptr != nullptr)
            {
                return ptr;
            }
        }
        return nullptr;
    }

private:
    //  C.12: Don't make data members const or references
    std::vector<std::shared_ptr<Button>> buttons;
    int index = 0;
    // P .2 : Write in ISO Standard C++ 
    std::string symbol = ""; // std::string
};

//  Enum.3: Prefer class enums over "plain" enums
enum class Symbols
{
    _0 = 0,
    _1 = 1,
    _2 = 2,
    _3 = 3,
    _4 = 4,
    _5 = 5,
    _6 = 6,
    _7 = 7,
    _8 = 8,
    _9 = 9,
    divide = -1,
    multi = -2,
    subtra = -3,
    add = -4,
    equal = -5
};