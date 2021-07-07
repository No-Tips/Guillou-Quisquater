#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include "BigInteger/BigInteger.h"

using namespace std;

class TrustCenter {
public:
	int p, q, g, y, w;

	void GenKeys() {
		printf("Trust Center is generating keys...\n");
		BigInteger temp;
		srand(time(0));
		bool Check;
		do {
			p = rand() % 500 + 5;
			Check = SimpleNumCheck(p);
		} while (!Check);
		Check = false;

		do {
			q = rand() % 500 + 5;
			if (mod(p - 1, q) == 0) {
				Check = true;
			}
		} while (!Check);
		Check = false;

		do {
			g = rand() % 500 + 5;
			temp = Bigpow(g, q);
			if (mod(temp, p) == 1) {
				Check = true;
			}
		} while (!Check);
		Check = false;

		w = rand() % (q - 1) + 1;

		temp = Bigpow(g, w);
		temp = reverse(temp, p);
		y = stoi(temp.getNumber());

		printf("\nOpen keys are {%d,%d,%d,%d}, Secret key is {%d}\n", p, q, g, y, w);
	}
private:
	BigInteger Bigpow(int base, int pow) {
		BigInteger result = 1;
		for (int i = 1; i < pow;i++) {
			result *= base;
		}
		return result;
	}

	BigInteger mod(BigInteger x, int N) {
		return ((x % N + N) % N);
	}

	int reverse(BigInteger a, int q) { //Обратное число по модулю
		mod(a, q);
		BigInteger i;
		for (i = 1;i < a;i++)
			if (mod((a * i), q) == 1) return stoi(i.getNumber());
		return 99999;
	}

	bool SimpleNumCheck(BigInteger num) { //Проверка числа на простоту
		for (BigInteger z = 2; stoi(z.getNumber()) <= sqrt(stoi(num.getNumber())); z++)
		{
			if (num % z == 0)
			{
				return false;
			}
		}
		return true;
	}
};