#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

template<typename variable>
ostream &operator<<(ostream &out, vector<variable> vectorOut) {
    for (int i = 0; i < vectorOut.size(); i++) {
        out << vectorOut[i] << "; ";
    }
    return out;
}


template<typename variable>
class node {
private:
    variable value;
    node *next;
    node *prev;
public:
    node() {
        next = prev = nullptr;
    }

    void setValue(variable setV) {
        value = setV;
    }

    variable getValue() {
        return value;
    }

    node *getNext() {
        return next;
    }

    node *getPrev() {
        return prev;
    }

    void setNext(node<variable> *nextNode) {
        next = nextNode;
    }

    void setPrev(node<variable> *prevNode) {
        prev = prevNode;
    }
};

template<typename variable>
class LIST {
private:
    node<variable> *head, *tail;
public:
    LIST() {
        head = tail = nullptr;
    }

    void AddLastNode(variable data) {
        node<variable> *temp = new node<variable>;
        temp->setValue(data);
        if (!head) {
            temp->setNext(temp);
            temp->setPrev(temp);
            head = tail = temp;
        } else {
            head->setPrev(temp);
            temp->setNext(head);
            tail->setNext(temp);
            temp->setPrev(tail);
            tail = temp;
        }
    }

    void showList() {
        node<variable> *temp = head;
        int i = 1;
        do {
            cout << "Data in node " << i << " = " << temp->getValue() << "\n";
            temp = temp->getNext();
            i++;
        } while (temp != head);
    }



    void qsort(){

    }


    friend ostream &operator<<(ostream &out, vector<variable>);

    ~LIST() {
        while (head != nullptr) {
            node<variable> *temp = head;
            head = head->getNext();
            delete (temp);
        }
    }
};


int main() {
    srand(time(nullptr));

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 1000.0);

    int sizeIntList, sizeStringList, sizeVectorList = 0;
    double sizeDoubleList = 0.0;
    cout << "Enter the size of IntList: ";
    cin >> sizeIntList;
    cout << "Enter the size of DoubleList: ";
    cin >> sizeDoubleList;
    cout << "Enter the size of StringList: ";
    cin >> sizeStringList;
    cout << "Enter the size of VectorList: ";
    cin >> sizeVectorList;
    LIST<int> intList;
    LIST<double> doubleList;
    LIST<string> stringList;
    LIST<vector<int>> vectorIntList;

    //LIST<int*> arrayList;

    LIST<vector<double>> vectorDoubleList;
    LIST<vector<string>> vectorStringList;
    for (int i = 0; i < sizeIntList; i++) {
        intList.AddLastNode(rand() % 10);
    }
    for (int i = 0; i < sizeDoubleList; i++) {
        doubleList.AddLastNode(dist(mt));
    }
    for (int j = 0; j < sizeStringList; j++) {
        stringList.AddLastNode("boPaQQQ");
    }
    for (int k = 0; k < sizeVectorList; k++) {
        vectorIntList.AddLastNode({rand() % 10 + 5, rand() % 10 + 15, rand() % 10 + 25});
    }
    intList.showList();
    doubleList.showList();
    stringList.showList();
    vectorIntList.showList();
    return 0;
}
