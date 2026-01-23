#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook( void ){

  // std::cout << "Initializing Phone Book" << std::endl;
  this->_counter = 0;
  this->_tot_contacts = 0;
  // std::cout << "Finished initializing Phone Book" << std::endl;
}

PhoneBook::~PhoneBook( void ){

  // std::cout << "Phone Book destructor called" << std::endl;
  return ;

}

int PhoneBook::getTotContacts( void ) const{

  return this->_tot_contacts;

}

int PhoneBook::getCounter( void ) const{

  return this->_counter;

}

Contact PhoneBook::getContact( int index ) const{

  return this->_contacts[index];

}

bool PhoneBook::setCounter( int counter ){

  if (counter < 0){
    return false;
  }
  this->_counter = counter;
  return true;

}

int PhoneBook::AddContact( Contact &contact ){

  int index = this->_counter % 8;
  this->_contacts[index] = contact;
  this->_counter++;
  if (this->_tot_contacts < 8){
    this->_tot_contacts++;
  }
  return index;
}

void displayName( std::string name ){

  int len = name.length();
  if (len >= 10){
    for (int i = 0; i < 9; i++){
      std::cout << name[i];
    }
    std::cout << ".";
  }
  else{
    for (int i = 0; i < 10; i++){
      if (i < 10 - len){
        std::cout << " ";
      }
      else {
        std::cout << name[i - (10 - len)];
      }
    }
  }
}

void PhoneBook::displayPB( void ) const{

  std::cout << "     Index | First Name |  Last Name |   Nickname" << std::endl;
  for (int i = 0; i < this->_tot_contacts; i++){
    std::cout << "         " << i + 1 << " | ";
    displayName(this->_contacts[i].getFName());
    std::cout << " | ";
    displayName(this->_contacts[i].getLName());
    std::cout << " | ";
    displayName(this->_contacts[i].getNName());
    std::cout << std::endl;
  }

}