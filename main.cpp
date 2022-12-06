#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>
#include <iomanip>
#include <chrono>
#include "PairingHeap.h"
#include "MinHeap.h"
#include "MinMakeup.h"
#include "Makeup.h"
using namespace std;
using namespace std::chrono;

void readPairing(vector<Makeup*>& previousMins, string category) {
    PairingHeap heap;

    fstream file("makeup (2).csv", ios_base::in);
    if (file.is_open()) {
        string line;
        //getline(file, line);
        while (getline(file, line)) {
            bool alreadyPrinted = false; // reset after every makeup added
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
            //cout << tempID;
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

            for (int i = 0; i < previousMins.size(); i++) { //iterate through past minimums
                if (previousMins[i]->id == ID) { //don't add a makeup that already has been printed as a min
                    alreadyPrinted = true;
                }
            }
            if (!alreadyPrinted && type == "Foundation") {
                Makeup* newMakeup = new Makeup(brand, type, price, rating, ID);
                heap.Insert(newMakeup);
            }
        }
    }
    else {
        cout << "file not open" << endl;
    }

    cout << "Price: $" << heap.GetMin()->price << " ";
    cout << "Product: " << heap.GetMin()->brand << " ";
    cout << "Rating: " << heap.GetMin()->rating << endl;
    //cout << "size: " << heap.size << endl;

    //place the minimum into a vector to keep track of those that have been printed
    if (heap.GetMin() != nullptr) { //TODO: if heap.GetMin()->price < whatever minimum price they insert
        //cout << "added " << heap.GetMin()->price << endl;
        previousMins.push_back(heap.GetMin());
    }
//    for (int i = 0; i < previousMins.size(); i++) {
//        cout << previousMins[i]->price << endl;
//    }
}
void read(MinHeap& h, string category) {
    fstream file("makeup (2).csv", ios_base::in);
    if (file.is_open()) {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            MinMakeup m;
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
            ID = stoi(tempID);
            m.id = ID;

            getline(stream, tempBrand, ',');
            brand = tempBrand;
            //cout << brand << endl;
            m.brand = brand;
            getline(stream, tempType, ',');
            type = tempType;
            m.type = type;
            getline(stream, tempPrice, ',');
            price = stof(tempPrice);
            //cout << price << endl;
            m.price = price;
            getline(stream, tempRating, ',');
            rating = stof(tempRating);
            //cout << rating << endl;
            m.rating = rating;

            //Makeup newMakeup(brand, type, price, rating);
            //pairingHeap.Insert(&newMakeup);
            if (m.type == category) {
                h.insertKey(m);
            }
        }
    }
    else {
        cout << "file not open" << endl;
    }
}

int main() {

    cout << endl << endl << "Welcome to SuperDuper! By searching through thousands of products, "
            "SuperDuper finds the best option that aligns with " << endl << "your budget without sacrificing quality!" << endl;
    cout << endl << "What type of product are you looking for today?" << endl;
    cout << "1. Makeup" << endl << "2. Skin Care" << endl << "3. Hair Care" << endl << "4. Nail Care" << endl;
    cout << "Please type in the corresponding number with your desired product type. (For example, '2' for Skin Care)" << endl;
    string tempNum;
    getline(cin, tempNum);
    int num = stoi(tempNum);
    if (num == 1) {
        cout << "Makeup:" << endl;
        cout << "BB Cream" << endl << "Lipstick" << endl << "Eyeshadow" << endl << "Perfume" << endl << "Setting Spray" << endl;
        cout << "Concealer" << endl << "Eyebrow Pencil" << endl << "Foundation" << endl << "Eyeliner" << endl << "Highlighter" << endl;
        cout << "Eyelashes" << endl << "Blush" << endl << "Mascara" << endl << "Makeup Brush" << endl << "Primer" << endl;
    } else if (num == 2) {
        cout << "Skin Care: " << endl;
        cout << "Sunscreen" << endl << "Kit" << endl << "Spot Patch" << endl << "Face Mask" << endl << "Moisturizer" << endl;
        cout << "Face Wash" << endl << "Eye Cream" << endl << "Hand Cream" << endl << "Acne Cream" << endl << "Lip Balm"  << endl;
        cout << "Night Cream" << endl << "Day Cream" << endl << "Anti-Ageing Cream" << endl << "Face Roller" << endl;

    } else if (num == 3) {
        cout << "Hair Care" << endl;
        cout << "Shampoo" << endl;
    } else if (num == 4) {
        cout << "Nail Care" << endl;
        cout << "Nail polish" << endl << "Nail Enamel Remover" << endl;
    } else {
        cout << "Please type a number. Restart the program." << endl;
    }

    cout << "Please type in the product you would like to find. (Type exactly how it is written above)" << endl;
    string userType;
//    cin >> userType;
    getline(cin, userType);

    cout << "SuperDuper will provide a list of the best products that are under that price!" << endl;
    cout << "Please enter a price that you would like the product to be cheaper than." << endl;
    int userIntPrice = 0;
    cin >> userIntPrice;

    float userPrice = (float)userIntPrice;

    //MIN HEAP:

    MinHeap h(103000);
    auto start = high_resolution_clock::now();
    read(h, userType);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    /*
    for (int i = 0; i < list.size(); i++) {
        h.insertKey(list[i]);
    }*/


    /*
    for (int i = 0; i <100; i++) {
        Makeup p = h.extractMin();
        cout << p.price << " " << p.brand << " "<<p.type<<" "<<endl;
    }*/

    float temp = 0.0;
    while (temp < userPrice) {
        MinMakeup p = h.extractMin();
        temp = p.price;
        if (temp < userPrice) {
            cout << "Price: $" << p.price << " " << "Product: " << p.brand << " " << p.type << " " << "Rating: " << p.rating << endl;
        }
    }
    cout << endl;
    cout << "Time taken to insert elements into minheap: "
         << duration.count() << " milliseconds" << endl << endl << endl;
    /*
    cout << "Minimun makeup price is:" << h.getMin() << endl;
    for (int i = 0; i < list.size(); i++) {
        //h.insertKey(list[i].price);
        if (list[i].price == h.getMin()) {
            cout << "brand name is: " << list[i].brand << endl;
        }
    }
    cout << "printing full heap:" << endl;
    for (int i = 0; i < list.size(); i++) {
        cout << h.extractMin() << " ";
    }
    */


    //PAIRING HEAP:
    vector<Makeup*> previousMins;

    //    1. ask user for makeup category that they want
    //    2. loop through file and insert all makeups with corresponding categories into the min heap/pairing heap
    //    3. print out the ones with the lowest price
    //    4. print out execution time


    auto startPairing = high_resolution_clock::now();
    readPairing(previousMins, userType);
    auto stopPairing = high_resolution_clock::now();
    auto durationPairing = duration_cast<milliseconds>(stopPairing - startPairing);

    while (previousMins[previousMins.size()-1]->price < userPrice) {
        readPairing(previousMins, userType);
    }

    cout << "Time taken to insert elements into pairing heap: " << durationPairing.count() << " milliseconds" << endl;
    //        readFile(previousMins, "foundation");
//        num++;

//        if (previousMins[previousMins.size()-1]->price > 50) {
//            break;
//        }

//        for (int i = 0; i < previousMins.size(); i++) {
//             cout << previousMins[i]->price << endl;
//             if (previousMins[i]->price > 50) {
//                 break;
//             }
//        }



    return 0;
}