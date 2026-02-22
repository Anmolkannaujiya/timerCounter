#include  <iostream>
#include <thread>
#include <ctime>
#include <chrono>
using namespace std;

//mini project, creating a timer in cpp using ctime, chrono and thread
//note: we have to use g++ 11 or newer version, so compile the ocde like below
//g++ projectTimer.cpp -std=c++17 -o projectTimer

string getCurrentDateTime(){
    //current time
    time_t tt;

    //pointer to struct tm, local time 
    struct tm* st;

    //fetching current time
    time(&tt);

    //converting it to local time
    st = localtime(&tt);

    //return as string
    return asctime(st);
}

int main(){
    //user given total number of seconds for the counter
    int seconds;

    cout<< "Enter the number of seconds to start 'Timer' : ";
    cin>>seconds;

    //fetching current time at the start of the counter
    cout<<"The 'Timer' starts at : "<<getCurrentDateTime()<<endl;

    while(seconds>=1){
        
        //value of counter currently
        cout<<"Time remaining : "<<seconds << endl;
        this_thread::sleep_for(chrono::seconds(1));
        

        //timer decrement
        seconds--;
    }
    
    cout<<"Time remaining : "<<seconds<<endl;
    cout<<"The 'Timer' ended at : "<<getCurrentDateTime()<<endl;
    return 0;

}
