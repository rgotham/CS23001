#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:  Randy Gotham
// Updated:     03/18
//
//
//
//

#include <new>
#include <cassert>
#include <iostream>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class node {
public:
  T data;
  node<T> *next;
  node() : next(0) {};
  node(const T& x) : data(x), next(0) {};
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
   stack     () : tos(0) {};
   stack     (const stack<T>&);
   ~stack    ();
  void      swap      (stack<T>&);
  stack<T>& operator= (stack<T> rhs){swap(rhs); return *this;};

  bool      empty     () const {return tos == 0;};
  bool      full      () const;
  T         top       () const;
  T         pop       ();
  void      push      (const T&);

private:
	node<T>   *tos;
};

template <typename T>                  // copy constructor
stack<T>::stack(const stack<T>& actual) : tos(0){
  node<T> *temp = actual.tos, *bottom = 0;
  while(temp != 0){
    if(tos == 0){                      // if stack is empty 
      tos = new node<T>(temp -> data); // create new node with data of temp
      bottom = tos;                    // bottom is now tos
    }
    else{                              // if stack is not empty
      bottom -> next = new node<T>(temp -> data);
      bottom = bottom -> next;
    }
    temp = temp -> next;
  }
  
}

template <typename T>
stack<T>::~stack(){
  while(tos != 0){      // while tos points to node
    node<T> *tmp = tos; // save address of current tos node
    tos = tos -> next;  // move tos to next node in stack
    delete tmp;         // deallocate address of previous tos
  }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs){
  node<T> *temp = tos;
  tos = rhs.tos;
  rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const{
  node<T> *temp = new(std::nothrow) node<T>;
  if(temp == 0)
    return true;
  delete temp;
  return false;
}

template <typename T> // returns top node's data value
T stack<T>::top() const{
  assert(!empty());
  return tos -> data;
}

template <typename T> // takes top node off stack
T stack<T>::pop(){
  assert(!empty());
  T result = tos -> data;
  node<T> *temp = tos;
  tos = tos -> next;
  delete temp;
  return result;
} 

template <typename T> // puts a new node on tos
void stack<T>::push(const T& item){
  assert(!full());
  node<T> *temp = new node<T>(item); // points a pointer to newly allocated node
                                     // initializes with value x
  temp -> next = tos;                // points temp's next to current tos node
  tos = temp;                        // gives tos temp's value which is address of new node
}



#endif

