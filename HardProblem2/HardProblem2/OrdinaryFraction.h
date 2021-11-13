#pragma once
#include<iostream>
#include<string>



using namespace std;


class OrdinaryFraction
{
private:
	int numerator = 0;
	int denominator = 0;
	int sign = 1;
public:
	OrdinaryFraction(){}
	OrdinaryFraction(string fraction){
		bool flag = false;
		string num = "", denom = "";
		int i;
		for (i = 0; i < fraction.size(); i++) {
			if (fraction[i] == '/') {
				flag = true;
				i++;
			}
			if (fraction[i] == '-') {
				sign = -1;
				i++;
			}
			if (flag) {
				denom += fraction[i];
			}
			else {
				num += fraction[i];
			}
		}
		for (i = 0; i < num.size(); i++) numerator += pow(10, num.size() - i - 1) * ((int)num[i] - 48);
		//numerator *= sign;
		for (i = 0; i < denom.size(); i++) denominator += pow(10, denom.size() - i - 1) * ((int)denom[i] - 48);
		//numerator *= sign;
	}
	void setNumDen(string fraction) {
		bool flag = false;
		string num = "", denom = "";
		int i;
		for (i = 0; i < fraction.size(); i++) {
			if (fraction[i] == '/') {
				flag = true;
				i++;
			}
			if (fraction[i] == '-') {
				sign = -1;
			}
			if (flag) {
				denom += fraction[i];
			}
			else {
				num += fraction[i];
			}
		}
		for (i = 0; i < num.size(); i++) numerator += pow(10, num.size() - i - 1) * ((int)num[i]-48);
		for (i = 0; i < denom.size(); i++) denominator += pow(10, denom.size() - i - 1) * ((int)denom[i]-48);
	}
	void getNumDen() {
		if(sign == 1) cout << numerator << "/" << denominator;
		else cout << "-" << numerator << "/" << denominator;
	}
	int getNum() {
		return numerator;
	}
	int getDenom() {
		return denominator;
	}
	int ordFracMult(int num1, int num2, int denom1, int denom2) {
		return (num1 * num2, denom1 * denom2);
	}
	static int NOD(int a, int b) {
		while (a > 0 && b > 0) {
			if (a == b) return a;
			else if (a > b) a %= b;
			else b %= a;
		}
		return max(a,b);
	}

	static int NOK(int a, int b) {
		return a * b / NOD(a, b);
	}
	friend const OrdinaryFraction operator*(OrdinaryFraction& fst, OrdinaryFraction& snd) {
		int num = fst.getNum() * snd.getNum();
		int denom = fst.getDenom() * snd.getDenom();
		int nod = NOD(num, denom);
		if (nod > 1) {
			num /= nod;
			denom /= nod;
		}
		string snum = "";
		string sdenom = "";
		while (num > 0) {
			snum += (char)(num % 10 + 48);
			num /= 10;
		}
		while (denom > 0) {
			sdenom += (char)(denom % 10 + 48);
			denom /= 10;
		}
		reverse(snum.begin(), snum.end());
		reverse(sdenom.begin(), sdenom.end());
		if(fst.sign * snd.sign == -1) return OrdinaryFraction("-" + snum + "/" + sdenom);
		else return OrdinaryFraction(snum + "/" + sdenom);
	}
	friend const OrdinaryFraction operator/(OrdinaryFraction& fst, OrdinaryFraction& snd) {
		int num = fst.getNum() * snd.getDenom();
		int denom = fst.getDenom() * snd.getNum();
		int nod = NOD(num, denom);
		if (nod > 1) {
			num /= nod;
			denom /= nod;
		}
		string snum = "";
		string sdenom = "";
		while (num > 0) {
			snum += (char)(num % 10 + 48);
			num /= 10;
		}
		while (denom > 0) {
			sdenom += (char)(denom % 10 + 48);
			denom /= 10;
		}
		reverse(snum.begin(), snum.end());
		reverse(sdenom.begin(), sdenom.end());
		if (fst.sign * snd.sign == -1) return OrdinaryFraction("-" + snum + "/" + sdenom);
		else return OrdinaryFraction(snum + "/" + sdenom);
	}
	friend const OrdinaryFraction operator+(OrdinaryFraction& fst, OrdinaryFraction& snd) {
		int num, denom;
		int localSign = 1;
		if (fst.denominator == snd.denominator) {
			if(fst.sign == 1 && snd.sign == 1) num = fst.numerator + snd.numerator;
			if (fst.sign == -1 && snd.sign == -1) {
				num = fst.numerator + snd.numerator;
				localSign = -1;
			}
			if (fst.sign == 1 && snd.sign == -1) {
				num = fst.numerator - snd.numerator;
				if (num < 0) {
					localSign = -1;
					num *= -1;
				}
			}
			if (fst.sign == -1 && snd.sign == 1) {
				num = snd.numerator - fst.numerator;
				if (num < 0) {
					localSign = -1;
					num *= -1;
				}
			}
			denom = fst.denominator;
		}
		else {
			denom = NOK(fst.denominator, snd.denominator);
			if (fst.sign == 1 && snd.sign == 1) num = fst.numerator * (denom / fst.denominator) + snd.numerator * (denom / snd.denominator);
			else if (fst.sign == -1 && snd.sign == -1) {
				num = fst.numerator * (denom / fst.denominator) + snd.numerator * (denom / snd.denominator);
				localSign = -1;
			}
			else if (fst.sign == 1 && snd.sign == -1) {
				num = fst.numerator * (denom / fst.denominator) - snd.numerator * (denom / snd.denominator);
				if (num < 0) {
					localSign = -1;
					num *= -1;
				}
			}
			else if (fst.sign == -1 && snd.sign == 1) {
				num = snd.numerator * (denom / snd.denominator) + fst.numerator * (denom / fst.denominator);
				if (num < 0) {
					localSign = -1;
					num *= -1;
				}
			}
		}
		int nod = NOD(num, denom);
		if (nod > 1) {
			num /= nod;
			denom /= nod;
		}
		string snum = "";
		string sdenom = "";
		while (num > 0) {
			snum += (char)(num % 10 + 48);
			num /= 10;
		}
		while (denom > 0) {
			sdenom += (char)(denom % 10 + 48);
			denom /= 10;
		}
		reverse(snum.begin(), snum.end());
		reverse(sdenom.begin(), sdenom.end());
		//cout << snum << "\n";
		//cout << "-" + snum + "/" + sdenom << "\n";
		if (localSign == -1) {
			return OrdinaryFraction("-" + snum + "/" + sdenom);
		}
		else {
			return OrdinaryFraction(snum + "/" + sdenom);
		}
	}
	friend const OrdinaryFraction operator-(OrdinaryFraction& fst, OrdinaryFraction& snd) {
		int num, denom;
		snd.sign *= (-1);
		OrdinaryFraction raz = fst + snd;
		snd.sign *= (-1);
		return raz;
	}
	double translateToDecimal() {
		return (double)numerator / (double)denominator;
	}
};