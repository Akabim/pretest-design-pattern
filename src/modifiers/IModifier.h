#pragma once
#include <string>

class IModifier {
    public:

        virtual ~IModifier() = default;

        virtual std::string GetName() const = 0;

        virtual void Apply(int& currrentChips, int& currentMult) = 0;
};