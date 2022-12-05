#include "ifop.h"

#include <iostream>

Ifop::Ifop(Expression *cond, Expression *thenops, Expression *elseops) : cond(cond), thenops(thenops), elseops(elseops)
{
}

std::string Ifop::get_string(int indent)
{
    std::string str;

    str += "if " + cond->get_string() + "\n" + std::string(indent, '\t') + "{\n";

    str += thenops.get_string(indent + 1);

    if (elseops.Size())
    {
        str += std::string(indent, '\t') + "\n}\nelse\n{\n" + elseops.get_string(indent + 1);
    }

    str += std::string(indent, '\t') + "}\n\n";

    return str;
}

Ifop::~Ifop()
{
    delete cond;
}