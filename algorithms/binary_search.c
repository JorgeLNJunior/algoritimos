int get_mid_index(int start_index, int end_index) {
  return (start_index + end_index) / 2;
}

int binary_search(int *arr, int value, int start_index, int end_index) {
  int mid = get_mid_index(start_index, end_index);

  if (arr[mid] == value) return mid;
  if (start_index == end_index) return -1;  // is not in the array.
  if (arr[mid] < value) return binary_search(arr, value, mid + 1, end_index);
  if (arr[mid] > value) return binary_search(arr, value, start_index, mid - 1);

  return -1;
}
