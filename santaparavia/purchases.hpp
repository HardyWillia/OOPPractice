//Class for each type of purchase/sell done in Santa Paravia

#ifndef PURCHASES_H
#define PURCHASES_H

#include "player.hpp"

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
struct SellLand : BuyLand {
	using BuyLand::BuyLand;
	void sellL() const {
		std::cout << "This function sells the land";
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
struct CheckNewTitle : public Purchase{
	using Purchase::Purchase;

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

struct NewLandAndGrainPrices {};

struct PrintGrain {};

struct ReleaseGrain {};

struct BuySellGrain {};

struct AdjustTax {};

struct StatePurchase {};
#endif
