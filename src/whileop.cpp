#include "whileop.h"

#include <iostream>

Whileop::Whileop(expr_t *cond, oper_t *ops) : cond(cond), ops(ops) 
{
}

void Whileop::print(int indent)
{
    std::cout << "while ";
    cond->print();
    std::cout << " {" << std::endl;
    ops.print(indent + 1);
    std::cout << std::string(indent, '\t') << "}" << std::endl;
}

Whileop::~Whileop() 
{ 
    delete cond; 
}