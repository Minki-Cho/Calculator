// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#include "ButtonManager.h"

void ButtonManager::Add(std::shared_ptr<Button> button) { buttons.push_back(button); }

void ButtonManager::Add(std::initializer_list<std::shared_ptr<Button>> buttonList)
{
    for (std::shared_ptr<Button> button : buttonList) {
        buttons.push_back(button);
    }
}


void ButtonManager::UpdateAll()
{
    index = 9;
    for (std::shared_ptr<Button> button : buttons)
    {
        button.get()->Update();
        
    }
}

void ButtonManager::DrawAll()
{
    for (std::shared_ptr<Button> button : buttons)
    {
        SetSymbol();
        button.get()->Draw(symbol);
        --index;
    }
}

void ButtonManager::SetSymbol()
{
    switch (static_cast<Symbols>(index))
    {
        case Symbols::_0:
        symbol = "0";
        break;
        case Symbols::_1:
        symbol = "1";
        break;
        case Symbols::_2:
        symbol = "2";
        break;
        case Symbols::_3:
        symbol = "3";
        break;
        case Symbols::_4:
        symbol = "4";
        break;
        case Symbols::_5:
        symbol = "5";
        break;
        case Symbols::_6:
        symbol = "6";
        break;
        case Symbols::_7:
        symbol = "7";
        break;
        case Symbols::_8:
        symbol = "8";
        break;
        case Symbols::_9:
        symbol = "9";
        break;
        case Symbols::divide:
        symbol = "/";
        break;
        case Symbols::multi:
        symbol = "x";
        break;
        case Symbols::subtra:
        symbol = "-";
        break;
        case Symbols::add:
        symbol = "+";
        break;
        case Symbols::equal:
        symbol = "=";
        break;
    default:
        break;
    }
}
