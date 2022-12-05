#include "ifop.h"

#include <iostream>

Ifop::Ifop(Expression *cond, Expression *thenops, Expression *elseops) : cond(cond), thenops(thenops), elseops(elseops)
{
}

std::string Ifop::get_string(int indent)
{
    std::string str;

    str += "if ";

    str += cond->get_string(indent);

    str += " {\n";

    str += thenops.get_string(indent + 1);

    if (elseops.Size())
    {
        str += std::string(indent, '\t');

        str += "} else {\n";
    }

    str += std::string(indent, '\t');

    str += "}\n";

    return str;
}

Ifop::~Ifop()
{
    delete cond;
}