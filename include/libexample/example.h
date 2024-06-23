#pragma once

namespace example
{

class Foo
{
public:
    Foo();
    explicit Foo(int x);

    void setValue(int v);
    int  value() const;

private:
    int m_value;
};

} // namespace example
