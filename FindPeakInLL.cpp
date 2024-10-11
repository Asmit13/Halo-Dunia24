#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to find the peak element in the linked list
Node* findPeak(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // If there's only one or no element, it's the peak
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return current; // Found a peak
        }
        current = current->next;
    }

    return current; // The last element is the peak if no previous element is greater
}

// Main function to test the code
int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(3);

    Node* peak = findPeak(head);
    if (peak != NULL) {
        cout << "Peak element: " << peak->data << endl;
    } else {
        cout << "No peak element found." << endl;
    }

    return 0;
}
