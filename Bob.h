#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <random>

using namespace std;

class Bob {
public:
	int e;

	int Bob_gen_e() {
		int temp = pow(2, 16);
		e = (rand() % temp + 1);
		printf("\nB -> A {%d}", e);
		return (e);
	}
	void Bob_check(int g, int s, int y, int p, int x) {
		BigInteger temp1 = Bigpow(g, s);
		BigInteger temp2 = Bigpow(y, e);
		temp1 *= temp2;
		int checkx = stoi(mod(temp1, p).getNumber());
		if (checkx = x) {
			printf("\nChecking, is x {%d} equals to our x {%d}", checkx, x);
			printf("\nNumbers checked succesfully!");
		}
		else {
			printf("\nChecking, is x {%d} equals to our x {%d}", checkx, x);
			printf("\nOh no, something went wrong!");
		}
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
};