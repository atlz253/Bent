#include "funcall.h"

#include <iostream>

Funcall::Funcall(const std::string &name, const std::list<Expression *> &args) : name(name), args(args) 
{
}

void Funcall::print(int indent)
{
    std::cout << name << "(";

    for (std::list<Expression *>::iterator iterator = args.begin(); iterator != args.end(); iterator++)
    {
        if (iterator != args.begin())
        {
            std::cout << ", ";
        }

        (*iterator)->print();
    }

    std::cout << ")";
}

Funcall::~Funcall()
{
    for (std::list<Expression *>::iterator iterator = args.begin(); iterator != args.end(); iterator++)
    {
        delete *iterator;
    }
}
