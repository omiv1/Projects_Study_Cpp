#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years(Employee** employee, int size){
    for (int i = 0; i < size ; i++)
    {
        if(employee[i]->getExperience() > 5){
            employee[i]->show();
        }
    }
}
void howManyEarnLessThanMeanBonus(Employee** employee,int size)
{
    float mean;
    for(int i = 0; i < size; i++)
    {
        mean = mean + employee[i]->getSalary();
    }
    mean = mean / size;
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(mean > employee[i]->calculateSalary(3)) {
            count++;
        }
    }
    cout<<count<<endl;

}
int main() {

    Employee* employees[5];

    employees[0] = new Developer("Smith", 30, 10, 5000);
    employees[1] = new Developer("Johnson", 25, 3, 4000);
    employees[2] = new TeamLeader("Williams", 35, 15, 6000);
    employees[3] = new Developer("Jones", 28, 6, 4500);
    employees[4] = new TeamLeader("Brown", 40, 20, 7000);

    whoWorkMoreThan5Years(employees, 5);
    howManyEarnLessThanMeanBonus(employees,5);

    return 0;
}
