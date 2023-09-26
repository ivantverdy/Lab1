#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include "nodeLIST.h"
#include "arrList.h"

using namespace std;


class book {
private:
    string nameOfBook, authorName, releaseDate, annotation;
    int numOfPages;
};

class character{
    string nameOfTheCharacter, characterIsInBook, characterIsMentionedInBook,  mainCharacter, minorCharacter, episodicCharacter;
};

int main() {
    srand(time(nullptr));

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 1000.0);

    /*   int sizeIntList, sizeStringList, sizeVectorList = 0;
       double sizeDoubleList = 0.0;
       string words;
       //cout << "Enter the size of IntList: "<< endl;
       //cin >> sizeIntList;
       //cout << "Enter the size of DoubleList: "<< endl;
       //cin >> sizeDoubleList;
       //cout << "Enter the size of StringList: " << endl;
       //cin >> sizeStringList;

       nodeLIST<int> intList;
       nodeLIST<double> doubleList;
       nodeLIST<string> stringList;


       for (int i = 0; i < sizeIntList; i++) {
           intList.AddLastNode(rand() % 100);
       }
       for (int j = 0; j < sizeDoubleList; j++) {
           doubleList.AddLastNode(dist(mt));
       }
       //for (int k = 0; k < sizeStringList; k++) {
       //     cout << "String Words you want to be in each node: " << endl;
       //     cin >> words;
       //     stringList.AddLastNode(words);
       //}



       intList.showList();
       doubleList.showList();
       stringList.showList();


       intList.bubbleSort();
       intList.selectionSort();
       intList.quickSort();
       intList.insertionSort();
       intList.MergeSort();

       doubleList.bubbleSort();
       doubleList.selectionSort();
       doubleList.quickSort();
       doubleList.insertionSort();
       doubleList.MergeSort();

       stringList.bubbleSort();
       stringList.selectionSort();
       stringList.quickSort();
       stringList.insertionSort();
       stringList.MergeSort();

       cout << "Sorted list: " << endl;
       intList.showList();
       doubleList.showList();
       stringList.showList();

   */

    int sizeIntListArray;
    cout << "Enter the size of IntListArray: ";
    cin >> sizeIntListArray;
    arrList<int> myArrList;
    for (int i = 0; i < sizeIntListArray; i++) {
        myArrList.add(rand() % 100);
    }

    myArrList.quickSort();
    myArrList.showList();

    return 0;
}
