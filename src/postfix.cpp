// Copyright 2021 Krayushkina
#include "MyStack.h"
#include "postfix.h"
#define STACK_PUSH stack.push(obj[i]);

string infix_to_postfix(string obj) {
    MyStack<char> stack(100);
    string tmp;
    for (int i = 0; i < obj.length(); i++) {
        if (obj[i] <= '9' && obj[i] >= '0') {
            while (obj[i] >= '0' && obj[i] <= '9') { tmp += obj[i]; ++i; }
            --i;
            tmp = tmp + ' ';
        }
    else if (obj[i] == '(') STACK_PUSH
    else if (obj[i] == '*' || obj[i] == '/') {
        if (stack.isEmpty()) STACK_PUSH
        else if (stack.get() == '*' || stack.get() == '/')
        { tmp += stack.pop(); tmp += ' '; STACK_PUSH }
        else 
			STACK_PUSH
    }
    else if (obj[i] == '+' || obj[i] == '-')
    {if (!stack.isEmpty() && stack.get() != '(') {
            tmp = tmp + stack.pop(); tmp = tmp + ' ';}
        STACK_PUSH
    }
    else if (obj[i] == ')') {
        while (stack.get() != '(') { tmp = tmp + stack.pop(); tmp = tmp + ' ';}
        stack.pop();
    }
  }
  while (!stack.isEmpty()) { tmp = tmp + stack.pop(); tmp = tmp + ' '; }
  tmp.erase(tmp.length() - 1);
  return tmp;
}
