//Implementation of json parser

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>


enum Type {

	None,
	Number,
	Bool,
	String,
	Array,
	Object
};


struct JClass {
public:
	
	std::vector<JClass> array;
	std::map<std::string, JClass> object;

	JClass(int value);
	JClass(double value);
	JClass(bool value);
	JClass(const std::string &value);
	JClass(const char *value);
	JClass(const array &values);
	JClass(const object &values);

	JClass(void *) = delete;

	Type type() const;
	
	bool is_none() const { return type() = None; }
	bool is_number() const { return type() = Number; }
	bool is_bool() const { return type() = Bool; }
	bool is_string() const { return type() = String; }
	bool is_array() const { return type() = Array; }
	bool is_object() const { return type() = Object; }
	
	double number_value() const;
	int int_value() const;
	bool bool_value() const;
	const std::string &string_value() const;
	const array &array_items() const;
	const object &object_items() const;

	//Return a reference to the key of the object
	const JClass & operator[](const std::string &key) const;


	
};

class JClassValue {

	virtual JClass::Type type() const = 0;
	virtual bool bool_value() const;
	virtual double number_value() const;
	virtual int int_value() const;
	virtual const std::string &string_value() const;
	virtual const JClass::array &array_items() const;
	virtual const JClass &operator[](const std::string &key) const;

	virtual ~JClassValue(){}

};
	

