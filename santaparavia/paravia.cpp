#include <iostream>
#include <cstdio> //stdio.h in c
#include <cstring> //string.h in c
#include <ncurses.h>
#include <ctime> //time.h in c
#include <cstdlib> //stdlib in c
#include <assert.h>

//Include any header files
#include "intro.hpp"
#include "player.hpp"
#include "purchases.hpp"


using namespace std;

int main(int argc, char* argv[]){

	std::cout << "Start of game enhancements\n";
	
	//Print introductory instructions of the game
	Introduction introduction;
	introduction.Intro(); 
	
	//Player Information
	Player *p = new PlayerProfile;
	Player *p1 = new InitializePlayer;
	p->profile();
	p1->initplayer();

	//Purchasing/Selling Items
	Purchase *c = new BuyCathedral;
	c->cathedral();

	return 0;
}
