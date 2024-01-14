#include<iostream>
//#include<map>
using namespace std;
class Student{
  
  string name;
  
  public:
Student(string n):name(n)
{

}
void setname(string n)
{name=n;}
string getname()
{return name;
}
};
class Courses:public Student{
//map<string, float> subject;
float credit_hour=3.0;
float GPA[5];
string sub[5]={"DS","Programming","DLD","Probability","Finance"};
float CGPA;
public:
Courses(string n):Student(n){
  cout<<"Enter the following information for "<<n<<endl;
for(int i=0;i<5;i++)
{cout<<"Enter the GPA for the course "<<sub[i]<<endl;
cin>>GPA[i];
//subject[sub[i]]=GPA[i];
}
}
void calculate_CGPA(){float sum=0.0;float c=0.0;
for(int i=0;i<5;i++)
{GPA[i]=GPA[i]*credit_hour;
sum=sum+GPA[i];
}
CGPA=sum/(credit_hour*5);

}
void display()
{
  cout<<"The CGPA of "<<getname() <<"is "<<CGPA<<endl;
}
  };



//the other way and a good way to do it is making a courses class and a student class and then make a pointer to the courses in the student class and assign it th evalue dma for 5 subjects 
//means doing aggregation 
int main()
{
  Courses c1("Ali");
  c1.calculate_CGPA();
  c1.display();
  
  Courses c2("Hiba");
  c2.calculate_CGPA();  c2.display();
  
  Courses c3("Asma");
  c3.calculate_CGPA();
  c3.display();
  
  Courses c4("Zayn");
  c4.calculate_CGPA();
  c4.display();
  
  Courses c5("Faisal");
  c5.calculate_CGPA();
  c5.display();



}