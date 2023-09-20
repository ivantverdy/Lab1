#include <iostream>
#include <list>

using namespace std;

class node {
private:
    int value;
    node *next;
    node *prev;
public:
    node() {
        next = prev = nullptr;
        value = 0;
    }

    void setValue(int setV) {
        value = setV;
    }

    int getValue() {
        return value;
    }

    node *getNext() {
        return next;
    }

    node *getPrev() {
        return prev;
    }

    void setNext(node *nextNode) {
        next = nextNode;
    }

    void setPrev(node *prevNode) {
        prev = prevNode;
    }
};

class LIST {
private:
    node *head, *tail;
public:
    LIST() {
        head = tail = nullptr;
    }

    void AddLastNode(int data) {
        node *temp = new node;
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

    void ShowNode() {
        node *temp = head;
        int i = 1;
        do {
            cout << "Data in node " << i << " = " << temp->getValue() << "\n";
            temp = temp->getNext();
            i++;
        } while (temp != head);
    }
};

int main() {
    LIST newList;
    for (int i = 0; i < 8; i++) {
        newList.AddLastNode(i * 5);
    }
    newList.ShowNode();
    return 0;
}
