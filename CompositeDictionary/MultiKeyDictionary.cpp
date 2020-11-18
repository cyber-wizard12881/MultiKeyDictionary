#include "MultiKeyDictionary.h"
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;

/// <summary>
/// Converts any Type to a string
/// </summary>
/// <typeparam name="Type">any Type</typeparam>
/// <param name="t">name of the Type parameter</param>
/// <returns>a string</returns>
template <typename Type> string toString(Type& t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}

/// <summary>
/// Concatenates two Types
/// </summary>
/// <typeparam name="Type1">first Type</typeparam>
/// <typeparam name="Type2">second Type</typeparam>
/// <param name="t1">first Type parameter</param>
/// <param name="t2">second Type parameter</param>
/// <param name="sep">the Separator char. for eg. ','</param>
/// <returns></returns>
template <typename Type1, typename Type2> string strConcatenate(const Type1& t1, const Type2& t2, char sep)
{
	string st1 = toString(t1);
	string st2 = toString(t2);
	return st1 + sep + st2;
}

/// <summary>
/// Generates a comma separated string from the Variable types of keys passed in
/// </summary>
/// <typeparam name="...T">Variadic Arguments .... heterogeneous types forming a composite key</typeparam>
/// <param name="...args">Variadic Parameters ... the heterogeneous parameters of the composite key</param>
/// <returns>comma separated string as a composite key</returns>
template<class ...T>
string deConstructVarArgs(T&& ...args)
{
	string multiKey;
	auto vargs = make_tuple(args...);
	multiKey = generateCompositeKey(vargs);
	return multiKey;
}

/// <summary>
/// Default Constructor
/// </summary>
/// <typeparam name="Value">the Value to be stored in the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">the Heterogeneous Keys of the Multi-Key Dictionary</typeparam>
template <typename Value, typename ...Keys>
MultiKeyDictionary<Value, Keys...>::MultiKeyDictionary()
{
}

/// <summary>
/// Prints the Contents of the Multi-Key Dictionary
/// </summary>
/// <typeparam name="Value">The Value Type of the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">The Heterogeneous Keys Types forming the Composite Key of the Multi-Key Dictionary</typeparam>
template <typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::print()
{
	cout << "-----------Multi-Key Dictionary--------------" << endl;
	for (const auto &pDict : this->primaryDictionary)
	{
		cout << "MultiKey:" << pDict.first << " ; Value:" << pDict.second << endl;
	}
	cout << "---------------------------------------------" << endl;
}

/// <summary>
/// To add an entry inside the Multi-Key Dictionary
/// </summary>
/// <typeparam name="Value">The Value Type to Add in the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">The Heterogeneous Composite Key Types in the Multi-Key Dictionary</typeparam>
/// <param name="value">The value to be added in the Multi-Key Dictionary</param>
/// <param name="...args">The key to be added in the Multi-Key Dictionary</param>
template <typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::add(const Value& value, const Keys& ...args)
{
		string multiKey = deConstructVarArgs(args...);
		this->primaryDictionary[multiKey] = value;
}

/// <summary>
/// To remove an entry from the Multi-Key Dictionary
/// </summary>
/// <typeparam name="...Keys">The Heterogeneous Composite Keys Types in the Multi-Key Dictionary</typeparam>
/// <param name="...args">The key (& its associated value) to be removed from the Multi-Key Dictionary</param>
template <typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::remove(const Keys & ...args)
{
	string multiKey = deConstructVarArgs(args...);
	if (this->primaryDictionary.find(multiKey) == this->primaryDictionary.end()) {
		cout << "Cannot remove value as the Multi-Key " << multiKey << " was not Found in the Dictionary!!" << endl;
		return;
	}
	this->primaryDictionary.erase(multiKey);
}

/// <summary>
/// To Get or Fetch the Entry from the Multi-Key Dictionary
/// </summary>
/// <typeparam name="Value">The Value Type in the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">Heterogeneous Keys Types that you want to fetch the Value for in the Multi-Key Dictionary</typeparam>
/// <param name="...args">The actual Composite Heterogeneous Keys parameter</param>
/// <returns>The Value associated with the Composite Multi-Key in the Dictionary</returns>
template<typename Value, typename ...Keys>
Value MultiKeyDictionary<Value, Keys...>::get(const Keys & ...args)
{
	string multiKey = deConstructVarArgs(args...);
	if (this->primaryDictionary.find(multiKey) == this->primaryDictionary.end()) {
		cout << "Value for Multi-Key "<<multiKey<<" not Found in Dictionary!!" << endl;
		return Value();
	}
	return this->primaryDictionary[multiKey];
}

/// <summary>
/// Removes All Entries (Clear) from the Multi-Key Dictionary
/// </summary>
/// <typeparam name="Value">The Value type in the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">The Keys Types in the Multi-Key Dictionary</typeparam>
template<typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::clear()
{
	this->primaryDictionary.clear();
}
