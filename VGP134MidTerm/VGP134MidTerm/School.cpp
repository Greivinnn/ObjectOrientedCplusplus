#include "School.h"
#include "Student.h"
#include <vector>
#include <string>

School::School(int schoolId, std::string schoolName)
	: mSchoolId(schoolId), mSchoolName(schoolName)
{
}
School::School()
	:mSchoolId(0), mSchoolName("")
{
}
School::~School()
{
}
void School::AddStudent(const Student& student)
{
	mStudents.push_back(student);
}
float School::GetAverage() const
{
	if (mStudents.empty())
	{
		return 0.0f;
	}
	float total = 0.0f;
	for (const auto& student : mStudents)
	{
		total += student.grade;
	}
	return total / mStudents.size();
}
std::vector<Student>& School::GetStudents()
{
	return mStudents;	// no const version
}
int School::GetId() const
{
	return mSchoolId;
}
const std::string& School::GetName() const
{
	return mSchoolName;
}
const std::vector<Student>& School::GetStudents() const
{
	return mStudents; // Const version
}
