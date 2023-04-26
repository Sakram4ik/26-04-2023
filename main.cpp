#include <iostream>
#include <string.h>
class FlightBooking {
public:
FlightBooking(int id, int capacity, int reserved,int ticket,std::string WhatDo);
  void printStatus();
  void set(int id, int capacity, int reserved, int ticket, std::string WhatDo);
  void get();
  void add(int ticket);
  void cancel(int ticket);
  void quit();
  bool checkReserved(int capacity,int reserved);
  void whatToDo(std::string WhatDo);

  private:
  int id;
  int capacity;
  int reserved;
  int ticket;
  std::string WhatDo;
};
  void FlightBooking::printStatus()
{
  std::cout<< "Flight "<<this-> id<< " : "<<this-> reserved<< "/"<<this->capacity<<" ( "<< double(this->reserved)/this->capacity * 100<<"% ) " <<"seats reserved"<< "\n" << "Your ticket: "<< this -> ticket<< "\n";
}
FlightBooking::FlightBooking(int id, int capacity, int reserved, int ticket, std::string WhatDo)
{
  set(id,capacity,reserved,ticket,WhatDo);
}
void FlightBooking::set(int inputId, int inputCapacity, int inputReserved, int inputTicket, std::string inputWhatDo ){
  id=inputId;
  capacity=inputCapacity;
  reserved=inputReserved;
  ticket = inputTicket;
  WhatDo = inputWhatDo;
}

void FlightBooking::get(){
  std::cout<<this-> id << "/"<<this-> capacity<< "/"<<this-> reserved<<"\n";
}

bool FlightBooking::checkReserved(int capacity, int reserved){
  bool checking=false;
    if(double(this->reserved)/this->capacity * 100 < 105){
    checking = true;
    }
  return checking;
}

void FlightBooking::add(int ticket){
  if(checkReserved(reserved,capacity) == true){
    reserved=ticket+reserved;
    checkReserved(reserved,capacity);
    if(checkReserved(reserved,capacity) == false){
      std::cout << "Cannot perform this operation"<< "\n";
    }
  }
  else if(checkReserved(reserved,capacity) == false){
    std::cout << "Cannot perform this operation"<< "\n";
  }
  quit();
}

void FlightBooking:: whatToDo(std::string WhatDo){
  if(WhatDo == "cancel"){
    cancel(ticket);
  }
  else if(WhatDo == "add"){
    add(ticket);
  }
  else{
    std::cout<< "No such command in our program"<< "\n";
  }
}

void FlightBooking::cancel(int ticket){
  if(checkReserved(reserved,capacity) == true){
    reserved=reserved - ticket;
    checkReserved(reserved,capacity);
    if(checkReserved(reserved,capacity) == false){
      std::cout << "Cannot perform this operation"<< "\n";
    }
  }
  quit();
}

void FlightBooking::quit(){
  if(checkReserved(capacity, reserved)){
    std::cout << "Your ticket approved, now total reserved: " << this-> reserved<< "/"<<this->capacity<<" ( "<< double(this->reserved)/this->capacity * 100<<"% ) "<< "\n";
      }
  else if(checkReserved(capacity, reserved) == false){
    std:: cout << "No such place for your order"<< "\n";
  }
  std::cout<< "Thanks for using our program"<< "\n";
}


int main() {
  int reserved = 0,
  capacity = 0,
  ticket=0;
  std::string WhatDo; 
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;
  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;
  std::cout << "Provide number of ticket: ";
  std::cin >> ticket;
  std::cout<< "What you want to do?"<<"\nInput there: ";
  std::cin>>WhatDo;
  FlightBooking booking(1, capacity, reserved, ticket, WhatDo);
  booking.printStatus();
  booking.whatToDo(WhatDo);
  return 0;
}