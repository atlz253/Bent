#include "import.h"

#include <iostream>

Import::Import(Expression *id) : id(id)
{
}

Import::~Import()
{
    delete id;
}