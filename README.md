<!-- Project Logo -->
<p align="center">
  <img src="docs/logo.png" alt="Generalised Data Structures Library Logo" width="180"/>
</p>

<h1 align="center">Generalised Data Structures Library</h1>

<p align="center">
  <b>A modern, extensible, and type-safe C++ library for linked list data structures</b>
</p>

<p align="center">
  <a href="https://github.com/yourusername/Generalised-Data-Structures-Library-/actions">
    <img src="https://github.com/yourusername/Generalised-Data-Structures-Library-/workflows/CI/badge.svg" alt="Build Status">
  </a>
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License">
  </a>
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg" alt="C++17">
</p>

---

## 📽️ Demo

<p align="center">
  <img src="docs/demo.gif" alt="Demo Animation" width="600"/>
</p>

<p align="center">
  <a href="https://youtu.be/your-demo-video-link">
    <img src="https://img.shields.io/badge/Watch%20Demo%20Video-YouTube-red?logo=youtube" alt="Demo Video">
  </a>
</p>

---

## 🚀 Overview

The **Generalised Data Structures Library** is a header-only, modern C++ library providing robust, reusable, and efficient implementations of linked list data structures.  
It is designed for both educational and production use, with a focus on type safety, exception safety, and extensibility.

---

## ✨ Features

- **Singly Linked List** (`SinglyLinkedList<T>`)
- **Doubly Linked List** (`DoublyLinkedList<T>`)
- **Singly Circular Linked List** (`SinglyCircularList<T>`)
- **Doubly Circular Linked List** (`DoublyCircularList<T>`)
- Fully templated and type-safe
- Exception-safe operations
- Consistent, intuitive API
- Header-only: easy integration
- Well-documented and tested
- Modern C++17 codebase

---

## 📂 Directory Structure

```
include/
  DataStructures.hpp
  SinglyLinkedList.hpp
  DoublyLinkedList.hpp
  SinglyCircularList.hpp
  DoublyCircularList.hpp
src/
  main.cpp
tests/
  test_linkedlists.cpp
docs/
  logo.png
  demo.gif
CMakeLists.txt
README.md
.gitignore
LICENSE
```

---

## 🛠️ Installation

### Prerequisites

- C++17 compatible compiler (e.g., GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 or newer

### Build Instructions

```sh
git clone https://github.com/yourusername/Generalised-Data-Structures-Library-.git
cd Generalised-Data-Structures-Library-
mkdir build && cd build
cmake ..
make
./main
```

---

## 📦 Usage Example

```cpp
#include "DataStructures.hpp"
using namespace gds;

int main() {
    SinglyLinkedList<int> sll;
    sll.insertFirst(10);
    sll.insertLast(20);
    sll.display();

    DoublyLinkedList<char> dll;
    dll.insertFirst('A');
    dll.insertLast('B');
    dll.display();

    SinglyCircularList<int> scl;
    scl.insertFirst(1);
    scl.insertLast(2);
    scl.display();

    DoublyCircularList<char> dcl;
    dcl.insertFirst('X');
    dcl.insertLast('Y');
    dcl.display();

    return 0;
}
```

---

## 📖 API Documentation

All list types support:

| Method                                 | Description                                 |
|-----------------------------------------|---------------------------------------------|
| `insertFirst(const T& value)`           | Insert at the beginning                     |
| `insertLast(const T& value)`            | Insert at the end                           |
| `insertAtPos(const T& value, size_t p)` | Insert at position (1-based)                |
| `deleteFirst()`                         | Remove the first element                    |
| `deleteLast()`                          | Remove the last element                     |
| `deleteAtPos(size_t pos)`               | Remove element at position                  |
| `display(std::ostream& os = std::cout)` | Print the list to the output stream         |
| `size() const`                          | Get the number of elements                  |

All operations throw `std::out_of_range` on invalid positions or empty lists.

---

## 🧪 Testing

Unit tests are located in the `tests/` directory.  
To run tests (if provided):

```sh
cd build
ctest
```

---

## 🤝 Contributing

Contributions are welcome! Please open issues or pull requests for improvements, bug fixes, or new features.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/YourFeature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/YourFeature`)
5. Open a pull request

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙋‍♂️ Contact

**Maintainer:** Abhishek Atole  
For questions or support, please open an issue or contact via [GitHub](https://github.com/yourusername).

---

<p align="center">
  <img src="docs/logo.png" alt="Logo" width="80"/>
</p>
