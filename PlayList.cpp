#include "PlayList.h"

PlayList::PlayList(){

}

PlayList::PlayList(const Song& a_song){
  PlayList::add(a_song);
}

PlayList::PlayList(const PlayList& a_play_list){
  // STUB
}

PlayList::~PlayList(){
  // STUB
}

bool PlayList::add(const Song& new_song) {
  if(!contains(new_song)){
    // Add to end of chain: new node references null pointer;
    Node<Song>* next_node_ptr = new Node<Song>();
    next_node_ptr->setItem(new_song);
    tail_ptr_->setItem(next_node_ptr);
    next_node_ptr->setNext(nullptr);  // New node points to chain
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
  // STUB
}

//
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
  // STUB
}
