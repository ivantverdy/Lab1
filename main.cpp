#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

#include "nodeList.h"
#include "arrList.h"
#include "vectorList.h"
#include "booksInfo.h"

using namespace std;

int menuMovement;

void menu(){
    cout << "Choose option: " << endl;
    cout << "Close program: 1" << endl;
    cout << "Write down data: 2" << endl;
    cout << "Show data: 3" << endl;
    cout << "Change data: 4" << endl;
    cout << "Add data: 5" << endl;
    cout << "Sort data: 6" << endl;
    cout << "Save data: 7" << endl;
    cout << "Your choice: ";
    cin >> menuMovement;
}

int main() {

    srand(time(nullptr));

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 1000.0);

    //menu();

    string fileName;
    int actons;

    /*series bookSeries;
    vectorList<book> Library;
    book book1("abcd", "01.01.2001", "annotation", {"abd", "abd", "aac"}, 1);
    book book2("adab", "02.02.2002", "annotation", {"dab", "dba", "caa"}, 1);
    book1.getNameOfBook();
    Library.add(book2);
    Library.add(book1);
    Library.showList();
    Library.quickSort();
    Library.mergeSort();
    Library.insertionSort();
    Library.showList();*/


    vectorList<book> library;

    // Create authors for books
    vectorList<string> authorsWitcher;
    vectorList<string> authorsThe_Hound_of_the_Baskervilles;
    vectorList<string> authorsAbab;

    series bookSeriesWitcher;

    authorsWitcher.add("andrzej sapkowski");
    authorsWitcher.add("may be me ;)");
    authorsThe_Hound_of_the_Baskervilles.add("Arthur Conan Doyle");
    authorsAbab.add("abab");
    authorsAbab.add("abac");
    authorsAbab.add("dabc");

    book book1("Sword of Destiny", "1992", "Annotation", authorsWitcher.getVectorList(), 200);
    book book2("Name", "2020", "Annotation", authorsAbab.getVectorList(), 200);
    book book3("The Hound of the Baskervilles", "1902", "Annotation",authorsThe_Hound_of_the_Baskervilles.getVectorList(), 226);
    book book4("The Last Wish", "1993", "Annotation", authorsWitcher.getVectorList(), 200);
    book book5("Blood of Elves", "1994", "Annotation", authorsWitcher.getVectorList(), 200);

    character character1("Geralt", "main");
    character character2("Yennefer", "secondary");
    character character3("Sherlock Holmes", "main");
    character character4("John Watson", "secondary");

    book1.addCharacter(character1);
    book1.addCharacter(character2);
    book4.addCharacter(character1);
    book4.addCharacter(character2);
    book5.addCharacter(character1);
    book5.addCharacter(character2);

    library.quickSort();
    library.insertionSort();
    library.mergeSort();
    bookSeriesWitcher.addBookToSeries(book1);
    bookSeriesWitcher.addBookToSeries(book1);
    bookSeriesWitcher.addBookToSeries(book4);
    bookSeriesWitcher.addBookToSeries(book5);
    bookSeriesWitcher.addBookToSeries(book1);


    bookSeriesWitcher.sortByReleaseDate();

    library.add(book1);
    library.add(book2);
    library.add(book3);
    library.add(book4);
    library.add(book5);

    bookSeriesWitcher.show();
    //library.showList();



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

    nodeList<int> intList;
    nodeList<double> doubleList;
    nodeList<char> charList;
    nodeList<string> stringList;


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
