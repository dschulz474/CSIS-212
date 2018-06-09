//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file  HashedDictionary.cpp */

// Separate chaining resolves collisions

// PARTIALLY COMPLETE
#include "HashedDictionary.h"
#include <string>
#ifndef HASHED_DICTIONARY_CPP
#define HASHED_DICTIONARY_CPP

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	for (int index = 0; index < TABLE_SIZE; index++)
		hashTable[index] = nullptr;
	numofItems = 0;
}

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
	clear();
}

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& sKey) const
{
	int x = 0;
	for (int i = 0; i < sKey.size(); i++)
		x += sKey[i];
	return x % TABLE_SIZE;
}

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   // Create entry to add to dictionary
   HashedEntry<KeyType, ItemType>* entryToAddPtr =
                  new HashedEntry<KeyType, ItemType>(newItem, searchKey);
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   
   // Add the entry to the chain at itemHashIndex
   if (hashTable[itemHashIndex] == nullptr)
   {
      hashTable[itemHashIndex] = entryToAddPtr;
   }
   else
   {
      entryToAddPtr->setNext(hashTable[itemHashIndex]);
      hashTable[itemHashIndex] = entryToAddPtr;
   } // end if
   numofItems++;
   return true;
} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
   bool itemFound = false;
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   if (hashTable[itemHashIndex] != nullptr)
   {
      // Special case - first node has target
      if (searchKey == hashTable[itemHashIndex]->getKey())
      {
         HashedEntry<KeyType, ItemType>* entryToRemovePtr = hashTable[itemHashIndex];
         hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
         delete entryToRemovePtr;
		 numofItems--;
         entryToRemovePtr = nullptr; // For safety
         itemFound = true;
      }
      else // Search the rest of the chain
      {
         HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
         HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
         while ((curPtr != nullptr) && !itemFound )
         {
            // Found item in chain so remove that node
            if (searchKey == curPtr->getKey())
            {
               prevPtr->setNext(curPtr->getNext());
               delete curPtr;
               curPtr = nullptr; // For safety
               itemFound = true;
            }
            else // Look at next entry in chain
            {
               prevPtr = curPtr;
               curPtr = curPtr->getNext();
            } // end if
         } // end while
		 //decrement numofitems if itemFound is true
		 if (itemFound)
			 numofItems--;
      } // end if
   } // end if
   
   return itemFound;
} // end remove

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != nullptr)
			return false;
	}
	return true;
}

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
	return numofItems;
}

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
	for (int x = 0; x < TABLE_SIZE; x++)
	{
		HashedEntry<KeyType, ItemType>* ptr = hashTable[x];
		while (ptr != nullptr)
		{
			hashTable[x] = ptr->getNext();
			ptr->setNext(nullptr);
			delete ptr;
			ptr = hashTable[x];
		}
	}
}

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const throw(NotFoundException)
{
	int itemHashIndex = getHashIndex(searchKey);
	HashedEntry<KeyType, ItemType> *ptr = hashTable[itemHashIndex];
	if (ptr != nullptr)
	{
		while (ptr != nullptr)
		{
			if (searchKey == ptr->getKey())
			{
				return ptr->getItem();
			}
			ptr = ptr->getNext();
		}
	}
	else
		throw NotFoundException("Item does not exist.");
		
}

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	int itemHashIndex = getHashIndex(searchKey);
	bool itemFound = false;
	if (hashTable[itemHashIndex] != nullptr)
	{
		if (searchKey == hashTable[itemHashIndex]-> getKey())// if first node is target 
		{
			itemFound = true;
			return itemFound;
		}
		else
		{
			HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
			HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
			while ((curPtr != nullptr) && !itemFound)
			{
				if (searchKey == curPtr->getKey())// return true if curPtr is target 
				{
					itemFound = true;
					return itemFound;
				}
				else//otherwise move on to next node
				{
					prevPtr = curPtr;
					curPtr = curPtr->getNext();
				}
			}
		}
	}//if target is not found return false
    return false;
}

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) 
{
    int x = 0;
	int y = 0;
	int ageAverage = 0;
	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != nullptr)
		{
			x = hashTable[i]->getItem();
			ageAverage += x;
			cout << "Slot #" << i;
			cout << " "<<hashTable[i]->getKey() << " ";
			visit(x);
		}
	}
	cout << "Average Age is: " << ageAverage / getNumberOfItems() << endl;
}

//HashedDictionary<std::string, int> xyz;


#endif
