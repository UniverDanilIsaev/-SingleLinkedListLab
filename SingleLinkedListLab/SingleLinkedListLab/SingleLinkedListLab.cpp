#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};


void MoveNode(Node** destRef, Node** sourceRef);

Node* SortedMerge(Node* list1, Node* list2)
{
    Node dummy;

    Node* tail = &dummy;

    dummy.next = NULL;
    while (1)
    {
        if (list1 == NULL)
        {
            tail->next = list2;
            break;
        }
        else if (list2 == NULL)
        {
            tail->next = list1;
            break;
        }
        if (list1->data <= list2->data)
            MoveNode(&(tail->next), &list1);
        else
            MoveNode(&(tail->next), &list2);

        tail = tail->next;
    }
    return(dummy.next);
}

void MoveNode(Node** destRef, Node** sourceRef)
{
    Node* newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;

    newNode->next = *destRef;

    *destRef = newNode;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void reverseLL(Node** head)
{
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;

    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();

        temp = temp->next;
    }
    temp->next = NULL;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* AddObject(Node* node , int size)
{
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 100;
        push(&node, num);

    }
    return node;
}

int main()
{
    Node* head = NULL;

    cout << "List is:" << std::endl;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printList(head);
    reverseLL(&head);
    cout << std::endl <<  "Merged Linked List is:" << std::endl;
    printList(head);
    cout << std::endl;

    Node* res   = NULL;
    Node* List1 = NULL;
    Node* List2 = NULL;

    cout << "List first:" << std::endl;
    push(&List1, 15);
    push(&List1, 10);
    push(&List1, 5);
    printList(List1);
    cout << std::endl;

    cout << "List second:" << std::endl;
    push(&List2, 20);
    push(&List2, 3);
    push(&List2, 2);
    printList(List2);
    cout << std::endl;

    res = SortedMerge(List1, List2);

    cout << "Merged Linked List is: \n";
    printList(res);

    return 0;
}