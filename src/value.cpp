#include "value.h"

#include <iostream>

Value::Value(const std::string &text) : text(text)
{
}

void Value::print(int indent)
{
    std::cout << text;
}