//Place for classes that I cannot find commonalities between


struct SerfsProcreating {
	int absc;
	float ord;
	int Serfs, NewSerfs;

	void procreating(float MyScale){
		absc = (int)MyScale;
		ord = MyScale - (float)absc;
		NewSerfs = (int)((((float)(rand() % absc) + ord) * (float)Serfs) / 100.0);
		Serfs += NewSerfs;

		std::cout <<  NewSerfs << " serfs born this year.\n";
		return;
	}

};

struct SerfsDecomposing {

	int absc;
	float ord;
	int Serfs, DeadSerfs;

	void decomposing(float MyScale){
		absc = (int)MyScale;
		ord = MyScale - (float)absc;
		DeadSerfs = (int)((((float)(rand() % absc) + ord) * (float)Serfs) / 100.0);
		Serfs -= DeadSerfs;

		std::cout <<  DeadSerfs << " serfs died this year.\n";
		return;
	}

};

struct SeizeAssets{

	int Marketplace = 0;
	int Palace = 0;
	int Cathedral = 0;
	int Mills = 0;
	int Land = 6000;
	float PublicWorks = 1.0;
	int Treasury = 100;
	bool isBankrupt = false;
	char goahead[256];

	void seize(){
	std::cout << "\n\nYou are bankrupt\n";
	std::cout << "\nCreditors have seized much of your assets.\n";
	std::cout << "Press y to continue: ";
	std::cin >> goahead;

	return;

	};



};
