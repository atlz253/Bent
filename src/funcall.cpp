#include "funcall.h"

#include <iostream>

Funcall::Funcall(const std::string &name, const std::list<Expression *> &args) : name(name), args(args) 
{
}

Funcall::~Funcall()
{
    for (std::list<Expression *>::iterator iterator = args.begin(); iterator != args.end(); iterator++)
    {
        delete *iterator;
    }
}
