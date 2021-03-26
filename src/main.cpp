#include <iostream>
#include <string>

#include <iostream>
#include "postfix.h"
#include "MyStack.h"
using std::cout;
using std::endl;

int main() 
{
  string str("1 + 2 * 3 / (4 - 5)");
  cout << infix_to_postfix(str) << endl;  // 1 2 3 * 4 5 - / +
  return 0;
}
