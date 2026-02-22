#include <iostream>
#include <string>

int main(void) {
	std :: string a = "", b = "";
	do {	
		if(!(std :: cin >> a || std :: cin >> b)) break;
	
		if(a.size() > b.size()) std :: cout << a << " is bigger\n";
		else std :: cout << b << " is bigger\n";	
	} while(true);
	return 0;
}
