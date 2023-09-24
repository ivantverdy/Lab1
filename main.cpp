#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <utility>

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
    node<variable> *next;
public:
    node() {
        next = nullptr;
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

    void setNext(node<variable> *nextNode) {
        next = nextNode;
    }

};

template<typename variable>
class LIST {
private:
    node<variable> *head;

    node<variable>* getTail(node<variable>* cur)
    {
        while (cur != nullptr &&
               cur->getNext() != nullptr)
            cur = cur->getNext();
        return cur;
    }

    // taken algorithm and code from this site and rebuild it for myself: https://www.geeksforgeeks.org/cpp-program-for-quicksort-on-singly-linked-list/

    node<variable> *partition(node<variable> *head, node<variable> *end, node<variable> **newHead, node<variable> **newEnd) {
        // Set pivot as the last element
        node<variable>* pivot = end;
        node<variable>* prev = nullptr;
        node<variable>* cur = head;
        node<variable>* tail = pivot;

        while (cur != pivot) {
            if (cur->getValue() < pivot->getValue()) {
                if ((*newHead) == nullptr) {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->getNext();
            } else {
                if (prev)
                    prev->setNext(cur->getNext());

                node<variable>* tmp = cur->getNext();
                cur->setNext(nullptr);
                tail->setNext(cur);
                tail = cur;
                cur = tmp;
            }
        }

        if ((*newHead) == nullptr)
            (*newHead) = pivot;
        (*newEnd) = tail;
        return pivot;
    }

    node<variable>* quickSortRecur(node<variable> *head, node<variable> *end) {
        if (!head || head == end)
            return head;

        node<variable> *newHead = nullptr;
        node<variable> *newEnd = nullptr;

        node<variable> *pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            node<variable>* tmp = newHead;
            while (tmp->getNext() != pivot)
                tmp = tmp->getNext();
            tmp->setNext(nullptr);

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->setNext(pivot);
        }

        pivot->setNext(quickSortRecur(pivot->getNext(), newEnd));

        return newHead;
    }
public:
    LIST() {
        head  = nullptr;
    }

    void AddLastNode(variable data) {
        node<variable> *temp = new node<variable>;
        temp->setValue(data);
        temp->setNext(nullptr);
        if (head == nullptr) {
            head = temp;
        } else {
            node<variable> *curr = head;
            while(curr->getNext() != nullptr)
                curr = curr->getNext();
            curr->setNext(temp);
        }
    }

    void showList() {
        node<variable> *temp = head;
        if (temp == nullptr) {
            cout << "List is empty.";
            return;
        }
        int i = 1;
        while (temp != nullptr) {
            cout << " Data in node " << i << " = " << temp->getValue() << endl;
            temp = temp->getNext();
            i++;
        }
    }

    void bubbleSort() {
        bool change = true;
        node<variable> *temp;
        node<variable> *lastSorted = nullptr; //last sorted node

        while (change) {
            temp = head;
            change = false;
            while (temp->getNext() != lastSorted) {
                if (temp->getValue() > temp->getNext()->getValue()) {
                    //swap the data in the nodes
                    variable temporary = temp->getValue();
                    temp->setValue(temp->getNext()->getValue());
                    temp->getNext()->setValue(temporary);
                    change = true;
                }
                temp = temp->getNext();
            }
            lastSorted = temp; //last sorted node
        }
    }

    void selectionSort() {
        node<variable> *temp = head;

        // Traverse the List
        while (temp->getNext() != nullptr) {
            node<variable> *min = temp;
            node<variable> *r = temp->getNext();

            // Traverse the unsorted sublist
            while (r != nullptr) {
                if (min->getValue() > r->getValue())
                    min = r;

                r = r->getNext();
            }

            // Swap Data
            variable temporary = temp->getValue();
            temp->setValue(min->getValue());
            min->setValue(temporary);
            temp = temp->getNext();
        }
    }

    void quickSort() {
        head = quickSortRecur(head, getTail(head));
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

class bookShelf {
private:
    string nameOfBook;
    string authorName;
    string releaseDate;
    int numOfPages;

};


int main() {
    srand(time(nullptr));

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 1000.0);

    int sizeIntList, sizeStringList, sizeVectorList = 0;
    double sizeDoubleList = 0.0;
    string words;
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
    for (int j = 0; j < sizeDoubleList; j++) {
        doubleList.AddLastNode(dist(mt));
    }
    for (int k = 0; k < sizeStringList; k++) {
        cout<< "String Words you want to be in each node: ";
        cin >> words;
        stringList.AddLastNode(words);
    }
    for (int q = 0; q < sizeVectorList; q++) {
        vectorIntList.AddLastNode({rand() % 10 + 5, rand() % 10 + 15, rand() % 10 + 25});
    }
    //intList.bubbleSort();
    //doubleList.bubbleSort();
    //stringList.bubbleSort();
    //intList.selectionSort();
    //doubleList.selectionSort();
    intList.quickSort();
    intList.showList();
    //doubleList.showList();
    //stringList.showList();
    //vectorIntList.showList();
    return 0;
}
