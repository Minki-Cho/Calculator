// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#include "CalcWindow.h"
#include "NumberButton.h"
#include "MathSymbolButton.h"
#include "ButtonManager.h"
#include "DrawResult.h"
#include "CalcWindow.h"
#include <gsl/gsl>

#define NUM_FRAMES  3       // Number of frames (rectangles) for the button sprite texture

//  F.46: int is the ruturn type of main()
int main(void)
{
    const int screenWidth = 600;
    const int screenHeight = 800;

    gsl::owner<CalcWindow*> window_owner = new CalcWindow(screenWidth, screenHeight, "Calculator");
    //  I.12: Declare a pointer that must not be null as not_null
    gsl::not_null<CalcWindow*> window = window_owner;
    window.get()->Init();

    ButtonManager buttonManager;

    buttonManager.Add(std::make_shared<NumberButton<9>>());
    buttonManager.Add(std::make_shared<NumberButton<8>>());
    buttonManager.Add(std::make_shared<NumberButton<7>>());
    buttonManager.Add(std::make_shared<NumberButton<6>>());
    buttonManager.Add(std::make_shared<NumberButton<5>>());
    buttonManager.Add(std::make_shared<NumberButton<4>>());
    buttonManager.Add(std::make_shared<NumberButton<3>>());
    buttonManager.Add(std::make_shared<NumberButton<2>>());
    buttonManager.Add(std::make_shared<NumberButton<1>>());
    buttonManager.Add(std::make_shared<NumberButton<0>>());

    buttonManager.Add(std::make_shared<MathSymbolButton<MathSymbol::Divide>>());
    buttonManager.Add(std::make_shared<MathSymbolButton<MathSymbol::Multiple>>());
    buttonManager.Add(std::make_shared<MathSymbolButton<MathSymbol::Minus>>());
    buttonManager.Add(std::make_shared<MathSymbolButton<MathSymbol::Plus>>());
    buttonManager.Add(std::make_shared<MathSymbolButton<MathSymbol::Assign>>());
    window.get()->Print();

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        buttonManager.UpdateAll();
    
        BeginDrawing();
        ClearBackground(RAYWHITE);
        window.get()->draw();
        buttonManager.DrawAll();
        DrawResult();
        EndDrawing();
    }
    CloseWindow();          // Close window and OpenGL context
    delete window_owner;

    //  F.46: int is the ruturn type of main()
    return 0;
}
