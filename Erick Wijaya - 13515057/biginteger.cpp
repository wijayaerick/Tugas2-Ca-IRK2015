// NIM/Nama : 13515057 / Erick Wijaya
// File     : biginteger.cpp

#include "biginteger.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Constructors */
biginteger::biginteger() {
	pos = true;
	digits.push_back(0);
}

biginteger::biginteger(long long v) {
	pos = v >= 0;
	if (!pos)
		v = -v;
	while (v != 0){
		int dig = v % BASE;
		digits.push_back(dig);
		v /= BASE;
	}
}

biginteger::biginteger(const string& v) {
	if (v.length() == 0){
		pos = true;
		digits.push_back(0);
	}
	else{
		pos = v[0] != '-';
		int end = pos ? 0 : 1;
		for(int i=v.length()-1; i>=end; i--){
			int dig = v[i] - '0';
			digits.push_back(dig);
			//cout << v[i] << " " << dig << " " << endl;
			//cout << *this << endl;
		}
	}
}

biginteger::biginteger(const biginteger& v) : pos(v.pos), digits(v.digits) {

}


/* Operator= */
biginteger& biginteger::operator=(const biginteger& rhs){
	if (this != &rhs){
		pos = rhs.pos;
		digits = rhs.digits;
	}
	return *this;
}


/* Arithmetic Operators */
biginteger biginteger::operator+(const biginteger& rhs){
	if (pos == res.pos){
		int max = max(rhs.digits.size(), digits.size());
		int carry = 0;
		biginteger res = rhs;

		for(int i=0; i<max; i++){
			if (i == res.digits.size())
				res.digits.push_back(0);

			res.digits[i] += carry + (i < digits.size() ? digits[i] : 0);
			carry = res.digits[i] / BASE;
			if (carry)
				res.digits[i] -= BASE;
		}
		if (carry)
			res.digits.push_back(carry);

		return res;
	}
	else{
		return *this - (-rhs);
	}
}

biginteger biginteger::operator-(){
	biginteger res = *this;
	res.pos = !res.pos;
	return res;
}

biginteger biginteger::operator-(const biginteger& rhs){
	if (pos == rhs.pos){
		if (abs() >= rhs.abs()){ // this >= rhs
			biginteger res = *this;
			int carry = 0;

			for(int i=0; i<digits.size(); i++){
				res.digits[i] -= carry + rhs.digits[i];
				carry = (res.digits[i] < 0)? 1 : 0;
				if (carry)
					res.digits += BASE;
			}

			return res;
		}
		else{ // this < rhs
			// this - rhs = -(rhs - this)
			return -(rhs - *this);
		}
	}
	else{
		return *this + (-v);
	}
}

biginteger biginteger::operator*(const biginteger& rhs){
	// Make sure both value have same size
	int diffsize = digits.size() - rhs.size();
	if (diffsize < 0) diffsize *= -1;

	biginteger v1 = *this;
	biginteger v2 = rhs;

	if (v1.digits.size() < v2.digits.size()){
		for(int i=0; i<diffsize; i++)
			v1.push_back(0);
	}
	else{
		for(int i=0; i<diffsize; i++)
			v2.push_back(0);
	}

	// Calculate with Karatsuba Algorithm

}

biginteger biginteger::operator/(const biginteger& rhs){

}

biginteger biginteger::operator%(const biginteger& rhs){

}

biginteger& biginteger::operator+=(const biginteger& rhs){
	*this = *this + rhs;
	return *this;
}

biginteger& biginteger::operator-=(const biginteger& rhs){
	*this = *this - rhs;
	return *this;
}

biginteger& biginteger::operator*=(const biginteger& rhs){

}

biginteger& biginteger::operator/=(const biginteger& rhs){

}

biginteger& biginteger::operator%=(const biginteger& rhs){

}

biginteger biginteger::add(const biginteger& rhs){
	return *this + rhs;
}

biginteger biginteger::min(const biginteger& rhs){
	return *this - rhs;
}

biginteger biginteger::mul(const biginteger& rhs){

}

biginteger biginteger::div(const biginteger& rhs){

}

biginteger biginteger::mod(const biginteger& rhs){

}

biginteger biginteger::abs(){
	biginteger res = *this;
	res.pos = true;
	return res;
}


/* Relational Operators */
bool biginteger::operator==(const biginteger& rhs){

}

bool biginteger::operator>(const biginteger& rhs){

}

bool biginteger::operator<(const biginteger& rhs){

}


/* I/O */
istream& operator>>(istream &is, const biginteger& v){

}

ostream& operator<<(ostream &os, const biginteger& v){
	if (!v.pos)
		os << "-";
	for(int i=v.digits.size()-1; i>=0; i--)
		os << v.digits[i];
	return os;
}

int biginteger::max(int a, int b){
	return (a > b) ? a : b;
}