// Copyright 2021 Krayushkina
#include <iostream>
#include <string>

#include "postfix.h"
#include "MyStake.h"

int main() {
  std::string inf = "(6 * (4 - 2) + 5)*(2.6 + 3 * 7) - 9";
  std::string postfix = infix2postfix(inf);
  std::cout << postfix << std::endl;
  return 0;
}
