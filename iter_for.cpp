#include <iostream> 
#include <vector>


int main(void) {
	std :: vector <int> data {1, 2, 3, 4};
	int _data[3] {1, 2, 3};
	for(int i : _data) {
		std :: cout << i << "\n";
	}	
	return 0;
}
