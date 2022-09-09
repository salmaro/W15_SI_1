#include "UserInterfaceDatabaseContext.h"

void UserInterfaceDatabaseContext::sortIncreasingByGrade(DatabaseManager obj1)
{
	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::function<bool(const DatabaseManager::student, const DatabaseManager::student)> sortInGra
		= [](const DatabaseManager::student& a, const DatabaseManager::student& b) {return a.grade < b.grade; };

	std::sort(exampleVector.begin(), exampleVector.end(), sortInGra);

	for (auto a : exampleVector) {
		std::cout << a << "\n";
	}
}

void UserInterfaceDatabaseContext::sortIncreasingByName(DatabaseManager obj1)
{
	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::function<bool(const DatabaseManager::student, const DatabaseManager::student)> sortInNam
		= [](const DatabaseManager::student& a, const DatabaseManager::student& b) {return a.student_name < b.student_name; };

	std::sort(exampleVector.begin(), exampleVector.end(), sortInNam);

	for (auto a : exampleVector) {
		std::cout << a << "\n";
	}
}

void UserInterfaceDatabaseContext::sortDecreasingByGrade(DatabaseManager obj1)
{
	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::function<bool(const DatabaseManager::student, const DatabaseManager::student)> sortDecGra
		= [](const DatabaseManager::student& a, const DatabaseManager::student& b) {return a.grade > b.grade; };

	std::sort(exampleVector.begin(), exampleVector.end(), sortDecGra);

	for (auto a : exampleVector) {
		std::cout << a << "\n";
	}
}

void UserInterfaceDatabaseContext::sortDecreasingByName(DatabaseManager obj1)
{
	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::function<bool(const DatabaseManager::student, const DatabaseManager::student)> sortDecNam
		= [](const DatabaseManager::student& a, const DatabaseManager::student& b) {return a.student_name > b.student_name; };

	std::sort(exampleVector.begin(), exampleVector.end(), sortDecNam);

	for (auto a : exampleVector) {
		std::cout << a << "\n";
	}
}

void UserInterfaceDatabaseContext::filteringPassingGrades(DatabaseManager obj1)
{
	std::function<void(const DatabaseManager::student)> filterPassGrade
		= [](const DatabaseManager::student& a) {if (a.grade > 1)std::cout << a << "\n\n"; };

	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::for_each(exampleVector.begin(), exampleVector.end(), filterPassGrade);
}

void UserInterfaceDatabaseContext::filteringNonPassingGrades(DatabaseManager obj1)
{
	std::function<void(const DatabaseManager::student)> filterNonPassGrade
		= [](const DatabaseManager::student& a) {if (a.grade < 2)std::cout << a << "\n\n"; };

	std::vector<DatabaseManager::student> exampleVector;
	for (auto a : obj1.schoolDiary) {
		exampleVector.push_back(DatabaseManager::student(a.first, a.second));
	}

	std::for_each(exampleVector.begin(), exampleVector.end(), filterNonPassGrade);
}
