
#include <iomanip>
#include <iostream>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <string>
using namespace std;


int main() {
	//"hello lauren";
	fstream file("sephora_dataset.csv", ios_base::in);
	if (file.is_open()) {
		string line;
		getline(file, line);
		while (getline(file, line)) {
			stringstream stream(line);
			string temp;
			cout << line << endl;
		
		}
	}
	else {
		cout << "file not open" << endl;
	}
	return 0;
}