//Start of object-oriented design card class using an inheritance hierarchy

#include <cassert>
#include <iosfwd>

enum Rank {

	Ace,
	Two,
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
};


enum Suit {
	Spades,
	Clubs,
	Diamonds,
	Hearts,
};

enum Largeness {
	Big, 
	Little,
};

class Card {
public:

	Card(int n)
		: id(n) {}

	int get_id() const { return id; }

	//Uniquely number each card in the deck
	int id;
};


//First derived class
class RegularCard : public Card {
public:

	RegularCard(int n, Rank r, Suit s)
		:Card(n), rank(r), suit(s) {}

	Rank get_rank() const {return rank;}
	Suit get_suit() const {return suit; }

private:
	Rank rank;
	Suit suit;
};


//Second derived class
class JokerCard : public Card{
public:
	JokerCard(int n, Largeness l)
		:Card(n), size(l){}

private:
	Largeness size;
};


class Deck : public std::vector<Card*> {
public:
	Deck(std::initializer_list<Card*> list)
		: std::vector<Card*>(list){}

	Deck(const Deck& d){
		
		for (Card* c : d) {
			std::cout << c << '\n';
		}
	}
	

	~Deck() {
		for (Card* c : *this)
			delete c;
		}
	}:

Deck get_deck();
