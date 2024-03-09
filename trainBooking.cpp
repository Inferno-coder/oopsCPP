#include<bits/stdc++.h>
using namespace std;


// --------------------------------passenger class--------------------------------------

class Passenger{
public:
 static int id;
 string name;
 int age;
 string gender;
 string berthPlace;
 int passengerId=id++;
 string allotedBerth="";
 int seatNumber;
 Passenger() : name(""), age(0), gender(""), berthPlace(""), passengerId(id), allotedBerth(""), seatNumber(-1) {}

 Passenger(string _name,int _age,string _gender,string _berthPlace){
     name=_name;
     age=_age;
     gender=_gender;
     berthPlace=_berthPlace;
     allotedBerth="";
     seatNumber=-1;
 }
 
};
int Passenger::id=1;

// ----------------------------------------------------------------------------------------

// --------------------------------Ticket Booking class--------------------------------------
class Passenger; 
class TicketBooking{
public:
    static int AvailableLowerBerth;
    static int AvailableMiddleBerth;
    static int AvailableUpperBerth;
    static int AvailableRAC;
    static int AvailableWaiting;
 
    static vector<int> lbSeats;
    static vector<int> mbSeats;
    static vector<int> ubSeats;
    static vector<int> RACSeats;
    static vector<int> WaitingSeats;
    
    static queue<int>RacList;
    static queue<int>WaitingList;
    static vector<int>bookedTickets;
    static map<int,Passenger>BookedTicketDetails;
    
    void bookTicket(Passenger p,int _seatNumber,string _allotedBerth){
        p.seatNumber=_seatNumber;
        p.allotedBerth=_allotedBerth;
        bookedTickets.push_back(p.passengerId);
        BookedTicketDetails[p.passengerId]=p;
        if(_allotedBerth=="R")RacList.push(p.passengerId);
        if(_allotedBerth=="W")WaitingList.push(p.passengerId);
        cout<<"Passenger Id:"<<p.passengerId<<endl;
        cout<<"Passenger name:"<<p.name<<endl;
        cout<<"Passenger age:"<<p.age<<endl;
        cout<<"Passenger gender:"<<p.gender<<endl;
        cout<<"Passenger alloted seat:"<<_seatNumber<<" "<< _allotedBerth <<endl;
        cout<<"----------------------------Booked Successfully"<<endl;
    }
    void details(){
      for(auto it :BookedTicketDetails){
         cout<<"-------------------------------------------"<<endl;
         cout<<"Passenger id:"<<it.second.passengerId<<endl;
         cout<<"Passenger Name:"<<it.second.name<<endl;
         cout<<"Passenger gender:"<<it.second.gender<<endl;
         cout<<"Passenger age:"<<it.second.age<<endl;
         cout<<"Passenger Alloted Berth:"<<it.second.allotedBerth<<endl;
         cout<<"-------------------------------------------"<<endl;
     }   
    }
    
    void setTickets(Passenger &p){
TicketBooking tb;
if(
    p.berthPlace=="L" && tb.AvailableLowerBerth>0 ||
    p.berthPlace=="M" && tb.AvailableMiddleBerth>0 ||
    p.berthPlace=="U" && tb.AvailableUpperBerth>0    
 )
 {
  if(p.berthPlace=="L" && tb.AvailableLowerBerth>0){
      cout<<"Lower Berth Given"<<endl;
      tb.bookTicket(p,tb.lbSeats[0],"L");
      tb.AvailableLowerBerth--;
      tb.lbSeats.erase(tb.lbSeats.begin());
  }  
  else if( p.berthPlace=="M" && tb.AvailableMiddleBerth>0 ){
      cout<<"Middle Berth Given"<<endl;
      tb.bookTicket(p,tb.mbSeats[0],"M");
      tb.AvailableMiddleBerth--;
      tb.mbSeats.erase(tb.mbSeats.begin());
  }
  else if(p.berthPlace=="U" && tb.AvailableUpperBerth>0){
      cout<<"Upper Berth Given"<<endl;
      tb.bookTicket(p,tb.ubSeats[0],"U");
      tb.AvailableUpperBerth--;
      tb.ubSeats.erase(tb.ubSeats.begin());
  }
 }
 else if(tb.AvailableLowerBerth>0){
      cout<<"Lower Berth Given"<<endl;
      tb.bookTicket(p,tb.lbSeats[0],"L");
      tb.AvailableLowerBerth--;
      tb.lbSeats.erase(tb.lbSeats.begin());
 }
 else if(tb.AvailableMiddleBerth>0){
      cout<<"Middle Berth Given"<<endl;
      tb.bookTicket(p,tb.mbSeats[0],"M");
      tb.AvailableMiddleBerth--;
      tb.mbSeats.erase(tb.mbSeats.begin());
 }
 else if(tb.AvailableUpperBerth>0){
        cout<<"Upper Berth Given"<<endl;
      tb.bookTicket(p,tb.ubSeats[0],"U");
      tb.AvailableUpperBerth--;
      tb.ubSeats.erase(tb.ubSeats.begin());
 }
 else if(tb.AvailableRAC>0){
     cout<<"given Rac Berth"<<endl;;
     tb.bookTicket(p,tb.RACSeats[0],"R");
     tb.AvailableRAC--;
     tb.RACSeats.erase(tb.RACSeats.begin());
 }
 else if(tb.AvailableWaiting>0){
     cout<<"given waiting ticket"<<endl;
     tb.bookTicket(p,tb.WaitingSeats[0],"W");
     tb.AvailableWaiting--;
     tb.WaitingSeats.erase(tb.WaitingSeats.begin());
 }
 else{
     cout<<"All the seats are filled plese visit again later"<<endl;
 }
} 

    
    void cancelticket(int id){
        Passenger p=BookedTicketDetails[id];
        BookedTicketDetails.erase(id);
        bookedTickets.erase(remove(bookedTickets.begin(),bookedTickets.end(),id),bookedTickets.end());
        cout<<"---------------------------ticket canceled"<<endl;
        if(p.allotedBerth=="L"){
            int seat=p.seatNumber;
            lbSeats.push_back(seat);
            AvailableLowerBerth++;
        }
        if(p.allotedBerth=="M"){
            int seat=p.seatNumber;
            mbSeats.push_back(seat);
            AvailableMiddleBerth++;
        }
        if(p.allotedBerth=="U"){
            int seat=p.seatNumber;
            ubSeats.push_back(seat);
            AvailableUpperBerth++;
        }
        if(RacList.size()>0){
            int racPersonId=RacList.front();
            RacList.pop();
            Passenger racPerson=BookedTicketDetails[racPersonId];
            int seat=racPerson.seatNumber;
            AvailableRAC++;
            if(WaitingList.size()>0){
                int waitingPersonId=WaitingList.front();
                WaitingList.pop();
                Passenger waitingPerson=BookedTicketDetails[racPersonId];
                int waitPersonSeat=waitingPerson.seatNumber;
                WaitingSeats.push_back(waitPersonSeat);
                AvailableWaiting++;
                RacList.push(waitingPersonId);
                waitingPerson.seatNumber=seat;
                waitingPerson.allotedBerth="R";
                AvailableRAC--;
            }
            setTickets(racPerson);
        }
    }
};

int TicketBooking::AvailableLowerBerth = 1;
int TicketBooking::AvailableMiddleBerth = 1;
int TicketBooking::AvailableUpperBerth = 1;
int TicketBooking::AvailableRAC = 1;
int TicketBooking::AvailableWaiting = 1;

vector<int> TicketBooking::lbSeats = {1};
vector<int> TicketBooking::mbSeats = {1};
vector<int> TicketBooking::ubSeats = {1};
vector<int> TicketBooking::RACSeats = {1};
vector<int> TicketBooking::WaitingSeats = {1};

queue<int> TicketBooking::RacList;
queue<int> TicketBooking::WaitingList;
vector<int> TicketBooking::bookedTickets;
map<int, Passenger> TicketBooking::BookedTicketDetails;
// ----------------------------------------------------------------------------------------

// void setTickets(Passenger p){
// TicketBooking tb;
// if(
//     p.berthPlace=="L" && tb.AvailableLowerBerth>0 ||
//     p.berthPlace=="M" && tb.AvailableMiddleBerth>0 ||
//     p.berthPlace=="U" && tb.AvailableUpperBerth>0    
//  )
//  {
//   if(p.berthPlace=="L" && tb.AvailableLowerBerth>0){
//       cout<<"Lower Berth Given"<<endl;
//       tb.bookTicket(p,tb.lbSeats[0],"L");
//       tb.AvailableLowerBerth--;
//       tb.lbSeats.erase(tb.lbSeats.begin());
//   }  
//   else if( p.berthPlace=="M" && tb.AvailableMiddleBerth>0 ){
//       cout<<"Middle Berth Given"<<endl;
//       tb.bookTicket(p,tb.mbSeats[0],"M");
//       tb.AvailableMiddleBerth--;
//       tb.mbSeats.erase(tb.mbSeats.begin());
//   }
//   else if(p.berthPlace=="U" && tb.AvailableUpperBerth>0){
//       cout<<"Upper Berth Given"<<endl;
//       tb.bookTicket(p,tb.ubSeats[0],"U");
//       tb.AvailableUpperBerth--;
//       tb.ubSeats.erase(tb.ubSeats.begin());
//   }
//  }
//  else if(tb.AvailableLowerBerth>0){
//       cout<<"Lower Berth Given"<<endl;
//       tb.bookTicket(p,tb.lbSeats[0],"L");
//       tb.AvailableLowerBerth--;
//       tb.lbSeats.erase(tb.lbSeats.begin());
//  }
//  else if(tb.AvailableMiddleBerth>0){
//       cout<<"Middle Berth Given"<<endl;
//       tb.bookTicket(p,tb.mbSeats[0],"M");
//       tb.AvailableMiddleBerth--;
//       tb.mbSeats.erase(tb.mbSeats.begin());
//  }
//  else if(tb.AvailableUpperBerth>0){
//         cout<<"Upper Berth Given"<<endl;
//       tb.bookTicket(p,tb.ubSeats[0],"U");
//       tb.AvailableUpperBerth--;
//       tb.ubSeats.erase(tb.ubSeats.begin());
//  }
//  else if(tb.AvailableRAC>0){
//      cout<<"given Rac Berth"<<endl;;
//      tb.bookTicket(p,tb.RACSeats[0],"R");
//      tb.AvailableRAC--;
//      tb.RACSeats.erase(tb.RACSeats.begin());
//  }
//  else if(tb.AvailableWaiting>0){
//      cout<<"given waiting ticket"<<endl;
//      tb.bookTicket(p,tb.WaitingSeats[0],"W");
//      tb.AvailableWaiting--;
//      tb.WaitingSeats.erase(tb.WaitingSeats.begin());
//  }
//  else{
//      cout<<"All the seats are filled plese visit again later"<<endl;
//  }
// } 

int main(){
int loop=true;
while(loop){
cout<<"1. Book"<<endl;
cout<<"2. Cancel"<<endl;
cout<<"3. Available Tickets"<<endl;
cout<<"4. Booked Tickets"<<endl;
cout<<"5. Exit"<<endl;
int choice;
cin>>choice;
switch(choice){
case 1:
    {
       cout<<"Enter the Passenger name:"<<endl;
       string name;
       cin>>name;
       cout<<"Enter the age:"<<endl;
       int age;
       cin>>age;
       cout<<"Enter the gender :[M,F]"<<endl;
       string gender;
       cin>>gender;
       cout<<"Enter the berth place : [L,M,U]"<<endl;
       string berthPlace;
       cin>>berthPlace;
       cout<<endl;
       Passenger p(name,age,gender,berthPlace);
       TicketBooking tb;
       tb.setTickets(p);
       break;
    }
case 2:
    {
        int id;
        cout<<"Enter the passenger id to cancel the ticket:"<<endl;
        cin>>id;
        TicketBooking tb;
        if(tb.BookedTicketDetails.find(id)==tb.BookedTicketDetails.end()){
            cout<<"Passenger with the given id is not available"<<endl;
        }
        else{
           tb.cancelticket(id);
        }
        break;
    }
case 3:
    {
     
        break;
    }
case 4:
    {
     TicketBooking tb;
     tb.details();
     break;   
    }
case 5:
    {
      loop=false;
      break;
    }
default:{cout<<"Enter the correct option"<<endl;break;}
    
}
}
return 0;
}
