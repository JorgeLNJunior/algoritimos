# insertion sort
gcc algorithms/insertion_sort_test.c algorithms/insertion_sort.c libs/unity/unity.c -o bin/insertion_sort_test
./bin/insertion_sort_test

# array
gcc data_structures/array_test.c data_structures/array.c libs/unity/unity.c -o bin/array_test
./bin/array_test

# linked list
gcc data_structures/linked_list_test.c data_structures/linked_list.c libs/unity/unity.c -o bin/linked_list_test
./bin/linked_list_test