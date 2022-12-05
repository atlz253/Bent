#include "value.h"

#include <iostream>

Value::Value(const std::string &text) : text(text)
{
}

std::string Value::get_string(int indent)
{
    return text;
}
