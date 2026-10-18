
//String.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring>

using namespace std;


String::String()
{
    length = 0;
    str = new char[1];
    str[0] = '\0';
}


String::String(const char* s)
{
    str = nullptr;
    length = 0;
    SetStr(s); 
}


String::String(const String& other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
}


String::~String()
{
    delete[] str;
}


const char* String::GetStr() const
{
    return str;
}

int String::GetLength() const
{
    return length;
}


void String::SetStr(const char* s)
{
    delete[] str;

    if (s != nullptr)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    else
    {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
}

String& String::operator = (const String& other)
{
    if (this != &other)
    {
        SetStr(other.str);
    }
    return *this;
}


String::operator string() const
{
    return string(str);
}


String operator + (const String& s1, const String& s2)
{
    int newLen = s1.length + s2.length;
    char* buffer = new char[newLen + 1];

    strcpy(buffer, s1.str);
    strcat(buffer, s2.str);

    String result(buffer);
    delete[] buffer;

    return result;
}


String operator - (const String& s1, const String& s2)
{
    if (s2.length == 0 || s1.length == 0)
        return s1;

    char* pos = strstr(s1.str, s2.str);
    if (pos == nullptr)
    {
        return s1;
    }

    int prefixLen = pos - s1.str;
    int suffixLen = strlen(pos + s2.length);
    char* buffer = new char[prefixLen + suffixLen + 1];

    strncpy(buffer, s1.str, prefixLen);
    buffer[prefixLen] = '\0';
    strcat(buffer, pos + s2.length);

    String result(buffer);
    delete[] buffer;

    return result;
}


int operator * (const String& s1, const String& s2)
{
    if (s2.length == 0)
        return 0;

    char* pos = strstr(s1.str, s2.str);
    if (pos != nullptr)
    {
        return static_cast<int>(pos - s1.str);
    }
    return -1;
}


ostream& operator << (ostream& out, const String& s)
{
    out << string(s);
    return out;
}

istream& operator >> (istream& in, String& s)
{
    char buffer[256];
    in >> buffer;
    s.SetStr(buffer);
    return in;
    


}