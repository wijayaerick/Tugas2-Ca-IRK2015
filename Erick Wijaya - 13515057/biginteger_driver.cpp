// NIM/Nama : 13515057 / Erick Wijaya
// File     : biginteger_driver.cpp

#include "biginteger.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	biginteger b1(1234);
	biginteger b2("-8765432210003232830134147208");
	biginteger b3 = b2;
	biginteger b4;

	biginteger b5(-17364324723847238LL);
	biginteger b6("1234567890");
	biginteger b7("1");
	biginteger b8("-2");

	biginteger b9(1);
	biginteger b10(-2);
	biginteger b11 = b8;
	biginteger b12 = b10;

	cout << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
	cout << b5 << " " << b6 << " " << b7 << " " << b8 << endl;
	cout << b9 << " " << b10 << " " << b11 << " " << b12 << endl;

	return 0;
}
