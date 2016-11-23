// *****************************************************************************
// list_sort.cpp
// Author: YOUR NAME HERE
// Description: implement the two sorting algorithms on singly linked lists
// - please feel free to add more functions to this file
// - this is the only file you can modify
// *****************************************************************************
#include<iostream>
#include "list_sort.h"
using namespace std;

/**
 * -----------------------------------------------------------------------------
 * the selection sort algorithm
 * -----------------------------------------------------------------------------
 */
Node* insertion_sort(Node* head) {
    
    Node* next;
    Node* prev;
    Node* temp;   
    Node* nrec;
    Node* prec;
    if (head==NULL){
        return head;
    }
    else {
    while(head!=NULL){
	
        prev = head;
        next = head->next;
        prec = prev;
        nrec = next;
	
        while(prev->key>next->key&&temp!=NULL){
	
            temp = next;
            temp->next=prev;
            prev->next=next->next;
            next = prev->next;
		temp = temp->next;
        }
        head = head->next;
    }
    
    // your code goes here
    return temp; // and you can return a different value!
    }              // the way it is right now no sorting is done
}

/**
 * -----------------------------------------------------------------------------
 * the merge sort algorithm
 * -----------------------------------------------------------------------------
 */
Node* merge_sort(Node* head) {
    
    Node* next;
    Node* prev;
    Node* temp;
    Node* left;
    Node* right;
    if (head==NULL){
        return head;
    }
    else{
    while(head!=NULL){
        prev = head;
        next = head->next;
        merge_sort(left);
        merge_sort(right);
        
        
    }


    // your code goes here
    return head; // and you can return a different value!
                 // the way it is right now no sorting is done
    }}

// *****************************************************************************
// DO NOT MODIFY BEYOND THIS POINT
// *****************************************************************************

/**
 * -----------------------------------------------------------------------------
 * free the memory of all nodes starting from ptr down
 * -----------------------------------------------------------------------------
 */
void free_list(Node* ptr) {
    Node* temp;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

