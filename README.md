# C implementation of a Linked List with Sentinel Node

The main goal of this implementation is to ensure that any kind of data can be preserved in the list, while respecting all the API conventions. As a student, it is really important to practice what is taught in class, so this is a way I found to be proactive in the construction of knowledge.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Functions](#functions)
- [Code Explanation](#code-explanation)
- [License](#license)

## Introduction

A linked list is a fundamental data structure in computer science, consisting of nodes where each node contains data and a reference (or pointer) to the next and previous node in the sequence.

In this implementation, we use a sentinel node at the beginning of the list to avoid special handling of empty lists or edge cases, such as inserting at the head or deleting the head. The sentinel node helps simplify the code and improves readability and maintainability.

## Features
- **Sentinel Node**: The list uses a sentinel node to simplify boundary conditions.
- **Insert**: Insert nodes at the front or rear of the list.
- **Remove**: Remove nodes from the front or rear of the list.
- **Data Handling**: Handles data of arbitrary size, using dynamic memory allocation for each node's data.
- **Memory Management**: Ensures proper memory management by freeing node data and the list structure when no longer needed.

## Functions

### `initialize(unsigned data_size)`
Creates a new linked list with a sentinel node. The `data_size` parameter specifies the size of data that each node will hold.

### `insert_front(List *l, void* data)`
Inserts a new node with the given data at the front of the list.

### `insert_rear(List *l, void* data)`
Inserts a new node with the given data at the rear of the list.

### `remove_front(List *l, void* data_removed)`
Removes the first node from the list and stores its data in `data_removed`. If the list is empty, it returns `false`.

### `remove_rear(List *l, void* data_removed)`
Removes the last node from the list and stores its data in `data_removed`. If the list is empty, it returns `false`.

### `destroy(List *l)`
Frees all the nodes and the sentinel node, and then frees the list itself.

## Code Explanation

### Sentinel Node
The sentinel node is a dummy node used to simplify the code and avoid special cases when manipulating the list. The sentinel node’s `next` and `prev` pointers point to the sentinel itself when the list is empty. This design eliminates the need for checking whether the list is empty for each operation.

### Insertions and Removals
- **Insertion**: Nodes are inserted at the front or rear of the list. The sentinel node helps handle edge cases like an empty list.
- **Removal**: Nodes are removed from the front or rear of the list. The `data_removed` parameter is used to store the data of the node being removed.
- **Memory Management**: Proper memory allocation and deallocation is done for each node’s data and for the nodes themselves. The `destroy` function ensures that the list is properly cleaned up when it is no longer needed.

### Traversal and Data Copying
Each node in the list holds a pointer to the data, and data is copied into new nodes when they are inserted. This design ensures that the list can handle data of arbitrary size. Data is copied using `memcpy`, which ensures efficient copying of memory blocks.

### Edge Case Handling
- **Empty List**: The sentinel node ensures that the list is never empty from a logical standpoint, and operations like insertion and deletion are simplified.
- **Memory Leaks**: Memory is freed at each operation, and `destroy` ensures that all allocated memory is freed when the list is no longer needed.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

