/*
 * *****************************************************************************
 * file name : error_handling.h
 * author    : Hung Ngo
 * description : error reporting functions
 * *****************************************************************************
 */


#ifndef _ERROR_HANDLING_H
#define _ERROR_HANDLING_H

#include <string>
#include <stdexcept>

struct Undefined_Variable_Exception : public std::runtime_error {
    Undefined_Variable_Exception() : 
        std::runtime_error("Undefined variable") {}
    Undefined_Variable_Exception(std::string var) : 
        std::runtime_error(std::string("Varible ") + var + " undefined") {}
};

struct DBZ_Exception : public std::runtime_error {
    DBZ_Exception() : std::runtime_error("Divide by zero") {}
};

struct Syntax_Error_Exception : public std::runtime_error {
    Syntax_Error_Exception() : std::runtime_error("Syntax Error") {}
};

void error_quit(std::string);
void error_return(std::string);
void print_warning(std::string);
void note(std::string);

#endif
