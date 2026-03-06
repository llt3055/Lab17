#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

//prototypes.
void push_front(Node *&head, float val);  
void push_back(Node *&head, float val);   
void insert_node(Node *&head, float val, int pos); 
void delete_node(Node *&head, int pos);   
void delete_list(Node *&head);
void output(Node *);

int main() {
    srand(time(0));// seed random number generator with current time
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        push_front(head, rand() % 100);
    }
    cout << "Initial list:" << endl;
    output(head);

    // deleting a node
    cout << "Which node to delete? (1-" << SIZE << ")" << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    delete_node(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    cout << "Choice --> ";
    cin >> entry;
    insert_node(head, 10000, entry);
    output(head);


    // deleting the linked list
    cout << "Deleting the entire list..." << endl;
    delete_list(head);
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void push_front(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void push_back(Node *&head, float val) {
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = nullptr;
    if (!head) {
        head = newVal;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newVal;
    }
}

void insert_node(Node *&head, float val, int pos) {
    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < pos; i++) {
        if (current) {
            prev = current;
            current = current->next;
        }
    }
}

void delete_node(Node *&head, int pos) {
    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < (pos - 1); i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next; 
    delete current;
}

void delete_list(Node *&head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next; 
        delete current;                
        current = nextNode;           
    }
    head = nullptr; 
}

