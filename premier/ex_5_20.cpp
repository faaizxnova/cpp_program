#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(void) {
	std :: string text;
	std :: string word;

	std :: cout << "Enter a sentance : ";
	std :: getline(std :: cin, text);
	
	std :: stringstream ss(text);
	std :: vector <std :: string> sent;

	while(ss >> word) { sent.push_back(word); }

	auto start = sent.begin();
	while(start != sent.end() - 1) {
		std :: cout << *start << " ";
		if(*start == *(start + 1)) {
			break;
		}
		start ++;
	}
	

	if(start == sent.end() - 1) std :: cout << *start;
	return 0;
}
