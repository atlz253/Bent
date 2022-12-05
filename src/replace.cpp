#include "replace.h"

std::string replaceAll(const std::string &where, const std::string &what, const std::string &withWhat)
{
    std::string result = where;
    while (1)
    {
        int pos = result.find(what);
        if (pos == -1)
            return result;
        result.replace(pos, what.size(), withWhat);
    }
}