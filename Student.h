#include<iostream>
#include <string>

using namespace std;

class Student
{
    friend ostream& operator<<(ostream& os,const Student& st);
    public:
        Student(string name = "Hrishabh", int age=21, int noOfSkills=3);
        Student(const Student& source);
        Student& operator=(const Student& source);
        Student(Student&& source);
        Student& operator=(Student&& source);
        ~Student();
        void addSkill(string skill);
    private:
        string name;
        int age;
        int noOfSkills;
        int assignedSkills;
        string* skills;

};
