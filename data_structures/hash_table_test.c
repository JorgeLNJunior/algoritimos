#include "../libs/unity/unity.h"
#include "hash_table.h"

void test_create()
{
  HashTable *table = hash_table_create(DEFAULT_TABLE_CAPACITY);

  TEST_ASSERT_NOT_EMPTY(&table);
  TEST_ASSERT_NOT_EMPTY(&(table->data));

  hash_table_free(table);
}

void test_hash()
{
  int position = hash("key", DEFAULT_TABLE_CAPACITY);

  TEST_ASSERT_GREATER_THAN_UINT(0, position);
  TEST_ASSERT_LESS_THAN_UINT(DEFAULT_TABLE_CAPACITY, position);
}

void test_add()
{
  HashTable *table = hash_table_create(DEFAULT_TABLE_CAPACITY);
  char *key = "key";
  char *value = "value";

  unsigned int position = hash(key, DEFAULT_TABLE_CAPACITY);

  hash_table_add(table, key, value);

  TEST_ASSERT_EQUAL_STRING(key, table->data[position]->key);
  TEST_ASSERT_EQUAL_STRING(value, table->data[position]->value);

  hash_table_free(table);
}

void test_key_exists()
{
  HashTable *table = hash_table_create(DEFAULT_TABLE_CAPACITY);
  char *key = "key";
  hash_table_add(table, key, "value");

  bool exists = hash_table_key_exists(table, key);

  TEST_ASSERT_EQUAL_UINT(1, exists);

  char const *invalid_key = "invalid_key";
  exists = hash_table_key_exists(table, invalid_key);

  TEST_ASSERT_EQUAL_UINT(0, exists);

  hash_table_free(table);
}

void test_get()
{
  HashTable *table = hash_table_create(DEFAULT_TABLE_CAPACITY);
  char *key = "key";
  char *value = "value";

  hash_table_add(table, key, value);

  char const *result = hash_table_get(table, key);

  TEST_ASSERT_EQUAL_STRING(value, result);
  hash_table_free(table);
}

void test_remove()
{
  HashTable *table = hash_table_create(DEFAULT_TABLE_CAPACITY);
  char *key = "key";

  hash_table_add(table, key, "value");

  hash_table_remove(table, key);

  char *result = hash_table_get(table, key);
  TEST_ASSERT_NULL(result);

  hash_table_free(table);
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_create);
  RUN_TEST(test_hash);
  RUN_TEST(test_add);
  RUN_TEST(test_key_exists);
  RUN_TEST(test_get);
  RUN_TEST(test_remove);

  UNITY_END();
}
