// Program 1 - MTF & Transpose List - CSS343A Wooyoung Kim - CDLinkedList class by David H. Kim

#ifndef CDLINKEDLIST_H_
#define CDLINKEDLIST_H_
#include <iostream>
#include <cmath>
using namespace std;

//node struct 
struct DListNode
{
  int item;
  DListNode *prev;
  DListNode *next;
};

class CDLinkedList 
{
public:
  CDLinkedList();
  CDLinkedList(const CDLinkedList &rhs);
  ~CDLinkedList();

  int getCurrentSize() const;
  bool isEmpty() const;

  bool add(int newEntry);
  bool remove(int anEntry);
  void clear();

  // This will search the entry from the list. Virtual so MTF & Transpose list overrides
  virtual bool contains(int anEntry);

  int getTraverseCount() const;        // return traverseCount
  int retrieve( const int index ); // retrieve the data by index. The first item is at index 0. 

  void resetTraverseCount();

protected:
  DListNode *dummy_header; // a dummy header
  int traverseCount = 0;
};
#endif