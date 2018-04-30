//Total the categories as the game continues

#ifndef GENERATE_H
#define GENERATE_H

//Base class for generating totals
struct Generate {
public:


	virtual ~Generate() = default;
	virtual void harvest() {}
	virtual void income() {}


};

//Generate the harvest
struct GenHarvest : public Generate {
	void harvest(){}

};


//Generate final income 
struct GenIncome : public Generate {
	void income(){}

};


#endif

