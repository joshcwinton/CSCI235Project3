// TITLE: Song.cpp
// AUTHOR: Josh Winton
// PURPOSE: Function definitions for Song class
// DATE: 9/25/18

#include "Song.h"
#include <iostream>

// default constructor
Song::Song() {
  std::string title_;
  std::string author_;
  std::string album_ ;
}

// paramaterized constructor
Song::Song(const std::string &title, const std::string &author,
           const std::string &album) {
  title_ = title;
  author_ = author;
  album_ = album;
}

// mutuator function for title_
void Song::setTitle(std::string title) { title_ = title; }

// mutuator function for author_,
void Song::setAuthor(std::string author) { author_ = author; }

// mutuator function for album_,
void Song::setAlbum(std::string album) { album_ = album; }

// accessor function for title_
std::string Song::getTitle() const { return title_; }

// accessor function for author_
std::string Song::getAuthor() const { return author_; }

// accessor function for album_
std::string Song::getAlbum() const { return album_; }

// overloaded == checks if two songs are the same
bool operator==(const Song &lhs, const Song &rhs) {
  if ((lhs.getTitle() == rhs.getTitle()) &&
      (lhs.getAuthor() == rhs.getAuthor()) &&
      (lhs.getAlbum() == rhs.getAlbum())) {
    return true;
  }
  return false;
}
