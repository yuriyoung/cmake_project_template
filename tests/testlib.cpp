#include <iostream>

#include <gtest/gtest.h>
#include <libexample/example.h>

GTEST_TEST(Testlib, FooClass)
{
    EXPECT_EQ(example::Foo(0).value(), 0);
    EXPECT_NE(example::Foo(10).value(), 112);

    example::Foo foo;
    foo.setValue(-999999);
    EXPECT_EQ(foo.value(), -999999);

    foo.setValue('a');
    EXPECT_EQ(foo.value(), 'a');

    foo.setValue(96);
    EXPECT_NE(foo.value(), 'a');
}