#include "Character.hpp"

Character::Character( void ) : m_name("Default") {

  for (int i = 0; i < 4; i++){
    this->m_inventory[i] = nullptr;
  }
  for (int i = 0; i < 100; i++){
    this->m_trash[i] = nullptr;
  }
  std::cout << "Character default constructor called." << std::endl;

}

Character::Character( std::string name ) : m_name(name) {

  for (int i = 0; i < 4; i++){
    this->m_inventory[i] = nullptr;
  }
  for (int i = 0; i < 100; i++){
    this->m_trash[i] = nullptr;
  }
  std::cout << "Character parametrized constructor called." << std::endl;

}


Character::Character( Character const & other ) : m_name(other.m_name) {

  for (int i = 0; i < 4; i++){
    if (this->m_inventory[i] != nullptr)
      delete this->m_inventory[i];
    this->m_inventory[i] = other.m_inventory[i]->clone();
  }
  for (int i = 0; i < 100; i++){
    if (this->m_trash[i] != nullptr)
      delete this->m_trash[i];
    this->m_trash[i] = other.m_trash[i]->clone();
  }
  std::cout << "Character copy constructor called." << std::endl;
}


Character::~Character( void ){

  for (int i = 0; i < 4; i++){
    delete this->m_inventory[i];
  }
  for (int i = 0; i < 100; i++){
    delete this->m_trash[i];
  }
  std::cout << "Character destructor called." << std::endl;
}

Character& Character::operator=( Character const & other ){

  if (this != &other)
  {
    for (int i = 0; i < 4; i++){
      if (this->m_inventory[i] != nullptr)
        delete this->m_inventory[i];
      this->m_inventory[i] = other.m_inventory[i]->clone();
    }
    for (int i = 0; i < 100; i++){
      if (this->m_trash[i] != nullptr)
        delete this->m_trash[i];
      this->m_trash[i] = other.m_trash[i]->clone();
    }
    this->m_name = other.m_name;
  }
  std::cout << "Character copy assignment operator called." << std::endl;

  return *this;
}

std::string const & Character::getName() const {

  return this->m_name;

}

void Character::equip( AMateria* m ) {

  for (int i = 0; i < 4; i++){
    if (this->m_inventory[i] == nullptr){
      this->m_inventory[i] = m->clone();
      std::cout << this->m_name << " equiped materia: " << this->m_inventory[i]->getType() << std::endl;
      break;
    }
  }

}

void Character::unequip( int idx ) {

  if (this->m_inventory[idx] == nullptr || idx < 0 || idx > 3)
    return ;
  // delete this->m_inventory[idx];
  for (int i = 0; i < 100; i++){
    if (this->m_trash[i] == nullptr){
      this->m_trash[i] = this->m_inventory[idx];
      break;
    }
  }
  this->m_inventory[idx] = nullptr;

}

void Character::use( int idx, ICharacter& target ) {
  
  if (this->m_inventory[idx] == nullptr)
    return ;
  this->m_inventory[idx]->use(target);
}

void Character::printMaterias( void ) const {

  std::cout << this->m_name << "'s materias: [ ";
  for (int i = 0; i < 4; i++){
    if (this->m_inventory[i] == nullptr)
      std::cout << " --- ";
    else
     std::cout << " " << this->m_inventory[i]->getType() << " ";
    if (i < 3)
      std::cout << "|";
  }
  std::cout << "]" << std::endl;

}