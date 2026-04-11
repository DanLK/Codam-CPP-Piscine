#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

  for (int i = 0; i < 4; i++){
    this->m_known_materias[i] = nullptr;
  }
  // std::cout << "MateriaSource default constructor called." << std::endl;

}


MateriaSource::MateriaSource( MateriaSource const & other ){

  for (int i = 0; i < 4; i++){
    this->m_known_materias[i] = other.m_known_materias[i]->clone();
  }
  // std::cout << "MateriaSource copy constructor called." << std::endl;
}


MateriaSource::~MateriaSource( void ){


  for (int i = 0; i < 4; i++){
    delete this->m_known_materias[i];
  }
  // std::cout << "MateriaSource destructor called." << std::endl;

}

MateriaSource& MateriaSource::operator=( MateriaSource const & other ){

  if (this != &other){
    for (int i = 0; i < 4; i++){
      this->m_known_materias[i] = other.m_known_materias[i]->clone();
    }
  }
  std::cout << "MateriaSource copy assignment operator called." << std::endl;

  return *this;

}

void MateriaSource::learnMateria(AMateria* m) {

  for (int i = 0; i < 4; i++){
    if (this->m_known_materias[i] == nullptr) {
      this->m_known_materias[i] = m->clone();
      delete m;
      // std::cout << i << std::endl;
      return ;
    }
    if (i == 3) {
      delete m;
      std::cout << "Space for known materias is full. Did not learn materia. Materia has been deleted." << std::endl;
    }
  }
}


AMateria* MateriaSource::createMateria(std::string const & type) {

  for (int i = 0; i < 4; i++){
    if (this->m_known_materias[i] != nullptr &&
        this->m_known_materias[i]->getType() == type){

      // std::cout << this->m_known_materias[i]->getType() << std::endl;
      return this->m_known_materias[i]->clone();
    }
  }
  return nullptr;
}