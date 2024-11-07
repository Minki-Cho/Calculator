// Seongryul.park Minki.cho.
// Class Project
// CS225, Fall & 2022.

#pragma once
#include <type_traits>
#include <concepts>
#include <iostream>
#include "Button.h"
#include "MathSymbol.h"
#include "CalculatorContent.h"
#include "CalculatorEngine.h"

template<MathSymbol symbol>
class MathSymbolButton : public Button
{
public:
    MathSymbolButton() : Button(){
        unsigned int restCount{3};
        unsigned int DivideCount{static_cast<unsigned int>(symbol)};

        float xPos{initialPos.x + static_cast<float>(restCount) * (termSize.x + size.x)};
        float yPos{initialPos.y + static_cast<float>(DivideCount) * (termSize.y + size.y)};

        SetPosition({xPos, yPos});
        SetScale(size);
	};

    MathSymbolButton(float xPos, float yPos, float Width, float Height) : Button(xPos, yPos, Width, Height) {}
    MathSymbolButton(Vector2 pos, Vector2 size_) : Button(pos, size_) {}
    MathSymbolButton(Rectangle rect_) : Button(rect_) {}


	void ClickedResult() override 
    {
        if(CalculatorEngine::GetMathSymbol() != MathSymbol::Assign)
        {
            CalculatorEngine::GetMathSymbol() = symbol;
        }
	}

	private:
};

//  Algorithm Selection - Template Specialization
template<MathSymbol>
struct Calc
{   
    static void Calculation(){}
};

template<>
struct Calc<MathSymbol::Plus>
{   
    static void Calculation()
    {
        CalculatorEngine::GetFirstValue() += CalculatorEngine::GetSecondValue();
    }
};

template<>
struct Calc<MathSymbol::Minus>
{   
    static void Calculation()
    {
        CalculatorEngine::GetFirstValue() -= CalculatorEngine::GetSecondValue();
    }
};

template<>
struct Calc<MathSymbol::Multiple>
{   
    static void Calculation()
    {
        CalculatorEngine::GetFirstValue() *= CalculatorEngine::GetSecondValue();
    }
};

template<>
struct Calc<MathSymbol::Divide>
{   
    static void Calculation()
    {
        CalculatorEngine::GetFirstValue() /= CalculatorEngine::GetSecondValue();
    }
};

//  Algorithm Selection - Tag DisPatch
struct DefaultTag
{   };

struct PlusTag
{   };

struct MinusTag
{   };

struct MultiTag
{   };

struct DivideTag
{   };

template<MathSymbol>
struct CalcTag
{
    using tag = DefaultTag;
};

template<>
struct CalcTag<MathSymbol::Plus>
{
    using tag = PlusTag;
};

template<>
struct CalcTag<MathSymbol::Minus>
{
    using tag = MinusTag;
};

template<>
struct CalcTag<MathSymbol::Multiple>
{
    using tag = MultiTag;
};

template<>
struct CalcTag<MathSymbol::Divide>
{
    using tag = DivideTag;
};

void CalculationWithTag(DefaultTag)
{   }

void CalculationWithTag(PlusTag)
{   
    CalculatorEngine::GetFirstValue() += CalculatorEngine::GetSecondValue();
}

void CalculationWithTag(MinusTag)
{   
    CalculatorEngine::GetFirstValue() -= CalculatorEngine::GetSecondValue();
}

void CalculationWithTag(MultiTag)
{   
    CalculatorEngine::GetFirstValue() *= CalculatorEngine::GetSecondValue();
}

void CalculationWithTag(DivideTag)
{   
    CalculatorEngine::GetFirstValue() /= CalculatorEngine::GetSecondValue();
}

template <MathSymbol math>
void CalculationTag()
{
    CalculationWithTag(typename CalcTag<math>::tag{});
}

//  use if constexpr
template<MathSymbol math>
void CalculationIf()
{
    if constexpr(math == MathSymbol::Plus)
    {
        CalculatorEngine::GetFirstValue() += CalculatorEngine::GetSecondValue();
    }
    else if constexpr(math == MathSymbol::Minus)
    {
        CalculatorEngine::GetFirstValue() -= CalculatorEngine::GetSecondValue();
    }
    else if constexpr(math == MathSymbol::Multiple)
    {
        CalculatorEngine::GetFirstValue() *= CalculatorEngine::GetSecondValue();
    }
    else if constexpr(math == MathSymbol::Divide)
    {
        CalculatorEngine::GetFirstValue() /= CalculatorEngine::GetSecondValue();
    }
}

//  use the C++ Concepts via requires keyword 
template<MathSymbol math>
struct IsPlus
{
    static constexpr bool value = (math == MathSymbol::Plus);
};

template<MathSymbol math>
struct IsMinus
{
    static constexpr bool value = (math == MathSymbol::Minus);
};

template<MathSymbol math>
struct IsMulti
{
    static constexpr bool value = (math == MathSymbol::Multiple);
};

template<MathSymbol math>
struct IsDivide
{
    static constexpr bool value = (math == MathSymbol::Divide);
};

template<MathSymbol math>
concept PlusConcept = IsPlus<math>::value;

template<MathSymbol math>
concept MinusConcept = IsMinus<math>::value;

template<MathSymbol math>
concept MultiConcept = IsMulti<math>::value;

template<MathSymbol math>
concept DivideConcept = IsDivide<math>::value;

template<MathSymbol math>
requires PlusConcept<math>
void CalculateConcept()
{
    CalculatorEngine::GetFirstValue() += CalculatorEngine::GetSecondValue();
}

template<MathSymbol math>
requires MinusConcept<math>
void CalculateConcept()
{
    CalculatorEngine::GetFirstValue() -= CalculatorEngine::GetSecondValue();
}

template<MathSymbol math>
requires MultiConcept<math>
void CalculateConcept()
{
    CalculatorEngine::GetFirstValue() *= CalculatorEngine::GetSecondValue();
}

template<MathSymbol math>
requires DivideConcept<math>
void CalculateConcept()
{
    CalculatorEngine::GetFirstValue() /= CalculatorEngine::GetSecondValue();
}

//  use the enable_if
template <MathSymbol math>
typename std::enable_if_t<IsPlus<math>::value> 
CalculateEnableIf()
{
    CalculatorEngine::GetFirstValue() += CalculatorEngine::GetSecondValue();
}

template <MathSymbol math>
typename std::enable_if_t<IsMinus<math>::value> 
CalculateEnableIf()
{
    CalculatorEngine::GetFirstValue() -= CalculatorEngine::GetSecondValue();
}

template <MathSymbol math>
typename std::enable_if_t<IsMulti<math>::value> 
CalculateEnableIf()
{
    CalculatorEngine::GetFirstValue() *= CalculatorEngine::GetSecondValue();
}

template <MathSymbol math>
typename std::enable_if_t<IsDivide<math>::value> 
CalculateEnableIf()
{
    CalculatorEngine::GetFirstValue() /= CalculatorEngine::GetSecondValue();
}

template<>
class MathSymbolButton<MathSymbol::Assign> : public Button
{
public:
    MathSymbolButton() : Button(){
        unsigned int restCount{3};
        unsigned int DivideCount{static_cast<unsigned int>(MathSymbol::Assign)};

        float xPos{initialPos.x + static_cast<float>(restCount) * (termSize.x + size.x)};
        float yPos{initialPos.y + static_cast<float>(DivideCount) * (termSize.y + size.y)};

        SetPosition({xPos, yPos});
        SetScale(size);
	};

    MathSymbolButton(float xPos, float yPos, float Width, float Height) : Button(xPos, yPos, Width, Height) {}
    MathSymbolButton(Vector2 pos, Vector2 size_) : Button(pos, size_) {}
    MathSymbolButton(Rectangle rect_) : Button(rect_) {}


	void ClickedResult() override 
    {
        const MathSymbol math_{CalculatorEngine::GetMathSymbol()};

        if(CalculatorEngine::GetMathSymbol() != MathSymbol::Count)
        {
            if(count == 0)  //  use the template specialization
            {
                if(math_ == MathSymbol::Plus)
                {
                    Calc<MathSymbol::Plus>::Calculation();
                }
                else if(math_ == MathSymbol::Minus)
                {
                    Calc<MathSymbol::Minus>::Calculation();
                }
                else if(math_ == MathSymbol::Multiple)
                {
                    Calc<MathSymbol::Multiple>::Calculation();
                }
                else if(math_ == MathSymbol::Divide)
                {
                    Calc<MathSymbol::Divide>::Calculation();
                }

                count++;
            }
            else if(count == 1)   //  use the tag dispatch
            {
                if(math_ == MathSymbol::Plus)
                {
                    CalculationTag<MathSymbol::Plus>();
                }
                else if(math_ == MathSymbol::Minus)
                {
                    CalculationTag<MathSymbol::Minus>();
                }
                else if(math_ == MathSymbol::Multiple)
                {
                    CalculationTag<MathSymbol::Multiple>();
                }
                else if(math_ == MathSymbol::Divide)
                {
                    CalculationTag<MathSymbol::Divide>();
                }
                
                count++;
            }
            else if(count == 2) //  use the if constexpr
            {                
                if(math_ == MathSymbol::Plus)
                {
                    CalculationIf<MathSymbol::Plus>();
                }
                else if(math_ == MathSymbol::Minus)
                {
                    CalculationIf<MathSymbol::Minus>();
                }
                else if(math_ == MathSymbol::Multiple)
                {
                    CalculationIf<MathSymbol::Multiple>();
                }
                else if(math_ == MathSymbol::Divide)
                {
                    CalculationIf<MathSymbol::Divide>();
                }
                
                count++;
            }            
            else if(count == 3) //  use C++ Concepts via requires keyword 
            {                
                if(math_ == MathSymbol::Plus)
                {
                    CalculateConcept<MathSymbol::Plus>();
                }
                else if(math_ == MathSymbol::Minus)
                {
                    CalculateConcept<MathSymbol::Minus>();
                }
                else if(math_ == MathSymbol::Multiple)
                {
                    CalculateConcept<MathSymbol::Multiple>();
                }
                else if(math_ == MathSymbol::Divide)
                {
                    CalculateConcept<MathSymbol::Divide>();
                }
                
                count++;
            }            
            else if(count == 4) //  use C++ Concepts via requires keyword 
            {                
                if(math_ == MathSymbol::Plus)
                {
                    CalculateEnableIf<MathSymbol::Plus>();
                }
                else if(math_ == MathSymbol::Minus)
                {
                    CalculateEnableIf<MathSymbol::Minus>();
                }
                else if(math_ == MathSymbol::Multiple)
                {
                    CalculateEnableIf<MathSymbol::Multiple>();
                }
                else if(math_ == MathSymbol::Divide)
                {
                    CalculateEnableIf<MathSymbol::Divide>();
                }
                
                count = 0;
            }

            CalculatorEngine::GetSecondValue() = 0;
            CalculatorEngine::GetMathSymbol() = MathSymbol::Assign;
        }
	}

	private:
    int count{0};
};

