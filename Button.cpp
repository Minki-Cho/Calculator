// Minki.cho Seongryul.park 
// Class Project
// CS225, Fall & 2022.

#include "Button.h"
#include "CalculatorEngine.h"

// F.51: Where there is a choice, prefer default arguments over overloading
Button::Button() : Button{125, 125, 100, 100} { }

// C.46: Define and initialize member variables in the order of member declaration
// We got error in gcc because we didn't initialize in order.
Button::Button(float xPos, float yPos, float Width, float Height) : Button(Rectangle{xPos, yPos, Width, Height}) {   }

Button::Button(Vector2 pos, Vector2 size_) : Button(Rectangle{pos.x, pos.y, size_.x, size_.y}) { }

Button::~Button(){}

// I.23 Keep the number of function arguments low
Button::Button(Rectangle rect_) 
: currentColor(nullptr), rect(rect_)
{
    SetColor(GetColor(0xAAAAAAFF), GetColor(0xCCCCCCFF), GetColor(0xBBBBBBFF));
}

void Button::SetColor(Color idle, Color clickable, Color clicking)
{
    ButtonColor.idle      = idle;
    ButtonColor.clickable = clickable;
    ButtonColor.clicking  = clicking;
}

bool Button::DidClickedButton()
{
    if (MouseIsOver() && IsMouseButtonPressed(static_cast<int>(MouseButton::MOUSE_BUTTON_LEFT))) {
        return true;
    }

    return false;
}

void Button::Update()
{
    currentColor = &ButtonColor.idle;

    if (MouseIsOver()) 
    {
        currentColor = &ButtonColor.clickable;

        if (IsMouseButtonDown(static_cast<int>(MouseButton::MOUSE_BUTTON_LEFT))) 
        {
            currentColor = &ButtonColor.clicking;
        }
    }
    if(DidClickedButton())
    {
        ClickedResult();
    }
}

void Button::Draw(std::string info)
{ 
    //int number = CalculatorEngine::Instance().GetFirstValue();
    //std::string tmp = std::to_string(number);
    //char const* num_char = tmp.c_str();

    DrawRectangleRec(rect, *currentColor); 
    DrawText(info.c_str(), static_cast<int>(rect.x+25), static_cast<int>(rect.y+25), 70, DARKGRAY);
    //DrawText(num_char, 75, 75, 70, DARKBLUE);
}

void Button::SetPosition(Vector2 position)
{
    rect.x = position.x;
    rect.y = position.y;
}

void Button::SetScale(Vector2 scale)
{
    rect.width  = scale.x;
    rect.height = scale.y;
}

bool Button::MouseIsOver()
{
    Vector2 mousePos{GetMousePosition()};
    
    bool withinX{mousePos.x > rect.x && mousePos.x < rect.x + rect.width};
    bool withinY{mousePos.y > rect.y && mousePos.y < rect.y + rect.height};

    return withinX && withinY;
}