#pragma once
#include <string>
#include <vector>
#include "Student.h"

class School
{
public:
	School(int schoolId, std::string schoolName);
	School();
	~School();
	void AddStudent(const Student& student);
	// void GradeStudents();
	float GetAverage() const;
	std::vector<Student>& GetStudents();	// non constant 
	const std::vector<Student>& GetStudents() const;	// const method
	int GetId() const;
	const std::string& GetName() const;
private:
	int mSchoolId;
	std::string mSchoolName;
	std::vector<Student> mStudents;
};