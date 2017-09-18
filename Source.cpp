//Name kedamawi mulualem
//CSCI 241-01 Assignment 
//sep/18/2017


#include <iostream>
#include<string>
#include<cmath>
using namespace std;
//global variables 
int sumeven = 0;
int sumodd = 0;
//function to Double every second digit from right to left. 
int sumOfDoubleEvenPlace(int i, long long int input_i) {
	string input = to_string(input_i);
	//base of function
	if (i == 16) {
		return 0;
	}

	else {
		//change the string to int
		int num = int(input[i]) - 48;
		//If double of a digit results in a two-digit number, add up the two digits to get a single digit number.
		if (num >= 5) {
			//Now add all single-digit to global variable sumeven
			sumeven += (num * 2) - 9;
		}
		//If double of a digit results one-digit number doubel it.
		else {
			//Now add all single-digit to global variable sumeven
			sumeven += (num * 2);
		}
		i += 2;
		//call it's self to add the next  second digit from right to left
		sumOfDoubleEvenPlace(i, input_i);
	}
}
//function to Add all digits in the odd places from right to left in the card number.
int sumOfOddPlace(int i, long long int input_i) {
	string input = to_string(input_i);
	//base of function
	if (i == 17) {

		return 0;
	}
	else {
		//change the string to int
		int num = int(input[i]) - 48;
		//Now add all single-digit to global variable sumeodd
		sumodd=sumodd+ num;
		i += 2;
		//call it's self to add the next  second digit from right to left
		sumOfOddPlace(i, input_i);
	}
}
//function to Return the first k number of digits from the number. 
int getPrefix(long long int number, int k) {
	//change the input to string for processing 
	string input = to_string(number);
	//variabel to save the item of the string at i'th index
	string Prefix = "";
	//If the number of digits in number is less than k, return number 
	if (input.size() < k) {
		return number;
	}
	//else Return the first k number of digits from the number. 
	else {
		//add the first k digets to a string 
		for (int i = 0; i < k&&i < 16; i++) {
			Prefix += input[0];
		}
		//variavels for processing 
		long double input_ = 0;
		long int input_2 = 0;
		//loop to change the first k items in the string prefix to intiger
		for (int i = 0; i < k; i++) {
			int mul;
			if (i >= 1) {
				 mul = 10;
			}
			else
				 mul = 1;
			input_ = int(input[i]) - 48;
			cout << input_ << endl;
			input_2 *= mul;
			//add the prefix to a variable
			input_2 += input_;

			

		}
		//return the prefix
		return input_2;
	}

}
//function input a long int and chakes if the sum of the odd place and the even place from left to right mod 10 is 0
bool isValid(long long int input_i) {
	//change the int to string for processing purpuses 
	string input = to_string(input_i);
	//if the card numbers ofcradit card digets is 16 check if the card is valid
	if (input.size() == 16) {
		//set the global variables to 0;
		sumeven = 0;
		sumodd = 0;
		//call the sumOfOddPlace function to add the the items in the odd place the 1 is to show it to start counting by two from the second item in the array
		sumOfOddPlace(1, input_i);
		//call the sumOfDoubleEvenPlace function to add the the items in the odd place the 1 is to show it to start counting by two from the second item in the array
		sumOfDoubleEvenPlace(0, input_i);
		
		//if the sum of the sum of Odd Place digits and sum Of Double Even Place mod 10 is 0 and if the first prefix is one of visa mastercard of other valid card prefix print the card is valid
		if ((sumeven + sumodd) % 10 == 0&&(getPrefix(input_i,1)==4|| getPrefix(input_i, 1) == 5|| getPrefix(input_i, 1) == 6|| getPrefix(input_i, 2) == 37)){
			cout << input << " is valid credit card number" << endl;
		}
		//else print the card is invalid
		else {
			cout<< input << " is a invalid credit card number" << endl;
		}
		//return true or false
		return (sumeven + sumodd) % 10 == 0;
	}
	//if the card does not have 16 digits print the input is invalid 
	else {
		cout << "input card does not have 16 digets" << endl;
		return false;
	}
	
}

void main() {
	long long int user_input;
	while (true) {
		//ask the the user for the cradit card number
		cout << "Enter cradit card number" << endl;
		//input the card number
		cin >> user_input;
		//cheak if the cradit card number is valid
		isValid(user_input);
	}
	system("pause");
}
