#include<iostream>
#include<string>
using namespace std;
class Employee{
private:
	int empId;
	string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;
public:
    Employee() {
        employeeCount++;
        empId = 1000 + employeeCount;
        isActive = true;
    }
    static int getEmployeeCount(){
        return employeeCount;
      }

    void setName(const string& n){
    	if(!n.empty()){
    		name = n;
    	}else{
    		cout<<"ERROR: Name cannot be empty."<<endl;
    	}
    }
    void setDepartment(const string& dep){


    	if(dep == "Engineering" || dep == "HR" || dep == "Finance" || dep == "Operations"){
    		 department = dep;
    	}else{
    		cout<<"ERROR: " <<"'"<<  dep << "'" << "is not a registered department."<<endl;
    	}
    }

    void setGrade(char g){

    	    	if(g == 'A' || g == 'B' || g == 'C' || g == 'D'){
    	    		grade = g;
    	    	}else{
    	    		cout<<"ERROR: Invalid grade " <<"'"<<  g << "'" << " Accepted values: A , B , C ,D. "<<endl;
    	    	}
    }

    void setBasicSalary(double salary){

    	if(salary > 10000 && salary < 500000){
    		basicSalary = salary;
    	}else{
    		cout<<"ERROR : Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."<<endl;
    	}
    }
    void deactivate(){
    	isActive = false;
    }

    int getEmpId() const{
    	return empId;
    }
    string getName()const{
    	return name;
    }
    string getDepartment()const{
    	return department;
    }
    char getGrade() const{
    	return grade;
    }
    double getBasicSalary()const{
    	return basicSalary;
    }
    bool getIsActive() const{
    	return isActive;
    }
    double computeAllowances() const{
    	switch(grade){
    	case 'A':
    		return basicSalary * 0.40;
    		break;
    	case 'B':
    		return basicSalary * 0.30;
    		break;
    	case 'C':
    		return basicSalary * 0.20;
    		break;
    	case 'D':
    		return basicSalary * 0.10;
    		break;
    	}
    	return 0;
    }
    double  computeGrossSalary() const{
    	 return basicSalary + computeAllowances();
    }
    double computeTax() const{
    	if( computeGrossSalary() <= 50000){
    		 return 0;
    	}else if( computeGrossSalary() <= 100000){
    		return (computeGrossSalary() - 50000) * 0.10;
    	}else{
    		return   5000 + (computeGrossSalary() - 100000) * 0.20;
    	}

    }
    double computeNetSalary() const{
      return computeGrossSalary() - computeTax();
    }
    void acceptDetails(){
    	string n ;
    	cin>>n;
    	setName(n);

    	char g;
    	cout<<"Enter grade: ";
    	cin>>g;
    	setGrade(g);

    	double salary;
    	cout<<"Enter basic salary: ";
    	cin>>salary;
    	setBasicSalary(salary);

    	string dep;
    	cout<<"Enter department: ";
    	cin>>dep;
    	setDepartment(dep);
    }
    void printPayslip() const{
    	cout<<"==========================================="<<endl;
    	cout<<"          EMPLYOEE PAYSLIP - AUG 2026      "<<endl;
    	cout<<"==========================================="<<endl;

    	cout<<"Emp ID              : "<<empId<<endl;
    	cout<<"Name                : "<<name<<endl;
    	cout<<"Department          : "<<department<<endl;
    	cout<<"Grade               : "<<grade<<endl;
    	cout<<"Status              : "<<isActive<<endl;

    	cout<<"--------------------------------------------"<<endl;

    	cout<<"Basic Salary                   : "<<"Rs."<<basicSalary<<".00"<<endl;
    	cout << "Allowances                   : " << computeAllowances() <<endl;
    	cout<<"Gross Salary                   : "<<computeGrossSalary()<<endl;

    	cout<<"--------------------------------------------"<<endl;

    	cout<<"Tax Deduction                   : "<< computeTax() <<endl;
    	cout<<"Net Salary                      : "<<computeNetSalary()<<endl;

    	cout<<"============================================"<<endl;

    }




};
int Employee::employeeCount = 0;
int main(){
//	Employee e1;
//
//	Employee *e2 = new Employee();
	Employee *e3 = new Employee();

//	e1.acceptDetails();
//	e2->acceptDetails();
	e3->acceptDetails();

//	e1.printPayslip();
//	e2->printPayslip();
	e3->printPayslip();
	e3->deactivate();
	if (!e3->getIsActive())
	cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
	cout << "Total Employees : " << Employee::getEmployeeCount() << endl;
//	delete e2;
	delete e3;
	return 0;
}


