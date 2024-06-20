#include <stddef.h>
#include <stdexcept>
#include <string.h>
#include "String.h"

String::String(std::string str) {
    if (str == "")
        throw std::invalid_argument("str es vacio");
    
    s = strcpy(new char[str.size() + 1], str.c_str());
}

String::String(const char* str){
    if(str == NULL)
        throw std::invalid_argument("str es NULL");
        
    int strSize = strlen(str);
    s = strcpy(new char[strSize+1], str);
}

ComparisonRes String::compare(OrderedKey* k) const
{
    String *str = dynamic_cast<String *>(k);
    if(str == NULL) 
        throw std::invalid_argument("Invalid key k");
    
    int cmp = strcmp(s, str->s);
    if(cmp == 0)
        return EQUAL;
    else if(cmp > 0)
        return GREATER;
    else
        return LESSER;
}

const char *String::getValue() const
{
    return s;
}

String::~String(){
    delete[] s;
}