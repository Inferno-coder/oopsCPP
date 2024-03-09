#include<bits/stdc++.h>
using namespace std;

class Flight{
public:
    static int id;
    static int pId;
    int flightId;
    int numOfSeats;
    int curTicketPrice;
    vector<int>passengerIdList;
    vector<int>passengerPaidList;
    vector<int>bookedTicketPerPassengerList;
    vector<string>passengerDetails;
    Flight(){ 
    flightId=id++;
    numOfSeats=50;
    curTicketPrice=2000;
    }
    void flightDetails(){
      cout<<"--------------"<<flightId<<"-------------"<<endl<<endl;
      for(auto it:passengerDetails){
          cout<<it<<endl;
      }
      cout<<"Number of tickets available: "<<numOfSeats<<endl;
      cout<<"price of a ticket          : "<<curTicketPrice<<endl<<endl;
      cout<<"-------------------------------"<<endl<<endl;
    }
    
void cancelTicket(int passId) {
    int ind = -1; // Initialize to an invalid index
    // Find the index of the passenger in the list
    for (int i = 0; i < passengerIdList.size(); i++) {
        if (passId == passengerIdList[i]) {
            ind = i;
            break; // No need to continue searching once found
        }
    }

    if (ind != -1) { // Check if passenger found
        int totTicBooked = bookedTicketPerPassengerList[ind];
        int refund = passengerPaidList[ind];
        numOfSeats += totTicBooked;
        curTicketPrice -= (200 * totTicBooked);

        // Erase passenger details
        passengerDetails.erase(passengerDetails.begin() + ind);

        // Erase passenger related data
        passengerIdList.erase(passengerIdList.begin() + ind);
        bookedTicketPerPassengerList.erase(bookedTicketPerPassengerList.begin() + ind);
        passengerPaidList.erase(passengerPaidList.begin() + ind);

        cout << "Ticket canceled successfully." << endl;
    } else {
        cout << "Passenger with ID " << passId << " not found." << endl;
    }
}

    
    void addPassenger(int passengerId,int passengerPaid,int totalTickets){
        string str="passenger "+to_string(passengerId)+" paid "+to_string(passengerPaid)+" and booked "+to_string(totalTickets)+"in flight"+to_string(flightId);
        passengerIdList.push_back(passengerId);
        passengerPaidList.push_back(passengerPaid);
        bookedTicketPerPassengerList.push_back(totalTickets);
        passengerDetails.push_back(str);
        numOfSeats-=totalTickets;
        int increment=200*totalTickets;
        curTicketPrice+=increment;
        cout<<str<<endl;
    }
};

int Flight::id=1; 
int Flight::pId=1; 

void showFlightDetails(vector<Flight>flights){
    for(auto flight:flights){
        flight.flightDetails();
    }
}



class Booking{
public:
    void book(Flight& f, int ticketsToBuy) {
        int curTicketPrice = f.curTicketPrice;
        int totSeats = f.numOfSeats;
        if (totSeats <= 0) {
            cout << "The seats are already full so try another flight or come back later" << endl;
        } else if (totSeats - ticketsToBuy < 0) {
            cout << "Only " << totSeats << " seats are available." << endl;
        } else {
            f.addPassenger(Flight::pId, 200 * ticketsToBuy, ticketsToBuy);
            cout<<"------Booked Successfully------------";
            cout<<"remember your passenger id"<<Flight::pId<<endl;
            Flight::pId++;
        }
    }
};



int main(){

vector<Flight>flights;
for(int i=0;i<3;i++){
    Flight f;
    flights.push_back(f);
}
int loop=true;
while(loop){
    cout<<"1.Book"<<endl;
    cout<<"2. cancel"<<endl;
    cout<<"3. flight details"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        {
          int flightId;
          cout<<"Enter the flight Id: "<<endl;
          cin>>flightId;
          Flight& f=flights[flightId-1];
          f.flightDetails();
          cout<<"Enter the total tickets to buy : "<<endl;
          int totTickets;
          cin>>totTickets;
          Booking b;
          b.book(f,totTickets);
         break;
        }
        case 2:
        {
         cout<<"Enter the flight id :"<<endl;
         int flightId;
         cin>>flightId;
         cout<<"Enter the passenger id"<<endl;
         int passId;
         cin>>passId;
         Flight &f=flights[flightId-1];
         f.cancelTicket(passId);
        }
        case 3:
        {
         showFlightDetails(flights); 
         break;
        }
        default:{cout<<"Enter the correct choice";break;}
     }
    }
return 0;
 }
