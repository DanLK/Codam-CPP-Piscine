#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook{

  public:
    PhoneBook( void );
    ~PhoneBook( void );

    int AddContact(Contact &contact);
    int getCounter( void ) const;
    int getTotContacts( void ) const;
    Contact getContact( int index ) const;
    bool setCounter( int counter );
    void increaseCounter( void );
    void displayPB( void ) const;

  private:

    Contact _contacts[8];
    int _tot_contacts;
    int _counter;

};

# endif