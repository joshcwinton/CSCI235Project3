// Title: PlayList.cpp
// Author: Josh Winton
// Purpopse: Function definitions for playlist class
// Created: 10/17/18

#include "PlayList.h"
#include <iostream>

// default constructor, sets pointers and item_count_ to base values
PlayList::PlayList() {
  head_ptr_ = nullptr;
  tail_ptr_ = nullptr;
  item_count_ = 0;
}

// PlayList::add takes care of starting a playlist with one item
PlayList::PlayList(const Song &a_song) { add(a_song); }

// destructor unloops to deallocate properly
PlayList::~PlayList() { unloop(); }

// adds a new song to the end of the playlist if it isn't included already
bool PlayList::add(const Song &new_song) {
  // checks if song is already in playlist using contains from linked set
  // false if song is already in playlist
  if (contains(new_song)) {
    return false;
  } else {
    // note: I know there's another function that does this but I felt that
    // this way was more readable and helped me debug more easily
    Node<Song> *new_node_ptr =
        new Node<Song>;              // allocates memory for a new node
    new_node_ptr->setItem(new_song); // puts the new song in it
    new_node_ptr->setNext(nullptr);  // marks node as the end of the chain
    // case if the playlist is empty, added item is the first and last
    if (item_count_ == 0) {
      head_ptr_ = new_node_ptr;
      tail_ptr_ = new_node_ptr;
    } else {
      // if the playlist is not empty, point the last item to it, then make it
      // the tail pointer
      tail_ptr_->setNext(new_node_ptr);
      tail_ptr_ = tail_ptr_->getNext();
    }
    item_count_++;
    return true;
  }
}

// removes an item from the playlist
bool PlayList::remove(const Song &a_song) {
  // Node to be passed by reference to getPointerTo
  // If getPointerTo can find the item, and its not the first, this points to
  // the item before it
  Node<Song> *prev_ptr;
  // stores the pointer to the node containing a_song, unless it's not in the
  // playlist, in which case it's just nullptr
  Node<Song> *my_ptr = getPointerTo(a_song, prev_ptr);
  if (my_ptr == nullptr) {
    return 0; // if the song isn't found, the function returns false
  } else {
    // if the song is the first item, head_ptr_ just get moves to the following
    // item.
    // note: this works even if it's the only item because then head_ptr_
    // becomes nullptr
    if (head_ptr_ == my_ptr) {
      head_ptr_ = my_ptr->getNext();
      item_count_--;
      return true;
      // if it's the last item, just set the previous item to point to nullptr
      // instead
      // note: this doesn't get checked if it's the only item, happens in the
      // last
      // if
    } else if (tail_ptr_ == my_ptr) {
      prev_ptr->setNext(nullptr);
      tail_ptr_ = prev_ptr;
      item_count_--;
      return true;
      // otherwise, just point, the previous item to the item that follows the
      // removed song
    } else {
      prev_ptr->setNext(my_ptr->getNext());
      item_count_--;
      return true;
    }
  }
  return 0;
}

// points the last item back to the first
void PlayList::loop() {
  if (tail_ptr_ != nullptr) {
    tail_ptr_->setNext(head_ptr_);
  }
}

// does the opposite of loop by pointing tail_ptr_ back to nullptr
void PlayList::unloop() {
  if (tail_ptr_ != nullptr) {
    tail_ptr_->setNext(nullptr);
  }
}

// uses toVector from LinkedSet to print playlist info
void PlayList::displayPlayList() {
  std::vector<Song> display_vector = toVector();
  for (int i = 0; i < display_vector.size(); i++) {
    std::cout << "* Title: " << display_vector[i].getTitle()
              << "* Author: " << display_vector[i].getAuthor()
              << "* Album: " << display_vector[i].getAlbum() << " *"
              << std::endl;
  }
  std::cout << "End of playlist" << '\n';
}

// Pointer to last node
Node<Song> *PlayList::getPointerToLastNode() const {
  // cylces through each node until it finds one that points to nullptr and
  // returns a pointer to it
  Node<Song> *current = head_ptr_;
  Node<Song> *previous = nullptr;
  while (current != nullptr) {
    previous = current;
    current = current->getNext();
  }
  return previous;
}

// returns a pointer to a song matching target, and changes previous_ptr pointer
// to reference the previous node
Node<Song> *PlayList::getPointerTo(const Song &target,
                                   Node<Song> *&previous_ptr) const {
  Song my_target = target;
  Node<Song> *current = head_ptr_;
  Node<Song> *previous = nullptr;
  // cycles through each node until it finds one whose song matches target,
  // which it returns
  // if nothing is found, nullptr is returned
  while (current != nullptr) {
    if (current->getItem() == my_target) {
      previous_ptr = previous;
      return current;
    }
    previous = current;
    current = current->getNext();
  }
  return nullptr;
}
