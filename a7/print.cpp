// *****************************************************************************
// file name : print.cpp
// author    : TANVEER GUPTA
// description : implement the two tree printing routines
// *****************************************************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // for max()
#include <map>
#include <vector>
#include <deque>
#include "BTree.h"
#include "term_control.h"
using namespace std;

// feel free to change the following notice
string version = 
    "UB Tree Program. Version 0.1\n"
    " Author: TANVEER GUPTA\n"
    " Report bugs to tanveerg@buffalo.edu\n";


/*
 * -----------------------------------------------------------------------------
 * print a given tree vertically
 * -----------------------------------------------------------------------------
 */
void vertical_print(BTNode<string>* root) {
    // your code goes here
    BTNode<string>* temp1; // storing the previous node
    BTNode<string>* temp2 = root; // storing the value of the original root
    cout<<root->payload<<endl;
    while(root->right!=NULL){
        
        cout<<"|"<<"_"<<root->right->payload<<endl;
        root=root->right;
        temp1 = root;
    }
    if(temp1->left!=NULL){
        cout<<"|"<<" "<<"|"<<endl<<"|"<<" "<<"|"<<"_"<<temp1->left->payload<<endl;
        vertical_print(temp1->left);
    }
    else if(temp2->left!=NULL){
         cout<<"|"<<" "<<"|"<<endl<<"|"<<" "<<"|"<<"_"<<temp2->left->payload<<endl;
        vertical_print(temp2->left);
    }
    else{
        cout<<"|"<<" "<<"|"<<endl<<"|"<<" "<<"|"<<"_"<<"x"<<endl;

    }
    
   // cout << "Vertical print: TBD\n";
}

/*
 * -----------------------------------------------------------------------------
 * print a given tree horizontally
 * -----------------------------------------------------------------------------
 */
void horizontal_print(BTNode<string>* root) {
    // your code goes here
    BTNode<string>* temp1; // storing the previous node
    BTNode<string>* temp2 = root; // storing the value of the original root
    cout<<root->payload<<endl;
    int count = 1;
    while(root->right!=NULL){
        
        cout<<setw(count)<<"\\"<<endl<<setw(count+1)<<root->right->payload<<endl;
        root=root->right;
        temp1 = root;
            count+=2;
    }
 
    if(temp1->left!=NULL){
        cout<<"|"<<endl<<temp1->left->payload<<endl;
        horizontal_print(temp1->left);
    }

   else if(temp2->left!=NULL){
        cout<<"|"<<endl<<temp2->left->payload<<endl;
        horizontal_print(temp2->left);
    }
    
   else{
       cout<<"|"<<"x"<<endl;
       
   }
  //  cout << "Horizontal print: TBD\n";
}

/*
 * -----------------------------------------------------------------------------
 * print a given tree symmetrically
 * -----------------------------------------------------------------------------
 */
void symmetric_print(BTNode<string>* root) {
    // your code goes here
    BTNode<string>* temp1; // storing the previous node
    BTNode<string>* temp2 = root; // storing the value of the original root
    
    cout<<setw(10)<<root->payload<<endl;
    int count = 1;
    
    while(root->right!=NULL){
        
        cout<<setw(count)<<"\\"<<endl<<setw(count+1)<<root->right->payload<<endl;
        root=root->right;
        temp1 = root;
        count+=2;
    }
    
    if(temp1->left!=NULL){
        cout<<"/"<<endl<<temp1->left->payload<<endl;
        horizontal_print(temp1->left);
    }
    
    else if(temp2->left!=NULL){
        cout<<"/"<<endl<<temp2->left->payload<<endl;
        horizontal_print(temp2->left);
    }
    
    else{
        cout<<"/"<<"x"<<endl;
        
    }

   // cout << "Symmetric print: TBD\n";
}
