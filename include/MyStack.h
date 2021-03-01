// Copyright 2021 Krayushkina
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>
#include <string>
#include <cassert>

template<class S>
class MyStack {
 public:
  explicit MyStack(int size);
  ~MyStack();
  MyStack(const MyStack<S>&);
  int getMyStackSize() const;
  int getUpper() const;
  S* getPtr() const;
  void push(const S&);
  void pop();
  void printMyStack();
  S isEmpty() const;
  S isFull() const;
  S get() const;
 private:
  int size;
  int upper;
  S* store;
};

template<class S>
MyStack<S>::MyStack(int _size) :
  size(_size), upper(0) {
  store = new S[size]; }

template<class S>
MyStack<S>::MyStack(const MyStack <S>& otherStack) :
  size(otherStack.getMyStackSize()) {
  store = new S[size];
  upper = otherStack.getUpper;
  for (int ix = 0; ix < upper; ix++)
    store[ix] = otherStack.getPtr()[ix]; }

template<class S>
MyStack<S>::~MyStack() {
  delete[] store; }

template <class S>
int MyStack<S>::getMyStackSize() const {
  return size; }

template <class S>
int MyStack<S>::getUpper() const {
  return upper; }

template <class S>
S* MyStack<S>::getPtr() const {
  return store; }

template <typename S>
void MyStack<S>::push(const S& value) {
  assert(upper < size);
  store[upper++] = value; }

template <typename S>
void MyStack<S>::pop() {
  assert(upper > 0);
  store[--upper]; }

template <typename S>
void MyStack<S>::printMyStack() {
  for (int ix = upper - 1; ix >= 0; ix--)
    std:: cout << store[ix] << " "; }

template <typename S>
S MyStack<S>::isEmpty() const {
  if (upper == 0) return 1;
  return 0; }

template <typename S>
S MyStack<S>::isFull() const {
  if (upper == size) return 1;
  return 0; }

template <typename S>
S MyStack<S>::get() const {
  if (upper != 0)
  return store[upper - 1]; }

#endif  // INCLUDE_MYSTACK_H_
