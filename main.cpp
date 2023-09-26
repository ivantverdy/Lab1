#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>

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
    node<variable> *sorted;

    node<variable> *getTail(node<variable> *cur) {
        while (cur != nullptr && cur->getNext() != nullptr)
            cur = cur->getNext();
        return cur;
    }

    // taken algorithm and code from this site and rebuild it for myself: https://www.geeksforgeeks.org/cpp-program-for-quicksort-on-singly-linked-list/

    node<variable> *
    partition(node<variable> *head, node<variable> *end, node<variable> **newHead, node<variable> **newEnd) {
        // Set pivot as the last element
        node<variable> *pivot = end;
        node<variable> *prev = nullptr;
        node<variable> *cur = head;
        node<variable> *tail = pivot;

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

                node<variable> *tmp = cur->getNext();
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

    node<variable> *quickSortRecur(node<variable> *head, node<variable> *end) {
        if (!head || head == end)
            return head;

        node<variable> *newHead = nullptr;
        node<variable> *newEnd = nullptr;

        node<variable> *pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            node<variable> *tmp = newHead;
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

    // Merge sort for a linked list
    void MergeSort(node<variable> **headRef) {
        node<variable> *head = *headRef;
        node<variable> *a;
        node<variable> *b;

        // Base case -- length 0 or 1
        if (head == nullptr || head->getNext() == nullptr) {
            return;
        }

        // Split head into 'a' and 'b' sublists
        FrontBackSplit(head, &a, &b);

        // Recursively sort the sublists
        MergeSort(&a);
        MergeSort(&b);

        // Merge the sorted lists together
        *headRef = SortedMerge(a, b);
    }

    // Merge two sorted lists
    node<variable> *SortedMerge(node<variable> *a, node<variable> *b) {
        node<variable> *result = nullptr;

        // Base cases
        if (a == nullptr)
            return b;
        else if (b == nullptr)
            return a;

        // Pick either a or b, and recur
        if (a->getValue() <= b->getValue()) {
            result = a;
            result->setNext(SortedMerge(a->getNext(), b));
        } else {
            result = b;
            result->setNext(SortedMerge(a, b->getNext()));
        }
        return result;
    }

    // Split the nodes of the given list into front and back halves
    void FrontBackSplit(node<variable> *source, node<variable> **frontRef, node<variable> **backRef) {
        node<variable> *fast;
        node<variable> *slow;
        slow = source;
        fast = source->getNext();

        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != nullptr) {
            fast = fast->getNext();
            if (fast != nullptr) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
        }

        // 'slow' is before the midpoint in the list, so split it in two at that point
        *frontRef = source;
        *backRef = slow->getNext();
        slow->setNext(nullptr);
    }

public:
    LIST() {
        head = nullptr;
    }

    void AddLastNode(variable data) {
        auto *temp = new node<variable>;
        temp->setValue(data);
        temp->setNext(nullptr);
        if (head == nullptr) {
            head = temp;
        } else {
            node<variable> *curr = head;
            while (curr->getNext() != nullptr)
                curr = curr->getNext();
            curr->setNext(temp);
        }
    }

    void showList() {
        node<variable> *temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
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
        quickSortRecur(head, getTail(head));
    }

    // taken algorithm and code from this site and rebuild it for myself: https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/

    void insertionSort() {
        // Initialize sorted linked list
        sorted = NULL;
        node<variable> *current = head;

        // Traverse the given linked list
        // and insert every node to sorted
        while (current != NULL) {
            // Store next for next iteration
            node<variable> *next = current->getNext();

            // Insert current in sorted
            // linked list
            sortedInsert(current);

            // Update current
            current = next;
        }

        // Update head_ref to point to
        // sorted linked list
        head = sorted;
    }

    /* Function to insert a new_node in a list.
       Note that this function expects a pointer
       to head_ref as this can modify the head of
       the input linked list (similar to push()) */
    void sortedInsert(node<variable> *newNode) {
        // Special case for the head end
        if (sorted == NULL || sorted->getValue() >= newNode->getValue()) {
            newNode->setNext(sorted);
            sorted = newNode;
        } else {
            node<variable> *current = sorted;
            /* Locate the node before the
               point of insertion */
            while (current->getNext() != NULL && current->getNext()->getValue() < newNode->getValue()) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
    }

    //taken algorithm and code from this site and rebuild it for myself: https://www.geeksforgeeks.org/cpp-program-for-merge-sort-of-linked-lists/

    void MergeSort() {
        MergeSort(&head);
    }

    void vectorSort(){

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
    //cout << "Enter the size of IntList: "<< endl;
    //cin >> sizeIntList;
    //cout << "Enter the size of DoubleList: "<< endl;
    //cin >> sizeDoubleList;
    //cout << "Enter the size of StringList: " << endl;
    //cin >> sizeStringList;
    cout << "Enter the size of VectorList: " << endl;
    cin >> sizeVectorList;
    LIST<int> intList;
    LIST<double> doubleList;
    LIST<string> stringList;
    LIST<vector<int>> vectorIntList;

    //LIST<int*> arrayList;

    LIST<vector<double>> vectorDoubleList;
    LIST<vector<string>> vectorStringList;
    for (int i = 0; i < sizeIntList; i++) {
        intList.AddLastNode(rand() % 100);
    }
    for (int j = 0; j < sizeDoubleList; j++) {
        doubleList.AddLastNode(dist(mt));
    }
    for (int k = 0; k < sizeStringList; k++) {
        cout << "String Words you want to be in each node: " << endl;
        cin >> words;
        stringList.AddLastNode(words);
    }
    for (int q = 0; q < sizeVectorList; q++) {
        vectorIntList.AddLastNode({rand() % 100, rand() % 100, rand() % 100, rand() % 100});
    }

    //intList.showList();
    //doubleList.showList();
    //stringList.showList();
    vectorIntList.showList();

    //intList.bubbleSort();
    //intList.selectionSort();
    //intList.quickSort();
    //intList.insertionSort();
    //intList.MergeSort();

    //doubleList.bubbleSort();
    //doubleList.selectionSort();
    //doubleList.quickSort();
    //doubleList.insertionSort();
    //doubleList.MergeSort();

    //stringList.bubbleSort();
    //stringList.selectionSort();
    //stringList.quickSort();
    //stringList.insertionSort();
    //stringList.MergeSort();

    vectorIntList.bubbleSort();
    vectorIntList.selectionSort();
    vectorIntList.quickSort();
    vectorIntList.insertionSort();
    vectorIntList.MergeSort();

    cout << "Sorted list: " << endl;
    //intList.showList();
    //doubleList.showList();
    //stringList.showList();
    vectorIntList.showList();
    return 0;
}
