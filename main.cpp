#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include "nodeLIST.h"
#include "arrList.h"
#include "vectorList.h"
#include "booksInfo.h"

using namespace std;


int main() {
    srand(time(nullptr));

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 1000.0);


    vector<string> authorsNot = {"mama", "papa", "brat", "sestra"};
    vectorList<string> authors;
    vectorList<book> library;
    authors.add("abab");
    authors.add("abac");
    authors.add("abbc");
    authors.add("abcd");
    authors.quickSort();
    authors.mergeSort();
    authors.insertionSort();
    book book1("Name", "11.03.2005", "Annotation",authorsNot , 200);
    book book2("Name", "11.03.2005", "Annotation", authors.getVectorList() , 200);
    library.add(book1);
    library.add(book2);
    library.showList();



/*
    int sizeIntList, sizeCharList, sizeStringList = 0;
    double sizeDoubleList = 0.0;
    char symbol;
    string words;
    cout << "Enter the size of IntList: " << endl;
    cin >> sizeIntList;
    cout << "Enter the size of DoubleList: " << endl;
    cin >> sizeDoubleList;
    cout << "Enter the size of CharList: " << endl;
    cin >> sizeCharList;
    cout << "Enter the size of StringList: " << endl;
    cin >> sizeStringList;

    nodeLIST<int> intList;
    nodeLIST<double> doubleList;
    nodeLIST<char> charList;
    nodeLIST<string> stringList;


    for (int i = 0; i < sizeIntList; i++) {
        intList.AddLastNode(rand() % 100);
    }
    for (int i = 0; i < sizeDoubleList; i++) {
        doubleList.AddLastNode(dist(mt));
    }

    for (int i = 0; i < sizeCharList; i++) {
        cout << "Char symbols you want to be in each node: ";
        cin >> symbol;
        charList.AddLastNode(symbol);
        cout << "Char list" << endl;
    }

    for (int i = 0; i < sizeStringList; i++) {
        cout << "String Words you want to be in each node: ";
        cin >> words;
        stringList.AddLastNode(words);
        cout << "String list" << endl;
    }

    intList.showList();
    doubleList.showList();
    charList.showList();
    stringList.showList();

    intList.bubbleSort();
    intList.selectionSort();
    intList.quickSort();
    intList.insertionSort();
    intList.mergeSort();

    doubleList.bubbleSort();
    doubleList.selectionSort();
    doubleList.quickSort();
    doubleList.insertionSort();
    doubleList.mergeSort();

    charList.bubbleSort();
    charList.selectionSort();
    charList.quickSort();
    charList.insertionSort();
    charList.mergeSort();

    stringList.bubbleSort();
    stringList.selectionSort();
    stringList.quickSort();
    stringList.insertionSort();
    stringList.mergeSort();

    cout << "Sorted list: " << endl;
    intList.showList();
    doubleList.showList();
    charList.showList();
    stringList.showList();




    int sizeIntListVector;
    cout << "Enter the size of IntListArray: ";
    cin >> sizeIntListVector;
    arrList<int> myArrList;
    for (int i = 0; i < sizeIntListVector; i++) {
        myArrList.add(rand() % 100);
    }

    myArrList.quickSort();
    myArrList.showList();

    int sizeIntListVector;
    cout << "Enter the size of IntListVector: ";
    cin >> sizeIntListVector;
    vectorList<int> myVectorList;
    for (int i = 0; i < sizeIntListVector; i++) {
        myVectorList.add(rand() % 100);
    }

    myVectorList.showList();
    myVectorList.quickSort();
    myVectorList.mergeSortPrivate();
    myVectorList.insertionSort();
    myVectorList.showList();
*/



    return 0;
}
