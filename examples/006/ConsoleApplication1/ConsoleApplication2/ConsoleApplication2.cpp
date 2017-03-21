
#include "stdafx.h"

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
// 	return x+x;
// }
// 

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
// int fu(int N) {
// 	return N;
// }

// template <int N>
// int uu(int N) {
// 	return N*uu<int>(N-1);
// }
// 
// template <1>
// int uu(int N) {
// 	return 1;
// }

// type traits

template <typename int>
bool is_int() {
	return true;
}


template <typename T>
bool is_int() {
	return false;
}

int main()
{
//	auto x = fun3<int*>(nullptr);

//	What<int, 100> x{10};
//	auto f3 = fu<3>;
//	auto f2 = fu<2>;

//	auto u = uu<3>;

	auto czy1 = is_int<float>();
	auto czy2 = is_int<int>();

	return 0;
}
