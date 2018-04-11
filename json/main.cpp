#include "json.hpp"

#include <iostream>

int main(int argc, int argv[]){

  	if (argc < 2)
   	 return 1;
	}
  
  	// Read an input file into a string.
  	std::ifstream ifs(argv[1]);
  	std::istreambuf_iterator<char> first(ifs);
  	std::istreambuf_iterator<char> last;
  	std::string str(first, last);
  	
	Value* val = parse(str);
  	val->print();
}
