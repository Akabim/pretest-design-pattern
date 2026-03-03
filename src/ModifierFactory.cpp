#include "ModifierFactory.h"
#include "modifiers/FlatBonusModifier.h"
#include "modifiers/DoubleScoreModifier.h"
#include "modifiers/SquareScoreModifier.h"
IModifier *ModifierFactory::CreateModifier(const std::string &type)
{
    if (type == "FlatBonus")
    {
        return new FlatBonusModifier();
    }
    else if (type == "DoubleScore")
    {
        return new DoubleScoreModifier();
    }
    else if (type == "SquareScore")
    {
        return new SquareScoreModifier();
    }

    return nullptr;
}