#include <libexample/example.h>

namespace example
{

Foo::Foo()
{
}

Foo::Foo(int x)
    : m_value(x)
{
}

void Foo::setValue(int v)
{
    m_value = v;
}

int Foo::value() const
{
    return m_value;
}

} // namespace example
