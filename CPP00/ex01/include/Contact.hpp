#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>

class Contact{
  
  public:

    Contact( void );
    Contact( std::string fname, std::string lname, 
      std::string nickname, std::string phone, std::string secret );
    ~Contact( void );

    void displayContact( void ) const;
    std::string getFName ( void ) const;
    std::string getLName ( void ) const;
    std::string getNName ( void ) const;
    void setFname( std::string fname);
    void setLname( std::string lname);
    void setNname( std::string nickname);
    void setPhone( std::string phone);
    void setSecret( std::string secret);

  private:
  
    std::string _fname;
    std::string _lname;
    std::string _nickname;
    std::string _phone;
    std::string _secret;
};

bool ValidatePhone( std::string phone );

#endif
