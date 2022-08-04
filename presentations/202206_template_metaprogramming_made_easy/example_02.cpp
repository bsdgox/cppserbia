#include <vector>
#include <cassert>
#include <fmt/format.h>
#include <string>
#include <utility>

template<typename T>
class Stack {
private:
    std::vector<T> elems; // elements
public:
    void push(T const& elem); // push element
    void pop(); // pop element
    T const& top() const; // return top element
    bool empty() const // return whether the stack is empty 
    { 
        return elems.empty();
    }

    bool operator==(Stack const & rhs) const;

    void print() const
    {
        for (auto const & val : elems)
        {
            fmt::print("{},", val);
        }
    }

};

template<typename T>
void Stack<T>::push (T const& elem)
{
    elems.push_back(elem); // append copy of passed elem
}

template<typename T>
void Stack<T>::pop ()
{
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}

template<typename T>
T const& Stack<T>::top () const
{
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

Stack(char const *) -> Stack<std::string>;

template<typename T>
Stack(T) -> Stack<T>;

// Regular use, partial use
// specialization, partial specialization
// type deduction and deduction guide

template<>
struct Stack<std::string>{};

template<typename T, typename U>
struct MyStruct{};

template<typename T>
struct MyStruct<T,T>{};

template<typename T>
struct wrapper{};

template<typename T>
struct wrapper<T*>{};

int main()
{
    Stack<int> s{};
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.print();

    Stack<std::pair<float, float>> s2{};
    s2.push({1.0,2.0});
    s2.push({1.0,2.0});
    s2.push({1.0,2.0});
    s2.push({1.0,2.0});
    s2.push({1.0,2.0});
    //s2.print();

    return 0;
}