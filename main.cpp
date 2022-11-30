#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "PairingHeap.h"
using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;
    PairingHeap pairingHeap;

    vector<Makeup> list;
//    Makeup m;
//    m.price = 9;
//    pairingHeap.Insert(&m);
//    Makeup n;
//    n.price = 33;
//    pairingHeap.Insert(&n);
//    Makeup o;
//    o.price = 17;
//    pairingHeap.Insert(&o);
//    Makeup p;
//    p.price = 8;
//    pairingHeap.Insert(&p);
//    Makeup q;
//    q.price = 72;
//    pairingHeap.Insert(&q);

//    Makeup* cheapest = pairingHeap.GetMin();
//    cout << cheapest->price << endl;

//    1. ask user for makeup category that they want
//    2. loop through file and insert all makeups with corresponding categories into the min heap/pairing heap
            //if id is the same, don't insert duplicates
//    3. print out the ones with the lowest price
//    4. print out execution time
    //pairingHeap.Print();
fstream file("makeupMaybeFinal.csv", ios_base::in);
	if (file.is_open()) {
		string line;
		getline(file, line);
		while (getline(file, line)) {
			stringstream stream(line);
			string temp;
			//cout << line << endl;
            int ID = 0;
            string type = "";
            float rating = 0.0;
            float price = 0.0;
            string brand = "";

            string tempID = "";
            string tempType = "";
            string tempRating = "";
            string tempPrice = "";
            string tempBrand = "";
            //id, brand, type, price, rating
            getline(stream, tempID, ',');
//            if (tempID == "") {
//                break;
//            }
            ID = stoi(tempID);
            //cout << ID << " ";
            getline(stream, tempBrand, ',');
            brand = tempBrand;
            getline(stream, tempType, ',');
            type = tempType;
            getline(stream, tempPrice, ',');
            price = stof(tempPrice);
            //cout << price << endl;
            getline(stream, tempRating, ',');
            rating = stof(tempRating);

            Makeup* newMakeup;
            newMakeup->price = price;
            newMakeup->brand = brand;
            newMakeup->rating = rating;
            newMakeup->type = type;
            pairingHeap.Insert(newMakeup);
		}
	}
	else {
		cout << "file not open" << endl;
	}

    float cheapest = pairingHeap.GetMin();
    cout << cheapest << endl;

	return 0;
}
