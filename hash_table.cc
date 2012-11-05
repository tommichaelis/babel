#include "hash_table.h"

namespace
{

template <class K, class V>
int Bucket<K, V>::add_entry(K key, V value)
{
  if( num_entries_ >= size_ )
  {
    Entry<K, V>* temp_entries = entries;
    entries_ = new Entry<K, V>[2*size_];
    size_ = 2*size_;

    for( int i = 0; i < num_entries_; i += 1 )
    {
      entries_[i] = temp_entries[i];
    }

  }

  Entry entry;
  entry.key = key;
  entry.value = value;
  entries[num_entries_] = entry;
  num_entries += 1;

  return 1;
}

template <class K, class V>
V Bucket<K, V>::get_entry(K key)
{
  V value = NULL;

  for(int i = 0; i < num_entries_; i += 1)
  {
    if( entries[i].key == key )
    {
      value = entries[i].value;
    }
  }

  return value;
}

template <class K, class V>
int Bucket<K, V>::delete_entry(K key)
{
  boolean deleted = false;
  for(int i = 0; i < num_entries_; i++)
  {
    if(deleted)
    {
      entries[i-1] = entries[i];
    }

    if(entries[i].key == key)
    {
      deleted = true;
      num_entries_ -= 1;
    }
  }

}
