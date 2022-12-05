#include "expression.h"

std::string Expression::get_string(int indent)
{
    return std::string(indent, '\t');
}

void Expression::print(int indent)
{
    std::cout << get_string();
}

void Expression::write(FILE *file, int indent)
{
    fprintf(file, get_string().c_str());
}