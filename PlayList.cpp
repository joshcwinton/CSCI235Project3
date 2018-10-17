#include "PlayList.h"

PlayList::PlayList(){
  head_ptr_ = nullptr;
  tail_ptr_ = nullptr;
}

PlayList::PlayList(const Song& a_song){
  Node<Song>* new_node = new Node<Song>(a_song, nullptr);
  tail_ptr_ = new_node;
  tail_ptr_->setNext(nullptr);
  item_count_++;
}

PlayList::PlayList(const PlayList& a_play_list){
  // STUB
}

PlayList::~PlayList(){
  // STUB
}

bool PlayList::add(const Song& new_song) {
  if(!contains(new_song)){
    Node<Song>* next_node_ptr = new Node<Song>(new_song, nullptr);
    tail_ptr_->setNext(next_node_ptr);
    tail_ptr_=next_node_ptr;
    item_count_++;
    return true;
  }
  return false;
}

bool PlayList::remove(const Song& a_song) {
  // STUB
  return 0;
}

void PlayList::loop(){
  // STUB
}

void PlayList::unloop(){
  // STUB
}

void PlayList::displayPlayList(){
  // STUB
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
  std::cout << "im working" << '\n';
  Song my_target = target;
  Node<Song> *current = head_ptr_;
  Node<Song> *previous = nullptr;
  while (current != nullptr) {
      if(current->getItem() == my_target){
        return current;
      }
      previous = current;
      current = current->getNext();
  }
  return current;
}
