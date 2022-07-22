/*  • When declaring call parameters by reference, even trivial conversions do not apply
    to type deduction. Two arguments declared with the same template parameter T
    must match exactly.
    • When declaring call parameters by value, only trivial conversions that decay are
    supported: Qualifications with const or volatile are ignored, references
    convert to the referenced type, and raw arrays or functions convert to the
    corresponding pointer type. For two arguments declared with the same template
    parameter T the decayed types must match.
*/
template<typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}

template<typename T>
T max_by_ref(T& a, T& b)
{
    return b < a ? a : b;
}

auto min(auto a, auto b)
{
    return a > b ? b : a;
}

int main()
{
    int const a = 5;
    int b = 7;
    int& c = b;
    int const & d = a;
    max(b,c);
    max(a,d);
    max(c,d);
    return max(a,b);
    //return max_by_ref(a,b);
}