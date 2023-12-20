#include "hash_table.h"
#include <stdio.h>

char *dummy_key = "<dummy>";
unsigned int const DEFAULT_TABLE_SIZE = 100;

HashTable *hash_table_create(const size_t size)
{
  HashTable *table = malloc(sizeof(HashTable));
  if(table == NULL) exit(1);

  table->data = malloc(sizeof(HashTableItem*) * size);

  for(size_t index = 0; index < size; ++index)
  {
    table->data[index] = NULL;
  }

  table->size = size;
  return table;
}

void hash_table_free(HashTable *table)
{
  for(size_t index = 0; index < table->size; ++index)
  {
    free(table->data[index]);
  }
  free(table);
}

int hash(const char *key, size_t table_size)
{
  unsigned long hash = 2166136261;
  unsigned long const fnv_prime = 16777619;

  for(size_t index = 0; key[index] != '\0'; index++)
  {
    hash = hash ^ key[index];
    hash = (hash * fnv_prime);
  }

  return hash % table_size;
}

void hash_table_add(HashTable *table, char *key, char *value)
{
  unsigned int const position = hash(key, table->size);

  if(table->data[position] == NULL)
  {
    HashTableItem *item = malloc(sizeof(HashTableItem));
    item->key = key;
    item->value = value;
    table->data[position] = item;
    return;
  }

  if(strcmp(table->data[position]->key, key)) {
    table->data[position]->value = value;
    return;
  }

  for(size_t index = position + 1; index < table->size; ++index)
  {
    if(table->data[index] == NULL) {
      HashTableItem *item = malloc(sizeof(HashTableItem));
      item->key = key;
      item->value = value;
      table->data[index] = item;
      break;
    }
  }
}

bool hash_table_key_exists(const HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->size);

  if(table->data[position] == NULL) return false;
  if(strcmp(table->data[position]->key, key) == 0) return true;

  for(int index = position + 1; index < table->size; ++index)
  {
    if(table->data[index] == NULL) return false;
    if(strcmp(table->data[index]->key, key) == 0) return true;
  }

  return false;
}

char *hash_table_get(const HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->size);

  if(table->data[position] == NULL) return NULL;
  if(strcmp(table->data[position]->key, key) == 0) return table->data[position]->value;

  for(int index = position + 1; index < table->size; ++index)
  {
    if(table->data[index] == NULL) return NULL;
    if(strcmp(table->data[index]->key, key) == 0) return table->data[index]->value;
  }

  return NULL;
}

void hash_table_remove(const HashTable *table, const char *key)
{
  unsigned int const position = hash(key, table->size);

  if(table->data[position] == NULL) return;
  if(strcmp(table->data[position]->key, key) == 0)
  {
    table->data[position]->key = dummy_key;
    return;
  }

  for(int index = position + 1; index < table->size; ++index)
  {
    if(table->data[index] == NULL) return;
    if(strcmp(table->data[index]->key, key) == 0) {
      table->data[index]->key = dummy_key;
      break;
    }
  }
}
