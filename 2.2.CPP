#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];

    float validate(float m) {
        if (m < 0) return 0;
        if (m > 100) return 100;
        return m;
    }

public:
    Student() {
        rollNumber = 0;
        name = "Unknown";
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(int r, string n, float m1, float m2, float m3) {
        rollNumber = r;
        name = n;
        marks[0] = validate(m1);
        marks[1] = validate(m2);
        marks[2] = validate(m3);
    }

    float getAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    string getName() const { return name; }

    void display() const {
        cout << rollNumber << "\t" << name << "\tAvg: " << getAverage() << endl;
    }
};

int main() {
    const int SIZE = 3;
    Student classroom[SIZE];

    classroom[0] = Student(101, "Alice", 95, 88, 92);
    classroom[1] = Student(102, "Bob", 40, 55, 60);
    classroom[2] = Student();

    cout << "Roll\tName\tStatus" << endl;
    cout << "-------------------------------" << endl;

    float maxAvg = -1;
    int topIndex = 0;

    for (int i = 0; i < SIZE; i++) {
        classroom[i].display();

        if (classroom[i].getAverage() > maxAvg) {
            maxAvg = classroom[i].getAverage();
            topIndex = i;
        }
    }

    cout << "-------------------------------" << endl;
    cout << "Topper: " << classroom[topIndex].getName() << " with " << maxAvg << endl;

    return 0;
}
