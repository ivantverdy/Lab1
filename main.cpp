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
    node<variable> *prev;
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
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        node<variable> *temp = head;
        int i = 1;
        do {
            cout << "Data in node " << i << " = " << temp->getValue() << "\n";
            temp = temp->getNext();
            i++;
        } while (temp != head);
    }

    void bubbleSort(variable size) {
        bool change = true;
        int sorted = 0;
        while (change and sorted < size) {
            node<variable> *temp = head;
            change = false;
            for (int i = 0; i < size - 1 - sorted; i++) {
                if (temp->getValue() > (temp->getNext())->getValue()) {
                    variable temporary = temp->getValue(); // to swap data in nodes
                    temp->setValue((temp->getNext())->getValue());
                    (temp->getNext())->setValue(temporary);
                    change = true;
                }
                temp = temp->getNext();
            }
            sorted++;
        }
    }

    void selectionSort() {
        node<variable> *temp = head;

        // Traverse the List
        while (temp->getNext() != head) {
            node<variable> *min = temp;
            node<variable> *r = temp->getNext();

            // Traverse the unsorted sublist
            while (r != head) {
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


/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
    node<variable> *partition(node<variable> *leftMost, node<variable> *rightMost) {
        // set pivot as rightMost element
        variable x = rightMost->getValue();

        // similar to i = l-1 for array implementation
        node<variable> *i = leftMost->getPrev();

        // Similar to "for (int j = l; j <= rightMost- 1; j++)"
        for (node<variable> *j = leftMost; j != rightMost; j = j->getNext()) {
            if (j->getValue() <= x) {
                // Similar to i++ for array

                i = (i == NULL) ? leftMost : i->getNext();

                //swap(&(i->getValue()), &(j->getValue()));
                variable temporary = i->getValue();
                i->setValue(j->getValue());
                j->setValue(temporary);
            }
        }
        i = (i == NULL) ? leftMost : i->getNext(); // Similar to i++
        //swap(&(i->getValue()), &(rightMost->getValue()));
        variable temporary = i->getValue();
        i->setValue(rightMost->getValue());
        rightMost->setValue(temporary);
        return i;
    }

/* A recursive implementation
of quicksort for linked list */
    void _quickSort(node<variable> *leftMost, node<variable> *rightMost) {
        if (rightMost != nullptr && leftMost != rightMost && leftMost != rightMost->getNext()) {
            node<variable> *p = partition(leftMost, rightMost);
            _quickSort(leftMost, p->getPrev());
            _quickSort(p->getNext(), rightMost);
        }
    }

// The main function to sort a linked list.
// It mainly calls _quickSort()
    void quickSort() {
        // Call the recursive QuickSort
        _quickSort(head, tail);
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

class books {
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
    //intList.bubbleSort(sizeIntList);
    //doubleList.bubbleSort(sizeDoubleList);
    //intList.selectionSort();
    intList.quickSort();
    intList.showList();
    doubleList.showList();
    stringList.showList();
    vectorIntList.showList();
    return 0;
}
