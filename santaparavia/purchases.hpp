//Hierarchy for the individual purchases of the game

#ifndef PURCHASES_H
#define PURCHASES_H



struct Purchase {
public:
	Purchase() : Treasury(1000) {}

	virtual ~Purchase() = default;
	virtual void cathedral() { }
	virtual void grain() { }
	virtual void land() { }
	virtual void market() { }
	virtual void mill() { }
	virtual void palace() { }
	virtual void soldiers() { }


protected:
	int Treasury;
};

struct BuyCathedral : public Purchase {

	int Cathedral = 0;
	int Clergy = 5;
	float PublicWorks = 1.0;

	void cathedral() {

		Cathedral += 1;
		Clergy = rand() % 7;
		PublicWorks += 1.0;
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
			std::cout << "You do not have to sell any grains\n";
		}
	int t = Purchase::Treasury;
	t += (BuyGrain::grains * BuyGrain::GrainPrice / 1000);
	BuyGrain::GrainReserve -= BuyGrain::grains;

	return;
	}
};

struct BuyLand : public Purchase {
	void land() {}

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
	void market() {}
};

struct BuyMill : public Purchase {
	void mill() {}
};

struct BuyPalace : public Purchase {
	void palace() {}

};

struct BuySoldiers : public Purchase {
	void soldiers() {}
};

#endif
