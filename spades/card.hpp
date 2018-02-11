enum Rank {
	Two, //Special case since using the jokers. Is not used for Hearts and Diamonds
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
	Deuce,
	LJoker,
	BJoker,
};


enum Suit {
	Spade,
	Diamond,
	Heart,
	Club,
};


struct Card{

	Card(Rank r,  Suit s)
	: rank(r), suit(s) {}


};

