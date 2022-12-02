
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
//minheap code
/*
#include <iomanip>
#include <iostream>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <string>
using namespace std;

int main() {
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
}*/
#include<iostream>
#include <vector>
#include <string>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);
class Makeup {
public:
	string type;
	int rating = 0;
	int price = 0;
	string brand;
};
// A class for Min Heap
class MinHeap
{
	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size;
	
	public:
		// Constructor
		MinHeap(int capacity);

		// to heapify a subtree with the root at given index
		void MinHeapify(int);

		int parent(int i) { return (i - 1) / 2; }

		// to get index of left child of node at index i
		int left(int i) { return (2 * i + 1); }

		// to get index of right child of node at index i
		int right(int i) { return (2 * i + 2); }

		// to extract the root which is the minimum element
		int extractMin();
		void decreaseKey(int i, int new_val);

		// Returns the minimum key (key at root) from min heap
		int getMin() { return harr[0]; }

		// Deletes a key stored at index i
		void deleteKey(int i);

		// Inserts a new key 'k'
		void insertKey(int k);
	};
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{	/*
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();*/
	vector<Makeup> list;
	Makeup m;
	m.price = 9;
	m.brand = "Brenda Babes";
	list.push_back(m);
	Makeup n;
	n.price = 33;
	n.brand = "Brenda Babes";
	list.push_back(n);
	Makeup o;
	o.price = 1;
	o.brand = "Brenda Babes";
	list.push_back(o);
	Makeup p;
	p.price = 8;
	p.brand = "Brenda Babes";
	list.push_back(p);
	Makeup q;
	q.price = 72;
	q.brand = "Brenda Babes";
	list.push_back(q);

	MinHeap h(list.size());
	for (int i = 0; i < list.size(); i++) {
		h.insertKey(list[i].price);
	}
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
	return 0;
}


//modified code
/*
#include <iomanip>
#include <iostream>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <string>
using namespace std;

int main() {
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
}*/
#include<iostream>
#include <vector>
#include <string>
#include<climits>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>

using namespace std;

// Prototype of a utility function to swap two integers
//void swap(int* x, int* y);
class Makeup {
public:
	string type;
	int rating = 0;
	float price = 0;
	string brand;
};
void swap(Makeup* x, Makeup* y);
// A class for Min Heap
class MinHeap
{
	//int* harr; // pointer to array of elements in heap
	Makeup* harr;
	int capacity; // maximum possible size of min heap
	int heap_size;
	
	public:
		// Constructor
		MinHeap(int capacity);

		// to heapify a subtree with the root at given index
		void MinHeapify(int);
		//dont change
		int parent(int i) { return (i - 1) / 2; }

		// to get index of left child of node at index i
		int left(int i) { return (2 * i + 1); }

		// to get index of right child of node at index i
		int right(int i) { return (2 * i + 2); }

		// to extract the root which is the minimum element
		//int extractMin();
		Makeup extractMin();
		//void decreaseKey(int i, int new_val);
		void decreaseKey(int i, Makeup new_val);

		// Returns the minimum key (key at root) from min heap
		Makeup getMin() { return harr[0]; }

		// Deletes a key stored at index i
		void deleteKey(int i);

		// Inserts a new key 'k'
		//void insertKey(int k);
		void insertKey(Makeup k);
	};
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	//change to new makeup
	//harr = new int[cap];
	harr = new Makeup[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(Makeup k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)].price > harr[i].price)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, Makeup new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)].price > harr[i].price)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}
Makeup MinHeap::extractMin()
{
	//if (heap_size <= 0)
	//	return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	Makeup root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}
//void MinHeap::deleteKey(int i)
//{
//	decreaseKey(i, INT_MIN);
//	extractMin();
//}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].price < harr[i].price)
		smallest = l;
	if (r < heap_size && harr[r].price < harr[smallest].price)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(Makeup* x, Makeup* y)
{
	Makeup temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{	/*
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();*/
	
	vector<Makeup> list;
	Makeup m;
	m.price = 9;
	m.brand = "Brenda Babes";
	list.push_back(m);
	Makeup n;
	n.price = 33;
	n.brand = "Brenda Babes";
	list.push_back(n);
	Makeup o;
	o.price = 1;
	o.brand = "Brenda Babes";
	list.push_back(o);
	Makeup p;
	p.price = 8;
	p.brand = "Brenda Babes";
	list.push_back(p);
	Makeup q;
	q.price = 72;
	q.brand = "Brenda Babes";
	list.push_back(q);

	MinHeap h(list.size());
	for (int i = 0; i < list.size(); i++) {
		h.insertKey(list[i]);
	}
	for (int i = 0; i < list.size(); i++) {
		cout << h.extractMin().price << " ";
	}
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

	return 0;
}
///code works now
/*
#include <iomanip>
#include <iostream>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <string>
using namespace std;

int main() {
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
}*/
#include<iostream>
#include <vector>
#include <string>
#include<climits>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Prototype of a utility function to swap two integers
//void swap(int* x, int* y);
class Makeup {
public:
	string type;
	float rating = 0;
	float price = 0;
	string brand;
	double id = 0;
};
void swap(Makeup* x, Makeup* y);
// A class for Min Heap
class MinHeap
{
	//int* harr; // pointer to array of elements in heap
public:
	Makeup* harr;
	int capacity; // maximum possible size of min heap
	int heap_size;
	
	//public:
		// Constructor
		MinHeap(int capacity);

		// to heapify a subtree with the root at given index
		void MinHeapify(int);
		//dont change
		int parent(int i) { return (i - 1) / 2; }

		// to get index of left child of node at index i
		int left(int i) { return (2 * i + 1); }

		// to get index of right child of node at index i
		int right(int i) { return (2 * i + 2); }

		// to extract the root which is the minimum element
		//int extractMin();
		Makeup extractMin();
		//use this function to get most minimun price
		//void decreaseKey(int i, int new_val);
		void decreaseKey(int i, Makeup new_val);

		// Returns the minimum key (key at root) from min heap
		Makeup getMin() { return harr[0]; }

		// Deletes a key stored at index i
		void deleteKey(int i);

		// Inserts a new key 'k'
		//void insertKey(int k);
		void insertKey(Makeup k);
	};
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	//change to new makeup
	//harr = new int[cap];
	harr = new Makeup[cap];
	//dynamic allocation
}

// Inserts a new key 'k'
void MinHeap::insertKey(Makeup k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)].price > harr[i].price)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, Makeup new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)].price > harr[i].price)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}
Makeup MinHeap::extractMin()
{
	//if (heap_size <= 0)
	//	return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	Makeup root = harr[0];
	//replacing the root with the last value
	harr[0] = harr[heap_size - 1];
	heap_size--;
	//heapifying to make the min the root again
	MinHeapify(0);

	return root;
}
//void MinHeap::deleteKey(int i)
//{
//	decreaseKey(i, INT_MIN);
//	extractMin();
//}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].price < harr[i].price)
		smallest = l;
	if (r < heap_size && harr[r].price < harr[smallest].price)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(Makeup* x, Makeup* y)
{
	Makeup temp = *x;
	*x = *y;
	*y = temp;
}

void read(MinHeap &h, string category) {
	fstream file("makeup.csv", ios_base::in);
	if (file.is_open()) {
		string line;
		getline(file, line);
		while (getline(file, line)) {
			Makeup m;
			stringstream stream(line);
			string temp;
			//cout << line << endl;
			double ID = 0;
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
			ID = stod(tempID);
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


int main()
{	/*
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();*/
	
	vector<Makeup> list;
	Makeup m;
	m.price = 9;
	m.brand = "Brenda Babes";
	list.push_back(m);
	Makeup n;
	n.price = 33;
	n.brand = "Brenda Babes";
	list.push_back(n);
	Makeup o;
	o.price = 1;
	o.brand = "Brenda Babes";
	list.push_back(o);
	Makeup p;
	p.price = 8;
	p.brand = "Brenda Babes";
	list.push_back(p);
	Makeup q;
	q.price = 72;
	q.brand = "Brenda Babes";
	list.push_back(q);

	MinHeap h(103000);
	auto start = high_resolution_clock::now();
	read(h,"Foundation");
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
	while(temp < 50.0) {
		Makeup p = h.extractMin();
		temp = p.price;
		cout << "Price: $"<<p.price << " " << "Product: "<<p.brand << " " << p.type << " " <<"Rating: "<<p.rating << endl;
	}
	cout << endl;
	cout << "Time taken to insert elements into minheap: "
		<< duration.count() << " milliseconds" << endl;
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

	return 0;
}