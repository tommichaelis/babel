#ifndef BABEL_HASH_TABLE_H
#define BABEL_HASH_TABLE_H

namespace hash_table
{

template <class K, class V>
struct Entry
{
  K key;
  V value;
}

template <class K, class V>
class Bucket
{
 public:
  Bucket(){}
  
  int add_entry(K, V);
  int delete_entry(K);
  V get_entry(K);C

 private:
  Entry<K,V>* entries_ = new Entry<K,V>[1]; 
  int size_ = 1;
  int num_entries_ = 0;
}

template <class K, class V>
class HashTable
{
 public:
  HashTable(int size)
  {
    buckets_ = new Bucket<K, V>[size]
  }

  int add_entry(K, V);
  int delete_entry(K);
  V get_entry(K);

 private:
  Bucket<K,V>* buckets_;
}

}

#endif
