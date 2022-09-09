#include "DatabaseManager.h"

void DatabaseManager::add_entry(student newStudent) {

    std::pair<std::string, int> student1("Rafalek", 5);
    std::pair<std::string, int> student2("Iza", 2);
    std::pair<std::string, int> student3("Kuba", 6);
    schoolDiary.insert(student1);
    schoolDiary.insert(student2);
    schoolDiary.insert(student3);
    schoolDiary.insert({ newStudent.student_name, newStudent.grade });
}

void DatabaseManager::remove_entry(student deletedStudent)
{
    if (schoolDiary.erase(deletedStudent.student_name) == 1)
        std::cout << "Student " << deletedStudent.student_name << " was removed.\n";
    else
        std::cout << "Student " << deletedStudent.student_name << " is not exist.\n";
}

void DatabaseManager::modify_entry(student modifyStudent) {

    schoolDiary[modifyStudent.student_name] = modifyStudent.grade;

}

void DatabaseManager::visualize()
{
    auto it = begin(schoolDiary);
    for (it; it != end(schoolDiary); it++) {
        std::cout << "\t Name: " << std::setw(20) << std::left << it->first << "\t Grade: " << it->second << std::endl;
    }
}

std::vector<DatabaseManager::student> DatabaseManager::get_entries()
{
    std::vector<student> studentsList(schoolDiary.size());
    std::transform(schoolDiary.begin(), schoolDiary.end(), studentsList.begin(),
        [](auto a) {return student{ a.first, a.second }; });

    return studentsList;
}

void DatabaseManager::save()
{
    std::fstream myFile;

    myFile.open("database.csv", std::ios::out);

    auto it = schoolDiary.begin();
    for (it; it != schoolDiary.end(); it++) {

        myFile << it->first << "\n"
            << it->second << "\n ";
    }
    myFile.close();
}


void DatabaseManager::load()
{
    std::fstream path;
    path.open("database.csv");
    std::string line = "";
    std::string name{};
    std::string grade{};
    bool isName = false;
    bool isGrade = false;

    while (!path.eof()) {
        std::getline(path, line);

        if (!isName) {
            name = line;
            isName = true;
        }
        else if (!isGrade) {
            grade = line;
            isGrade = true;
        }
        if (isGrade && isName) {
            student newStudent;
            newStudent.student_name = name;
            newStudent.grade = std::stoi(grade);
            schoolDiary.insert({ newStudent.student_name, newStudent.grade });
            isName = false;
            isGrade = false;
        }
    }
    path.close();
}

std::ostream& operator<<(std::ostream& os, const DatabaseManager::student& rhs)
{
    os << "Student:" << std::setw(20) << std::left << rhs.student_name << "Grade: " + std::to_string(rhs.grade);
    return os;
}

std::istream& operator>>(std::istream& is, DatabaseManager::student& rhs)
{
    std::string first, second;
    is >> first >> second >> rhs.grade;
    rhs.student_name = first + " " + second;
    return is;
}
