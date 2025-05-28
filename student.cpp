#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int age;
    double grade;

public:
    Student(string n, int a, double g) : name(n), age(a), grade(g) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGrade() const { return grade; }
    string getStatus() const {
        return (grade >= 10) ? "Pass" : "Fail";
    }
    string getGradeStatus() const {
        if (grade < 10) return "Fail";
        else if (grade < 12) return "Average Pass";
        else if (grade < 16) return "Good Pass";
        else return "Excellent Pass";
    }
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Status: " << getGradeStatus() << endl;
    }
};
double calculateAverage(const vector<Student>& students);
double findMaxGrade(const vector<Student>& students);
double findMinGrade(const vector<Student>& students);
void searchStudent(const vector<Student>& students, const string& name);

int main() {
    vector<Student> students;
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();
    for (int i = 0; i < numStudents; ++i) {
        string name;
        int age;
        double grade;

        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Grade: ";
        cin >> grade;
        cin.ignore();
        students.emplace_back(name, age, grade);
    }
    cout << "\n📋 Student Information:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].displayInfo();
    }
    cout << fixed << setprecision(2);
    cout << "\n📊 Class average grade: " << calculateAverage(students) << endl;
    cout << "🔺 Highest grade: " << findMaxGrade(students) << endl;
    cout << "🔻 Lowest grade: " << findMinGrade(students) << endl;
    string searchName;
    cout << "\nEnter a student name to search: ";
    getline(cin, searchName);
    searchStudent(students, searchName);

    return 0;
}
double calculateAverage(const vector<Student>& students) {
    if (students.empty()) return 0.0;
    
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.getGrade();
    }
    return sum / students.size();
}
double findMaxGrade(const vector<Student>& students) {
    if (students.empty()) return 0.0;
    
    double maxGrade = students[0].getGrade();
    for (const auto& student : students) {
        if (student.getGrade() > maxGrade) {
            maxGrade = student.getGrade();
        }
    }
    return maxGrade;
}
double findMinGrade(const vector<Student>& students) {
    if (students.empty()) return 0.0;
    
    double minGrade = students[0].getGrade();
    for (const auto& student : students) {
        if (student.getGrade() < minGrade) {
            minGrade = student.getGrade();
        }
    }
    return minGrade;
}
void searchStudent(const vector<Student>& students, const string& name) {
    bool found = false;
    for (const auto& student : students) {
        if (student.getName() == name) {
            cout << "\n✅ Student found:\n";
            student.displayInfo();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "❌ Student not found!\n";
    }
}