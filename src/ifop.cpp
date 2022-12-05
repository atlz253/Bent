#include "ifop.h"

#include <iostream>

Ifop::Ifop(Expression *cond, Expression *thenops, Expression *elseops) : cond(cond), thenops(thenops), elseops(elseops)
{
}

void Ifop::print(int indent)
{
    std::cout << "if ";
    cond->print();
    std::cout << " {" << std::endl;
    thenops.print(indent + 1);
    if (elseops.Size())
    {
        std::cout << std::string(indent, '\t') << "} else {" << std::endl;
        elseops.print(indent + 1);
    }
    std::cout << std::string(indent, '\t') << "}" << std::endl;
}

Ifop::~Ifop()
{
    delete cond;
}