
//
//  assignment 1.cpp
//  f
//
//  Created by Tanveer Gupta on 9/10/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "assignment 1.h"

#include<iostream>
#include <fstream>

using namespace std;

void wcount(string );
void ccount(string);
void lcount(string );

int interpret(string &n);


int main(){
    
    int x;
    
    string f;
    
    cout<<"   enter filename :   ";
    cin>>f;
    
    x = interpret(f);
    
    switch(x){
        case 0 : {
            cout<<"ERROR : invalid command or filename ";
        }
        case 1 : {
            
        }
    }
    
    
    
    
    return 0;
}

int interpret(string &s){
   
    int sp;
    int ep;
    char a;
    char b;
    string cmd;
    string fn;
    string file;
    int i = 0;
    int fnl = 0;
    
    //checking for exit
    if(s=="exit"){
        i=4;
    }
    
    //checking otherwise
    else
    
    {
       
    cmd = s.substr(0, 2);
    
        if(cmd=="wc"){
            i = 1;
        }
        else if(cmd=="lc"){
            i=2;
        }
        else if (cmd=="cc"){
            i=3;
        }
        
        else{
           // cout<<"invalid command ";
            i=0;
        }
        
        sp = s.find(" ");
        ep = s.length()-1;

   
    
    a = s.at(sp+1);
    b = s.at(ep);
    
    if(a=='"'&&b=='"'){
        fn = s.substr(sp+1);
        
        fnl = fn.length();
        
        file = fn.substr(1, fnl-2);
       
        s=file;
        
   
    }
    
    
    else{
      //  cout<<"invalid filename ";
        i=0;
        
    }
    
       
    }
    
   
    
    
    
    return i;
}


void ccount(string fname){
    ifstream ifile;
    int i = 0;
    
    ifile.open(fname.c_str());
    if (ifile.fail()) {
        cerr << "ERROR: Failed to open file " << fname << endl;
        ifile.clear();}
    
    else {
        string line;
       
     
        while (!ifile.eof()){
            while(getline(ifile, line)){
                i=i+line.length();
                
            }
            
            ifile.close();
            cout<<"number of characters in file are "<<i;
 
        }
   
    }
    cout<<"number of characters in file are "<<i;
    
    
}

void lcount(string fname){
    string line;
    ifstream ifile;
    int i = 0;
    
    
    
    ifile.open(fname.c_str());
    if (ifile.fail()) {
        cerr << "ERROR: Failed to open file " << fname << endl;
        ifile.clear();}
    
    
    else {
        while (getline(ifile, line)){
            i++;
        }
          
        ifile.close();
        cout<<"number of lines in file are "<<i;
    }
    
}


void wcount(string fname){
    ifstream ifile;
    int i = 0;
    
    ifile.open(fname.c_str());
    if (ifile.fail()) {
        cerr << "ERROR: Failed to open file " << fname << endl;
        ifile.clear();}
    
    else {
        char a;
        while(!ifile.eof()){
            ifile>>a;
            if(a==' '||a=='\t'||a=='\n'){
                i++;
            
                }
        
    }
        cout<<"number of words in file are "<<i;
    }
    
}
