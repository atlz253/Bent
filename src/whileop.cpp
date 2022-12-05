#include "whileop.h"

#include <iostream>

Whileop::Whileop(Expression *cond, Expression *ops) : cond(cond), ops(ops) 
{
}

std::string Whileop::get_string(int indent)
{
    std::string str;

    str += "while ";

    str += cond->get_string();

    str += " {\n";

    str += ops.get_string(indent + 1);

    str += std::string(indent, '\t');

    str += "}\n";

    return str;
}

Whileop::~Whileop() 
{ 
    delete cond; 
}