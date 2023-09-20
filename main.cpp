#include <iostream>
#include <list>

using namespace std;

class node
{
public:
    node *next;
    node *prev;
    void SetValue(int setV)
    {
        value = setV;
    }
    int GetValue()
    {
        return value;
    }
private:
    int value;
};

class LIST{
private:
    node *head, *tail;
public:
    LIST()
    {
        head = tail = nullptr;
    }
    void AddLastNode(int data)
    {
        node* temp = new node;
        temp->SetValue(data);
        if(!head)
        {
            temp->next=temp->prev=temp;
            head=tail=temp;
        }
        else
        {
            head->prev=temp; temp->next=head;
            tail->next=temp; temp->prev=tail;
            tail=temp;
        }
    }
    void ShowNode()
    {
        node *temp=head;
        int i=1;
        do
        {
            cout <<"Data in node "<< i << " = "<< temp->GetValue() << "\n";
            temp=temp->next;
            i++;
        }
        while(temp!=head);
    }
};

int main() {
    LIST newList;
    for(int i=0; i<8; i++) {
        newList.AddLastNode(i*5);
    }
    newList.ShowNode();
    return 0;
}
