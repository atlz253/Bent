#include "funcall.h"

#include <iostream>

#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define foreach(i, list) typedef typeof(list) TOKENPASTE2(T,__LINE__); \
                    for(TOKENPASTE2(T,__LINE__)::iterator i = list.begin(); i != list.end(); i++)


Funcall::Funcall(const std::string &name, const std::list<expr_t *> &args) : name(name), args(args) 
{
}

void Funcall::print()
{
    std::cout << name << "(";
    foreach (i, args)
    {
        if (i != args.begin())
            std::cout << ", ";
        (*i)->print();
    }
    std::cout << ")";
}

Funcall::~Funcall()
{
    foreach (i, args)
    {
        delete *i;
    }
}