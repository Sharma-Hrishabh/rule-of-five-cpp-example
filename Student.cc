#include "Student.h"


Student::Student(string name, int age, int noOfSkills)
{
    this->name = name;
    this->age = age;
    this->noOfSkills = noOfSkills;
    this->skills = new string[noOfSkills];
    this->assignedSkills=0;
}

Student::Student(const Student& source)
{
    name = source.name;
    age=source.age;
    noOfSkills = source.noOfSkills;
    assignedSkills = source.assignedSkills;
    skills = new string[source.noOfSkills];
    copy(source.skills,source.skills+assignedSkills,skills);
}

Student& Student::operator=(const Student& source)
{
    if(this == &source) return *this;

    name = source.name;
    age=source.age;
    noOfSkills = source.noOfSkills;
    assignedSkills = source.assignedSkills;
    // skills = new string[source.noOfSkills]; as we are not creating new object
    copy(source.skills,source.skills+assignedSkills,skills);

    return *this;
}

Student::~Student()
{
    delete[] skills;
}

ostream& operator<<(ostream& os,const Student& st)
{
    os<< "Name : " << st.name <<", Age: " << st.age<< ", Skills:[\"";
    for(int i=0;i<st.assignedSkills;i++) os<<st.skills[i]<<",";
    cout<<"\"]";
    return os;
}


void Student::addSkill(string skillName)
{
    if(assignedSkills==noOfSkills) cout<<"Full\n";
    else
    {
        skills[assignedSkills]=skillName;
        assignedSkills++;
    }
}

int main()
{
    Student s("ujjwal",21,3);
    s.addSkill("C++");
    s.addSkill("Java");

    cout<<s<<endl;

}