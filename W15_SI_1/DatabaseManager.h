#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>


class DatabaseManager
{
public:
    DatabaseManager() = default;
    ~DatabaseManager() = default;

    struct student {
        std::string student_name{};
        int grade{};
        student() = default;
        student(std::string name, int grade) : student_name{ name }, grade{ grade } {};

        bool operator==(const student& rhs) {
            if (this->student_name == rhs.student_name && this->grade == rhs.grade)
                return true;
            else
                return false;
        }

        bool operator<(const student& rhs) const {
            if (this->grade < rhs.grade)
                return true;
            else
                return false;
        }
    };


    std::unordered_map <std::string, int> schoolDiary;

    void add_entry(student);
    void remove_entry(student);
    void modify_entry(student);
    void visualize();

    std::vector <student> get_entries();

    void save();
    void load();

    friend std::ostream& operator<<(std::ostream& os, const DatabaseManager::student& rhs);
    friend std::istream& operator>>(std::istream& is, DatabaseManager::student& rhs);
};


