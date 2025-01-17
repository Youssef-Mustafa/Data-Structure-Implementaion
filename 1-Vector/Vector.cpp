#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
private:
  int *arr{nullptr}; // Pointer to the dynamic array
  int size{0};       // Current size of the vector
  int capacity{};    // Current capacity of the vector

public:
  // Constructor to initialize the vector with a given size
  Vector(int size) : size(size)
  {
    if (size < 0)
      size = 1;                // Ensure size is at least 1
    capacity = size + 10;      // Set capacity to size + 10
    arr = new int[capacity]{}; // Allocate memory for the array
  }

  // Destructor to clean up memory
  ~Vector()
  {
    delete[] arr;  // Free the allocated memory
    arr = nullptr; // Set pointer to nullptr
  }

  // Get element at a specific index
  int get(int idx)
  {
    assert(0 <= idx && idx < size); // Ensure index is valid
    return arr[idx];                // Return the element at the index
  }

  // Set element at a specific index
  void set(int idx, int value)
  {
    assert(0 <= idx && idx < size); // Ensure index is valid
    arr[idx] = value;               // Set the value at the index
  }

  // Print all elements in the vector
  void print()
  {
    for (int i = 0; i < size; i++)
      cout << arr[i] << " "; // Print each element
    cout << "\n";            // New line after printing all elements
  }

  // Find the index of the first occurrence of a value
  int find(int value)
  {
    for (int i = 0; i < size; i++)
      if (arr[i] == value) // If value is found, return its index
        return i;
    return -1; // Return -1 if value is not found
  }

  // Get the first element of the vector
  int get_front()
  {
    return arr[0]; // Return the first element
  }

  // Get the last element of the vector
  int get_back()
  {
    return arr[size - 1]; // Return the last element
  }

  // Expand the capacity of the vector when it's full
  void expand_capacity()
  {
    capacity *= 2; // Double the capacity
    cout << "Expanded Capacity to " << capacity << endl;

    // Create a new array with the expanded capacity
    int *arr2 = new int[capacity];
    for (int i = 0; i < size; i++)
      arr2[i] = arr[i]; // Copy existing elements to the new array

    swap(arr, arr2); // Swap the old array with the new one
    delete[] arr2;   // Delete the temporary array
  }

  // Add an element to the end of the vector
  void push_back(int value)
  {
    if (size == capacity) // If capacity is full, expand it
      expand_capacity();
    arr[size++] = value; // Add the value and increment size
  }

  // Insert an element at a specific index
  void insert(int idx, int value)
  {
    assert(0 <= idx && idx < size); // Ensure index is valid
    if (size == capacity)           // If capacity is full, expand it
      expand_capacity();

    if (idx == size) // If inserting at the end, use push_back
      push_back(value);
    else
    {
      // Shift elements to the right to make space
      for (int i = size; i > idx; i--)
        arr[i] = arr[i - 1];
      arr[idx] = value; // Insert the value at the specified index
      size++;           // Increment size
    }
  }

  // Rotate the vector to the right by one position
  void right_rotate()
  {
    int temp = arr[size - 1]; // Save the last element
    for (int i = size - 1; i > 0; i--)
      arr[i] = arr[i - 1]; // Shift elements to the right
    arr[0] = temp;         // Place the last element at the first position
  }

  // Rotate the vector to the right by a specific number of steps
  void right_rotate(int step)
  {
    if (step > size)
      step = step % size; // Handle cases where step is greater than size
    while (step--)
    {
      right_rotate(); // Rotate by one step at a time
    }
  }

  // Rotate the vector to the left by one position
  void left_rotate()
  {
    int temp = arr[0]; // Save the first element
    for (int i = 0; i < size - 1; i++)
      arr[i] = arr[i + 1]; // Shift elements to the left
    arr[size - 1] = temp;  // Place the first element at the last position
  }

  // Remove and return the element at a specific index
  int pop(int idx)
  {
    assert(0 <= idx && idx < size); // Ensure index is valid
    int value = arr[idx];           // Store the element to be removed
    for (int i = idx; i < size - 1; i++)
    {
      arr[i] = arr[i + 1]; // Shift elements left to fill the gap
    }
    size--;       // Decrement size
    return value; // Return the removed element
  }
};

int main()
{
  // Create a vector with initial size of 5
  Vector vec(5);

  // Set values at specific indices
  vec.set(0, 10);
  vec.set(1, 20);
  vec.set(2, 30);
  vec.set(3, 40);
  vec.set(4, 50);

  // Print the vector
  cout << "Vector after setting values: ";
  vec.print(); // Expected output: 10 20 30 40 50

  // Get and print a specific element
  cout << "Element at index 2: " << vec.get(2) << endl; // Expected output: 30

  // Find an element's index
  int index = vec.find(40);
  cout << "Index of value 40: " << index << endl; // Expected output: 3

  // Get front and back elements
  cout << "First element: " << vec.get_front() << endl; // Expected output: 10
  cout << "Last element: " << vec.get_back() << endl;   // Expected output: 50

  // Add a new element to the end (push_back)
  vec.push_back(60);
  cout << "Vector after push_back(60): ";
  vec.print(); // Expected output: 10 20 30 40 50 60

  // Insert an element at a specific index
  vec.insert(2, 25);
  cout << "Vector after insert(2, 25): ";
  vec.print(); // Expected output: 10 20 25 30 40 50 60

  // Rotate the vector right by one step
  vec.right_rotate();
  cout << "Vector after right_rotate(): ";
  vec.print(); // Expected output: 60 10 20 25 30 40 50

  // Rotate the vector right by 3 steps
  vec.right_rotate(3);
  cout << "Vector after right_rotate(3): ";
  vec.print(); // Expected output: 40 50 60 10 20 25 30

  // Rotate the vector left by one step
  vec.left_rotate();
  cout << "Vector after left_rotate(): ";
  vec.print(); // Expected output: 50 60 10 20 25 30 40

  // Pop an element at a specific index and print the removed value
  int popped_value = vec.pop(3);
  cout << "Popped value at index 3: " << popped_value << endl; // Expected output: 20
  cout << "Vector after pop(3): ";
  vec.print(); // Expected output: 50 60 10 25 30 40

  return 0;
}
