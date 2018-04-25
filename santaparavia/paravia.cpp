#include <iostream>
#include <cstdio> //stdio.h in c
#include <cstring> //string.h in c
#include <ncurses.h>
#include <ctime> //time.h in c
#include <cstdlib> //stdlib in c

//Include any header files
#include "intro.hpp"
#include "player.hpp"


using namespace std;

int main(int argc, char* argv[]){

	std::cout << "Start of game enhancements\n";
	
	//Print introductory instructions of the game
	Introduction introduction;
	introduction.Intro(); 
	
	//Player profiles
	
	Player *p = new PlayerProfile;
	Player *p1 = new InitializePlayer;
	p->profile();
	p->initplayer();

	return 0;
}
