//String.h
#pragma once
#include <iostream>
#include <string>

using namespace std;

class String
{
private:
    char* str;      
    int length;     

public:
    
   String();                         
    String(const char* s);             
    String(const String& other);     
    ~String();                         

   
    const char* GetStr() const;
    int GetLength() const;
    void SetStr(const char* s);

    String& operator = (const String& other);

    
    operator string() const;

    
    friend String operator + (const String& s1, const String& s2); 
    friend String operator - (const String& s1, const String& s2); 
    friend int operator * (const String& s1, const String& s2);     

    
    friend ostream& operator << (ostream& out, const String& s);
    friend istream& operator >> (istream& in, String& s);
};