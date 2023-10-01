#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

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

    character character1("Geralt", "main");
    character character2("Yennefer", "secondary");
    character character3("Lutic", "secondary");
    character character4("Sherlock Holmes", "main");
    character character5("John Watson", "secondary");

    //witcher book:
    vectorList<string> authorsWitcher;
    authorsWitcher.add("andrzej sapkowski");
    authorsWitcher.add("may be me 123 check");
    authorsWitcher.add("542351 check");

    vectorList<character> charactersWitcher;
    charactersWitcher.add(character1);
    charactersWitcher.add(character2);
    charactersWitcher.add(character3);

    //Baskervilles book:
    vectorList<string> authorsBaskervilles;
    authorsWitcher.add("Arthur Conan Doyle");

    vectorList<character> charactersBaskervilles;
    charactersWitcher.add(character4);
    charactersWitcher.add(character5);


    book book1("Sword of Destiny", "1992", "Annotation",authorsWitcher , 200, charactersWitcher);
    book book2("The Last Wish", "1993", "Annotation", authorsWitcher, 200, charactersWitcher);
    book book3("The Hound of the Baskervilles", "1902", "Annotation",authorsBaskervilles, 226, charactersBaskervilles);
    book book4("Blood of Elves", "1994", "Annotation", authorsWitcher, 200,charactersWitcher);



    database LIBRARY_OF_BOOKS;
    LIBRARY_OF_BOOKS.addBook(book1);
    LIBRARY_OF_BOOKS.addBook(book2);
    LIBRARY_OF_BOOKS.addBook(book3);
    LIBRARY_OF_BOOKS.addBook(book4);
    //LIBRARY_OF_BOOKS.showSeries();
    //LIBRARY_OF_BOOKS.showLibrary();
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
