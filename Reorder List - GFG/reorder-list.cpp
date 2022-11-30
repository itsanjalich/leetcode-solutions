//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    int length(Node *head) {
        int l = 0;
        Node *p = head;
        while(p!=NULL){
            p=p->next;
            l+=1;
        }
        return l;
    }
    
    void reorderList(Node* head) {
        // Your code here
        int len = length(head);
        stack<Node *> st;
        Node * p = head;
        int l = 0;
        while(l!=(len + 1)/2){
            p = p->next;
            l++;
        }
        while(p!=NULL){
            st.push(p);
            p=p->next;
        }
        int i=0;
        Node * q = head;
        while(i!=l && !st.empty()){
            Node * r = st.top();
            r->next = q->next;
            q->next = r;
            q = r->next;
            st.pop();
            i++;
        }
        q->next = NULL;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends