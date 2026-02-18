#include <string>
#include <iostream>
#include <fstream>

std::string  replace_once( std::string big, std::string s1, std::string s2 , int pos){

  std::string before;
  std::string after;
  std::size_t len_small = s1.length();
  
  before = big.substr(0, pos);
  after = big.substr(pos + len_small, big.length() - before.length() - len_small);
  
  std::string& result = before;
  result.append(s2).append(after);

  return result;
}


std::string replace_in( std::string big, std::string s1, std::string s2 ){

  std::string& result = big;
  std::size_t  pos = result.find(s1);

  while (pos != std::string::npos){
    result = replace_once(result, s1, s2, pos);
    pos = result.find(s1);
  }

  return result;
}

int main( int argc, char *argv[] ){

  if (argc != 4){
    std::cout << "Wrong number of parameters." << std::endl;
    std::cout << "Usage: ./string_replace <filename> <string1> <string2>" << std::endl;
    return 1;
  }
  
  std::string file_name = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  std::string outfile_name = file_name + ".replace";

  std::ifstream filein(file_name);
  
  
  if (!filein.is_open()){
    std::cout << "Unable to open file." << std::endl;
    return 1;
  }
  std::ofstream fileout(outfile_name);
  if (!fileout.is_open()){
    std::cout << "Unable to create .replace file" << std::endl;
    return 1;
  }

  std::string line;
  while (getline(filein, line)){
    std::string result = replace_in(line, s1, s2);
    fileout << result << std::endl;
  }

  filein.close();
  fileout.close();

  return 0;
}