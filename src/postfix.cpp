// Copyright 2021 Krayushkina
#include "MyStack.h"	
#include "postfix.h"	
#include <iostream>	
#include <string>	
#include <unordered_map>	


std::string infix2postfix(std::string infix) {	
  std::string postfix;	
  std::unordered_map<char, int> return_prior({ {'(', 0}, {')', 1},	
   {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} });	
  int count = 0;	
  int l = inf.length();	
  MyStack<char> operation(l+100);	
  for (count = 0; count < l; count++) {	
    if (inf[count] != ' ') {	
      if (inf[count] == '(') {	
        operation.push(inf[count]);	
      } else if (inf[count] == ')') {	
        while (operation.get() != '(') {	
          postfix += operation.pop();	
          postfix += ' '; }	
        operation.pop();	
      } else if (inf[count] == '+' || inf[count] == '-') {	
        while (return_prior[operation.get()] > 1) {	
          postfix += operation.pop();	
          postfix += ' '; }	
        operation.push(inf[count]);	
      } else if (inf[count] == '*' || inf[count] == '/') {	
        while (operation.get() == '*' || operation.get() == '/') {	
          postfix += operation.pop();	
          postfix += ' '; }	
        operation.push(inf[count]);	
      } else if (inf[count] >= '0' && inf[count] <= '9') {	
        while (count < l && inf[count] != ')' &&	
          inf[count] != ' ') { postfix += inf[count];	
          count += 1; }	
          count -= 1;	
          postfix += ' '; }	
    }	
  }	
  if (postfix.back() == ' ') postfix.pop_back();	
  while (!operation.isEmpty()) { postfix += ' ';	
    postfix += operation.pop(); }	
  return postfix; }