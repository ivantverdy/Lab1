#include <iostream>
#include <list>
#include <string>
#include <vector>

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

    friend ostream& operator << (ostream &out, vector<variable>);
};



int main() {
    LIST<int> intList;
    LIST<double> doubleList;
    LIST<string> stringList;
    LIST<vector<int>> vectorList;
    for (int i = 0; i < 8; i++) {
        intList.AddLastNode(i * 5);
    }
    for (int i = 0; i < 8; i++) {
        stringList.AddLastNode("boPaQQQ");
    }
    for (int i = 0; i < 8; i++) {
        vectorList.AddLastNode({i, 2 * i, 3 * i});
    }
    intList.showList();
    stringList.showList();
    vectorList.showList();
    return 0;
}
