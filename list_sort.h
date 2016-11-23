// *****************************************************************************
// list_sort.h
// Author: Hung Q. Ngo
// - singly linked list node structure
// - prototypes for a couple of sorting functions on singly linked lists
// - DO NOT MODIFY THIS FILE
// *****************************************************************************

#ifndef LIST_SORT_H
#define LIST_SORT_H

#include <cstddef> // this header defines NULL

struct Node {
    int   key;
    Node* next;
    Node(int k=0, Node* n=NULL) : key(k), next(n) {};
};

void  print_list(Node* ptr); // print all nodes starting from ptr
void  free_list(Node* ptr);  // free nodes from ptr down

// *****************************************************************************
// below are the two functions you are asked to implement
// each function
// - takes the pointer to the head node of a singly linked list of Node's
// - returns the pointer to a modified linked list whose keys are sorted in
//   increasing order
// *****************************************************************************
Node* insertion_sort(Node* head); // here are the 2 functions you're asked
Node* merge_sort(Node* head);     // to implement

#endif
