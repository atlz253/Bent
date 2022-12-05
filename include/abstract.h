#ifndef ABSTRACT
#define ABSTRACT

class oper_t
{ // abstract
protected:
    oper_t() {}

public:
    virtual ~oper_t() {}
    virtual void print(int indent = 0) = 0;
};

class expr_t
{ // abstract
protected:
    expr_t() {}

public:
    virtual ~expr_t() {}
    virtual void print() = 0;
};

#endif // ABSTRACT