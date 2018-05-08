#ifndef utilities
#define utilities

#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include "stack.hpp"
#include "string.hpp"

String toPostfix(const String&);
void toAssembly(const String&);
String evaluate(const String&, const String&, const String&, bool[]);
#endif
