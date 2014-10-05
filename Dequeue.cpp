#include "stdafx.h"
#include "Dequeue.h"
#include <iterator>


/// 05.10.2014
/// not fulley tested function
/// use of own risk


template <typename T>
Dequeue<T>::Dequeue()
{
	qsize = 0;

}

template <typename T>
Dequeue<T>::~Dequeue()
{
	
}


template <class T>
bool Dequeue<T>::isEmpty()
{
	return aArray[0] ? true : false;
	
}

template <class T>
unsigned long Dequeue<T>::size()
{
	return (posEnd-posBegin);
}


template <class T>
unsigned long Dequeue<T>::arraysize()
{
	return qsize;
}


template <class T>
void Dequeue<T>::addFirst(T item)
{
	if (qsize < UNSIGNEDLONGMAXSIZE)
	{

		if (qsize == 0)
		{
			initArray();
		}
		else
		{
			resizeAtBegin();
			posBegin -= 1;
		}
		qArray[posBegin] = item;
	}
}

template <class T>
void Dequeue<T>::addLast(T item)
{
	if (qsize < UNSIGNEDLONGMAXSIZE)
	{
		if (qsize == 0)
		{
			initArray();
		}
		else
		{
			resizeAtEnd();
		}
		if (qArray[posEnd] != NULL)
		{
			posEnd += 1;
		}
		qArray[posEnd] = item;
	}
}


template <class T>
T  Dequeue<T>::removeFirst()
{
	T item = NULL;
	if (qArray)
	{
		item = qArray[posBegin];
		qArray[posBegin] = NULL;
		posBegin += 1;

		removeAtBegin();	
	}
	return item;
}

template <class T>
T Dequeue<T>::removeLast()
{
	T item = NULL;
	if (qArray)
	{
		item = qArray[posEnd];
		qArray[posEnd] = NULL;
		if (posEnd > posBegin)
		{
			posEnd -= 1;
		}
	
		removeAtEnd();
	}
	return item;
}





template <class T>
void Dequeue<T>::resizeAtBegin()
{
	if (posBegin == 0)
	{
		int tempSize = qsize;
		T* tempArray = createTempArray();
		qsize = qsize * 2;
		createQArray(tempArray);
		//copy tempArray -> qArray, take care of position
		std::copy(tempArray,tempArray+tempSize,qArray + tempSize);
		// increase position for begin and for end
		posBegin += qsize/2;
		posEnd += qsize/2;
		tempArray = NULL;
		delete[] tempArray;
	}
}


template <class T>
void Dequeue<T>::resizeAtEnd()
{
	if (posEnd == (qsize-1))
	{
		int tempSize = qsize;
		T* tempArray = createTempArray();
		qsize = qsize * 2;
		createQArray(tempArray);
		//copy tempArray -> qArray, take care of position
		std::copy(tempArray, tempArray+tempSize, qArray);
		tempArray = NULL;
		delete[] tempArray;
	}
}


template <class T>
void Dequeue<T>::removeAtBegin()
{
	if ((posBegin == qsize / 2) && (qsize > INITIALSIZE))
	{
		int tempsize = qsize;
		T* tempArray = createTempArray();
		qsize /= 2;
		createQArray(tempArray);
		std::copy(tempArray + qsize, tempArray + tempsize, qArray);
		// increase position for begin and for end
		posBegin = 0;
		posEnd = posEnd - qsize + 1;
		tempArray = NULL;
		delete[] tempArray;
	}
}

template <class T>
void Dequeue<T>::removeAtEnd()
{
	if ((posEnd <= qsize / 2) && (qsize > INITIALSIZE))
	{
		int tempsize = qsize;
		T* tempArray = createTempArray();
		qsize /= 2;
		createQArray(tempArray);
		std::copy(tempArray, tempArray + qsize, qArray);

		tempArray = NULL;
		delete[] tempArray;
	}
}


template <class T>
void Dequeue<T>::initArray()
{
	qsize = INITIALSIZE;
	qArray = (T*)new Dequeue<T>[INITIALSIZE];
	std::fill(qArray, qArray + qsize, NULL);
	posBegin = 0;
	posEnd = 0;
}


template <class T>
T* Dequeue<T>::createTempArray()
{
	T* tempArray = new T[qsize];
	tempArray = qArray;
	qArray = NULL;
	delete[] qArray;
	return tempArray;
}


template <class T>
void Dequeue<T>::createQArray(T* tempArray)
{
	qArray = (T*)new Dequeue<T>[qsize];
	std::fill(qArray, qArray + qsize, NULL);
}

template <class T>
T* Dequeue<T>::getQueue()
{
	return qArray;
}


template <class T>
unsigned long Dequeue<T>::getPosBegin()
{
	return posBegin;
}

template <class T>
unsigned long Dequeue<T>::getPosEnd()
{
	return posEnd;
}




