#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void print_array(int array[],int count){
for(int i=0;i<count;i++){
    cout<<array[i]<<"\t";
   
}
}
void play_game(){
    int guesses[251];
    int guess_count=0;
    int random=rand()%251;
    
    cout<<"Guess a number:";
    while(true){
        int guess;
        cin>>guess;
        guesses[guess_count++]=guess;
        if(guess==random){
             cout<<"Well done\n";
             break;
        }else if(guess<random){
            cout<<"no is low\n";
        }else{
            cout<<"no is high\n";
        }
    }
    print_array(guesses,guess_count);

}

int main(){
srand(time(NULL));     
int choice;
    do{cout<<"0.Quit\n1.Play Game\n";
    cin>>choice;
    switch(choice){
        case 0:
        cout<<"See you soon\n";
        break;
        case 1:
        play_game();
        break;
    }
    }
    while (choice!=0);

    
    

}