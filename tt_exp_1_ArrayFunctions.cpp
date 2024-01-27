#include <iostream>

void insertElement(int arr[], int& size, int element, int position) {
    // Check if position is valid
    if (position < 0 || position > size) {
        std::cout << "Invalid position for insertion." << std::endl;
        return;
    }
    // Shift elements to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element
    arr[position] = element;
    // Increment the size of the array
    size++;

    std::cout << "Element inserted successfully." << std::endl;
}

void deleteElement(int arr[], int& size, int position) {
    // Check if position is valid
    if (position < 0 || position >= size) {
        std::cout << "Invalid position for deletion." << std::endl;
        return;
    }
    // Shift elements to fill the gap left by the deleted element
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrement the size of the array
    size--;
    std::cout << "Element deleted successfully." << std::endl;
}

int searchElement(const int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            // Element found, return its index
            return i;
        }
    }
    // Element not found, return -1
    return -1;
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size = 0;

    // Get the size of the array from the user
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Get array elements from the user
    std::cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Insert an element
    int ei, pos;
    std::cout << "Enter the element to insert: ";
    std::cin >> ei;
    std::cout << "Enter the position to insert (0-based index): ";
    std::cin >> pos;
    insertElement(arr, size, ei, pos);

    // Print the updated array
    std::cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Delete an element
    int pd;
    std::cout << "Enter the position to delete (0-based index): ";
    std::cin >> pd;
    deleteElement(arr, size, pd);

    // Print the updated array
    std::cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Search for an element
    int ele;
    std::cout << "Enter the element to search: ";
    std::cin >> ele;
    int index = searchElement(arr, size, ele);

    if (index != -1) {
        std::cout << "Element found at index " << index << "." << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
