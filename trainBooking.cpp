#include<bits/stdc++.h>
using namespace std;


class Passenger{
public:
 static int id;
 string name;
 int age;
 string gender;
 int passengerId;
 char allotedBerth;
 int seat;
 Passenger(){}
 Passenger(string _name,int _age,string _gender,char _allotedBerth){
     name=_name;
     age=_age;
     passengerId=id++;
     seat=0;
     gender=_gender;
     allotedBerth=_allotedBerth;
 }
};
int Passenger::id=1;

class Booking{
public:
  static int upperBerth;
  static int lowerBerth;
  static int middleBerth;
  static int racTicket;
  static int waitingListTicket;
  
  static vector<int>lowerBerthList;
  static vector<int>upperBerthList;
  static vector<int>middleBerthList;
  static vector<int>racList;
  static vector<int>waitingList;
    
  static queue<int>racListQueue;
  static queue<int>waitingListQueue;
  static vector<int>bookedTickets;
  static map<int,Passenger*>storedBookedDetils;
  
  void book(Passenger *p ,int seat,char berth){
      p->allotedBerth=berth;
      if(berth=='R')racListQueue.push(p->passengerId);
      if(berth=='W')waitingListQueue.push(p->passengerId);
      p->seat=seat;
      bookedTickets.push_back(p->passengerId);
      storedBookedDetils[p->passengerId]=p;
      cout<<"Passneger id:"<<p->passengerId<<endl;
      cout<<"Passneger name:"<<p->name<<endl;
      cout<<"Passneger age:"<<p->age<<endl;
      cout<<"Passneger gender:"<<p->gender<<endl;
      cout<<"Booked tikcet is "<< berth << seat <<endl;
      cout<<"-------------------------"<<endl;
  }
  
  void bookingTicket(Passenger *p,char preferredBerth){
      if(
        (preferredBerth=='L' && lowerBerth>0) ||
        (preferredBerth=='U' && upperBerth>0) ||
        (preferredBerth=='M' && middleBerth>0)
        )
        {
         if(preferredBerth=='L' && lowerBerth>0){
             cout<<"lower Berth alloted";
             lowerBerth--;
             book(p,lowerBerthList[0],'L');
             lowerBerthList.erase(lowerBerthList.begin());
         }   
         else if (preferredBerth=='M' && middleBerth>0){
             cout<<"Middle Berth alloted";
             middleBerth--;
             book(p,middleBerthList[0],'M');
             middleBerthList.erase(middleBerthList.begin());
         }
         else if (preferredBerth=='U' && upperBerth>0){
             cout<<"Upper Berth alloted";
             upperBerth--;
             book(p,upperBerthList[0],'U');
             upperBerthList.erase(upperBerthList.begin());
         }
        }
     else{
         if(lowerBerth>0){
             cout<<"lower Berth alloted";
             lowerBerth--;
             book(p,lowerBerthList[0],'L');
             lowerBerthList.erase(lowerBerthList.begin());
         }
         else if(middleBerth>0){
             cout<<"Middle Berth alloted";
             middleBerth--;
             book(p,middleBerthList[0],'M');
             middleBerthList.erase(middleBerthList.begin());
         }
         else if(upperBerth>0){
              cout<<"Upper Berth alloted";
             upperBerth--;
             book(p,upperBerthList[0],'U');
             upperBerthList.erase(upperBerthList.begin());
         }
         else if(racTicket>0){
             racTicket--;
             cout<<"RAC taicket allocated"<<endl;
             book(p,racList[0],'R');
             racList.erase(racList.begin());
         }
         else if(waitingListTicket>0){
             waitingListTicket--;
             cout<<"Waiting list taicket allocated"<<endl;
             book(p,waitingList[0],'W');
             waitingList.erase(waitingList.begin());
         }
        }
  }
  
  void cancelTickets(int id){
      if(storedBookedDetils.find(id)==storedBookedDetils.end()){
          cout<<"No person with id "<< id <<" exits";
          return;
      }
      auto *p=storedBookedDetils[id];
       bookedTickets.erase(remove(bookedTickets.begin(),bookedTickets.end(),p->passengerId),bookedTickets.end());
       storedBookedDetils.erase(id);
       cout<<"Ticket cancelled successfully--------------------------------";
      if(p->allotedBerth=='L'){
          lowerBerth++;
          lowerBerthList.push_back(p->seat);
      }
      if(p->allotedBerth=='U'){
          upperBerth++;
          upperBerthList.push_back(p->seat);
      }
      if(p->allotedBerth=='M'){
          middleBerth++;
          middleBerthList.push_back(p->seat);
      }
      if(racListQueue.size()>0){
          auto racPersonId=racListQueue.front();
          racListQueue.pop();
          auto *racPerson=storedBookedDetils[racPersonId];
          cout<<"racperson : "<<racPerson->name<<" ";
          int racPersonSeat=racPerson->seat;
          racTicket++;
          if(waitingListQueue.size()>0){
              auto waitingListPeronId=waitingListQueue.front();
              auto *waitingPerson=storedBookedDetils[waitingListPeronId];
              waitingListQueue.pop();
              cout<<"waitperson : "<<waitingPerson->name<<" ";
              waitingList.push_back(waitingPerson->id);
              waitingPerson->allotedBerth='R';
              waitingPerson->seat=racPersonSeat;
              racTicket--;
          }
          else {
              racList.erase(remove(racList.begin(),racList.end(),racPersonId),racList.end());
          }
          bookingTicket(racPerson,'L');
      }
  }
  
  void displayAllTickets(){
      if(storedBookedDetils.size()<=0){
          cout<<"Not yet any details recoreded"<<endl;return;
      }
      for(auto it:storedBookedDetils){
          auto *p=it.second;
          cout<<"Passneger id:"<<p->passengerId<<endl;
          cout<<"Passneger name:"<<p->name<<endl;
          cout<<"Passneger age:"<<p->age<<endl;
          cout<<"Passneger gender:"<<p->gender<<endl;
          cout<<"Booked tikcet is "<< p->allotedBerth <<p->seat <<endl;
          cout<<"-------------------------"<<endl;
      }
  }
  
};

int Booking:: upperBerth=0;
int Booking:: lowerBerth=0;
int Booking:: middleBerth=1;
int Booking:: racTicket=1;
int Booking:: waitingListTicket=1;
vector<int> Booking:: upperBerthList={1};
vector<int> Booking:: middleBerthList={1};
vector<int> Booking:: lowerBerthList={1};
vector<int> Booking:: racList={1};
vector<int> Booking:: waitingList={1};


queue<int>Booking:: racListQueue;
queue<int>Booking:: waitingListQueue;
vector<int>Booking::bookedTickets;
map<int,Passenger*> Booking::storedBookedDetils;



int main(){
int loop=true;
while(loop){
    cout<<"1. Book"<<endl;
    cout<<"2. cancel"<<endl;
    cout<<"3. booked Tickets Details"<<endl;
    cout<<"4. Available Tickets Details"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
    case 1:
    {
        cout<<"Enter the name :"<<endl;
        string name;
        cin>>name;
        cout<<"Enter the age :"<<endl;
        int age;
        cin>>age;
        cout<<"Enter the gender"<<endl;
        string gender;
        cin>>gender;
        cout<<"Enter the preferred Berth: "<<endl;
        char berth;
        cin>>berth;
        Passenger* p = new Passenger(name, age, gender, berth); // Correct way to create Passenger object pointer
        Booking b;
        b.bookingTicket(p, berth); 
        break;
    }
    case 2:
    {
        Booking b;
        cout<<"Enter the passenger id to cancel the ticket";
        int id;
        cin >>id;
        b.cancelTickets(id);
        break;
    }
    case 3:
    {
        Booking b;
        b.displayAllTickets();
        break;
    }
    case 4:
    {
        
    }
    }
}
return 0;
}
