/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

/* Add a prototype for a helper function here if you need */
Node* pop(Node*& in);
void pushBack(Node* in, Node* to);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == NULL){
    return;
  }
  Node* current = pop(in);
  if(in->value % 2 == 0){
    if(evens != NULL){
      pushBack(current, evens);
    }
    else{
      evens = current;
      evens->next= NULL;
    }
  }
  else{
    if(odds != NULL){
      pushBack(current, odds);
    }
    else{
      evens = current;
      evens->next= NULL;
    }
  }
  split(in, odds, evens);

}

/* If you needed a helper function, write it here */

Node* pop(Node*& in){
  Node* node = in;
  in = in->next;
  return node;
}

void pushBack(Node* in, Node* to){
  if(to->next == NULL){
    to -> next = in;
    in -> next = NULL;
  }
  else{
    pushBack(in, to->next);
  }
}