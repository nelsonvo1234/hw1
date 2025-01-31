/*
CSCI 104: Homework 1 Problem 1

Use this file to test yor split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/


#include <iostream>
#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
  std::cout << "started" << std::endl;
  Node* even = NULL;
  Node* odd = NULL;
  Node* in = new Node(0, NULL);
  std::cout << "initialized" << std::endl;
  for(int i = 1; i < 10; i++){
    Node* next = new Node(i, in);
    in = next;
  }
  std::cout << "filled in" << std::endl;
  split(in, odd, even);
  do{
    std::cout << odd -> value << std::endl;
    Node* temp = odd;
    odd = odd -> next;
    delete temp;
  }while(odd->next != NULL);
  do{
    std::cout << even -> value << std::endl;
    Node* temp = even;
    even = even -> next;
    delete temp;
  }while(even->next != NULL);
}
