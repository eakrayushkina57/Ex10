// Copyright 2021 Krayushkina
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>
#include <string>
#include <cassert>

template<class T>
class MyStack {
 public:
  explicit MyStack(int size);
  ~MyStack();
  MyStack(const MyStack<T>&);
  int getMyStackSize() const;
  int getUpper() const;
  T* getPtr() const;
  void push(const T&);
  void pop();
  void printMyStack();
  T isEmpty() const;
  T isFull() const;
  T get() const;
 private:
  int size;
  int upper;
  T* store;
};

template<class T>
MyStack<T>::MyStack(int _size) :
  size(_size), upper(0) {
  store = new T[size]; }

template<class T>
MyStack<T>::MyStack(const MyStack <T>& otherStack) :
  size(otherStack.getMyStackSize()) {
  store = new T[size];
  upper = otherStack.getUpper;
  for (int ix = 0; ix < upper; ix++)
    store[ix] = otherStack.getPtr()[ix]; }

template<class T>
MyStack<T>::~MyStack() {
  delete[] store; }

template <class T>
int MyStack<T>::getMyStackSize() const {
  return size; }

template <class T>
int MyStack<T>::getUpper() const {
  return upper; }

template <class T>
S* MyStack<T>::getPtr() const {
  return store; }

template <typename T>
void MyStack<T>::push(const T& value) {
  assert(upper < size);
  store[upper++] = value; }

template <typename T>
void MyStack<T>::pop() {
  assert(upper > 0);
  store[--upper]; }

template <typename T>
void MyStack<T>::printMyStack() {
  for (int ix = upper - 1; ix >= 0; ix--)
    std:: cout << store[ix] << " "; }

template <typename T>
S MyStack<T>::isEmpty() const {
  if (upper == 0) return 1;
  return 0; }

template <typename T>
S MyStack<T>::isFull() const {
  if (upper == size) return 1;
  return 0; }

template <typename T>
S MyStack<T>::get() const {
  if (upper != 0)
  return store[upper - 1]; }

#endif  // INCLUDE_MYSTACK_H_
