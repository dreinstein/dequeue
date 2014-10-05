#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <iterator>

/// 05.10.2014
/// not fulley tested function
/// use of own risk

template <class T>
class Dequeue
{

private:
	enum
	{
		INITIALSIZE = 4,
		UNSIGNEDLONGMAXSIZE = 4294967295  // max size for unsigned long
	};

	T  *qArray;
	void resizeAtBegin();
	void resizeAtEnd();
	void removeAtBegin();
	void removeAtEnd();
	unsigned long qsize;
	void initArray();
	T* createTempArray();
	void createQArray(T* tempArray);
	unsigned long posBegin;
	unsigned long posEnd;

public:
	Dequeue();                          // construct an empty deque
	~Dequeue();
	bool isEmpty();                   
	unsigned long size();             // return the number of items in the deque
	unsigned long arraysize();       // return the arraysize     
	void addFirst(T item);          // insert item at the front (posBegin)
	void addLast(T item);           // insert item at the end (posEnd)
	T removeFirst();                // delete and return the item at the front
	T removeLast();                 // delete and return the item at the end
	T* getQueue();					// gets the whole queue
	unsigned long getPosBegin();    // gets the firstPos (need it to test)
	unsigned long getPosEnd();		// gets the last Pos (need it to test)

};






