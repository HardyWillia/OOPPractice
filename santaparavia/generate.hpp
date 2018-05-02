//Total the categories as the game continues

#ifndef GENERATE_H
#define GENERATE_H

//Base class for generating totals
struct Generate {
public:

	Generate() : Treasury(1000), PublicWorks(1.0), SalesTaxRevenue(), IncomeTaxRevenue(), JusticeRevenue(),
	CustomsDutyRevenue(), TitleNum(1){}
	virtual ~Generate() = default;
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
	//int t = Generate::Treasury;
	//int jr = Generate::JusticeRevenue;
	//int cdr = Generate::CustomsDutyRevenue;
	//int itr = Generate::IncomeTaxRevenue;
	//int str = Generate::SalesTaxRevenue;

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

	int JusticeRevenue;
	int CustomsDutyRevenue;
	int SalesTaxRevenue;
	int IncomeTaxRevenue;

	int Justice = 2;
	int TitleNum = 1;
	int SalesTax = 10;
	int CustomsDuty = 25;
	int IncomeTax = 5;
	int nobles = 4;
	int clergy = 5;
	int merchants = 25;

	float PublicWorks = 1.0;

	void income(){
		float y;
		int revenues = 0;
		

	}

};


#endif

