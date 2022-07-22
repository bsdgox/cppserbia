// general case for any two types
template<typename T, typename U>
struct are_same_t
{
    static constexpr bool value = false;
};

// specialization for the case wehen the tyes are the same
template<typename T>
struct are_same_t<T,T>
{
    static constexpr bool value = true;
};

static_assert(are_same_t<int,int>::value);
static_assert(not are_same_t<int,double>::value);
static_assert(not are_same_t<int, int volatile>::value);

// base case
template<typename T, typename ... ARGS>
struct contains_t
{
    static constexpr bool value = false;
};

// specialization for the case when there is at least one element in the parameter pack
template<typename T, typename FIRST, typename ... ARGS>
struct contains_t<T,FIRST,ARGS...>
{
    static constexpr bool value = are_same_t<T,FIRST>::value || contains_t<T,ARGS...>::value;
};

static_assert(contains_t<int, double, char, float, int, int const>::value);
static_assert(not contains_t<int, double, char, float, int const>::value);

// similar to the contains_t but now we use a predicate which is just another metafunction
template<template <typename> typename PRED, typename ... ARGS>
struct find_if_t
{
    static constexpr bool value = false;
};

// specialization for the case when there is at least one element in the parameter pack
template<template <typename> typename PRED, typename FIRST, typename ... ARGS>
struct find_if_t<PRED,FIRST,ARGS...>
{
    static constexpr bool value = PRED<FIRST>::value || find_if_t<PRED, ARGS...>::value;
};

// new metafuction to use as a predicate
template<typename T>
struct is_int_t
{
    static constexpr bool value = are_same_t<T,int>::value;
};

static_assert(find_if_t<is_int_t, double, char, float, int, int const>::value);
static_assert(not find_if_t<is_int_t, double, char, float, int const>::value);

// or use a an alias template to bind one argument of are_same_t
template <typename T>
using is_int_alias_t = are_same_t<T,int>;

static_assert(find_if_t<is_int_alias_t, double, char, float, int, int const>::value);
static_assert(not find_if_t<is_int_alias_t, double, char, float, int const>::value);

int main()
{
    return 0;
}