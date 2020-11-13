#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class roman {
private:
	string number;
	bool isRoman() { // check is all number in string are roman or not
		// for example MMMMXL is a roman but mmmmxl not
		//MMFS not a roman
		for (int i = 0; number[i] != '\0';) {
			if (number[i] == 'I' || number[i] == 'V' || number[i] == 'X' || number[i] == 'L' || number[i] == 'C' || number[i] == 'D' || number[i] == 'M') {
				i++;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	int correspondingValue(char c) { //retrun corresponding value of roman number in decimal
		if (c == 'I')
			return 1;
		else if (c == 'V')
			return 5;
		else if (c == 'X')
			return 10;
		else if (c == 'L')
			return 50;
		else if (c == 'C')
			return 100;
		else if (c == 'D')
			return 500;
		else if (c == 'M')
			return 1000;
	}
	int romanToInt() { // convert roman number into decimal
		int res = 0;
		for (int i = 0; i < number.length(); i++) {
			int num1 = correspondingValue(number[i]);
			if (i + 1 < number.length()) {
				int num2 = correspondingValue(number[i + 1]);
				if (num1 >= num2) {
					res = res + num1;
				}
				else {
					res = res + num2 - num1;
					i++;
				}
			}
			else {
				res = res + num1;
			}
		}
		return res;
	}
	void intToRoman(int num) { // roman into number(decimal)
		number.clear();
		while (num != 0) {
			if (num >= 1000) {// 1000 - m
				string s2 = "M";
				number.append(s2);
				num -= 1000;
			}
			else if (num >= 900) {// 900 -  cm
				string s2 = "CM";
				number.append(s2);
				num -= 900;
			}
			else if (num >= 500) {   // 500 - d
				string s2 = "D";
				number.append(s2);
				num -= 500;
			}
			else if (num >= 400) {   // 400 -  cd
				string s2 = "CD";
				number.append(s2);
				num -= 400;
			}
			else if (num >= 100) {// 100 - c{
				string s2 = "C";
				number.append(s2);
				num -= 100;
			}
			else if (num >= 90) {// 90 - xc
				string s2 = "XC";
				number.append(s2);
				num -= 90;
			}
			else if (num >= 50) {// 50 - l
				string s2 = "L";
				number.append(s2);
				num -= 50;
			}
			else if (num >= 40) {// 40 - xl
				string s2 = "XL";
				number.append(s2);
				num -= 40;
			}
			else if (num >= 10) {// 10 - x
				string s2 = "X";
				number.append(s2);
				num -= 10;
			}
			else if (num >= 9) {// 9 - ix
				string s2 = "IX";
				number.append(s2);
				num -= 9;
			}
			else if (num >= 5) {// 5 - v
				string s2 = "V";
				number.append(s2);
				num -= 5;
			}
			else if (num >= 4) {// 4 - iv
				string s2 = "IV";
				number.append(s2);
				num -= 4;
			}

			else if (num >= 1) {     // 1 - i
				string s2 = "I";
				number.append(s2);
				num -= 1;
			}
		}
	}
public:
	roman() {
	}
	roman(roman &const RHS ) {
		int size = RHS.number.size();
		for (int i = 0; i < size; i++) { //copy data
			number[i] = RHS.number[i];
		}
	}
	roman& operator + (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		roman *temp = new roman;
		temp->intToRoman(number1 + number2);
		return *temp;
	}
	roman& operator - (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		roman *temp = new roman;
		temp->intToRoman(number1 - number2);
		return *temp;
	}
	roman& operator * (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		roman *temp = new roman;
		temp->intToRoman(number1 * number2);
		return *temp;
	}
	roman& operator / (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		roman *temp = new roman;
		temp->intToRoman(number1 / number2);
		return *temp;
	}
	roman& operator ++ () {
		int getNumber = this->romanToInt();
		int temp = ++getNumber;
		roman *tempRoman = new roman;
		tempRoman->intToRoman(temp);
		this->intToRoman(getNumber);
		return *tempRoman;
	}
	roman& operator ++ (int) {
		int getNumber = this->romanToInt();
		int temp = getNumber++;
		roman *tempRoman = new roman;
		tempRoman->intToRoman(temp);
		this->intToRoman(getNumber);
		return *tempRoman;
	}
	roman& operator -- () {
		int getNumber = this->romanToInt();
		int temp = --getNumber;
		roman *tempRoman = new roman;
		tempRoman->intToRoman(temp);
		this->intToRoman(getNumber);
		return *tempRoman;
	}
	roman& operator -- (int) {
		int getNumber = this->romanToInt();
		int temp = getNumber--;
		roman *tempRoman = new roman;
		tempRoman->intToRoman(temp);
		this->intToRoman(getNumber);
		return *tempRoman;
	}
	void operator = (roman &const RHS) {
		this->number.clear();
		this->number.append(RHS.number);
	}
	bool operator == (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		if (number1 == number2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator != (roman&const RHS) {
		return !(*this == RHS);
	}
	friend ostream& operator <<(ostream& oUt, roman& const RHS) {
		oUt << RHS.number;
		return oUt;
	}
	friend istream& operator >>(istream& oIn, roman& const RHS) {
		bool isCorrect = false; // check is all number in string are roman or not
		while (!(isCorrect)){
			cout << "Enter Roman Number : ";
			cin >> RHS.number;
			isCorrect = RHS.isRoman();
		}
		return oIn;
	}
	bool operator < (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		if (number1 < number2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator > (roman&const RHS) {
		int number1 = this->romanToInt();
		int number2 = RHS.romanToInt();
		if (number1 > number2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	~roman() {
		number[0] = '\0';
	}
};