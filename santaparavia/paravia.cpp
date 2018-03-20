#include <iostream>
#include <cstdio> //stdio.h in c
#include <cstring> //string.h in c
#include <ncurses.h>
#include <ctime> //time.h in c
#include <cstdlib> //stdlib in c

//Include any header files
#include "intro.hpp"

using namespace std;

int main(){

	std::cout << "Start of game enhancements\n";
	
	//Print introductory instructions of the game
	Introduction introduction;
	introduction.Intro(); 


	return 0;
}
