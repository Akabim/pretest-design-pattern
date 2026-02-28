#include "modifiers/IModifier.h"
#include <string>

class ModifierFactory {
public:
    static IModifier* CreateModifier(const std::string& type);
};