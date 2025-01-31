#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(head_ == NULL){
    head_ = new Item();
    head_->val[9] = val;
    head_->last = 10;
    head_->first = 9;
    tail_ = head_;
    size_ = 1;
  }
  else{
    if(tail_->last == ARRSIZE){
      Item* newTail = new Item();
      tail_->next = newTail;
      newTail->prev = tail_;
      tail_ = newTail;
      tail_->val[0] = val;
      tail_->last = 1;
    }
    else{
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
    size_++;
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    head_ = new Item();
    head_->val[0] = val;
    head_->last = 1;
    tail_ = head_;
    size_ = 1;
  }
  else{
      if(head_->first == 0){
        Item* newHead = new Item();
        newHead->next = head_;
        head_->prev = newHead;
        head_ = newHead;
        head_->val[9] = val;
        head_->last = 10;
        head_->first = 9;
    }
    else{
      head_->val[head_->first - 1] = val;
      head_->first--;
    }
    size_++;
  }
}

void ULListStr::pop_back(){
  tail_->last++;
  if(tail_->first == tail_->last){
    if(tail_->prev != NULL){
      tail_ = tail_->prev;
    }
    
    delete tail_->next;
  }
  size_--;
  if(size_ == 0){
    head_ = NULL;
    tail_ = NULL;
  }
}

void ULListStr::pop_front(){
  head_->first++;
  if(head_->first == head_->last){
    if(head_->next != NULL){
      head_ = head_->next;
    }
    delete head_->prev;
  }
  size_--;
  if(size_ == 0){
    head_ = NULL;
    tail_ = NULL;
  }
}

std::string const & ULListStr::back() const{
  if(tail_ != NULL){
    return tail_->val[tail_->last];
  }
  return NULL;
}

std::string const & ULListStr::front() const{
    if(head_ != NULL){
    return head_->val[head_->first];
  }
  return NULL;
  
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_ || loc < 0){
    return NULL;
  }
  Item* current = head_;
  while(loc >= (current->last - current->first)){
    loc -= (current->last - current->first);
    current = current->next;
  }
  return &current->val[loc + current->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
