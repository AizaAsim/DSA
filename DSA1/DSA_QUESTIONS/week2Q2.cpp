#include<iostream>
using namespace std;
class Person {
private:
    string FirstName;
    string LastName;
    int BirthYear;
    int BirthDate;
    int BirthMonth;

public:
    Person(){}
    Person(string first, string last, int year, int date, int month) {
        FirstName = first;
        LastName = last;
        BirthYear = year;
        BirthMonth = month;
        BirthDate = date;
        
    }

     void display() const {
        cout << "First Name: " << FirstName << endl;
        cout << "Last Name: " << LastName << endl;
        cout << "Birth Year: " << BirthYear << endl;
        cout << "Birth Month: " << BirthMonth << endl;
        cout << "Birth Date: " << BirthDate << endl;
    }
    string getFirstName() {
        return FirstName;
    }

    string getLastName() {
        return LastName;
    }

    int getBirthYear() {
        return BirthYear;
    }

    int getBirthDate() {
        return BirthDate;
    }

    int getBirthMonth() {
        return BirthMonth;
    }

  
    void setFirstName(string first) {
        FirstName = first;
    }

    void setLastName(string last) {
        LastName = last;
    }

    void setBirthYear(int year) {
        BirthYear = year;
    }

    void setBirthDate(int date) {
        BirthDate = date;
    }

    void setBirthMonth(int month) {
        BirthMonth = month;
    }
};
void sort(Person * person,int n)
{Person temp;
  for(int i=0;i<n-1;i++)
  {int min=i;
    for(int j=i+1;j<n;j++)
    {
      if(person[j].getBirthYear()>person[min].getBirthYear())
      {
        min=j;
      }
      else if(person[j].getBirthYear()==person[min].getBirthYear())
      {
        if(person[j].getBirthMonth()>person[min].getBirthMonth())
      {
        min=j;
      }
      else if(person[j].getBirthMonth()==person[min].getBirthMonth())
      {
         if(person[j].getBirthDate()>person[min].getBirthDate())
         {
           min=j;
         }
      }

      }

    }
    if(min!=i)
    { 
temp=person[i];
person[i]=person[min];
person[min]=temp;
    }

  }



}
int main()
{int N;
  cout<<"Enter the number of persons"<<endl;
  cin>>N;
  Person person[N];
  string a,b;
  int c,d,e;
  for(int i=0;i<N;i++)
  {
    cout<<"Enter the First,Last name and bith year,birth month,birth date for Person "<<i+1<<endl;
    cin>>a>>b>>c>>d>>e;
    person[i].setFirstName(a);
     person[i].setLastName(b);
      person[i].setBirthYear(c);
       person[i].setBirthMonth(d);
        person[i].setBirthDate(e);
  }
  sort(person,N);
  cout<<"Sorted Person List"<<endl;
  for(int i=0;i<N;i++)
  { person[i].display();

  }
  }