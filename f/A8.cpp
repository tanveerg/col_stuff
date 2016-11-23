//
//  A8.cpp
//  f
//
//  Created by Tanveer Gupta on 12/6/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A8.h"



#include<iostream>
using namespace std;




vector<<BSTNode<Key, Value>* > range_query(BSTNode<Key, Value>* root, Key key1, Key key2){
    vector<<BSTNode<Key, Value>* > v;
    
    if(root==NULL||key1>key2){
        return v;
    }
    else if(root->key>=key1&&root->key<=key2){
        v.push_back(root);
        v.push_back(range_query(successor(root)), key1, key2);
        return v;
    }
    else if(root->key<=key1&&root->key<=key2){
        v.push_back(root);
        v.push_back(range_query(predecessor(root)), key1, key2);
        return v;
    }
    else{
        return v;
    }
}




void bst_insert(BSTNode<Key, Value>*& root, BSTNode<Key, Value>* node) {
    node->left = node->right = NULL;
    node->size = 1;
    BSTNode<Key, Value>* p   = NULL;
    BSTNode<Key, Value>* cur = root;
    while (cur != NULL) {
        p = cur;
       
        p->size = p->size + node->size;
       
        
        if (node->key < cur->key){
            cur = cur->left;
        }
        else{
            cur = cur->right;            
    }
    }
    
    node->parent = p;
    if (p == NULL) {
        root = node;
    }
    else if (node->key < p->key) {
        p->left = node;
    }
    else {
        p->right = node;
    }
    
}



BSTNode<Key, Value>* rank_query(size_t k, BSTNode<Key, Value>* root){
    
    BSTNode<Key, Value>* temp1, temp2;
    
    if(k<=0||k>=root->size||root==NULL){
        return NULL;
    }
    else if (k==root->size){
        return root;
    }
    else if(k<root->size){
        return rank_query(k, root->right);
    } else{
        return rank_query(k, root->left);
    }
        
    }
        
    
    

