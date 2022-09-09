#pragma once
#include "DatabaseManager.h"
#include <functional>
#include <map>

class UserInterfaceDatabaseContext
{
public:
	void sortIncreasingByGrade(DatabaseManager obj1);
	void sortIncreasingByName(DatabaseManager obj1);
	void sortDecreasingByGrade(DatabaseManager obj1);
	void sortDecreasingByName(DatabaseManager obj1);

	void filteringPassingGrades(DatabaseManager obj1);
	void filteringNonPassingGrades(DatabaseManager obj1);
};
