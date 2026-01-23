#include "Contact.hpp"
#include <iostream>

Contact::Contact( void ){

  // std::cout << "Contact created" << std::endl;
  return;
}

bool  ValidatePhone( std::string phone){

  if (phone.length() != 10){
    return false;
  }
  for (std::size_t i = 0; i < phone.length(); i++){
    if (phone[i] < 48 || phone[i] > 59){
      return false;
    }
  }
  return true;
}

Contact::Contact( std::string fname, std::string lname, 
      std::string nickname, std::string phone, std::string secret ) :
      _fname(fname), _lname(lname), _nickname(nickname), _phone(phone),
      _secret(secret){

        if (!ValidatePhone(phone)){
          this->_phone = "0000000000";
        }
      }

Contact::~Contact( void ){
  
  // std::cout << "Contact destructor called" << std::endl;
  return;
}

std::string Contact::getFName ( void ) const{

  return this->_fname;

}

std::string Contact::getLName ( void ) const{

  return this->_lname;

}

std::string Contact::getNName ( void ) const{

  return this->_nickname;

}

void Contact::setFname( std::string fname){
  
  this->_fname = fname;

}

void Contact::setLname( std::string lname){
  
  this->_lname = lname;

}

void Contact::setNname( std::string nickname){
  
  this->_nickname = nickname;

}

void Contact::setPhone( std::string phone){
  
  this->_phone = phone;

}

void Contact::setSecret( std::string secret){
  
  this->_secret = secret;

}

void Contact::displayContact( void ) const{

  std::cout << "\nFirst name: " << this->_fname <<
        "\nLast name: " << this->_lname <<
        "\nNickname: " << this->_nickname <<
        "\nPhone number: " << this->_phone << 
        "\nDarkest secret: " << this->_secret << std::endl << std::endl;

}