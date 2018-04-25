//Hierarchy for the individual purchases of the game

#ifndef PURCHASES_H
#define PURCHASES_H



struct Purchase {
public:
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
	void cathedral() {}

};

struct BuyGrain : public Purchase {
	void grain() {}

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
