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

Student::Student(Student&& source)
{
    cout << "Move constructor called" << endl;
    name = move(source.name);
    age = source.age;
    noOfSkills = source.noOfSkills;
    assignedSkills = source.assignedSkills;
    skills = source.skills;

    source.skills = nullptr;
}

Student& Student::operator=(Student&& source)
{
    cout << "Move operator called" << endl;
    if(this != &source)
    {
        delete[] skills;

        name = move(source.name);
        age = source.age;
        noOfSkills = source.noOfSkills;
        assignedSkills = source.assignedSkills;
        skills = source.skills;
        source.skills = nullptr;
    }

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

Student f(Student s) {
    return s;
}

int main()
{
    // Student s("ujjwal",21,3);
    // s.addSkill("C++");
    // s.addSkill("Java");

    // cout<<s<<endl;
    auto s1 = f(Student("jim", 20, 4));
    cout << "1 => " << s1 << endl;
    auto s2 = move(s1);
    cout << "2 => " << s1 << endl;
    cout << "3 => " << s2 << endl;
    Student s3;
    cout << "4 => " << s3 << endl;
    s3 = move(s2);
    cout << "5 => " << s2 << endl;
    cout << "6 => " << s3 << endl;
}
