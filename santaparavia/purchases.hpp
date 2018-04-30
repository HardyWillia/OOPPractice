//Class for each type of purchase/sell done in Santa Paravia

#ifndef PURCHASES_H
#define PURCHASES_H



struct Purchase {
public:
	Purchase() : Treasury(1000), PublicWorks(1.0) {}

	virtual ~Purchase() = default;
	virtual void cathedral() { }
	virtual void grain() { }
	virtual void land() { }
	virtual void market() { }
	virtual void mill() { }
	virtual void palace() { }
	virtual void soldier() { }


protected:
	int Treasury;
	float PublicWorks;
};

struct BuyCathedral : public Purchase {
	int Cathedral = 0;
	int Clergy = 5;

	void cathedral() {

		Cathedral += 1;
		Clergy = rand() % 7;
		float p = Purchase::PublicWorks;
		p += 1.0;
		int t = Purchase::Treasury;
		t -= 5000;

		return;
	}


};

struct BuyGrain : public Purchase {

public:
	BuyGrain(int g, int r, int p) : grains(g), GrainReserve(r), GrainPrice(p) {}

	void grain() {
		std::cout << "How much grain do you want to buy?: ";
		std::cin >> grains;
		assert(grains > 0);
	if(grains < 0){
		std::cout << "Invalid total amount, please enter a new amount: ";
		std::cin >> grains;
	}

	int t = Purchase::Treasury;
	t -= (grains * GrainPrice / 1000);
	GrainReserve += grains;
	return;
	}

protected:

	int grains;
	int GrainReserve;
	int GrainPrice;


};

//Selling functionality.
// TODO: derive this from BuyGrain class. done.
struct SellGrain : BuyGrain {
	using BuyGrain::BuyGrain;

	void sellG() {
		std::cout << "How much grain would you like to sell?: ";
		std::cin >> BuyGrain::grains;

		if(BuyGrain::grains > BuyGrain::GrainReserve){
			std::cout << "You do not have to sell any grains.\n";
		}
	int t = Purchase::Treasury;
	t += (BuyGrain::grains * BuyGrain::GrainPrice / 1000);
	BuyGrain::GrainReserve -= BuyGrain::grains;

	return;
	}
};

struct BuyLand : public Purchase {
public:
	BuyLand(int l, int lr, int lp) : lands(l), LandReserve(lr), LandPrice(lp) { }


	void land() {
		std::cout << "How much land do you want to buy?:";
		std::cin >> lands;
		assert(lands > 0);

	int t = Purchase::Treasury;
	t -= (int)(((float)lands * LandPrice));

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

	int Marketplace = 0;
	int Merchants = 25;

	void market() {
		Marketplace += 1;
		Merchants += 5;
		int t = Purchase::Treasury;
		t -= 1000;
		float p = Purchase::PublicWorks;
		p += 1.0;

	return;
	}
};

struct BuyMill : public Purchase {

	int Mills = 0;

	void mill() {
		Mills += 1;
		int t = Purchase::Treasury;
		float p = Purchase::PublicWorks;
		t -= 2000;
		p += 0.25;

	return;

	}
};

struct BuyPalace : public Purchase {
	int Palaces = 0;
	int Nobles = 4;
	void palace() {
		Palaces += 1;
		Nobles = rand() % 3;
		int t = Purchase::Treasury;
		float p = Purchase::PublicWorks;
		t -= 3000;
		p += 0.5;

	return;

	}

};

struct BuySoldier : public Purchase {
	int Soldiers = 25;
	int Serfs = 2000;

	void soldier() {
		Soldiers += 20;
		Serfs -= 20;
		int t = Purchase::Treasury;
		t -= 500;

	return;
	}
};

#endif
