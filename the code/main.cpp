#include <iostream>
#include "University.h"
#include "Dormitory.h"
#include "Room.h"
#include "Student.h"
#include "Restaurant.h"
#include "Menu.h"
using namespace std;

int main() {
    cout << "=== University Dormitory & Restaurant Management System ===" << endl << endl;
    Restaurant restaurant;
    Menu monday("Eggs & Toast", "Chicken & Rice", "Soup & Bread", "2026-06-15");
    restaurant.addMenu(monday);
    Dormitory dormA("Dorm A", 1, 100, restaurant);
    Room room101(101, 2, {});
    Room room102(102, 1, {});
    dormA.addRoom(room101);
    dormA.addRoom(room102);
    Student s1("Amine", 1, 2);
    Student s2("Sarah", 2, 1);
    Student s3("Karim", 3, 3);
    cout << "--- Polymorphism check ---" << endl;
    Person* p = &s1;
    p->displayInfo(); 
    cout << endl;
    University university("ENSIA University");
    university.addDormitory(dormA);
    Dormitory* dorm = university.findDormitory(1);
    if (dorm != nullptr) {
        Room* r101 = dorm->findRoom(101);
        Room* r102 = dorm->findRoom(102);
        cout << "--- Assigning students to rooms ---" << endl;
        if (r101 != nullptr) {
            cout << "Adding Amine to room 101: " << (r101->addStudent(s1) ? "OK" : "FAILED") << endl;
            cout << "Adding Sarah to room 101: " << (r101->addStudent(s2) ? "OK" : "FAILED") << endl;
            try {
                bool ok = r101->addStudent(s3);
                cout << "Adding Karim to room 101 (should fail, room full): " << (ok ? "OK" : "FAILED") << endl;
            } catch (const out_of_range& e) {
                cout << "Adding Karim to room 101 correctly threw: " << e.what() << endl;
            }
        }
        if (r102 != nullptr) {
            cout << "Adding Karim to room 102: " << (r102->addStudent(s3) ? "OK" : "FAILED") << endl;
        }
    }
    cout << endl << "--- Error handling checks ---" << endl;
    try {
        Student bad("Invalid", -5, 1); 
        cout << "ERROR: should have thrown for negative id" << endl;
    } catch (const invalid_argument& e) {
        cout << "Correctly rejected negative student id: " << e.what() << endl;
    }

    try {
        Dormitory* missing = university.findDormitory(999);
        if (missing == nullptr) {
            cout << "Correctly returned nullptr for a dormitory id that doesn't exist" << endl;
        }
    } catch (...) {
        cout << "ERROR: findDormitory should not throw" << endl;
    }

    try {
        university.getDormitory(5); 
        cout << "ERROR: should have thrown for out-of-range index" << endl;
    } catch (const out_of_range& e) {
        cout << "Correctly rejected out-of-range dormitory index: " << e.what() << endl;
    }
    cout << endl << "--- University Report ---" << endl;
    for (const Dormitory& d : university.getDormitories()) {
        cout << "Dormitory: " << d.getName() << " (ID: " << d.getId() << ")" << endl;
        cout << "Total occupancy: " << d.gettotalOccupency() << " / " << d.getCapacity() << endl;

        cout << "Restaurant menus:" << endl;
        for (const Menu& m : d.getRestaurant().getMenus()) {
            cout << "  [" << m.getDate() << "] Breakfast: " << m.getBreakfast()
                 << " | Lunch: " << m.getLunch()
                 << " | Dinner: " << m.getDinner() << endl;
        }

        for (const Room& r : d.getRooms()) {
            cout << "  Room " << r.getNumber() << " (capacity " << r.getCapacity()
                 << ", occupancy " << r.getOccupency() << "): ";
            for (const Student& s : r.getStudents()) {
                cout << s.getName() << " (ID " << s.getId() << ", Year " << s.getYear() << ") ";
            }
            cout << endl;
        }
    }

    return 0;
}