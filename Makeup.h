#pragma once
#include <iostream>
using namespace std;

class Makeup {
private:
public:
    int id;
    string type;
    float rating;
    float price;
    string brand;
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
