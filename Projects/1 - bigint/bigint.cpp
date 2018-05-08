/* Randy Gotham
   CS23001
  /Milestone 1/
   Milestone 2
*/

#include "bigint.hpp"
//---------------------------------------------------
//Constructors and constructor related thingies
//---------------------------------------------------

void bigint::initToZero(){
  for (int j = 0; j < bigintSize; j++){
    bigArray[j]=0;
  }
}

bigint::bigint(){
  initToZero();
}

bigint::bigint(int bigintNum){
  initToZero();
  for(int j = 0; j < bigintSize; j++){
    bigArray[j] = bigintNum % 10;
    bigintNum /= 10;
  }
}

bigint::bigint(const char charArray[]){
  initToZero();
  int charArrayCounter = 0;
  int bigArrayCounter = 0;
  while (charArray[charArrayCounter] != '\0'){
    ++charArrayCounter;
  }
  --charArrayCounter;
  while (charArrayCounter >= 0){
    bigArray[bigArrayCounter] = charArray[charArrayCounter] - '0';
    --charArrayCounter;
    ++bigArrayCounter;
  }
}
//-------------------------------------------------------
//A printer for all your printing things
//It doesn't suck, unlike Epson printers
//-------------------------------------------------------
void bigint::debugPrint(std::ostream& out) const{
  out << "|";
  for (int j = bigintSize - 1; j >=0; j--){
    out << bigArray[j] << "|";
  }
  out << "\n";
}
//-------------------------------------------------------
//Multiplication functions for even bigger bigints
//Times_10 shifts left until index of num is reached
//then 0's are placed (10^n = n shifts left)
//Times_digit simply multiplies a bigint by a single int 0-9
//-------------------------------------------------------

bigint bigint::times_10(int num) const {
  bigint result;
  for(int j = bigintSize - 1 - num; j >=0; --j){
    result.bigArray[num + j] = bigArray[j];
  }
  for(int i = 0; i < num; i++){
    result.bigArray[i] = 0;
  }
  return result;
}

bigint bigint::times_digit(int num) const{
  bigint result;
  int carry = 0;
  int placeholder = 0;
  for(int j = 0; j < bigintSize; j++){
    //multiply index by num and add carried digit
    placeholder = (bigArray[j] * num) + placeholder;
    carry = placeholder % 10; // to pull least sig digit
    placeholder /= 10; // pulls carried digit to be added
    result.bigArray[j] = carry; // adds the carried digit
  }
  return result;
}

//-------------------------------------------------------
//Overloaded operators of all kinds!
//-------------------------------------------------------

bool bigint::operator==(const bigint& bigintOne) const{
  for (int j = 0; j < bigintSize; j++){
    if (bigArray[j] != bigintOne.bigArray[j])
	return false;
  }
  return true; 
}

int& bigint::operator[](int element){
  return bigArray[element];
}

std::ostream& operator<<(std::ostream& out, const bigint& rhs){
  int digitCountToFifty = 1;
  int lineBreakLimit = bigintSize - 1;
  while ((rhs.bigArray[lineBreakLimit] == '\0') ||
	 (rhs.bigArray[lineBreakLimit] == 0)){
    if(lineBreakLimit == 0)
      break;
    --lineBreakLimit;
  }
  for(int j = lineBreakLimit; j >= 0; j--){
    if (digitCountToFifty > 50){
      digitCountToFifty = 0;
      out << '\n';
    }
    out << rhs.bigArray[j];
    digitCountToFifty++;
 }
  return out;
}

std::istream& operator>>(std::istream& in, bigint& bi){
  char charArray[bigintSize], tempChar;

  for(int i = 0; i < bigintSize; i++){
    in >> tempChar;
    if(tempChar == ';'){
      charArray[i] = '/0';
      break;
    }
    charArray[i] = tempChar;
  }
  bi = bigint(charArray);
  return in;
}

bigint bigint::operator+(const bigint& bi) const {
  bigint result;
  int carrier = 0;
  for(int i = 0; i < bigintSize; i++){
    int add = bigArray[i] + bi.bigArray[i] + carrier;
    if(add > 9)  // carry 1 to index+1
      carrier = 1;
    else
      carrier = 0;
    result.bigArray[i] = add % 10;
  }
  return result;
}

bigint bigint::operator*(bigint bigintOne){
  bigint product;
  bigint placeholder;
  
  for(int j = 0; j < bigintSize; j++){
    placeholder = times_digit(bigintOne.bigArray[j]);
    product = product + placeholder.times_10(j);
  }
  return product;
}
