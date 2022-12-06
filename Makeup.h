#pragma once
#include <iostream>
using namespace std;

class Makeup {
private:
public:
    string type = "";
    float rating = 0;
    float price = 0;
    string brand = "";
    int id = 0;
    //for pairing heap:
    Makeup* leftChild;
    Makeup* sibling;

    //float GetPrice();
    //void SetPrice(float price);
    Makeup(string brand, string type, float price, float rating, int id);

};

Makeup::Makeup(string brand, string type, float price, float rating, int id) {
    this->id = id;
    this->brand = brand;
    this->type = type;
    this->price = price;
    this->rating = rating;
}