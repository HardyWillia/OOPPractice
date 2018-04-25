//Hierarchy for the individual purchases of the game

#ifndef PURCHASES_H
#define PURCHASES_H



struct Purchase {
public:

	int Treasury = 1000;

	virtual ~Purchase() = default;
	virtual void cathedral() { }
	virtual void grain() { }
	virtual void land() { }
	virtual void market() { }
	virtual void mill() { }
	virtual void palace() { }
	virtual void soldiers() { }
};

struct BuyCathedral : public Purchase {
	
	int Cathedral = 0;
	int Clergy = 5;
	float PublicWorks = 1.0;
 
	void cathedral() {
	
		Cathedral += 1;
		Clergy = rand() % 7;
		PublicWorks += 1.0;
		Treasury -= 5000;

		return;
	}

};

struct BuyGrain : public Purchase {

	int grains;
	int GrainReserve;
	int GrainPrice;

	void grain() {
		std::cout << "How much grain do you want to buy?: ";
		std::cin >> grains;
		assert(grains > 0);
	if(grains < 0){
		std::cout << "Invalid total amount, please enter a new amount: ";
		std::cin >> grains;
	}

	Treasury -= (grains * GrainPrice / 1000);
	GrainReserve += grains;
	return;
	}

	void sellG(){ }


};

//Selling functionality.
// TODO: derive this from BuyGrain class
struct SellGrain : BuyGrain {
	using BuyGrain::BuyGrain;

	void sellG() const {
		std::cout << "This function sells the grain";
	 }
};

struct BuyLand : public Purchase {
	void land() {}

	void sellL() { }
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
