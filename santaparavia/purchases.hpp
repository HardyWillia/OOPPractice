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
};

struct BuyLand : public Purchase {
	void land() {}
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
