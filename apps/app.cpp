#include <iostream>

#include <libexample/example.h>

int main()
{
    example::Foo foo;
    foo.setValue(99);
    std::cout << "[App] foo value: " << foo.value() << std::endl;
    return 0;
}
