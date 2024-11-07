// Minki.cho Seongryul.park 
// Class Project
// CS225, Fall & 2022.

#pragma once
#include <string>
#include "raylib.h"

class Button
{
public:
    Button();
    Button(float xPos, float yPos, float Width, float Height);
    Button(Vector2 pos, Vector2 size_);
    Button(Rectangle rect_);
    virtual ~Button();

    void SetColor(Color idle, Color clickable, Color clicking);

    virtual void Update();
    virtual void Draw(std::string info);

    void SetPosition(Vector2 position);
    void SetScale(Vector2 scale);

    virtual bool DidClickedButton();
    
    virtual void ClickedResult(){};

private:
    bool MouseIsOver();

    struct
    {
        // C.7: Don't define a class or enum and declare a variable of its type in the same statement
        // Color idle, clickable, clincking -> bad
        Color idle;
        Color clickable;
        Color clicking;
    } ButtonColor;

    Color* currentColor;

    Rectangle rect;
};