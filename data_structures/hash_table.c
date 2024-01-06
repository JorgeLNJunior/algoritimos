#include "hash_table.h"
#include <stdio.h>

char *dummy_key = "<dummy>";
unsigned int const DEFAULT_TABLE_CAPACITY = 100;

HashTable *hash_table_create(const size_t capacity)
{
  HashTable *table = malloc(sizeof(HashTable));
  if(table == NULL) exit(1);

  table->data = malloc(sizeof(HashTableItem*) * capacity);

  for(size_t index = 0; index < capacity; ++index)
  {
    table->data[index] = NULL;
  }

  table->capacity = capacity;
  table->size = 0;
  return table;
}

void hash_table_free(HashTable *table)
{
  for(size_t index = 0; index < table->capacity; ++index)
  {
    free(table->data[index]);
  }
  free(table);
}

int hash(const char *key, size_t table_capacity)
{
  unsigned long hash = 2166136261;
  unsigned long const fnv_prime = 16777619;

  for(size_t index = 0; key[index] != '\0'; index++)
  {
    hash = hash ^ key[index];
    hash = (hash * fnv_prime);
  }

  return hash % table_capacity;
}

void hash_table_add(HashTable *table, char *key, char *value)
{
  unsigned int const position = hash(key, table->capacity);

  if(table->data[position] == NULL)
  {
    HashTableItem *item = malloc(sizeof(HashTableItem));
    item->key = key;
    item->value = value;
    table->data[position] = item;
    table->size = table->size + 1;
    return;
  }

  if(strcmp(table->data[position]->key, key)) {
    table->data[position]->value = value;
    return;
  }

  for(size_t index = position + 1; index < table->capacity; ++index)
  {
    if(table->data[index] == NULL) {
      HashTableItem *item = malloc(sizeof(HashTableItem));
      item->key = key;
      item->value = value;
      table->data[index] = item;
      table->size = table->size + 1;
      break;
    }
    if(strcmp(table->data[index]->key, dummy_key) == 0) {
      HashTableItem *item = malloc(sizeof(HashTableItem));
      item->key = key;
      item->value = value;
      table->data[index] = item;
      table->size = table->size + 1;
      break;
    }
  }
}

bool hash_table_key_exists(const HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->capacity);

  if(table->data[position] == NULL) return false;
  if(strcmp(table->data[position]->key, key) == 0) return true;

  for(int index = position + 1; index < table->capacity; ++index)
  {
    if(table->data[index] == NULL) return false;
    if(strcmp(table->data[index]->key, key) == 0) return true;
  }

  return false;
}

char *hash_table_get(const HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->capacity);

  if(table->data[position] == NULL) return NULL;
  if(strcmp(table->data[position]->key, key) == 0) return table->data[position]->value;

  for(int index = position + 1; index < table->capacity; ++index)
  {
    if(table->data[index] == NULL) return NULL;
    if(strcmp(table->data[index]->key, key) == 0) return table->data[index]->value;
  }

  return NULL;
}

void hash_table_remove(HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->capacity);

  if(table->data[position] == NULL) return;
  if(strcmp(table->data[position]->key, key) == 0)
  {
    table->data[position]->key = dummy_key;
    table->size = table->size - 1;
    return;
  }

  for(int index = position + 1; index < table->capacity; ++index)
  {
    if(table->data[index] == NULL) return;
    if(strcmp(table->data[index]->key, key) == 0) {
      table->data[index]->key = dummy_key;
      table->size = table->size - 1;
      break;
    }
  }
}
