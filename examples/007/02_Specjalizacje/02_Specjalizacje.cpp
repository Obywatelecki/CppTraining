#include "stdafx.h"
#include <iostream>
#include <type_traits>

/////////////////// case 1

// fun1, fun2 - nic ciekawego
// fun3 - nie zadza³a dl atypów, które nie maj¹ operatora T+T (na przyk³ad dla wskaŸników

// template <typename T>
// T fun1()
// {
// 	return T{ 0 };
// }
// 
// template <typename T>
// T fun2(T x)
// {
// 	return x;
// }
// 
// template <typename T>
// T fun3(T x)
// {
// 	return x + x;
// }

/////////////////// case 2

// int te¿ mo¿e byæ argumentem wzorca

// template <class T, int N>
// class What {
// private:
// 	T arg[N];
// public:
// 	What(T arg) {
// 	};
// 
// };

// template <int N>
// int fu() {
// 	return N;
// }

/////////////////// case 3

// template <unsigned int n>
// struct fact {
// 	enum { value = n * fact <n - 1>::value };
// };
// 
// template <>
// struct fact<0> {
// 	enum { value = 1 };
// };

/////////////////// case 4 - is_integral i inne type traitsy - w mainie

class C1 {
	int member;
	void aFun();
};

class C2 {
	int member;
	virtual void aFun();
};

int main()
{
	/////////////////// case 1

	//	auto f2 = fun3<int>(0);          // fun3 Ok
	//	auto f3 = fun3<int*>(nullptr);   // fun3 error

	/////////////////// case 2

	//	What<int, 100> x{ 10 };
	//	auto g = fu<19>();

	/////////////////// case 3

	//	auto s3 = fact<5>::value;            // 	mov dword ptr[s3], 78h     // 78h = 120 = 5!

	/////////////////// case 4	- is_integral i inne type traitsy

	//	std::cout << std::boolalpha << std::is_integral<unsigned int      >::value << std::endl;
	//	std::cout << std::boolalpha << std::is_integral<float             >::value << std::endl;

	//	static_assert(std::is_trivial<C1>::value, "Class is not trivial");
	//	static_assert(std::is_trivial<C2>::value, "Class is not trivial");

	return 0;
}
