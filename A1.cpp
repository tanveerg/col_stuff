//
//  A1.cpp
//  f
//
//  Created by Tanveer Gupta on 9/11/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A1.h"
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
    
    
    
       
 while(x!=4)   {
    
    cout<<"   enter command and filename :   ";
    getline(cin, f);
    
    x = interpret(f);

    
    switch(x){
        case 0 : {
            cout<<"ERROR : invalid command or filename ";
        }
            break;
        case 1 : {
            wcount(f);
            
        }
            break;
        case 2 : {
            lcount(f);
        }
            break;
        case 3 : {
            ccount(f);
        }
            break;
        case 4 : {
            exit(1);
            
        }
            break;
        default :{
           cout<<"ERROR : invalid command or filename ";
        }
            
    }
   }
    
    
    
    
    return 0;
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
        i=4;
    }
    
    //checking otherwise
    else
        
    {
        
        cmd = s.substr(0, 2); // extracting the command
      //  cout<<cmd;
        
        
        
        
        
        if(cmd=="wc"){
            i = 1;
        }
        else if(cmd=="lc"){
            i=2;
        }
        else if (cmd=="cc"){
            i=3;
        } else {
             cout<<"invalid command ";
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
             cout<<"invalid filename ";
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
    string line;
    ifile.open(fname.c_str());
    if (ifile.fail()) {
        cerr << "ERROR: Failed to open file " << fname << endl;
        ifile.clear();}
    
    else {
       char a;
        while(!ifile.eof()){
          //  ifile>>a;
            ifile.get(a);
            //cout<<a;
            if(a==' '||a=='\t'||a=='\n'){
                i++;
                
            }
                         
            }

            
            
            
                   }
        cout<<"number of words in file are "<<i;
    }
    

