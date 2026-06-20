# University Dormitory & Restaurant Management System

A desktop application developed in C++ using the Qt framework as part of an OOP course project. The system manages dormitory residents and restaurant services within a university environment.

---

## About

This project was built to practice Object-Oriented Programming concepts by modeling a real-world system. The main idea is to manage students living in a dormitory and their access to restaurant services, all through a graphical interface.

OOP concepts applied:
- Classes and Objects (Student, Room, Dormitory, Restaurant, Menu, Person, University)
- Inheritance (Person is the base class for Student)
- Encapsulation (each class manages its own data)
- Polymorphism

---

## Project Structure

```
University-Dormitory-Restaurant-Management-System/
│
├── the code/                  # C++ backend logic (VS Code)
│   ├── main.cpp               # Entry point
│   ├── University.cpp / .h    # University class
│   ├── Dormitory.cpp / .h     # Dormitory management
│   ├── Room.cpp / .h          # Room allocation
│   ├── Student.cpp / .h       # Student class
│   ├── Person.cpp / .h        # Base class
│   ├── Restaurant.cpp / .h    # Restaurant management
│   ├── Menu.cpp / .h          # Menu/meals
│   └── udrms.exe              # Compiled executable
│
├── the interface/             # Qt GUI project (UDRMS_GUI)
│
├── the real diagram.drawio.png  # UML Class Diagram
└── README.md
```

---

## Classes Overview

| Class | Role |
|---|---|
| `Person` | Base class with shared attributes (name, ID) |
| `Student` | Inherits Person, represents a dormitory resident |
| `Room` | Represents a dormitory room with capacity and status |
| `Dormitory` | Manages rooms and student assignments |
| `Restaurant` | Handles meal service and orders |
| `Menu` | Stores available meals and their details |
| `University` | Top-level class linking all components |

---

## Technologies Used

- C++ — core logic and OOP implementation
- Qt Framework — graphical user interface
- Draw.io — UML class diagram
- VS Code — code editor

---

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/nadagasti-wq/University-Dormitory-Restaurant-Management-System.git
   ```

2. To run the compiled version directly, open `the code/udrms.exe`

3. To open the GUI project, launch Qt Creator and open the `.pro` file inside `the interface/` folder, then click Run.

---

## UML Class Diagram

The file `the real diagram.drawio.png` in the repository shows the full class diagram of the system. It can also be opened with [Draw.io](https://app.diagrams.net/) for editing.

---

## Author

**Gasti Nada**  
National Higher School of Artificial Intelligence (ENSIA)  
OOP Course Project — 2025/2026
