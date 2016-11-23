//
//  A4.cpp
//  f
//
//  Created by Tanveer Gupta on 10/21/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A4.h"
#include <iostream>
#include <stack>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>   // for exit()
#include<iomanip>


#include<vector>
#include "vector.h"

//-------------------------------------------------------------------------
#ifndef _LEXER_H
#define _LEXER_H

#include <string>

enum token_types_t { 
    IDENT,  // a sequence of alphanumeric characters and _, starting with alpha
    TAG, // sequence of characters between < >, no escape
    ENDTOK, // end of string/file, no more token
    ERRTOK  // unrecognized token
};

struct Token {
    token_types_t type;
    std::string value;
    // constructor for Token
    Token(token_types_t tt=ENDTOK, std::string val="") : type(tt), value(val) {}
};

/**
 * -----------------------------------------------------------------------------
 * the Lexer class:
 * - take a string to be scanned
 * - scan for tokens and return one at a time
 * -----------------------------------------------------------------------------
 */
class Lexer {
    public:
    // constructor
    Lexer(std::string str="") : input_str(str), cur_pos(0), in_err(false), 
        separators(" \t\n\r") { }

    // a couple of modifiers
    void set_input(std::string); // set a new input, 
    void restart();              // move cursor to the beginning, restart

    Token next_token();    // returns the next token
    bool has_more_token(); // are there more token(s)?

    private:
    std::string input_str;  // the input string to be scanned
    size_t      cur_pos;    // current position in the input string
    bool        in_err;     // are we in the error state?
    std::string separators; // set of separators; *not* the best option!
};

#endif

//-----------------------------------------------------------------------------
#include "Lexer.h"
#include <iostream>
using namespace std;

/**
 * -----------------------------------------------------------------------------
 *  scan and return the next token
 *  cur_pos then points to one position right past the token
 *  the token type is set to ERRTOK on error, at that point the global state
 *  variable err will be set to true
 * -----------------------------------------------------------------------------
 */
Token Lexer::next_token() {
    Token ret;
    size_t last;

    if (in_err) {
        ret.type = ERRTOK;
        ret.value = "";
        return ret;
    }

    // if not in error state, the default token is the ENDTOK
    ret.type = ENDTOK;
    ret.value = "";

    if (has_more_token()) {
        last = cur_pos; // input_str[last] is a non-space char
        if (input_str[cur_pos] == '"') {
            cur_pos++;
            while (cur_pos < input_str.length() && input_str[cur_pos] != '"')
                cur_pos++;
            if (cur_pos < input_str.length()) {
                ret.type = TAG;
                ret.value = input_str.substr(last+1, cur_pos-last-1);
                cur_pos++; // move past the closing "
            } else {
                in_err = true;
                ret.type = ERRTOK;
                ret.value = "";
            }
        } else {
            while (cur_pos < input_str.length() &&
                   separators.find(input_str[cur_pos]) == string::npos &&
                   input_str[cur_pos] != '"') {
                cur_pos++;
            }
            ret.type  = IDENT;
            ret.value = input_str.substr(last, cur_pos-last);
        }
    }
    return ret;
}

/**
 * -----------------------------------------------------------------------------
 *  set a new input string, restart
 * -----------------------------------------------------------------------------
 */
void Lexer::set_input(string str) {
    input_str = str;
    restart();
}

/**
 * -----------------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 */
bool Lexer::has_more_token() {
    while (cur_pos < input_str.length() && 
           separators.find(input_str[cur_pos]) != string::npos) {
        cur_pos++;
    }
    return (cur_pos < input_str.length());
}

/**
 * -----------------------------------------------------------------------------
 *  restart from the beginning, reset error states
 * -----------------------------------------------------------------------------
 */
void Lexer::restart() {
    cur_pos = 0;
    in_err = false;
}



//---------------------------------------------------------------------------






using namespace std;


void vecdisplay(vector <vector <string> >);
void sortdisplay();
void nljoin();
void smjoin();
bool filereader(string s);
string jugaad(string &s);
vector<string> interpret(string s);


int main(){
    
    vector<string> vec;
    string s;
    int x ;
    
  //  filereader();
    
    
    cout<<"enter command and filename";
    getline(cin, s);
    
    vec = interpret(s);
    
    
    x = vec.size();
   
    switch (x){
        case 1 : {
            exit(1);
            
        }
        case 2 : {
            string s =  vec[1];
            filereader(s);
            //call display
        }
        
        case 4 : {
            string s = vec[1];
            filereader(s);
            // call sorted display
        }
        case 5 : {
            if(vec[0]=="nljoin"){
                //call nljoin
            }
            else {
                //call smjoin
        }
    }
        default : {
            cout << "ERROR, INVALID COMMAND OR FILENAME";
        }
    }
    
    
    return 0;
    
}

vector<string> interpret(string s){
    
    vector<string> v;
    
    
    string first; // storing the value of the first token i.e. the command
    string second; // storing the value of the second token i.e. the filename
    string third; // storing the value of the third token if necessary
    string fourth; // storing the value of the 4th token if necessary
    string fifth; //storing the value of the 5th token if necessary
    
    int x;
    int i = 0;
    Lexer lexer;
    
    Token tok;
    
    lexer.set_input(s);
    
    while(lexer.has_more_token()){
        i++;
        tok = lexer.next_token();
       
        switch(i){
            case 1 : {
                first = tok.value;
                }
                break;
            case 2 : {
                second = tok.value;
            }
                break;
            case 3 : {
                third = tok.value;
            }
                break;
            case 4 :{
                fourth = tok.value;
            }
                break;
            case 5 : {
                fifth = tok.value;
            }
                break;
            default : {
                x = 0;
                //error message
            }
                
        }
       
    
        }
        
    switch(i){
        case 1 : {
            if(first=="exit"){
                v.push_back(first);
                // x=5;
            }
            else{
                while(!v.empty()){
                    v.pop_back();
                }
            }
        }
            break;
        case 2 : {
            if(first=="display"){
                v.push_back(first);
                v.push_back(second);
                
            }
            else{
                while(!v.empty()){
                    v.pop_back();
                }
            }
        }
            break;
        case 4 : {
            if(first=="display"&&third=="sortedby"){
                v.push_back(first);
                v.push_back(second);
                v.push_back(third);
                v.push_back(fourth);
                // x = 2;
            }
            else{
                while(!v.empty()){
                    v.pop_back();
                }
            }
        }
            break;
        case 5 : {
            if(first == "nljoin"){
                v.push_back(first);
                v.push_back(second);
                v.push_back(third);
                v.push_back(fourth);
                v.push_back(fifth);
            }
            else if (first == "smjoin"){
                v.push_back(first);
                v.push_back(second);
                v.push_back(third);
                v.push_back(fourth);
                v.push_back(fifth);
                
            }
            else {
                while(!v.empty()){
                    v.pop_back();
                }
            }
        }
            break;
        default : {x = 0;}
       
    
    }
    return v;
    
        }
    
    
    
bool filereader(string s){
	
    
	
	    
   
	
	string line;
	ifstream ifs;
    
	vector <vector <string> > col;
	vector <string> row;
   	Lexer templex;
  	Token temptok;
    
    	ifs.open(s.c_str());
 	if (ifs.fail()) {
       		cerr << "ERROR: Failed to open file " << s << endl;
		ifs.clear();
		return false;
    	}
	else {
        	int i = 0;
        	while (getline(ifs, line)){
                if(i == 0){
                    line = jugaad(line);
                    //cout<<line<<endl<<endl;
                }
                //cout<<"The Line is "<<line<<endl;
            		templex.set_input(line);
            		while(templex.has_more_token()){
                		temptok = templex.next_token();
                        
                        //cout<<"The current token value is "<<temptok.value<<endl;
                		row.push_back(temptok.value);
                        
            		}
            		col.push_back(row);	
			i++;
		}
       		ifs.close(); // always remember to close it
    	}
     vecdisplay(col);
  	 return true;
    
}

void vecdisplay(vector <vector <string> > col){
    vector<string> t1;
    stack<string> temp;
    int size =col[0].size();
    cout<<size<<endl;
    string count;
    int max = 0;
    
    
    for(int i =0; i<col.size(); i++){
        
        if( i == 1){
            for(int x = 0; x<=32*size + 4 ; x++){
                cout<<"-";
            }
            cout<<endl;
        }
        else{
        t1 = col[i];
        int a = 0;
        while(a<size){
            a++;
            temp.push(t1.back());
            count = t1.back();
            if(max<count.length()){
                max = count.length();
            }
            t1.pop_back();
            
        }
            while(!temp.empty()){
            cout<<setw(32)<<left<<temp.top()<<" | ";
            temp.pop();
            }
        }
        cout<<endl;
        }
        
  
    
}


//mast nazron se allah bachaaye

string jugaad(string &s){
    for(int i = 0; i<s.length(); i++){
       
        if(s[i] == '<' || s[i] == '>'){
           
                s[i] = '"';
            
        }
    }
    return s;
}
	

        




