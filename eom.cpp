#include<iostream>
int Frist(int vi,int a,int t){
    //vf=vi+at
    int mul=a*t;
    int vf=vi+mul;
    return vf;
}
int Second(int a,int vi,int t){
    //s=vit+1/2at^2
    int one=t*t;
    int two=a*one;
    int thiser=two/2;
    int that=vi*t;
    int s=that+thiser;
    return s;
  
}
int third(int vf,int vi,int s){
    //2as=vf2-vi2
    //a=vf2-vi2/2s
     int one=vf*vf;
    int two=vi*vi;
    int thiser=one-two;
    int that=2*s;
    int a=thiser/that;
    return a;


}
int main(){
    std::string name;
    std::cout<<"Welcome,What is your name"<<std::endl;
    std::cin>>name;
    int choice;
    std::cout<<"Mr:"<<name<<" Which of the following EOM you want to solve"<<std::endl;
    std::cout<<"1:First EOM"<<std::endl;
    std::cout<<"2:Second EOM"<<std::endl;
    std::cout<<"3:Third EOM"<<std::endl;
    std::cin>>choice;
    if(choice==1){
        std::cout<<"Working with First Equation of motion"<<std::endl;
         int vi, a, t;
         std::cout<<"Enter Vi"<<std::endl;
         std::cin>>vi;
         std::cout<<"Enter acceleration"<<std::endl;
         std::cin>>a;
         std::cout<<"Enter time"<<std::endl;
         std::cin>>t;
         int result=Frist(vi, a, t);
         std::cout<<"Vf= "<<result<<std::endl;
    }
    else if(choice==2){
        std::cout<<"Working with Second Equation of motion"<<std::endl;
         int vi, a, t;
         std::cout<<"Enter Vi"<<std::endl;
         std::cin>>vi;
         std::cout<<"Enter acceleration"<<std::endl;
         std::cin>>a;
         std::cout<<"Enter time"<<std::endl;
         std::cin>>t;
         int result=Second(a, vi, t);
         std::cout<<"S= "<<result<<std::endl;
    }
     else if(choice==3){
        std::cout<<"Working with Third Equation of motion"<<std::endl;
         int vf, vi, s;
         std::cout<<"Enter Initial velocity(Vi)"<<std::endl;
         std::cin>>vi;
         std::cout<<"Enter distance"<<std::endl;
         std::cin>>s;
         std::cout<<"Enter Final velocity(Vf)"<<std::endl;
         std::cin>>vf;
         int result=third(vf, vi, s);
         std::cout<<"a= "<<result<<std::endl;
    }
    else{
        std::cout<<"Wrong option!"<<std::endl;
    }


}
