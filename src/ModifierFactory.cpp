#include "ModifierFactory.h"
#include "modifiers/FlatBonusModifier.h"
#include "modifiers/DoubleScoreModifier.h"
IModifier* ModifierFactory::CreateModifier(const std::string& type) {
    if (type == "FlatBonus") {
        return new FlatBonusModifier();
    } 
    else if (type == "DoubleScore") {
        return new DoubleScoreModifier();
    }
    
    return nullptr; 
}