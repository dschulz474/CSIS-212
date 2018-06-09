/** @file Node.cpp */

#ifndef ENTRY_CPP
#define ENTRY_CPP

#include "Entry.h" 
#include <cstddef>

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{
}  // end default constructor
 
template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType anItem, KeyType anKey):
item(anItem), searchKey(anKey)
{
}  // end constructor

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}  // end setItem

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& key) 
{
    searchKey = key;
}  // end setKey


template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
    return item;
}  // end getItem

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
    return searchKey;
}  // end getItem



template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandItem) const
{
	return searchKey == rightHandItem.searchKey;
}

template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const
{
	return searchKey > rightHandItem.searchKey;
}

#endif
