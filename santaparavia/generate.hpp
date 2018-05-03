//Total the categories as the game continues

#ifndef GENERATE_H
#define GENERATE_H

//Base class for generating totals
struct Generate {
public:

	Generate() : Treasury(1000), PublicWorks(1.0), SalesTaxRevenue(), IncomeTaxRevenue(), JusticeRevenue(),
	CustomsDutyRevenue(), TitleNum(1){}
	virtual ~Generate() = default;
	virtual void revenue() {}
	virtual void harvest() {}
	virtual void income() {}

protected:
	int Treasury;
	float PublicWorks;
	int SalesTaxRevenue;
	int IncomeTaxRevenue;
	int JusticeRevenue;
	int CustomsDutyRevenue;
	int TitleNum;
};

struct AddRevenue : public Generate {
	using Generate::Generate;

	bool isBankrupt = false;

	void revenue() {
		Treasury += JusticeRevenue + CustomsDutyRevenue;
		Treasury += IncomeTaxRevenue + SalesTaxRevenue;
		
		//Penalize deficit spending
		if(Treasury < 0)
			Treasury = (int)((float) Treasury * 1.5); //do not know if I should cast here
		if(Treasury < (-10000 * TitleNum))
			isBankrupt = true;
	return;
	}
	
};

//Generate the harvest
struct GenHarvest : public Generate {
	void harvest(){
		int Harvests = ((rand() % 5) + ((rand() % 6)/2));
		int Rats = rand() % 50;
		int GrainReserve = (GrainReserve * 100) - (GrainReserve * Rats)/100;

	return;

	}

};


//Generate final income 
struct GenIncome : public Generate {
	using Generate::Generate;

	int Justice = 2;
	int SalesTax = 10;
	int CustomsDuty = 25;
	int IncomeTax = 5;
	int nobles = 4;
	int clergy = 5;
	int merchants = 25;
	char just[256];

	void income(){
		float y;
		int revenues = 0;

		JusticeRevenue = (Justice * 300 - 500) * TitleNum;
		std::cout << "Select your justice (1-4): ";
		std::cin >> just;

		//Type of justice determined by the user
		switch(Justice){
			case 1: strcpy(just, "Very Fair"); break;
			case 2: strcpy(just, "Moderate"); break;
			case 3: strcpy(just, "Harsh"); break;
			case 4: strcpy(just, "Outrageous");
		}
		
		y = 150.0 - (float)SalesTax - (float)CustomsDuty - (float)IncomeTax;
		if( y < 1.0)
			y = 1.0;
		y /= 100.0;

		//Generate Revenue
		CustomsDutyRevenue = (nobles * 100) + (clergy * 75) + (merchants * 20 * y);
		CustomsDutyRevenue += (int)(PublicWorks * 100.0);
		CustomsDutyRevenue = (int)((float)(CustomsDuty/100) * (float)(CustomsDutyRevenue));

		SalesTaxRevenue = (nobles * 50) + (merchants * 25) + (int)(PublicWorks * 10.0);
		SalesTaxRevenue *= (y * (5 - Justice) * SalesTax);
		SalesTaxRevenue /= 200;
	
		IncomeTaxRevenue = (nobles * 250) + (int)(PublicWorks * 20.0);
		IncomeTaxRevenue += (10* Justice * nobles * y);
		IncomeTaxRevenue *= IncomeTax;
		IncomeTaxRevenue /= 100;
		
		
		revenues = CustomsDutyRevenue + SalesTaxRevenue + IncomeTaxRevenue + JusticeRevenue;

		std::cout << "State revenues " << revenues << " gold florins.\n";
		std::cout << "Customs Duty \t Sales Tax \t Income Tax \t Justice\n";
		std::cout << CustomsDutyRevenue << " \t\t " << SalesTaxRevenue << " \t\t " << IncomeTaxRevenue << " \t\t " << JusticeRevenue << " \t\t " << just << " \n ";

		return;

	}

};


#endif

