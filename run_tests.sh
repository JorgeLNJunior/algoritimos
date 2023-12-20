# insertion sort
gcc algorithms/insertion_sort_test.c algorithms/insertion_sort.c libs/unity/unity.c -o bin/insertion_sort_test
./bin/insertion_sort_test

# array
gcc data_structures/array_test.c data_structures/array.c libs/unity/unity.c -o bin/array_test
./bin/array_test

# linked list
gcc data_structures/linked_list_test.c data_structures/linked_list.c libs/unity/unity.c -o bin/linked_list_test
./bin/linked_list_test

# queue
gcc data_structures/queue_test.c data_structures/queue.c data_structures/linked_list.c libs/unity/unity.c -o bin/queue_test
./bin/queue_test

# hash_table
gcc data_structures/hash_table_test.c data_structures/hash_table.c data_structures/linked_list.c libs/unity/unity.c -o bin/hash_table_test
./bin/hash_table_test