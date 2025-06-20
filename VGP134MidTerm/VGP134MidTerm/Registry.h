#pragma once
#include "School.h"
#include "Student.h"
#include <set>
#include <map>

class Registry
{
public:
	// singleton delete and get methods
	static Registry* Get();
	
	Registry(Registry&) = delete;
	Registry(Registry&&) = delete;
	Registry& operator=(Registry&) = delete;
	Registry& operator=(Registry&&) = delete;

	// singleton functions (voids, returns): 
	void RegisterSchool(const School& school);
	void RegisterStudent(const Student& student);
	void DistributeAssignments();
	std::set<int> GetSchoolIds() const;
	School* GetSchool(int schoolId);
	void ExchangeStudent(int studentId, int newSchoolId);
	void DistributeAssignments(int numAssignments);
	const std::map<int, School>& GetSchools() const;
	int GetStudentSchoolId(int studentId) const;
private:
	Registry() = default;	// private constructor (not accessible)
	// data members
	std::map<int, School> schools;
	std::map<int, Student> students;
};