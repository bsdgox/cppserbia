#include <vector>
#include <cassert>
#include <fmt/format.h>
#include <string>
#include <utility>

template<typename T>
void print(T val)
{
    fmt::print("{}\t", val);
}

template<typename T, typename... Types>
void print(T first, Types... args)
{
    fmt::print("{}\t", first);
    print(args...);
}


template<int ... N>
int add()
{
    return (N + ...);
}

int main()
{
    print(1,2.3,5,'c');
    return add<1,3,-4,5,19,-3>();
}