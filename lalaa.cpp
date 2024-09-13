#include<iostream>

class student{
	private:
	std::string  name;
	 std::string reg_no;
	std::string section;
	std::string batch;
	std::string Department;
	std::string  semester;
	std::string Dues;
	public:
		student(	std::string n,std::string registration_no,std::string sec,std::string b,std::string D,std::string sem,std::string Fees){
			name=n;
		    reg_no=registration_no;
			section=sec;
		    batch=b;
			Department=D;
			semester=sem;
		    Dues=Fees;
			
			
		}
		void Dispaly(){
			std::cout<<"Name:"<<name<<std::endl;
			std::cout<<"Regestration_no:"<<reg_no<<std::endl;
			std::cout<<"Section:"<<section<<std::endl;
			std::cout<<"Batch:"<<batch<<std::endl;
			std::cout<<"Department:"<<Department<<std::endl;
			std::cout<<"Semester:"<<semester<<std::endl;	
			std::cout<<"Fees:"<<Dues<<std::endl;	
		}
};
	student Ahsan(){
	
  std::string name =	"Ahsan";
	std::string reg_no="123";
	std::string section= "A";
	std::string batch="2023";  
	std::string Department="Computer Systems Engineering";
	std::string  semester="spring";
     std::string Dues="100"; 
     
		
		  
	
	    return student(name, reg_no, section, batch, Department, semester, Dues);
		
	}
		student Aimal(){
	
  std::string name =	"Aimal";
	std::string reg_no="124";
	std::string section= "A";
	std::string batch="2023";  
	std::string Department="Computer Systems Engineering";
	std::string  semester="spring";
     std::string Dues="1000"; 
     
		
		  
	
	    return student(name, reg_no, section, batch, Department, semester, Dues);
		
	}
	student Ashar(){
	
  std::string name =	"Ashar";
	std::string reg_no="125";
	std::string section= "A";
	std::string batch="2023";  
	std::string Department="Computer Systems Engineering";
	std::string  semester="spring";
     std::string Dues="500"; 
     
		
		  
	
	    return student(name, reg_no, section, batch, Department, semester, Dues);
		
	}


int main(){
	std::string Name;
	std::cout<<"Name of the student"<<std::endl;
	std::cin>>Name;
	if(Name=="Ahsan"){
	
	
	Ahsan().Dispaly();}
	else if(Name=="Aimal"){
	
	
	Aimal().Dispaly();}
	else if(Name=="Ashar"){
	
	
	Ashar().Dispaly();}
	else if(Name=="All"){
		Ahsan().Dispaly();
		std::cout<<"----------------------"<<std::endl;
		Aimal().Dispaly();
		std::cout<<"----------------------"<<std::endl;
			Ashar().Dispaly();
	}
	else{
		std::cout<<"We don't have such a student"<<std::endl;
	}
	

}
