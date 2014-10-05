// Dequeue.cpp : Defines the entry point for the console application.

/// Test Function


#include "stdafx.h"

#include "Dequeue.h"
#include "Dequeue.cpp"
#include <iostream>
#include<string>



int _tmain(int argc, _TCHAR* argv[])
{
	int operation = 0;
	int value;

	typedef Dequeue<int> Queue;
	Queue queue;

	do
	{
		std::cout << "bitte operation eingeben, 1: addfirst; 2: addlast; 3 : remove first, 4 remove last, 5 size 6 empty;\n";
		std::cin >> operation;
		std::cout << "bitte wert eingeben:\n";
		std::cin >> value;
		std::cout << "\n";
		std::cout << "\n";
		switch (operation)
		{
		case 1:
		{
				  queue.addFirst(value);
				  break;
		}
		case 2:
		{

				  queue.addLast(value);
				  break;
		}
		case 3:
		{

				  int item = queue.removeFirst();
				  std::cout << "Item is:\n";
				  std::cout << item;
				  std::cout << "\n";
				  std::cout << "\n";
				  break;
		}
		case 4:
		{

				  int item = queue.removeLast();
				  std::cout << "Item is:\n";
				  std::cout << item;
				  std::cout << "\n";
				  std::cout << "\n";
				  break;
		}
		case 5:
		{

				  std::cout << queue.size();
				  std::cout << "\n";
				  break;
		}
		case 6:
		{

				  //std::cout << queue->isEmpty();
				  break;
		}
		default:
		{
				   break;
		}
		}

			unsigned long i = 0;
			int* qarray = queue.getQueue();

			if (qarray != NULL)
			{
				do
				{
					std::cout << qarray[i];
					std::cout << "\n";
					++i;
				} while (i < queue.arraysize());

				std::cout << "\n";
				std::cout << "posBegin: ";
				std::cout << queue.getPosBegin();
				std::cout << "\n";
				std::cout << "posEnd: ";
				std::cout << queue.getPosEnd();
				std::cout << "\n";
			}

			
	} while (operation != 0);
			
	return 0;
}

