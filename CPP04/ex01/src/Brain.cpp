#include "Brain.hpp"

Brain::Brain( void ) {

  std::cout << "Brain default constructor called." << std::endl;

}

Brain::Brain( Brain const & other ) {

  for (int i = 0; i < 100; i++){
    this->m_ideas[i] = other.m_ideas[i];
  }
  std::cout << "Brain copy constructor called." << std::endl;

}

Brain::~Brain( void ) {

  std::cout << "Brain destructor called." << std::endl;

}

Brain& Brain::operator=( Brain const & other ) {

  std::cout << "Brain copy assignment operator called." << std::endl;
  
  if (this != &other){
    for (int i = 0; i < 100; i++)
      this->m_ideas[i] = other.m_ideas[i];
  }

  return *this;

}

std::string Brain::getIdea( int i ) const {

  if (i >= 0 && i < 100){
    return this->m_ideas[i];
  }
  return ""; //Not sure how to handle this case.
  
}

bool Brain::setIdea( std::string idea, int i ){

  if (i >= 0 && i < 100){
    
    this->m_ideas[i] = idea;
    return true;
  
  }

  return false;
}