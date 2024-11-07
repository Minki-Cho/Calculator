// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#pragma once
#include "Button.h"
#include "CalculatorContent.h"
#include "CalculatorEngine.h"
#include <iostream>

template <unsigned int number>
class NumberButton : public Button
{
public:
	NumberButton() : Button() {
		unsigned int count{ number - 1 };
		unsigned int restCount{ count % 3 };
		unsigned int DivideCount{ count / 3 + 1 };

		float xPos{ initialPos.x + static_cast<float>(restCount) * (termSize.x + size.x) };
		float yPos{ initialPos.y + static_cast<float>(DivideCount) * (termSize.y + size.y) };

		SetPosition({ xPos, yPos });
		SetScale(size);
	}

	NumberButton(float xPos, float yPos, float Width, float Height) : Button(xPos, yPos, Width, Height) {}
	NumberButton(Vector2 pos, Vector2 size_) : Button(pos, size_) {}
	NumberButton(Rectangle rect_) : Button(rect_) {}

	unsigned int GetNumber() { return number; }

	void ClickedResult() override 
	{
		if(CalculatorEngine::GetMathSymbol() == MathSymbol::Assign)
		{
				CalculatorEngine::GetFirstValue() = 0;
				CalculatorEngine::GetMathSymbol() = MathSymbol::Count;
		}
		
		if (CalculatorEngine::GetMathSymbol() == MathSymbol::Count)
		{
			int temp{CalculatorEngine::GetFirstValue() * 10 + static_cast<int>(number)};

			if (temp < 0x3E8)
			{
				CalculatorEngine::GetFirstValue() = temp;
				std::cout << CalculatorEngine::GetFirstValue() << "\n";
			}
		}
		else
		{
			int temp{CalculatorEngine::GetSecondValue() * 10 + static_cast<int>(number)};

			if (temp < 0x3E8)
			{
				CalculatorEngine::GetSecondValue() = temp;
				std::cout << CalculatorEngine::GetSecondValue() << "\n";
			}
		}
	}

private:
};

template<>
class NumberButton<0> : public Button
{
public:
	NumberButton() : Button()
	{
		unsigned int restCount{ 1 };
		unsigned int DivideCount{ 4 };

		float xPos{ initialPos.x + static_cast<float>(restCount) * (termSize.x + size.x) };
		float yPos{ initialPos.y + static_cast<float>(DivideCount) * (termSize.y + size.y) };

		SetPosition({ xPos, yPos });
		SetScale(size);
	}

	NumberButton(float xPos, float yPos, float Width, float Height) : Button(xPos, yPos, Width, Height) {}
	NumberButton(Vector2 pos, Vector2 size_) : Button(pos, size_) {}
	NumberButton(Rectangle rect_) : Button(rect_) {}


	void ClickedResult() override
	{		
		if(CalculatorEngine::GetMathSymbol() == MathSymbol::Assign)
		{
				CalculatorEngine::GetFirstValue() = 0;
				CalculatorEngine::GetMathSymbol() = MathSymbol::Count;
		}
		
		if (CalculatorEngine::GetMathSymbol() == MathSymbol::Count)
		{
			int temp{CalculatorEngine::GetFirstValue() * 10};

			if (temp < 0x3E8)
			{
				CalculatorEngine::GetFirstValue()  = temp;
				std::cout << CalculatorEngine::GetFirstValue() << "\n";
			}
		}
		else
		{
			int temp{CalculatorEngine::GetSecondValue() * 10};

			if (temp < 0x3E8)
			{
				CalculatorEngine::GetSecondValue() = temp;
				std::cout << CalculatorEngine::GetSecondValue() << "\n";
			}
		}
	}

	unsigned int GetNumber() { return 0; }

private:
};