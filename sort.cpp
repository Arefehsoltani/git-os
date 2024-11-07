#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string firstname;
    std::string lastname;
    int sid;
};

bool sortByLastName(const Student& a, const Student& b) {
    return a.lastname < b.lastname;
}

int main() {
    std::vector<Student> students;
    std::string sortBy;

    // Get sorting criteria from user
    std::cout << "Enter sorting criteria (firstname, lastname, sid): ";
    std::cin >> sortBy;
    std::cin.ignore(); // To ignore the newline character after reading sortBy

    // Get student info from user
    std::cout << "Enter student information (first name, last name, ID):\n";
    while (true) {
        Student s;
        std::cout << "First name (or press Enter to finish): ";
        std::getline(std::cin, s.firstname);

        // Check if the user pressed Enter
        if (s.firstname.empty()) break;

        std::cout << "Last name: ";
        std::getline(std::cin, s.lastname);
        std::cout << "ID: ";
        std::cin >> s.sid;
        std::cin.ignore(); // To ignore the newline character after reading sid
        students.push_back(s);
    }

    // Sort students based on user's choice
    if (sortBy == "firstname") {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.firstname < b.firstname;
        });
    } else if (sortBy == "lastname") {
        std::sort(students.begin(), students.end(), sortByLastName);
    } else if (sortBy == "sid") {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.sid < b.sid;
        });
    }

    // Print sorted students
    std::cout << "\nSorted students:\n";
    for (const auto& student : students) {
        std::cout << student.firstname << " " << student.lastname << " (" << student.sid << ")" << std::endl;
    }

    return 0;
}

