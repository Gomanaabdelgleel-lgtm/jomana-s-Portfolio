#include <iostream>
#include <vector>
using namespace std;

// Class Student
class Student {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    Student(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    float getGpa() {
        return gpa;
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setGpa(float g) {
        gpa = g;
    }


void display(){
    cout<<"ID:"<<id<<endl;
    cout<<"NAME:"<<name<<endl;
    cout<<"GPA:"<<gpa<<endl;
cout << "-----------------\n";
}
};

// System Class
class StudentSystem {
private:
    vector<Student> students;

public:
    // Add Student
    void addStudent() {
        int id;
        string name;
        float gpa;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter GPA: ";
        cin >> gpa;

        students.push_back(Student(id, name, gpa));
        cout << "Student added successfully!\n";
    }

    // Display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students found!\n";
            return;
        }

        for (int i = 0; i < students.size(); i++) {
            students[i].display();
        }
    }

    // Search student
    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students[i].display();
                return;
            }
        }

        cout << "Student not found!\n";
    }

    // Delete student
    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully!\n";
                return;
            }
        }

        cout << "Student not found!\n";
    }

    // Update student
    void updateStudent() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                string name;
                float gpa;

                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new GPA: ";
                cin >> gpa;

                students[i].setName(name);
                students[i].setGpa(gpa);

                cout << "Student updated successfully!\n";
                return;
            }
        }

        cout << "Student not found!\n";
    }
};

// Main
int main() {
    StudentSystem system;
    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.displayStudents(); break;
            case 3: system.searchStudent(); break;
            case 4: system.deleteStudent(); break;
            case 5: system.updateStudent(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
