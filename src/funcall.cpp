#include "funcall.h"

#include <iostream>

Funcall::Funcall(const std::string &name, const std::list<Expression *> &args) : name(name), args(args) 
{
}

std::string Funcall::get_string(int indent)
{
    std::string str;

    str += name + "(";

    for (std::list<Expression *>::iterator iterator = args.begin(); iterator != args.end(); iterator++)
    {
        if (iterator != args.begin())
        {
            str += ", ";
        }

        str += (*iterator)->get_string();
    }

    str += ")";

    return str;
}

Funcall::~Funcall()
{
    for (std::list<Expression *>::iterator iterator = args.begin(); iterator != args.end(); iterator++)
    {
        delete *iterator;
    }
}
