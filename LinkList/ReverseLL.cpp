//via recursion
#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *Take_Input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseLL(Node *head, Node *prev, Node *next)
{
    if (head == NULL)
    {
        return prev;
    }
    else
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    Node *newhead = reverseLL(head, prev, next);
    return newhead;
}

// Node *reverseLL(Node *head)
// {

//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     // else
//     // {
//     //     next = head->next;
//     //     head->next = prev;
//     //     prev = head;
//     //     head = next;
//     // }
//     Node *newhead = reverseLL(head->next);
//     Node *temp = newhead;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     head->next = NULL;
//     return newhead;
// }

int main()
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *head = Take_Input();
    print(head);

    head = reverseLL(head, prev, next);
    print(head);
}