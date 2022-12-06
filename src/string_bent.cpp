#include "ifop.h"
#include "unary.h"
#include "block.h"
#include "value.h"
#include "chain.h"
#include "assign.h"
#include "binary.h"
#include "exitop.h"
#include "exprop.h"
#include "import.h"
#include "funcall.h"
#include "whileop.h"

std::string Assign::get_string(int indent)
{
    std::string str;

    str = name + " = " + value->get_string();

    return str;
}

std::string Binary::get_string(int indent)
{
    std::string str;

    str += "(" + arg1->get_string() + " " + op + " " + arg2->get_string() + ")";

    return str;
}

std::string Block::get_string(int indent)
{
    std::string str;

    for (std::list<Expression *>::iterator iterator = ops.begin(); iterator != ops.end(); iterator++)
    {
        str += std::string(indent, '\t');

        str += (*iterator)->get_string(indent);
    }

    return str;
}

std::string Exitop::get_string(int indent)
{
    return "exit;\n";
}

std::string Exprop::get_string(int indent)
{
    std::string str;

    str = expr->get_string() + ";\n";

    return str;
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

std::string Ifop::get_string(int indent)
{
    std::string str;

    str += "if " + cond->get_string() + "\n" + std::string(indent, '\t') + "{\n";

    str += thenops.get_string(indent + 1);

    if (elseops.Size())
    {
        str += std::string(indent, '\t') + "\n}\nelse\n{\n" + elseops.get_string(indent + 1);
    }

    str += std::string(indent, '\t') + "}\n\n";

    return str;
}

std::string Unary::get_string(int indent)
{
    std::string str;

    str = op + arg->get_string();

    return str;
}

std::string Value::get_string(int indent)
{
    return text;
}

std::string Whileop::get_string(int indent)
{
    std::string str;

    str = "while " + cond->get_string() + "\n" + std::string(indent, '\t') + "{\n";

    str += ops.get_string(indent + 1);

    str += std::string(indent, '\t') + "}\n\n";

    return str;
}

std::string Import::get_string(int indent)
{
    return std::string("import ") + id->get_string() + "\n";
}

std::string Chain::get_string(int indent)
{
    std::string str;

    for (std::list<Expression *>::iterator iterator = ops.begin(); iterator != ops.end(); iterator++)
    {
        if (iterator != ops.begin())
        {
            str += '.';
        }

        str += std::string(indent, '\t');

        str += (*iterator)->get_string(indent);
    }

    return str;
}
