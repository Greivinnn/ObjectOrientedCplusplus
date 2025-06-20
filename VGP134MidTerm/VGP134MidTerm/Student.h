#pragma once
#include <string>
#include <vector>

struct Student
{
	int id;
	std::string name;
	int grade;	// grade from 8 to 11
	std::vector<float> assignmentMarks;

	Student(int id, std::string name, int grade)
		:id(id), name(name), grade(grade)
	{
	}
	Student()
		:id(0), name(""), grade(0)
	{
	}
	~Student()
	{
	}
	float GetAverage() const
	{
		if (assignmentMarks.empty())
		{
			return 0.0f;
		}
		float total = 0.0f;
		for (float mark : assignmentMarks)
		{
			total += mark;
		}
		return total / assignmentMarks.size();
	}
};