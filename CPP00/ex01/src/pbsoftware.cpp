#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

bool  ValidateOption( std::string option){
  return option.compare("ADD") == 0 || option.compare("SEARCH") == 0 ||
    option.compare("EXIT") == 0;
}

void ToUpperCase(std::string &s){
  for (std::size_t i = 0; i < s.length(); i++){
    s[i] = std::toupper(s[i]);
  }
}

bool PromptUser( std::string &option ){

  std::cout << "Please enter one of the following commands: " << std::endl;
  std::cout << "------\nADD\t\t\tAdd a new contact" << std::endl;
  std::cout << "SEARCH\t\t\tSearch a contact" << std::endl;
  std::cout << "EXIT\t\t\tExit the program\n------\n" << std::endl;
  while (std::getline(std::cin, option)){
    if (!option.empty()){
      ToUpperCase(option);
      std::cout << "You have entered: " << option << std::endl << std::endl;
      if (ValidateOption(option))
        return true;
      std::cout << "Invalid option. Try again.\n" << std::endl;
      std::cout << "Please enter one of the following commands: " << std::endl;
    std::cout << "------\nADD\t\t\tAdd a new contact" << std::endl;
    std::cout << "SEARCH\t\t\tSearch a contact" << std::endl;
    std::cout << "EXIT\t\t\tExit the program\n------\n" << std::endl;
    }
  }

  return false;
}

bool isOnlyWhiteSpace( std::string &s){

  for (std::size_t i = 0; i < s.length(); i++){
    if (!std::isspace(s[i]))
      return false;
  }
  return true;

}

//To transform tabs into 4 spaces
std::string processFieldInput( std::string &s){

  std::string result;

  for (std::size_t i = 0; i < s.length(); i++){
    if (s[i] == '\t'){
      for (int j = 0; j < 4; j++){
        result.append(1, ' ');
      }
    }
    else
      result.append(1, s[i]);
  }
  return result;

}

std::string promptField(std::string field_name){

  std::string value;

  std::cout << "Enter "<< field_name << ": ";
  while (std::getline(std::cin, value)){
    if (isOnlyWhiteSpace(value)){
      std::cout << "Empty " << field_name <<" entered. Try again." << std::endl;
      std::cout << "Enter " << field_name << ": ";
    }
    else{
      if (!value.empty())
        return processFieldInput(value);
      
      std::cout << "No " << field_name <<" entered. Try again." << std::endl;
      std::cout << "Enter " << field_name << ": ";
    }
  }
  return {};
}

bool CreateContact( Contact &contact ){

  std::string fname;
  std::string lname;
  std::string nickname;
  std::string phone = "";
  std::string secret;

  fname = promptField("first name");
  if (std::cin.eof())
    return false;
  lname = promptField("last name");
  if (std::cin.eof())
    return false;
  nickname = promptField("nickname");
  if (std::cin.eof())
    return false;
  std::cout << "Enter 10 digit phone number: ";
  while (std::getline(std::cin, phone)){
    if (!phone.empty() && ValidatePhone(phone))
      break ;
    std::cout << "Invalid phone number. Try again." << std::endl;
    std::cout << "Enter 10 digit phone number: ";
  }
  if (std::cin.eof())
    return false;
  secret = promptField("darkest secret");
  if (std::cin.eof())
    return false;
  
  contact.setFname(fname);
  contact.setLname(lname);
  contact.setNname(nickname);
  contact.setPhone(phone);
  contact.setSecret(secret);
  // Contact contact(fname, lname, nickname, phone, secret);
  return true;
}

bool AddContact( PhoneBook &pb ){

  Contact contact;
  if (!CreateContact(contact)){
    std::cout << "\nNo contact added." << std::endl;
    return false;
  }
  int i = pb.AddContact(contact);
  std::cout << "Contact added to the Phone Book as entry #" << i + 1 <<
  std::endl << std::endl;
  return true;
}

bool IsNumber( std::string num ){

  return (num.length() == 1 && num[0] >= 48 && num[0] <= 57);

}

bool ValidateIndex(std::string index_char, PhoneBook &pb){

  if (!(IsNumber(index_char)))
    return false;
  int max = pb.getTotContacts();
  int index = std::stoi(index_char);
  for (int i = 0; i < max; i++){
    if (i + 1 == index ){
      return true;
    }
  }
  return false;
}

bool SearchContact( PhoneBook &pb ){

  std::string index_char = " ";
  int index;

  if (pb.getTotContacts() == 0){
    std::cout << "There aren't any contacts in your Phone Book yet.\n" << std::endl;
    return true;
  }
  pb.displayPB();
  std::cout << "Enter the index of the contact you wish to see: ";
  while (std::getline(std::cin, index_char)){
    if (!index_char.empty() && ValidateIndex(index_char, pb)){
      index = stoi(index_char);
      std::cout << "You entered index: " << index << std::endl;
      Contact contact = pb.getContact(index - 1);
      contact.displayContact();
      return true;
    }
    std::cout << "Index is incorrect. Try again." << std::endl;
    std::cout << "Enter the index of the contact you wish to see: ";
  }
  return false;
}

int main( void ){

  std::cout << "WELCOME TO YOUR PHONE BOOK! ";
  std::string option;
  PhoneBook pb;
  bool state = true;
  
  while(!std::cin.eof()){
    state = PromptUser(option);
    while (state && option.compare("EXIT") != 0){
      if (option.compare("ADD") == 0){
        state = AddContact(pb);
      }
      if (option.compare("SEARCH") == 0){
        state = SearchContact(pb);
      }
      if (!state || option.compare("EXIT") == 0)
          break;
      state = PromptUser(option);
    }
    if (!state || option.compare("EXIT") == 0)
          break;
  }
  std::cout << "See you next time!" << std::endl;
  return 0;
  
}