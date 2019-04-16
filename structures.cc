/*
 *
 *  Program: structures.cc
 *  Name: Zachary Knoblauch
 *  Date: 9/April/2019
 *  Description: Program fills vector with class objects from file consisting of an ID, first name, last name, and Salary
 *               Program calculates the total payroll for all employees
 *               Program outputs all IDs, first names, last names, and salaries, along with the total payroll
 *
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <vector>
#include <iomanip>

using namespace std;

struct Employees{
  int id;
  string firstName;
  string lastName;
  double salary;
};

void fillObject(Employees &emp, ifstream &read);
double calcSalary(vector<Employees> v);
void print(vector <Employees> v, ofstream &write);

int main(int argc, char const *argv[]) {

  ifstream read;
  ofstream write;
  read.open("employees.txt");
  if (read.fail()) {
    exit(1);
  }
  write.open("output.txt");
  if (write.fail()) {
    exit(1);
  }
  write.precision(2);
  vector <Employees> v;
  Employees gw;
  fillObject(gw, read);
  v.push_back(gw);

  Employees ja;
  fillObject(ja, read);
  v.push_back(ja);

  Employees tj;
  fillObject(tj, read);
  v.push_back(tj);

  Employees al;
  fillObject(al, read);
  v.push_back(al);

  Employees jc;
  fillObject(jc, read);
  v.push_back(jc);

  Employees gb;
  fillObject(gb, read);
  v.push_back(gb);

  print(v, write);


  read.close();
  write.close();
  return 0;
}

void fillObject(Employees &emp, ifstream &read){

    read >> emp.id;
    read >> emp.firstName;
    read >> emp.lastName;
    read >> emp.salary;

}

double calcSalary(vector<Employees> v){
  size_t length = v.size();
  double salary;
  for (size_t i = 0; i < length; i++) {
    salary += v[i].salary;
  }
  return salary;
}

void print(vector<Employees> v, ofstream &write){
  write << setw(8) << left << "ID" << setw(20) << "Name" << setw(9) << "Salary" << endl;
  for (size_t i = 0; i < 37; i++) {
    write << "-";
  }
  write << endl;
  size_t length = v.size();
  for (size_t i = 0; i < length; i++) {
    write << fixed << setw(8) << left << v[i].id << setw(20) << v[i].firstName + " " + v[i].lastName << setw(9) << v[i].salary << endl;
  }
  double payroll = calcSalary(v);
  write << endl << "Total Payroll: $" << payroll << endl;
}
