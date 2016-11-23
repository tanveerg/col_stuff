//
//  A5.cpp
//  f
//
//  Created by Tanveer Gupta on 10/30/12.
//  Copyright (c) 2012 Tanveer Gupta. All rights reserved.
//

#include "A5.h"
#include <iostream>
#include<vector>
using namespace std;

bool iterative_palindrome(const string& str){
    bool x;
    int start;
    int end;
    start = 0;
    end = str.length()-1;
    int len = str.length();
    
    // if the length of the string is one or zero , it is a palindrome
    if(len==1||len==0){
        x = true;
    }
    else{
    //if the length of the string is even
    if(len%2==0){
        for(start = 0; start<end; start ++ ){
            if(str[start]==str[end]){
                end--;
            }
        }
        if(start==end+1){
            x = true;
        }
        else{
            x = false;
        }
           }
   //if the length of the string is odd
    else{
        int pivot = len/2;
       
        for(start = 0; start<end; start ++ ){
            if(str[start]==str[end]){
                end--;
            }
        }
        if(start==pivot&&end==pivot){
            x = true;
        }
        else{
            x = false;
        }
            }
    }
    return x;
    
    

}

bool recursive_palindrome(const string& str, size_t start, size_t end){
    bool x;
    int len = end+1;
    

    
    if(len == 1|| len == 0){
        return true;
            }
    //checking with an even length string
    else if (len%2==0){
        
        if(str[start]==str[end-1]&&len==2){
            x = true;
        }
        
        else if(str[start]==str[end-1]){
            recursive_palindrome(str, start++, end--);
        }
       
        else{
          x = false;
        }
        
    }
        //checking with an odd length
        else{
            if(str[start]==str[end-1]){
                recursive_palindrome(str, start++, end--);
            }
            else{
                x = false;
            }
        }
        
       
    
      
    return x;
}

double iterative_avg(const vector<double>& vec){
    double avg;
    double sum=0;
    int size = vec.size();
    
    for(int i = 0; i<size; i++){
        sum = sum + vec[i];
    }
    avg = sum/size;
    
    return avg;
    
}

double recursive_avg(const vector<double>& vec, size_t start, size_t end){
    double avg;
    double sum;
    
    if(start==end){
        return avg;
    }
    else{
        sum = sum + vec[start];
        avg = (sum + recursive_avg(vec, start++, end))/vec.size();
       return avg;        
    }
        
    
    
}


string iterative_binrep(size_t n) {
    string s = "";
    string res;  //final result
    int quot;  // quotient
    int rem;   // remainder
    
    while(n>=1){
        quot = n/2;
        rem = n%2;
        if(rem==1){
            s = s+'1';
        }
        else{
            s = s + '0';
        }
        
        n = quot;
        
    }
    for(int i = s.length()-1;i>=0;i--){
        res = res + s[i];
    }
    return res;
    }



string recursive_binrep(size_t n){
    string res = "";
    if(n>=1){
        res = res+recursive_binrep(n/2);
        if (n%2==1){
            res=res+'1';
            
        }
        else{
            res=res+'0';
        }
    }
    return res;
    
}



int main(){
    size_t n;
    cout <<"enter a number";
    
    cin>>n;
    cout<<iterative_binrep(n);
    
}