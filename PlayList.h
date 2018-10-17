// #ifndef PLAY_LIST_H_
// #define PLAY_LIST_H_

#include "LinkedSet.h"
#include "Song.h"

#pragma once

class PlayList : public LinkedSet<Song>{
public:
  PlayList(); // default constructor
  PlayList(const Song& a__song); // paramaterized constructor
  PlayList(const PlayList& a_play_list):LinkedSet(a_play_list){ // copy constructor
    head_ptr_ = a_play_list.head_ptr_;
    tail_ptr_ = a_play_list.getPointerToLastNode();
  }
  ~PlayList(); // destructor
  bool add(const Song& new_song) override; // adds song to end of playlist
  bool remove(const Song& a_song) override; // overridden remove preserves order of songs
  void loop(); // looping the chain
  void unloop(); // unlooping the chain
  void displayPlayList(); // uses toVector to print playlist
private:
  Node<Song>* tail_ptr_; // Pointer to last node
  Node<Song>* getPointerToLastNode() const; // returns pointer to last node
  //
  Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const; // gets pointer to a node; used by remove
};
// #include "PlayList.cpp"
// #endif
