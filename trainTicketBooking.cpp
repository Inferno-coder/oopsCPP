#include <bits/stdc++.h>
using namespace std;

//creating a class for the ticket application
class TicketBooking{
public:
       string name;
       int age;
       char berth;
       int totBerths=63;
       int lowerBerths=21,middleBerths=21,upperBerth=21;
       int RAC_Tickets=18;
       int waitingListTickets=10;
       unordered_map<int,vector<string>>mp;
       int id=0;
       queue<pair<int,vector<string>>>qr;
       queue<pair<int,vector<string>>>wq;
   void setDetails(string name,int age,char berth)
   {
        this->name=name;
        this->age=age;
        this->berth=berth;
        bool success=false;
        
        if(berth=='L')
        {
            if(lowerBerths > 0 && lowerBerths <=21)
            {
                this->lowerBerths--;
            }
            else
            {
                cout<<"Check the Availability";
                return;
            }
        }
        else if(berth=='M')
        {
            if(middleBerths > 0 && middleBerths <=21)
            {
                this->middleBerths--;
         
            }
            else
            {
                cout<<"Check the Availability";
                return;
            } 
            
        }
        else if(berth=='U')
        {
            if(upperBerth > 0 && upperBerth <=21)
            {
                this->upperBerth--;
            
            }
            else
            {
                cout<<"Check the Availability";
                return;
            }   
        }
        else if (berth=='R'){
            if(lowerBerths<=0 && upperBerth<=0 && middleBerths<=0)
            {
                 if(RAC_Tickets > 0 && RAC_Tickets <=18)
                {
                    this->RAC_Tickets--;
                }
                else
                {
                    cout<<"Check the Availability";
                    return;
                }   
            }
            else {
                cout<<"there are already vacency available in normal berths";
                return;
            }
        }
        else if (berth=='W'){
            if(RAC_Tickets<=0 ){
             if(waitingListTickets > 0 && waitingListTickets <=10)
            {
                this->waitingListTickets--;
            }
            else
            {
                cout<<"Check the Availability";
                return;
            }  
            }
            else {
                cout<<"there are already vacency available in RAC Tickets";
                return;
            }
        }
        vector<string>temp;
        temp.push_back(name);
        string str="";
        str=str+berth;
        temp.push_back(to_string(age));
        temp.push_back(str);
        cout<<"you've successfully booked the ticket and your ID is "<<id<<endl;
        mp[id]=temp;
        if(berth=='R')qr.push({id,temp});
        if(berth=='W')wq.push({id,temp});
        id++;
   }
   
   //let the passenger know the seats Availability 
   void availableTickets()
   {
       cout<<endl;
       cout<<"This are the available seats that you can prefer"<<endl;
       cout<<"The lowerBerths seats are..."<<lowerBerths<< endl;
       cout<<"The middleBerths seats are..."<<middleBerths <<endl;
       cout<<"The upperBerth seats are..."<<upperBerth <<endl;
       cout<<"The available RAC Tickets are ...."<<RAC_Tickets<<endl;
       cout<<"The available waiting List Tickets are.... "<<waitingListTickets<<endl;
       cout<<endl;
   }
   
   void bookedTickets()
   {
        cout<<"Total number of booked tickets: "<< mp.size()<<endl;
        cout<<"Name\t"<<"age\t"<<"berth"<<endl;
        for(auto i : mp)
        {
            for(auto j :i.second){
            cout<<j<<" ";
            }
            cout<<endl;
        }
   }
   
  void cancelTickets()
  {
  cout<<"Please enter your ID to cancel the ticket:";
  int id;
  cin>>id;
  char b=mp[id][2][0];
  mp.erase(id);
  
  if(b=='L'){
      lowerBerths++;
      if(qr.size()>0){
        auto p=qr.front();
        qr.pop();
        int tempId=p.first;
        auto tempStr=p.second;
        string x="";
        x=x+b;
        tempStr[2]=x;
        mp[tempId]=tempStr;
        RAC_Tickets++;
        lowerBerths--;
      }
      if(wq.size()>0){
        auto p=wq.front();
        wq.pop();
        int tempId=p.first;
        auto tempStr=p.second;
        tempStr[2]="R";
        mp[tempId]=tempStr;
        RAC_Tickets--;
        waitingListTickets++;
      }
  }
  
  else if(b=='M')
  {
      middleBerths++;
      if(qr.size()>0){
        auto p=qr.front();
        qr.pop();
        int tempId=p.first;
        auto tempStr=p.second;
        string x="";
        x=x+b;
        tempStr[2]=x;
        mp[tempId]=tempStr;
        RAC_Tickets++;
        middleBerths--;
      }
      if(wq.size()>0){
        auto p=wq.front();
        wq.pop();
        int tempId=p.first;
        auto tempStr=p.second;
        tempStr[2]='R';
        mp[tempId]=tempStr;
        RAC_Tickets--;
        waitingListTickets++;
      }
  }
  else if(b=='U')
  {
      upperBerth++;
      if(qr.size()>0){
        auto p=qr.front();
        qr.pop();
        int tempId=p.first;
        vector<string>tempStr=p.second;
        string x="";
        x=x+b;
        tempStr[2]=x;
        mp[tempId]=tempStr;
        RAC_Tickets++;
        upperBerth--;
      }
      if(wq.size()>0){
        auto p=wq.front();
        wq.pop();
        int tempId=p.first;
        vector<string>tempStr=p.second;
        tempStr[2]='R';
        mp[tempId]=tempStr;
        RAC_Tickets--;
        waitingListTickets++;
      }
  }
  }
   
};
int main()
{   
    int flag=1;
    TicketBooking book;
    while(flag)
    {
        //displaiyng the options for the user to boo the ticket
        cout<<"----------------------------"<<endl;
        cout<<"1.Book Ticket"<<endl;
        cout<<"2.Cancel Ticket"<<endl;
        cout<<"3.Available Ticket"<<endl;
        cout<<"4.Booked Ticket"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"----------------------------"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1 : 
            {
               
                if(book.waitingListTickets > 0)
                {
                   book.availableTickets();
                   cout<<"Enter the name ,age ,berth option (L - LOWER ,M - MIDDLE, U - UPPER) "<<endl;
                   string name;
                   int age;
                   char berth;
                   cin>>name>>age>>berth;
                  
                   book.setDetails(name,age,berth);
                  // cout<<"your Id is :"<<book.id()<<endl;
                }
                else
                {
                    cout<<"Seats are filled already so kindly visit the app later";
                }
                break;
            }
            case 2:
                book.cancelTickets();
                break;
            case 3:
                book.availableTickets();
                break;
                
            case 4:
                book.bookedTickets();
                break;
            case 5:
            flag=0;
            break;
            
            default:
            flag=0;
            break;
        }
        if(flag==0)
        {
            break;
        }

    }

    return 0;    
}





