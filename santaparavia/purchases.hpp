//Class for each type of purchase/sell done in Santa Paravia

#ifndef PURCHASES_H
#define PURCHASES_H

#include "player.hpp"
#include "generate.hpp"

struct Purchase {
public:
	Purchase() : Treasury(1000), PublicWorks(1.0) {}

	virtual ~Purchase() = default;
	virtual void cathedral() { }
	virtual void grain() { }
	virtual void sellG() {}
	virtual void land() { }
	virtual void market() { }
	virtual void mill() { }
	virtual void palace() { }
	virtual void soldier() { }
	virtual bool checktitle() {}


protected:
	int Treasury;
	float PublicWorks;
};

struct BuyCathedral : public Purchase {
	using Purchase::Purchase;
	int Cathedral = 0;
	int Clergy = 5;

	void cathedral() {

		Cathedral += 1;
		Clergy = rand() % 7;
		PublicWorks += 1.0;
		Treasury -= 5000;
		return;
	}


};

struct BuyGrain : public Purchase {
	using Purchase::Purchase;
public:
	BuyGrain(int g, int r, int p) : grains(g), GrainReserve(r), GrainPrice(p) {}

	virtual void sellG() {}
	void grain() {
		std::cout << "How much grain do you want to buy?: ";
		std::cin >> grains;
		assert(grains >= 0);
	if(grains < 0){
		std::cout << "Invalid total amount, please enter a new amount: ";
		std::cin >> grains;
	}

	Treasury -= (grains * GrainPrice / 1000);
	GrainReserve += grains;
	return;
	}


	int grains;
	int GrainReserve;
	int GrainPrice;


};

//Selling functionality.
// TODO: derive this from BuyGrain class. done.
struct SellGrain : public BuyGrain {
	using Purchase::Purchase;
	using BuyGrain::BuyGrain;

	void sellG() {
		std::cout << "How much grain would you like to sell?: ";
		std::cin >> BuyGrain::grains;

		if(BuyGrain::grains > BuyGrain::GrainReserve){
			std::cout << "You do not have to sell any grains.\n";
		}
	//int t = Purchase::Treasury;
	//t += (BuyGrain::grains * BuyGrain::GrainPrice / 1000);
	//BuyGrain::GrainReserve -= BuyGrain::grains;

	Treasury += (grains * GrainPrice / 1000);
	GrainReserve -= grains;

	return;
	}
};

struct BuyLand : public Purchase {
	using Purchase::Purchase;
public:
	BuyLand(int l, int lr, int lp) : lands(l), LandReserve(lr), LandPrice(lp) { }


	void land() {
		std::cout << "How much land do you want to buy?: ";
		std::cin >> lands;
		assert(lands >= 0);

	Treasury -= (int)(((float)lands * LandPrice));

	return;

	}


protected:
	int lands;
	int LandReserve;
	int LandPrice;

};

//Selling functionality.
// TODO: derive this from BuyLand class
struct SellLand{
	using Purchase::Purchase;
	using BuyLand::BuyLand;
	void sellL() {
		char string[256];
		int HowMuch;
		cout << "How much land do you want to sell?: ";
		cin >> string;
	
		HowMuch = string;

		if(HowMuch > (Land - 5000)){
			cout << "You can't sell that much\n";
			return;
		}

		Land -= HowMuch;
		Treasury += (int)(((float)HowMuch * LandPrice));
		return;
	}
};

struct BuyMarket : public Purchase {
	using Purchase::Purchase;

	int Marketplace = 0;
	int Merchants = 25;

	void market() {
		Marketplace += 1;
		Merchants += 5;
		Treasury -= 1000;
		PublicWorks += 1.0;

	return;
	}
};

struct BuyMill : public Purchase {
	using Purchase::Purchase;

	int Mills = 0;

	void mill() {
		Mills += 1;
		Treasury -= 2000;
		PublicWorks += 0.25;

	return;

	}
};

struct BuyPalace : public Purchase {
	using Purchase::Purchase;

	int Palaces = 0;
	int Nobles = 4;
	void palace() {
		Palaces += 1;
		Nobles = rand() % 3;
		Treasury -= 3000;
		PublicWorks += 0.5;

	return;

	}

};

struct BuySoldier : public Purchase {
	using Purchase::Purchase;

	int Soldiers = 25;
	int Serfs = 2000;

	void soldier() {
		Soldiers += 20;
		Serfs -= 20;
		Treasury -= 500;

	return;
	}
};
/*
struct CheckNewTitle{
	using Purchase::Purchase;
	using BuyGrain::BuyGrain;
	using BuyLand::BuyLand;
	using BuyCathedral::BuyCathedral;
	using BuyMarket::BuyMarket;
	using BuyMill::BuyMill;
	using BuyPalace::BuyPalace;
	using BuySoldier::BuySoldier;
	

	int limit10(int num, int denom) {

		int val;
		val = num/denom;
		assert(denom != 0);
		return(val > 10 ? 10 : val);

	}

	bool checktitle(){
		int Total;
		/* Tally up our success so far . . . . */
		/*Total = limit10(Marketplaces, 1);
		Total += limit10(Palace, 1);
		Total += limit10(Cathedral, 1);
		Total += limit10(Mills, 1);
		Total += limit10(Treasury, 5000);
		Total += limit10(Land, 6000);
		Total += limit10(Merchants, 50);
		Total += limit10(Nobles, 5);
		Total += limit10(Soldiers, 50);
		Total += limit10(Clergy, 10);
		Total += limit10(Serfs, 2000);
		Total += limit10((int)(PublicWorks * 100.0), 500);
*/
		//TitleNum = (Total / level) - Justice;
	}
};
*/
//Other classes to implement

struct NewLandAndGrainPrices {
	using Purchase::Purchase;
	using BuyGrain::BuyGrain;
	using BuyCathedral::BuyCathedral;
	using BuySoldier::BuySoldier;

	float x, y, MyRandom;
	int h, GrainDemand, RatsAte;

	void newprices(){
		MyRandom = (float)((float)rand() / (float)RAND_MAX);

		x = (float)Land;
		y = (((float)Serfs - (float)Mills) * 100) * 5.0;

		if(y < 0.0)
			x = y;
		y = (float)GrainReserve * 2.0;

		if(y < x)
			x = 7;
		y = (float)Harvest + (MyRandom - 0.5);

		GrainReserve += h;
		GrainDemand += (Nobles * 100) + (Cathedral * 40) + (Merchants * 30);
		GrainDemand += ((Soldiers * 10) + (Serfs * 5));
		LandPrice = (3.0 * (float)Harvest + (float)rand() % 6 + 10.0) / 10.0;

		if(h < 0)
			h *= -1;
		if (h < 1)
			y = 2.0;
		else {
			y = (float)((float)GrainDemand / (float)h);
			if(y > 2.0)
				y = 2.0;
		}

		if(y < 0.8)
			y = 0.8;

		LandPrice *= y;
		
		if(LandPrice < 1.0)
			LandPrice = 1.0;

		GrainPrice = (int)(((6.0 - (float)Harvest) * 3.0 + (float)rand() & 5 + (float)rand() % 5) * 4.0 * y);

		RatsAte = h;

		return;
		}

};

struct PrintGrain {
	int Harvest;

	void grainprint(){

		switch(Harvest){

			case 0:
			case 1: printf("Drought. Famine Threatens. "); break;
			case 2: printf("Bad Weather. Poor Harvest. "); break;
			case 3: printf("Normal Weather. Average Harvest. "); break;
			case 4: printf("Good Weather. Fine Harvest. "); break;
			case 5: printf("Excellent Weather. Great Harvest! "); break;
		}

	return;
	}

};

struct ReleaseGrain {
	using BuyGrain::BuyGrain;
	using BuySoldier::BuySoldier;
	using BuyMarket::BuyMarket;
	using Generate::Generate;

	int TransplantedSers, FleeingSerfs;
	bool InvadeMe;
	
	int release(){
		double xp, zp;
		float x, z;
		char string[256];

		int HowMuch, Maximum, Minimum;
		bool isOK = false;
		Minimum = GrainReserve / 5;
		Maximum = GrainReserve - Minimum;

		while(isOK == false){

			cout << "How much grain will you release for consumption?\n";
			cout << "1 = Minimum " << Minimum << " 2 = Maximum " << Maximum << "or enter a value: ";
			cin >> string;

			HowMuch = string;

		if(HowMuch == 1)
			HowMuch = Minimum;
		if(HowMuch == 2)
			HowMuch = Maximum;
		if(HowMuch < Minimum)
			cout << "You must release at least 20% of your reserves.\n";
		else if (HowMuch > Maximum)
			cout << "You must keep at least 20%.\n";
		else
			isOK = true;
		}
		
		SoldierPay = MarketRevenue = NewSerfs = DeadSerfs = 0;
		TransplantedSerfs = FleeingSerfs = 0;
		InvadeMe = false;
		GrainReserve -= HowMuch;

		z = (float)HowMuch / (float)GrainDemand - 1.0;

		if(z > 0.0)
			z /= 2.0;
		if(z > 0.25)
			z = z / 10.0 + 0.25;

		zp = 50.0 - (double)CustomsDuty - (double)SalesTax - (double)IncomeTax;

		if(zp < 0.0)
			zp += (3.0 - (double)Justice);
		z += ((float)zp / 10.0);

		if(z > 0.5)
			z = 0.5;
		if(HowMuch < (GrainDemand - 1)){
			x = ((float)GrainDemand - (float)HowMuch) / (float)GrainDemand * 100.0 - 9.0;
			xp = (double)x;

			if(x > 65.0)
				x = 65.0;
			if(x < 0.0){
				xp = 0.0;
				x = 0.0;
			}

			procreating(3.0);
			decomposing(xp + 8.0);
		}

		else {

			procreating(7.0);
			decomposing(3.0);
	
		if((CustomsDuty + SalesTax) < 35) Merchants += rand() % 4;
		if(IncomeTax < rand() % 28){

			Nobles += rand() % 2;
			Clergy += rand() % 3;
		}
		

		if(HowMuch > (int)((float)GrainDemand * 1.3)){
			zp = (double)Serfs / 1000.0;
			z = ((float)HowMuch - (float)(GrainDemand))/(float)GrainDemand * 100.0;
			z *= ((float)zp * (float)rand() % 25);
			z += (float)rand() % 40;

			TransplantedSerfs = (int)z;
			Serfs += TransplantedSerfs;

			cout << TransplantedSerfs << " serfs move to the city\n";

			zp = (double)z;
			z = ((float)zp * (float)rand()) / (float)RAND_MAX;

			if(z > 50.0)
				z = 50.0;
			Merchants += (int)z;
			Nobles++;
			Clergy += 2;
		}
	}

	if(Justice > 2){
		JusticeRevenue = Serfs / 100 * (Justice - 2) * (Justice - 2);
		JusticeRevenue = rand() % JusticeRevenue;
		Serfs -= JusticeRevenue;
		FleeingSerfs = JusticeRevenue;

		cout << FleeingSerfs << " serfs flee harsh justice\n";
	}

	MarketRevenue = Marketplaces * 75;
	if(MarketRevenue > 0){
		Treasury += MarketRevenue;
		cout << "Your market earned " << MarketRevenue << " florins.\n";
	}

	MillRevenue = Mills * (55 + rand() % 250);
	if(MillRevenue > 0){
		Treasury += MillRevenue;
		cout << "Your woolen mill earned " << MillRevenue << " florins.\n";
	}

	SoldierPay = Soldiers * 3;
	Treasury -= SoldierPay;

	cout << "You paid your soldiers " << SoldierPay << " florins.\n";
	cout << "You have " << Serfs << " serfs in your city.\n";
	cout << "Press ENTER: ";
	cin >> string;

	if((Land / 1000) > Soldiers){
		InvadeMe = true;
		return(3);
	}

	return(0);
	}

};


struct BuySellGrain {};

struct AdjustTax {};

struct StatePurchase {};
#endif
