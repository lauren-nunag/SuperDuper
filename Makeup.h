#pragma once
#include <iostream>
using namespace std;

class Makeup {
private:
public:
    string type;
    float rating;
    float price;
    string brand;
    Makeup* leftChild;
    Makeup* sibling;

    float GetPrice();
    void SetPrice(float price);
    Makeup(string brand, string type, float price, float rating);
};

Makeup::Makeup(string brand, string type, float price, float rating) {
    brand = brand;
    type = type;
    price = price;
    rating = rating;
}

