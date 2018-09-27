// TITLE: Song.h
// AUTHOR: Josh Winton
// PURPOSE: Header file for song class
// DATE: 9/25/18

#ifndef SONG_H_
#define SONG_H_
#include <string>

class Song {
public:
  Song(); //default constructor
  Song(const std::string &title, const std::string &author = "",
       const std::string &album = "");

  // mutators for song change private data
  void setTitle(std::string title); //"set" in setTitle here means "give a
                                    // value" and has nothing
                                    // to do with the Set class. Similarly for
                                    // setAuthor and setAlbum
  void setAuthor(std::string author);
  void setAlbum(std::string album);

  // accessors for song return private data
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getAlbum() const;
  friend bool operator==(const Song &lhs, const Song &rhs);

private:
  std::string title_;
  std::string author_;
  std::string album_;
};
#include "Song.cpp"
#endif
