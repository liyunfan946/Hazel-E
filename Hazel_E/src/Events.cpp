#include "Events.h"

namespace Hazel_E
{
    std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
