//
//  A2.cpp
//  f
//
//  Created by Tanveer Gupta on 9/22/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A2.h"

#include<iostream>
#include <fstream>
#include "Lexer.h"

using namespace std;

int interpret(string &n);

void validate(string);

void display(string);




int main(){
    int x;
    string f;
    
    cout << "enter command and filename  ";

    while(x!=3)   {
        
        cout<<"   enter command and filename :   ";
        getline(cin, f);
        
        x = interpret(f);
        
     /*   switch(x){
                
        }*/

    }
    
    
}


int interpret(string &s) {
    
    int sp;    // starting position of file name
    int ep;    // ending position of file name
    char a;    // starting " of file name
    char b;    // ending " of file name
    string cmd; // command
    string fn;
    string file;
    int i = 0;
    int fnl = 0;
    
    //checking for exit
    if(s=="exit"){
        i=3;
    }
    
    //checking otherwise
    else
        
    {    sp = s.find(" ");
        
        cmd = s.substr(0, sp); // extracting the command
        //  cout<<cmd;
        
        
        
        
        
        if(cmd=="validate"){
            i = 1;
        }
        else if(cmd=="display"){
            i=2;
        }
         else {
            cout<<"invalid command ";
            i=0;
        }
        
    //    sp = s.find(" ");
        ep = s.length()-1;
        a = s.at(sp+1);
        b = s.at(ep);
        
        
        if(a=='<'&&b=='>'){
            fn = s.substr(sp+1);
            fnl = fn.length();
            file = fn.substr(1, fnl-2);
            s=file;
            
        }
        
        
        else{
            cout<<"invalid filename ";
            i=0;
            
        }
        
        
    }
    
    
    
    
    
    return i;
}
