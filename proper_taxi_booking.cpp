#include<bits/stdc++.h>
using namespace std;

class Taxi{
public:
   static int id;
   int taxiId;
   int freeTime;
   char curSpot;
   int totEarnings;
   vector<string>trips;
   
   Taxi(){
       taxiId=id++;
       freeTime=6;
       curSpot='A';
       totEarnings=0;
       trips={};
   }
   
   void setDetails(char _curSpot,int _totEarnings,string tripDetail,int _freeTime){
      curSpot=_curSpot;
      totEarnings=_totEarnings;
      freeTime=_freeTime;
      trips.push_back(tripDetail);
   }
   
   void taxiDetails(){
      cout<<"taxi id "<<taxiId<<" is currently at "<<curSpot<<" with tot Earnings of "<<totEarnings<<" and free at "<<freeTime<<endl;
      cout<<"-----------------------------------------------------------------"<<endl;
      cout<<"taxi id \t passenger id \t\t from \t\t to \t\t totEarnings \t\t current spot"<<endl;
      for(auto trip:trips){
          cout<<trip<<endl;
      } 
   }
};

int Taxi::id=1;



class BookingTaxi{
public:
    int passengerId;
    BookingTaxi(int pId){
        passengerId=pId;
    }
    vector<Taxi>getFreeTaxies(int pickTime,vector<Taxi>&taxies,int pickSpot){
    vector<Taxi>ans;
    for(auto t:taxies){
        if(t.freeTime <= pickTime){
            if(abs(t.curSpot - pickSpot) + t.freeTime <= pickTime){
               ans.push_back(t);
            }
        }
    }
    return ans; 
    }

   void book(char pickSpot,char dropSpot,int pickTime,vector<Taxi>&freetaxies,vector<Taxi>&originalTaxies){
    int mini=999;
    int distanceBetweenSpot=0;
    int nextFreeTime=0;
    char nextSpot='Z';
    int earning=0;
    string detail="";
    Taxi bookedTaxi;
    cout<<endl;
    for(auto &t:freetaxies){
    int distanceBetweenSpot=abs(pickSpot-t.curSpot)*15;
    if(distanceBetweenSpot<mini){
     nextSpot=dropSpot;
     nextFreeTime=pickTime+abs(pickSpot-t.curSpot);
     earning=100+((abs(pickSpot-dropSpot)*15)-5)*10;
     detail = to_string(t.taxiId) + "            " + to_string(passengerId) + "          " + pickSpot + "           " + dropSpot + "                         " + to_string(earning) + "                         " + nextSpot;
    //  cout<<detail<<endl;
     mini=distanceBetweenSpot;
     bookedTaxi=t;
    }
    }
      int ind=bookedTaxi.taxiId;
      Taxi* ori=&originalTaxies[ind-1];
      cout<<"Taxi id "<<ori->taxiId<<" is Booked Successfully"<<endl;
      ori->setDetails(nextSpot,ori->totEarnings+earning,detail,nextFreeTime);
   }

   void bookTaxi(vector<Taxi>&taxies){
     cout<<"Enter the pick up spot"<<endl;
     char pickSpot;
     cin>>pickSpot;
     cout<<"Enter the drop spot"<<endl;
     char dropSpot;
     cin>>dropSpot;
     cout<<"Enter the pick up time"<<endl;
     int pickTime;
     cin>>pickTime;
     vector<Taxi>freeTaxies=getFreeTaxies(pickTime,taxies,pickSpot);
     sort(freeTaxies.begin(),freeTaxies.end(),[](const Taxi &t1,const Taxi &t2){
         return t1.totEarnings < t2.totEarnings;
     });
     book(pickSpot,dropSpot,pickTime,freeTaxies,taxies);
   }
};

int main(){
vector<Taxi>taxies;
for(int i=0;i<4;i++){
    Taxi t;
    taxies.push_back(t);
}
int loop=true;
while(loop){
    cout<<"1. Book Taxi"<<endl;
    cout<<"2. Taxi Details"<<endl;
    cout<<"3. Exit"<<endl;
    int choice;
    cin>>choice;
    int passengerId=0;
    if(choice==1){
     BookingTaxi bt(++passengerId);
     bt.bookTaxi(taxies);
    }
    else if(choice==2){
      for(auto taxi:taxies){
          taxi.taxiDetails();
          cout<<endl;
      }
    }
    else{
        loop=false;
        break;
    }
}
return 0;
}
