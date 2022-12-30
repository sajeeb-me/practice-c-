#include<bits/stdc++.h>

using namespace std;

//class Student
//{
//protected:
//    string name;
//    int std_id;
//    int age;
//    string father_name;
//
//public:
//    void set_information(string s, int id, int a, string f)
//    {
//        name = s;
//        std_id = id;
//        age = a;
//        father_name = f;
//    }
//
//    void print_information()
//    {
//        cout << "Name: " << name << "\n" << "ID: " << std_id << "\n" << "Age: " << age << "\n" << "Father's name: " << father_name << "\n";
//    }
//};

//class Teacher : Student
//{
//private:
//    int teacher_id;
//
//public:
//    void get_teachers_info(int t_id, string n)
//    {
//        teacher_id = t_id;
//        name = n;
//    }
//
//    void print_info()
//    {
//        cout << teacher_id << "\n" << name << "\n";
//    }
//};

class Person
{
public:
    string name;
    Person* father;
    Person* mother;

    Person()
    {
        father = NULL;
        mother = NULL;
    }
    Person(string name, string f_name, string m_name)
    {
        this->name = name;
        father = new Person;
        father->name = f_name;
        mother = new Person;
        mother->name = m_name;
    }

    void print_info()
    {
        cout << name << "\n";
        cout << father->name << "\n";
        cout << mother->name << "\n";
    }

    ~Person()
    {
        cout << "Called \n";
        if(father != NULL)
            delete father;
        if(mother != NULL)
            delete mother;
    }
};

class Student
{
public:
    string name;
    int std_id;
    int age;
    string father_name;

    Student()
    {

    }

    Student(string s, int id, int a, string f_name)
    {
        name = s;
        std_id = id;
        this->age = age;
        father_name = f_name;
    }
    Student(string s, int id, int a)
    {
        name = s;
        std_id = id;
        this->age = age;
    }

    void print_information()
    {
//        cout << "Name: " << name << "\n" << "ID: " << std_id << "\n" << "Age: " << age << "\n" << "Father's name: " << father_name << "\n";
        cout << name << " " << std_id << " " << age << " " << father_name << "\n";
    }

//    ~Student()
//    {
//        cout<<"called ";
//        print_information();
//    }

    bool operator < (Student s)
    {
        return std_id < s.std_id;
    }
};

bool comp(Student a, Student b)
{
    return a.std_id < b.std_id;
};

int main()
{
    vector<Student>s;
    for(int i=0; i<10; i++)
    {
        s.push_back(Student("My", 20-i, i, "rki"));
    }
    for(int i=0; i<10; i++)
    {
        s[i].print_information();
    }

    cout << "After sortin: \n";
    sort(s.begin(), s.end());
    for(int i=0; i<10; i++)
    {
        s[i].print_information();
    }

//    Student *s = new Student("Madei", 1006, 1005, "modi");
////    s->print_information();
//    (*s).print_information();

//    Person p("shu", "vo", "mom");
//    p.print_info();

//    Student s1("Shuvo", 1005, 100, "Shasha");
//    s1.print_information();
//
//    Student s2("Madei", 1006, 1005, "modi");
//    s2.print_information();
//
//    Student s3("Shfjd", 1009, 150);
//    s3.print_information();

//    Person p;
//    p.father = new Person;
//    p.mother = new Person;
//    p.name = "Sh";
//    p.father->name = "uvo";
//    p.mother->name = "mom";
//    p.print_info();

//    Student s1;
//    s1.name = "Shuvo";
//    s1.std_id = 202518;
//    s1.age = 20;
//    s1.father_name = "Shashadhar";
//
//    s1.print_information();
//
//    cout << "\n";
//
//    Student s2;
//    s2.name = "Sajeeb";
//    s2.std_id = 202520;
//    s2.age = 21;
//    s2.father_name = "Shashadhar";
//
//    s2.print_information();

//    Student s;
//    s.set_information("Shuvo", 1005, 20, "Shashadhar");
//    s.print_information

//    Teacher t;
//    t.get_teachers_info(1252, "Teachhh");
//    t.print_info();

    return 0;
}
