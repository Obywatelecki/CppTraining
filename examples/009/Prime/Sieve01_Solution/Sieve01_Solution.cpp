// Sieve01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <assert.h>

template < typename T>
class ISieve {
public:
	virtual void resize(T m) = 0;
	virtual T getMax() const = 0;
	virtual T next(T n) const = 0;
	virtual bool isPrime(T n, bool& ok) const = 0;
	virtual size_t Arr1Size() = 0;
	virtual size_t Arr2Size() = 0;
};

template < typename T>
class SieveA : public ISieve<T> {
private:
	T N;
	std::vector<bool> arr1;
	std::vector<T> arr2;
public:
	SieveA() : N(T{ 0 }) {
		arr1.clear();
		arr2.clear();
	};

	SieveA(T n) : SieveA() {
		resize(n);
	};

	void resize(T m) override {
		assert(false);

		// na poczatek mozna zrobic to brute force:
		if (m > N) {
			arr1.clear();
			arr2.clear();
			// tutaj zwykle generowanie sita, takie jak pisaliscie w poprzednim zadaniu domowym
			N = m;
		}
	};

	T getMax() const override {
		return N;
	};

	T next(T n) const override {
		assert(false);
		return n + 1;
	};

	bool isPrime(T n, bool& ok) const override {
		ok = n >= 0 || n < N;
		return ok ? arr1[n] : false;
	};

	size_t Arr1Size() override {
		return arr1.size();
	};

	size_t Arr2Size() override {
		return arr2.size();
	};
};

int main()
{
	ISieve<int> *sito1 = new SieveA<int>{};
	assert(sito1->getMax() == 0);
	assert(sito1->Arr1Size() == 0);
	assert(sito1->Arr2Size() == 0);
	return 0;
}
