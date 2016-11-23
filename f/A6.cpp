//
//  File.cpp
//  f
//
//  Created by Tanveer Gupta on 11/17/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A6.h"

#include<iostream>
#include"Lexer.h"


using namespace std;

void interpret(string s){
    Lexer lexer;
    Token tok;
    
    lexer.set_input(s);
    tok = lexer.next_token();
    
        
}