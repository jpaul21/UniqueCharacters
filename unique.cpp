/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Joshua P. Hwang
 * Date        : 9/21/2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor Code.
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool is_all_lowercase(const string &s) {
	// TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
	for(const auto i : s){
		if(i < 'a' || i > 'z'){
			return false;
		}
	}
	return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
	unsigned long int check = pow(2, (s[0] - 97));
	for(unsigned long int i = 1; i < s.length(); i++){
		if((uint32_t(pow(2, (s[i] - 97)))&check) != 0){
			return false;
		}
		check = (check^uint32_t(pow(2, (s[i] - 97))));
	}
	return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
	if(argc != 2){
		cout << "Usage: ./unique <string>";
		return 0;
	}
	string word = argv[1];
	// checks if all lowercase. if yes, check for uniqueness.
	if(is_all_lowercase(word)){
		if(all_unique_letters(word)){
			cout << "All letters are unique.";
		} else cout << "Duplicate letters found.";
	} else cout << "Error: String must contain only lowercase letters.";
	return 0;
}
