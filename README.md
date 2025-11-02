# 📞 Contact Book using Singly Linked List (C++)

![C++](https://img.shields.io/badge/language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![DSA Project](https://img.shields.io/badge/Project-Data%20Structures%20%26%20Algorithms-blueviolet?style=for-the-badge)

---

## 🧾 Overview
This project is a **Contact Book Management System** built in **C++** using a **Singly Linked List** data structure.  
It allows users to manage contacts dynamically — **add, delete, search, display, sort, and count** — all directly in memory.

---

## 🚀 Features
✅ Add new contacts  
✅ Display all saved contacts  
✅ Search by **name** or **number**  
✅ Delete any contact by name or number  
✅ Sort contacts alphabetically or numerically  
✅ Count total contacts  
✅ Safe memory management via destructors  

---

## 🧱 Data Structure Used
The system is powered by a **Singly Linked List**, where each node represents one contact.

```cpp
class Node {
public:
    string cNum;   // Contact Number
    string cName;  // Contact Name
    Node* next;    // Pointer to next node

    Node(string num, string name) {
        cNum = num;
        cName = name;
        next = nullptr;
    }
};
```

---

## ⚙️ Core Functionalities

| Function | Description |
|-----------|--------------|
| `pushBack(string num, string name)` | Adds a new contact to the end of the list. |
| `popBack(string val)` | Deletes a contact by either name or number. |
| `search(string val)` | Searches for a contact and returns it if found. |
| `display()` | Displays all contacts in the list. |
| `sortContacts(bool byName = true)` | Sorts the contact list by name or number. |
| `size()` | Returns the total number of contacts. |
| `~ContactInfo()` | Frees all allocated memory safely. |

---

## 🧩 Sorting Algorithm
Contacts are sorted using the **Bubble Sort** algorithm, which is ideal for smaller datasets like contact lists.  
Instead of rearranging node pointers, the program swaps the **data fields** (name and number) directly.

---

## 💻 Example Output
```
===== 📞 CONTACT BOOK MENU =====
1. Add Contact
2. Display Contacts
3. Search any Contact
4. Delete Contact
5. Sort Contacts
6. Total Contacts
0. Exit
===============================
Enter your choice: 1
Enter name: Ali Hassan
Enter number: 03001234567
Contact added successfully!

Enter your choice: 2
All Contacts:
1.
    Name: Ali Hassan
    No: 03001234567
```

---

## 🧰 How to Compile & Run
### 🪟 Windows / Linux / macOS
```bash
g++ contact_book.cpp -o contact_book
./contact_book
```

### 💡 Or Run in VS Code / Dev-C++
- Open the file  
- Press **Run** or use the **Build and Execute** shortcut  

---

## 🧼 Memory Management
The destructor ensures no memory leaks occur:
```cpp
~ContactInfo() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
```

---

## 🧑‍🎓 Author
**Ali Hassan**  
🎓 BS Computer Science (3rd Semester)  
💻 Python & C++ Developer  
🌍 Gujranwala, Pakistan  

---

## ⭐ Future Improvements
- Save contacts to a text or binary file  
- Add edit/update functionality  
- Integrate input validation for phone numbers  
- Improve sorting efficiency using Merge Sort  

---

### 🏁 Final Note
> “People are less bothered by your flaws and more impacted by your strengths.”  
> — *Ali Hassan*
