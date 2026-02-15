
# 📚 C++ Doubly Linked List (Template)

A simple, clean **template-based Doubly Linked List** implementation in C++.
This project demonstrates how to build and use a doubly linked list from scratch using pointers and templates.

Perfect for:

* Practicing data structures in C++
* Understanding pointers (`Next` / `Prev`)
* Learning how linked lists work internally
* Reusing as a small utility in other projects

---

## ✨ Features

* Template-based (works with any data type)
* Insert at:

  * Beginning
  * End
  * After a given node
* Delete:

  * Specific node
  * First node
  * Last node
* Search (`Find`)
* Print list
* Proper forward & backward linking (`Next` / `Prev`)

---

## 📁 Structure

```
.
├── clsDblLinkedList.h
└── main.cpp (optional test file)
```

---

## 🚀 How to Use

Include the header in your project:

```
#include "clsDblLinkedList.h"
```

### Example

```
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main() {
    clsDblLinkedList<int> list;

    list.InsertAtBeginning(10);
    list.InsertAtBeginning(5);
    list.InsertAtEnd(20);

    list.PrintList(); // Output: 5 <-> 10 <-> 20 <->

    auto node = list.Find(10);
    if (node != nullptr) {
        list.InsertAfter(node, 15);
    }

    list.PrintList(); // Output: 5 <-> 10 <-> 15 <-> 20 <->

    list.DeleteFirstNode();
    list.PrintList(); // Output: 10 <-> 15 <-> 20 <->

    list.DeleteLastNode();
    list.PrintList(); // Output: 10 <-> 15 <->

    return 0;
}
```

---

## 🛠️ Build & Run

Using g++:

```
g++ main.cpp -o app
./app
```

Or compile it inside Visual Studio / any C++ IDE.

---

## 🧠 What You’ll Learn

* How doubly linked lists work internally
* Pointer manipulation in C++
* Basic memory management with `new` / `delete`
* Template classes
* Implementing classic data structure operations

---

## 📌 Notes

* This is an educational implementation (not STL replacement).
* No smart pointers or advanced memory management used (by design, for learning).
* You can extend this with:

  * Size tracking
  * Clear() function
  * Reverse traversal
  * Iterator support

---


* Add a **short “About” line** for GitHub
* Write a **perfect first commit message** 😄
