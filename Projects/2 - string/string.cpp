/* String: Project 2, Milestone 2
   Randy Gotham
   CS23001
*/
#include <iostream>
#include "string.hpp"
#include <cassert>
#include <cmath>
//------------------------------------------
//Constructors
//------------------------------------------
// Allocates memory for one element, sets it to null
String::String(){
  stringSize = 1;
  str = new char[stringSize];
  str[0] = '\0';
}
// creates String('a')
String::String(char ch) : String(1){
  str[0] = ch;
  str[1] = '\0';
}
// creates String("abcd")
String::String(const char ch[]){
  int len = 0;
  while(ch[len] != '\0'){
    len++;
  }
  stringSize = len + 1;
  str = new char[stringSize];
  for(int i = 0; i < len; ++i){
    str[i] = ch[i];
  }
  str[len] = '\0';
}


String::~String(){
  delete[] str;
}
String::String(int n){
  stringSize = n + 1;
  str = new char[stringSize];
  str[0] = '\0';
}
String::String(int n, const char carr[]) : String(n){
  int carr_leng = 0;
  while(carr[carr_leng] != '\0')
    ++carr_leng;
  for(int i = 0; i <= carr_leng; ++i)
    str[i] = carr[i];
  
}
// copy constructor
String::String(const String& actual){
  stringSize = actual.stringSize;
  str = new char[stringSize];
  for(int i = 0; i < stringSize; ++i)
    str[i] = actual.str[i];
}

//------------------------------------------
//In-class methods
//-----------------------------------------
String String::getline(std::istream& in, String& line){
  String temp;
  char ch = 0;
  in.get(ch);
  while(ch != '\n' && (!in.eof())){
    temp += ch;
    in.get(ch);
  }
  line = temp;
  return line;
}

void String::swap(String& rhs){
  char *tempor_str = str;
  int tempor_strSize = stringSize;
  
  str = rhs.str;
  stringSize = rhs.stringSize;

  rhs.str = tempor_str;
  rhs.stringSize = tempor_strSize;
}

String& String::operator=(String rhs){
  swap(rhs);
  return *this;
}
char String::operator[](int i) const{
  return str[i];
}

char& String::operator[](int i){
  return str[i];
}

void String::resetCapacity(int n){
  char * newArr = new char[n + 1];
  int i = 0;
  while(str[i] != 0)
    newArr[i] = str[i];
  newArr[i] = '\0';
  stringSize = n + 1;
  delete[] str;
  str = newArr;
}

int String::length() const{
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

int String::capacity() const{
  return (stringSize -1);
}

int String::strToInt() const{
  int result = 0, start = length() - 1;
  char temp;
  for(int i = 0; i < length(); ++i){
    temp = str[i];
    result += ((temp - '0') * pow(10, (start - i)));
  }
  return result;
}

String String::operator+(const String& rhs) const{
  String result(length() + rhs.length(), str);
  int offset = length();
  for(int i = 0; i <= rhs.length(); ++i)
    result[offset + i] = rhs.str[i];
  return result;
}

String& String::operator+=(const String& rhs){
   int offset = length();
  *this = String(length() + rhs.length(), str);
  for(int i = 0; i <= rhs.length(); ++i)
    str[offset + i] = rhs.str[i];
  return *this;
  
}

bool String::operator==(const String& rhs) const{
  if (length() != rhs.length()) // check length for equality at start
    return false;

  for(int i = 0; i < length(); ++i) // if length is same, check elements
    if(str[i] != rhs[i])
      return false;

  return true; //if loop completes and everything is equal
}

bool String::operator<(const String& rhs) const{
  if (length() < rhs.length()){ // assumed lhs is < than rhs
    for(int i = 0; i < length(); ++i){
      if(str[i] > rhs[i])
	return false;
    }
    return true;
  }
  else { // we assume lhs is >= rhs string
    for(int i = 0; i < rhs.length(); ++i){
      if(str[i] < rhs[i])
	return true;
    }
    return false;
  }
}

String String::substr(int start, int end) const{
    if (start < 0) // if start is <= 0
    start = 0;
  if (start > end) // if start is past the end position
    return String();
  if (start > length()) // if start is past end of string
    return String();
  
  int len = 0;
  if(start == end)
    len = 2;
  else
    len = (end - start) + 1;

  char tempstr[len];
  int i;
  for(i = start; i <= end; ++i)
    tempstr[i - start] = str[i];
  tempstr[i - start] = '\0';
  String result(tempstr);
  return result;
  


}

int String::findch(int pos, char ch) const{
  for(int i = pos; i < length(); ++i){
    if(str[i] == ch)
      return i;
  }
  return -1; //if ch cannot be found
}

int String::findstr(int pos, const String& sub) const{
  int sublen = sub.length();
  int searchlen = length() - sublen;
  if((pos > length()) || (pos < 0))
     return -1;
  for(int i = pos; i <= searchlen; i++){
    if(substr(i, (i + sublen -1)) == sub)
      return i;
  }
  return -1;
  
}

std::vector<String> String::split(char delimit) const{
  std::vector<String> result;
   String temp;
  if(delimit == '\0'){
    for(int i = 0; i < length(); ++i)
      result.push_back(str[i]);
  return result;
  }

   for(int i = 0; i < length(); ++i){
    if(str[i] == delimit){
      result.push_back(temp);
      if(str[i + 1] != str[i])
	temp = str[++i];
    } else{
      temp += str[i];
    }
    }
  return (result.push_back(temp), result);


}

std::istream& operator>>(std::istream& in, String& rhs){
  char ch;
  in.get(ch);

  rhs = String();

  while (ch != '\0' && !in.eof() && ch != '\n' && ch != ' '){
    rhs += ch;
    in.get(ch);
  }
  return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
  out << rhs.str;
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
  return (result + rhs);
}

String operator+(const char lhs[], const String& rhs){
  String result(lhs);
  return (result + rhs);
}

