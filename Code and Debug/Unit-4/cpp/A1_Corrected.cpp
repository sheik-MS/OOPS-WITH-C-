#include <iostream>
class Person { public: int idNumber; explicit Person(int id=0):idNumber(id){std::cout<<"Person initialized: "<<idNumber<<'\n';} };
class Student: virtual public Person { public: explicit Student(int id):Person(id){} };
class Employee: virtual public Person { public: explicit Employee(int id):Person(id){} };
class TeachingAssistant:public Student,public Employee { public: TeachingAssistant(int sid,int eid):Person(sid),Student(sid),Employee(eid){} };
int main(){TeachingAssistant ta(101,202);std::cout<<"TA ID: "<<ta.idNumber<<'\n';}
