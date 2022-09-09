#include "Application.h"

void Application::displayMainMenu()
{
    std::cout << "1. Modify database\n";
    std::cout << "2. Load/Store database\n";
    std::cout << "3. Filter database\n";
    std::cout << "4. Set sorting order\n";
    std::cout << "5. Visualize database\n";
    std::cout << "6. Exit\n\n>> ";
}

int Application::run()
{
    int choice;

    do {
        displayMainMenu();

        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {
            modifyDatabase();
        }
        else if (choice == 2) {
            loadStoreDatabase();
        }
        else if (choice == 3) {
            displayFilteringOptions();
        }
        else if (choice == 4) {
            displaySortingOptions();
        }
        else if (choice == 5) {
            obj1.visualize();
        }

    } while (choice != 6);

    return 0;
}

void Application::modifyDatabase()
{
    int choice;

    do {
        displayModifyDatabase();
        DatabaseManager::student newStudent;

        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {

            std::cout << "Enter name: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, newStudent.student_name);

            std::cout << "Enter grade: ";
            std::cin >> newStudent.grade;

            obj1.add_entry(newStudent);
        }
        else if (choice == 2) {
            std::cout << "Enter student's name to remove: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, newStudent.student_name);

            obj1.remove_entry(newStudent);
            break;
        }
        else if (choice == 3) {
            std::cout << "Enter name: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, newStudent.student_name);

            auto search = obj1.schoolDiary.find(newStudent.student_name);

            if (search != obj1.schoolDiary.end()) {
                std::cout << "Enter new grade: ";
                std::cin >> newStudent.grade;

                obj1.modify_entry(newStudent);

            }
            else {
                std::cout << "This student is unevailable ;) Try later...\n";
            }
            break;
        }
        else if (choice == 4) {

            auto a = obj1.get_entries();

            break;
        }
        else if (choice == 5) {
            obj1.visualize();
        }

    } while (choice != 6);

}

void Application::displayModifyDatabase()
{
    std::cout << "1. Add student \n";
    std::cout << "2. Remove student \n";
    std::cout << "3. Modify student \n";
    std::cout << "4. Get students \n";
    std::cout << "5. Visualize\n";
    std::cout << "6. Back \n\n>> ";
}

void Application::loadStoreDatabase()
{
    std::cout << "Load: 1\n";
    std::cout << "Save: 2\n\n>> ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        obj1.load();
        break;
    case 2:
        obj1.save();
        break;
    }

}

void Application::displayFilteringOptions()
{
    std::cout << "\n1. Passing grades\n";
    std::cout << "2. Non passing grades\n ";
    std::cout << "3. All grades\n";
    std::cout << "4. Back\n\n>> ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        obj2.filteringPassingGrades(obj1);
        break;
    case 2:
        obj2.filteringNonPassingGrades(obj1);
        break;
    case 3:
        obj1.visualize();
        break;
    case 4:
        displayMainMenu();
        break;
    }
}

void Application::displaySortingOptions()
{
    std::cout << "\n1. Incresing by name\n";
    std::cout << "2. Decreasing by name\n";
    std::cout << "3. Increasing by grade\n";
    std::cout << "4. Decreasing by grade\n ";
    std::cout << "5. Back\n\n>> ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        obj2.sortIncreasingByName(obj1);
        break;
    case 2:
        obj2.sortDecreasingByName(obj1);
        break;
    case 3:
        obj2.sortIncreasingByGrade(obj1);
        break;
    case 4:
        obj2.sortDecreasingByGrade(obj1);
        break;
    case 5:
        displayMainMenu();
        break;
    }
}

