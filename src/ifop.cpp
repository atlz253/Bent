#include "ifop.h"

#include <iostream>

Ifop::Ifop(expr_t *cond, oper_t *thenops, oper_t *elseops) : cond(cond), thenops(thenops), elseops(elseops)
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