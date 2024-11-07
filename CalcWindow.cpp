// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#include <iostream>
#include <string>
#include <array>
#include "CalcWindow.h"

gsl::span<int> CalcWindow::spans(int num) 
{ 
    std::vector<std::string> s_ints;
    std::array<int,3> ints{5,6,7};
    std::unique_ptr<int>     uniqueValue = std::make_unique<int>(8);
    s_ints.push_back(std::to_string(num).c_str());
    s_ints.push_back("2");
    s_ints.push_back("3");
    s_ints.push_back("4");
    gsl::span<int> numbers = ints;
    for (auto &i : s_ints)
    {
        std::cout << i << ' ';
    }
    for (int i : ints)
    {
        std::cout << i << ' ';
    }
    std::cout << *(uniqueValue.get()) << "\n";
    std::cout << "Loading finish!\n\n";
    return numbers;
}

void CalcWindow::Init()
{ 
	InitWindow(screenWidth, screenHeight, screenname.c_str()); 
	SetTargetFPS(60);
    names[0] = '!';
    names[1] = 'a';
}

void CalcWindow::Print() 
{
    //	 Viewing resources = reference, pointer dedicate stack area
    std::string  value    = "This is our calculator! Press the buttons!";
    std::string& valueRef = value;
    std::string* valuePtr = &(value);
    std::cout << " \n\n" << value << "\n" << valueRef << "\n" << *valuePtr << "\n\n";
    //	Owning resources
    std::vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);
    ints.push_back(4);
    // Viewing resources
    gsl::span<int> spans{ints};
    ViewExample(spans);
    stringView_Program_Infomation();
}
void CalcWindow::ViewExample(gsl::span<int> spanValue)
{
    spans(1);
    std::cout << "Viewing Resource : ";
    for (auto value : spanValue)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

void CalcWindow::stringView_Program_Infomation() 
{
    // std::string_view() which provides the view of pre-defined char str[] without creating a new object to the memory.
    char        str_info[]{"Hello!!, This program is made by Seongryul and Minki!"};
    std::string str_2{str_info};
    std::string_view str_3{str_2};
    std::cout << str_info << '\n' << str_2 << '\n' << str_3 << '\n';
}

void CalcWindow::draw()
{
	DrawRectangleGradientH( static_cast<int>(pos.x), static_cast<int>(pos.y) , static_cast<int>(scale.x), static_cast<int>(scale.y), SKYBLUE, YELLOW);
	DrawRectangle(static_cast<int>(pos2.x), static_cast<int>(pos2.y), static_cast<int>(scale2.x), static_cast<int>(scale2.y), WHITE);

    // Dynamic array
    std::string name_t(1, names[0]); // !
    DrawText(name_t.c_str(), 560, 700, 100, BLACK);
    DrawText(str_text.c_str(), 10, 700, 85, BLACK);
}
