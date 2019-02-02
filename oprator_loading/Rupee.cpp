#include "Rupee.h"

Rupee operator+(const Rupee &r1, const Rupee &r2)
{
    return Rupee(r1.getRupee() + r2.getRupee());
}
