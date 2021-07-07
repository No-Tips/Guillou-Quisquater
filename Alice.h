#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <random>

using namespace std;

class Alice {
public:
	int s, r;
	BigInteger temp;
	int Alice_make_x(int p, int q, int g) {
		int x;
		r = (rand() % (q - 2) + 1);
		temp = Bigpow(g, r);
		x = stoi((mod(temp, p).getNumber()));
		printf("\nA -> B {%d}", x);
		return(x);
	}
	int Alice_make_s(int w, int e, int q) {
		s = mod((r + w * e), q);
		printf("\nA -> B {%d}", s);
		return s;
	}
private:

	BigInteger Bigpow(int base, int pow) {
		BigInteger result = 1;
		for (int i = 1; i < pow;i++) {
			result *= base;
			//cout << result.getNumber() + "\t";
		}
		return result;
	}

	BigInteger mod(BigInteger x, BigInteger N) {
		return ((x % N + N) % N); //¬ отличии от просто % работает и с числами <0
	}
	int mod(int x, int N) {
		return ((x % N + N) % N); //¬ отличии от просто % работает и с числами <0
	}
};