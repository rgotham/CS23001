/* Randy Gotham
   CS23001
   Milestone 1
*/

#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP

#include <iostream>
const int bigintSize = 100;
class bigint {

public:

  bigint();                                                           // Default; inits to zero
  bigint(int);                                                        // Inits to user-provided bigintSize and zero
  bigint(const char[]);                                               // Inits to a char array, unclear insofar
  void debugPrint(std::ostream&) const;                               // To print array; currently for debugging
  friend std::ostream&  operator<<(std::ostream&, const bigint&);     // Overloads output operator to output bigints 
  bool operator==(const bigint&) const;                               // Overloads equality operator to compare bigints
  void initToZero();                                                  // Method that inits to zero; unclear if needed (is the for loop an idiom?)
  
  bigint operator+(const bigint&) const;
  int& operator[](int);
  friend std::istream& operator>>(std::istream&, bigint&);

  bigint times_10(int) const;
  bigint times_digit(int) const;
  bigint operator*(bigint);

private:
  int bigArray[bigintSize];

};

#endif
