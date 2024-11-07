// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#pragma once
#include "raylib.h"
#include "Dynamic.h"
#include <gsl/gsl>
#include <vector>

class CalcWindow
{
private:
    int screenWidth;
    int screenHeight;
    std::string screenname;
    static constexpr Vector2 pos = { 25,25 };
    static constexpr Vector2 pos2 = { 50,50 };
    static constexpr Vector2 scale = { 525, 650 };
    static constexpr Vector2 scale2 = { 350,100 };
    // Dynamic array
    Dynamic_Array<char, 2>   names;
    std::string              str_text{"Hello!!, there"};

public:
    CalcWindow() : screenWidth(800), screenHeight(450), screenname("Window") {}
    CalcWindow(int width, int height, std::string name) : screenWidth(width), screenHeight(height), screenname(name) {}
    void Init();
    void Print();
    void draw();
private:
    gsl::span<int> spans(int num);
    void           ViewExample(gsl::span<int> spanValue);
    void           stringView_Program_Infomation();

};
