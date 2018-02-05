//Header file for string class

struct String {

	int len;
	char *s;
	
	//Default constructor 
	String():len(),str(nullptr){}

	//Copy constructor
	String(char const *s):len(strlen(s)), str(new char[len+1]){
		strcpy(str, s);

	}

	//Destructor - dtor
	~String(){
		delete[]str;
	}

	String & operator=(String const &s){

		delete[]str;
		len = s.len;
		str = new char[len+1];
		strcpy(str, s.str);
		return *this;
	}
}	

