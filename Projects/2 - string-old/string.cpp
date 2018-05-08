/* String: Project 2, Milestone 1
   Randy Gotham
   CS23001
*/
#include <iostream>
#include "string.hpp"
#include <cassert>
//------------------------------------------
//Constructors
//------------------------------------------
String::String(){
  str[0] = '\0';
}

String::String(char ch){
  str[0] = ch;
  str[1] = '\0';
}

String::String(const char ch[]){
  int i = 0;
  while(ch[i] != '\0'){
    str[i] = ch[i];
    i++;
    if( i >= capacity())
      break;
    str[i] = 0;
  }
}
//------------------------------------------
//In-class methods
//-----------------------------------------

char String::operator[](int i) const{
  return str[i];
}

char& String::operator[](int i){
  return str[i];
}

int String::length() const{
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

int String::capacity() const{
  return STRING_SIZE -1;
}

String String::operator+(const String& rhs) const{
    int offset = length();
  String result(str);
  int i = 0;
  while(rhs.str[i] != '\0'){
    result.str[offset + i] = rhs.str[i];
    ++i;
  }
  result.str[offset + i] = '\0';
  return result;
}

String& String::operator+=(const String rhs){
  int offset = length();
  int i = 0;
  while(str[i] != '\0'){
    str[offset + i] = rhs.str[i];
    ++i;
  }
  str[offset + i] = '\0';
  return *this;
}

bool String::operator==(const String& rhs) const{
    int i = 0;
    while((str[i] != '\0') && (str[i] == rhs.str[i]))
      ++i;
    return str[i] == rhs.str[i];

}

bool String::operator<(const String& rhs) const{
  int i = 0;
  while((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i] == rhs.str[i]))
    i++;
  if((str[i] == '\0') && (rhs.str[i] == 0))
    return false;
  if(str[i] == '\0')
    return true;
  if(str[i] < rhs.str[i])
    return true;
  else
    return false;
}

String String::substring(int start, int end) const{
  if (start < 0)
    start = 0;
  if (start > end)
    return String();
  if (start >= length())
    return String();
  String result;
  int i = start;
  while((i <= end) && (str[i] != '\0')){
    result.str[i - start] = str[i];
    ++i;
  }
  result.str[i - start] = '\0';
  return result;
}

int String::findchar(int pos, char ch) const{
  if((pos > length()) || (pos < 0))
    return -1;
  while((str[pos] != 0) && (str[pos] != ch))
    ++pos;
  if(str[pos] == 0)
    return -1;
  else
    return pos;
}

int String::findstr(int pos, const String& sub) const{
  int sublen = sub.length();
  int searchlen = length() - sublen;
  if((pos > length()) || (pos < 0))
     return -1;
  for(int i = pos; i <= searchlen; i++){
    if(substring(i, (i + sublen -1)) == sub)
      return i;
  }
  return -1;
  
}

std::istream& operator>>(std::istream& in, String& rhs){
  in >> rhs.str;
  return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
  int counter = 0;
  while(rhs.str[counter] != '\0'){
    out << rhs.str[counter];
    counter++;
  }
  return out;
}

//-----------------------------------------------
//non member functions
//----------------------------------------------

bool operator<=(const String& lhs, const String& rhs){
  return((lhs < rhs) || (lhs == rhs));
}

bool operator>(const String& lhs, const String& rhs){
  return (rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs){
  return ((rhs < lhs) || (lhs == rhs));
}

bool operator!=(const String& lhs, const String& rhs){
  return !(lhs == rhs);
} 

bool operator<(char lhs, const String& rhs){
  return(String(lhs) < rhs);
} 

bool operator<(const char lhs[], const String& rhs){
  return(String(lhs) < rhs);
}

bool operator==(char lhs, const String& rhs){
  return(String(lhs) == rhs);
}

bool operator==(const char lhs[], const String& rhs){
  return(String(lhs) == rhs);
}

String operator+(char lhs, const String& rhs){
  String result(lhs);
  return (result += rhs);
}

String operator+(const char lhs[], const String& rhs){
  String result(lhs);
  return (result += rhs);
}
