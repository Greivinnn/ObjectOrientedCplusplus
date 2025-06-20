#include "School.h"
#include "Student.h"
#include "Registry.h"
#include <set>
#include <map>
#include <iostream>

Registry* Registry::Get()
{
	static Registry insctance;
	return &insctance;
}
void Registry::RegisterSchool(const School& school)
{
	schools[school.GetId()] = school;
}
void Registry::RegisterStudent(const Student& student)
{
	if (schools.empty())
	{
		throw std::runtime_error("No schools registered to assign the student to.");
	}

	//put the student on a random school
	auto it = schools.begin();
	std::advance(it, rand() % schools.size());
	it->second.AddStudent(student);

	students[student.id] = student;
}
void Registry::DistributeAssignments()
{
	for (auto& pair : schools)
	{
		int schoolId = pair.first;
		School& school = pair.second;
		std::cout << "Distributing assignments for School ID: " << schoolId << "\n";

		for (auto& student : school.GetStudents())
		{
			float randomMark = static_cast<float>(rand() % 101);
			student.assignmentMarks.push_back(randomMark);
			std::cout << "Assigned mark " << randomMark << " to Student ID: " << student.id
				<< " (" << student.name << ")\n";
		}
	}
}
const std::map<int, School>& Registry::GetSchools() const
{
	return schools;
}
int Registry::GetStudentSchoolId(int studentId) const
{
	auto it = students.find(studentId);
	if (it != students.end()) 
	{
		return it->first; // Return the school ID
	}
	throw std::runtime_error("Student ID not found in any school.");
}
std::set<int> Registry::GetSchoolIds() const
{
	std::set<int> ids;
	for (auto& pair : schools)
	{
		int schoolId = pair.first;
		ids.insert(schoolId);
	}
	return ids;
}
School* Registry::GetSchool(int schoolId)
{
	auto it = schools.find(schoolId);
	if (it != schools.end())
	{
		return &it->second;
	}
	return nullptr; // if nothing is found pointer set to nullptr
}
void Registry::ExchangeStudent(int studentId, int newSchoolId)
{
	// crash prevention
	auto studentIt = students.find(studentId);
	if (studentIt == students.end())
	{
		throw std::runtime_error("Student not found.\n");
	}
	auto newSchoolIt = schools.find(newSchoolId);
	if (newSchoolIt == schools.end())
	{
		throw std::runtime_error("New school not found.\n");
	}
	// find school of student
	for (auto& pair : schools)
	{
		int schoolId = pair.first;
		School& school = pair.second;
		auto& students = school.GetStudents();
		
		// using the lambda function to find the school of the given student
		auto it = std::find_if(students.begin(), students.end(), [&](const Student& s)	// this is use to find the current school of the student
			{
				return s.id == studentId;
			});
		if (it != students.end())
		{
			students.erase(it);

			newSchoolIt->second.AddStudent(studentIt->second);
			return;
		}
	}
	throw std::runtime_error("Student not found in any school.\n");
}
void Registry::DistributeAssignments(int numAssignments)
{
	for (auto& pair : schools)
	{
		int schoolId = pair.first;
		School& school = pair.second;
		
		for (auto& student : school.GetStudents())
		{
			for (int i = 0; i < numAssignments; ++i)
			{
				int randomMark = rand() % 101;
				student.assignmentMarks.push_back(randomMark);
			}
		}
	}
}