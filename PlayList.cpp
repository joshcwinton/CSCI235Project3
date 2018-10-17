#include "PlayList.h"
#include <iostream>

PlayList::PlayList(){
  head_ptr_ = nullptr;
  tail_ptr_ = nullptr;
  item_count_ = 0;
}

PlayList::PlayList(const Song& a_song){
  add(a_song);
}

PlayList::~PlayList(){
  unloop();
}

bool PlayList::add(const Song& new_song) {
  if(contains(new_song)){
    return false;
  } else {
    Node<Song>* new_node_ptr = new Node<Song>;
    new_node_ptr->setItem(new_song);
    new_node_ptr->setNext(nullptr);
    if(item_count_ == 0){
      head_ptr_ = new_node_ptr;
      tail_ptr_ = new_node_ptr;
    } else {
      tail_ptr_->setNext(new_node_ptr);
      tail_ptr_ = tail_ptr_->getNext();
    }
    item_count_++;
    return true;
  }
}

bool PlayList::remove(const Song& a_song) {
  Node<Song> *prev_ptr;
  Node<Song> *my_ptr = getPointerTo(a_song, prev_ptr);
  if(my_ptr == nullptr){
    return 0;
  } else {
    if(head_ptr_ == my_ptr){
      head_ptr_=my_ptr->getNext();
      item_count_--;
      return true;
    } else if(tail_ptr_ == my_ptr){
      prev_ptr->setNext(nullptr);
      tail_ptr_ = prev_ptr;
      item_count_--;
      return true;
    } else {
      prev_ptr->setNext(my_ptr->getNext());
      item_count_--;
      return true;
    }
  }
  return 0;
}

void PlayList::loop(){
  if(tail_ptr_ != nullptr){
    tail_ptr_->setNext(head_ptr_);
  }
}

void PlayList::unloop(){
  if(tail_ptr_ != nullptr){
    tail_ptr_->setNext(nullptr);
  }
}

void PlayList::displayPlayList(){
  std::vector<Song> display_vector = toVector();
  for(int i = 0; i < display_vector.size(); i++){
    std::cout << "* Title: " << display_vector[i].getTitle() << "* Author: " << display_vector[i].getAuthor() << "* Album: " << display_vector[i].getAlbum() << " *" << std::endl;
  }
  std::cout << "End of playlist" << '\n';
}

 // Pointer to last node
Node<Song>* PlayList::getPointerToLastNode() const {
  Node<Song> *current = head_ptr_;
  Node<Song> *previous = nullptr;
  while (current != nullptr) {
      previous = current;
      current = current->getNext();
  }
  return previous;
}

//
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
  Song my_target = target;
  Node<Song> *current = head_ptr_;
  Node<Song> *previous = nullptr;
  while (current != nullptr) {
      if(current->getItem() == my_target){
        previous_ptr = previous;
        return current;
      }
      previous = current;
      current = current->getNext();
  }
  return nullptr;
}
