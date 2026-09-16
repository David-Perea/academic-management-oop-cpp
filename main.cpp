#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ===================================================
//      ACADEMIC MANAGEMENT SYSTEM - SYSTEM LOG
// ===================================================

class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}
    virtual void displayInfo() const {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
    virtual ~Person() {}
};

class Student : public Person {
private:
    string major;
    double gpa;

public:
    Student(string n, int i, string m, double g) 
        : Person(n, i), major(m), gpa(g) {}

    void displayInfo() const override {
        cout << "[Student] ID: " << id << " | Name: " << name 
             << " | Major: " << major << " | GPA: " << gpa << endl;
    }
};

class Teacher : public Person {
private:
    string department;

public:
    Teacher(string n, int i, string dept) 
        : Person(n, i), department(dept) {}

    void displayInfo() const override {
        cout << "[Teacher] ID: " << id << " | Name: " << name 
             << " | Dept: " << department << endl;
    }
};

int main() {
    cout << "===================================================" << endl;
    cout << "        ACADEMIC MANAGEMENT SYSTEM v1.0            " << endl;
    cout << "===================================================" << endl << endl;

    vector<Person*> academicRegistry;

    // Puedes cambiar estos registros por cualquier otro nombre genérico o académico
    academicRegistry.push_back(new Student("Carlos Mendoza", 101, "Data Analytics", 3.9));
    academicRegistry.push_back(new Student("Sofia Ramirez", 102, "Computer Science", 3.8));
    academicRegistry.push_back(new Teacher("Prof. Robert Vance", 201, "Mathematics"));

    cout << "--- Registered Academic Profiles ---" << endl;
    for (const auto& person : academicRegistry) {
        person->displayInfo();
    }

    // Free memory
    for (auto person : academicRegistry) {
        delete person;
    }

    return 0;
}
