// VGP134MidTerm.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Registry.h"
#include "School.h"
#include "Student.h"

//Part 2: The Schools District (70%)
//  Create a struct Student
//      id, name, grade, assignmentMarks (id does not have to be const)
//  Create a class School
//      id, name, students  (id does not have to be const) 
//      AddStudent
//      GradeStudents
//      GetAverage
//      GetStudents
//  Create a singleton Registry
//      schools, students
//      RegisterSchool - stores the new school
//      RegisterStudent - stores the new student and gets randomly assigned to a registered school
//      DistributeAssignments - randomly gives a mark to each student from 0-100
//      GetSchoolIds - returns all the school ids
//      GetSchool - returns the school with the id
//      ExchangeStudent - takes the id of student and a different school id, removes the student from their current school and adds to the new school
// 
//FLOW
//  1. Register 3 schools
//  2. Register 30 students
//  3. Distribute a random number of assignments (between 5-10)
//  4. Calculate the overall average for each student
//  5. In each School, Print the overall average of all the students as well as the number of students that pass (average over 54%)
//  6. Print which school has the heighest average
//  7. Exchange 6 students between the schools
//  8. Distribute 3 more assignments
//  9. In each School, Print the overall average of all the students as well as the number of students that pass (average over 54%)
//  10. Print which school has the heighest average


//  Application builds and runs:                    /50
//  Application functions as described:             /20
//  Build uses global accessors and stl containers: /20
//  Coding standards, minor errors:                 /10


int main()
{
    srand(static_cast<unsigned>(time(0)));
    
    //Flow of the code

    // 0. access the singleton instance
    Registry* registry = Registry::Get();

    // 1
    School school1(1, "Killarney School");
    School school2(2, "Douglas School");
    School school3(3, "Langara School");
    registry->RegisterSchool(school1);
    registry->RegisterSchool(school2);
    registry->RegisterSchool(school3);
    // 2
    for (int i = 1; i <= 30; ++i)
    {
        std::string studentName = "Student" + std::to_string(i);
        int grade = 0 + (rand() % 4);

        Student student(i, studentName, grade);
        registry->RegisterStudent(student);
    }
    // 3
    int numAssignments = 5 + (rand() % 6);
    registry->DistributeAssignments(numAssignments);
    // 4 - 5
    std::cout << "Question 4 and 5\n";
    const auto& schools = registry->GetSchools();
    for (auto it = schools.begin(); it != schools.end(); ++it)
    {
        int schoolId = it->first;
        const School& school = it->second;

        float totalAverage = 0.0f;
        int passingStudents = 0;
        int totalStudents = 0;

        for (const auto& student : school.GetStudents())
        {
            float studentAverage = student.GetAverage();
            totalAverage += studentAverage;
            ++totalStudents;

            if (studentAverage > 54.0f)
            {
                ++passingStudents;
            }
        }
        float overallAverage = (totalStudents > 0) ? (totalAverage / totalStudents) : 0.0f;
        std::cout << "School ID: " << schoolId << " - " << school.GetName() << "\n";
        std::cout << "Overall Average: " << overallAverage << "%\n";
        std::cout << "Number of Passing Students: " << passingStudents << "\n\n";
    }
    // 6
    std::cout << "Question 6\n";
    float highestAverage = 0.0f;
    int highestAverageSchoolId = -1;
    std::string highestAverageSchoolName;

    for (auto it = schools.begin(); it != schools.end(); ++it)
    {
        int schoolId = it->first;
        const School& school = it->second;
        float totalAverage = 0.0f;
        int totalStudents = 0;

        for (const auto& student : school.GetStudents())
        {
            float studentAverage = student.GetAverage();
            totalAverage += studentAverage;
            ++totalStudents;
        }
        float overallAverage = (totalStudents > 0) ? (totalAverage / totalStudents) : 0.0f;

        if (overallAverage > highestAverage)
        {
            highestAverage = overallAverage;
            highestAverageSchoolId = schoolId;
            highestAverageSchoolName = school.GetName();
        }
    }

    if (highestAverageSchoolId != -1)
    {
        std::cout << "The school with the highest average is:\n";
        std::cout << "School ID: " << highestAverageSchoolId << " - " << highestAverageSchoolName << "\n";
        std::cout << "Highest Average Of: " << highestAverage << "%\n";
    }
    else
    {
        std::cout << "No schools found.\n";
    }
    std::cout << "\n";
    // 7
    std::cout << "Question 7\n";
    const auto& schoolIds = registry->GetSchoolIds();
    std::vector<int> schoolIdsVector(schoolIds.begin(), schoolIds.end());
    for (int i = 1; i <= 6; ++i)
    {
        int studentId = i;
        int currentSchoolId = registry->GetStudentSchoolId(studentId);
        int targetSchoolId = currentSchoolId;

        while (targetSchoolId == currentSchoolId)
        {
            targetSchoolId = schoolIdsVector[rand() % schoolIdsVector.size()];
        }

        registry->ExchangeStudent(studentId, targetSchoolId);
        std::cout << "Exchanged Student ID: " << studentId
            << " from School ID: " << currentSchoolId
            << " to School ID: " << targetSchoolId << "\n";
    }
    std::cout << "\n";
    // 8
    registry->DistributeAssignments(3);

    // 9
    std::cout << "Question 9\n";
    for (auto it = schools.begin(); it != schools.end(); ++it)
    {
        int schoolId = it->first;
        const School& school = it->second;

        float totalAverage = 0.0f;
        int passingStudents = 0;
        int totalStudents = 0;

        for (const auto& student : school.GetStudents())
        {
            float studentAverage = student.GetAverage();
            totalAverage += studentAverage;
            ++totalStudents;

            if (studentAverage > 54.0f)
            {
                ++passingStudents;
            }
        }
        float overallAverage = (totalStudents > 0) ? (totalAverage / totalStudents) : 0.0f;
        std::cout << "School ID: " << schoolId << " - " << school.GetName() << "\n";
        std::cout << "Overall Average: " << overallAverage << "%\n";
        std::cout << "Number of Passing Students: " << passingStudents << "\n\n";
    }
    // 10
    std::cout << "Question 10\n";
    for (auto it = schools.begin(); it != schools.end(); ++it)
    {
        int schoolId = it->first;
        const School& school = it->second;
        float totalAverage = 0.0f;
        int totalStudents = 0;

        for (const auto& student : school.GetStudents())
        {
            float studentAverage = student.GetAverage();
            totalAverage += studentAverage;
            ++totalStudents;
        }
        float overallAverage = (totalStudents > 0) ? (totalAverage / totalStudents) : 0.0f;

        if (overallAverage > highestAverage)
        {
            highestAverage = overallAverage;
            highestAverageSchoolId = schoolId;
            highestAverageSchoolName = school.GetName();
        }
    }

    if (highestAverageSchoolId != -1)
    {
        std::cout << "The school with the highest average is:\n";
        std::cout << "School ID: " << highestAverageSchoolId << " - " << highestAverageSchoolName << "\n";
        std::cout << "Highest Average Of: " << highestAverage << "%\n";
    }
    else
    {
        std::cout << "No schools found.\n";
    }
    std::cout << "\n";

    return 0;
}