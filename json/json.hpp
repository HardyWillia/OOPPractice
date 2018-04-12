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
	
};

	

