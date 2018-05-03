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
#include "generate.hpp"
#include "others.hpp"

using namespace std;

//Functions to carry out the behavior of the game
void PlayGame(){}
void ImDead(){}

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
	Purchase *g = new BuyGrain(500, 5000, 25);
	//BuyGrain *sg = new SellGrain;
	//BuyLand *bl  new SellLand;
	Purchase *l = new BuyLand(2, 1000, 10);
	Purchase *mark = new BuyMarket;
	Purchase *mil = new BuyMill;
	Purchase *pal = new BuyPalace;
	Purchase *s = new BuySoldier;
	c->cathedral();
	g->grain();
	//sg->sellG();
	//bl->sellL();
	l->land();
	mark->market();
	mil->mill();
	pal->palace();
	s->soldier();


	//Generate Income
	Generate *ar = new AddRevenue;
	Generate *gh = new GenHarvest;
	Generate *gi = new GenIncome;

	ar->revenue();
	gh->harvest();
	gi->income();

	return 0;
}
