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
class Sieve0 : public ISieve<T> {
	// Sito bez sita. Generyczna, najprostsza impementacja interfejsu. next(n) zwraca n+1, iSPrime() zawsze zwraca ok==false, nie ma przesiewania liczb pierwszych.
public:
	Sieve0() {};

	Sieve0(T n) : Sieve0() {
		resize(n);
	};

	void resize(T m) override {	};

	T getMax() const override {
		return 0;
	};

	T next(T n) const override {
		return n + 1;
	};

	bool isPrime(T n, bool& ok) const override {
		ok = false;
		return false;
	};

	size_t Arr1Size() override {
		return 0;
	};

	size_t Arr2Size() override {
		return 0;
	};
};

template < typename T>
class SieveA : public ISieve<T> {
private:
	T N;
	std::vector<bool> sieve;
	std::vector<T> primes;
public:
	SieveA() : N(T{ 0 }) {
		sieve.clear();
		primes.clear();
	};

	SieveA(T n) : SieveA() {
		resize(n);
	};

	void resize(T m) override {
		if (m > N) {
			assert(m / 2 <= std::numeric_limits<T>::max());

			sieve.clear();
			primes.clear();
			sieve.resize(m);
			std::fill(sieve.begin(), sieve.end(), true);

			for (T i = T{ 2 }; i < m; ++i) {
				if (sieve[i]) {
					primes.push_back(i);
					for (T j = 2 * i; j < m; j += i) {
						sieve[j] = false;
					}
				}
			}
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
		return ok ? sieve[n] : false;
	};

	size_t Arr1Size() override {
		return sieve.size();
	};

	size_t Arr2Size() override {
		return primes.size();
	};
};

int main()
{
	bool ok = false;

	//	ISieve<int> *sito0 = new Sieve0<int>{1000};
	//	assert(sito0->getMax() == 0);
	//	assert(sito0->Arr1Size() == 0);
	//	assert(sito0->Arr2Size() == 0);
	//	assert(sito0->next(9) == 10);
	//	ok = true;
	//	sito0->isPrime(9, ok);
	//	assert(!ok);



	ISieve<int> *sito1 = new SieveA<int>{};
	sito1->resize(1'000'000);
	std::cout << sito1->Arr2Size();


	//	assert(sito1->getMax() == 0);
	//	assert(sito1->Arr1Size() == 0);
	//	assert(sito1->Arr2Size() == 0);
	return 0;
}
