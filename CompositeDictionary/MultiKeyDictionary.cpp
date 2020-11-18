#include "MultiKeyDictionary.h"
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;

template <typename Type> string toString(Type& t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}

template <typename Type1, typename Type2> string strConcatenate(const Type1& t1, const Type2& t2, char sep)
{
	string st1 = toString(t1);
	string st2 = toString(t2);
	return st1 + sep + st2;
}

template<class ...T>
string deConstructVarArgs(T&& ...args)
{
	string multiKey;
	auto vargs = make_tuple(args...);
	multiKey = generateCompositeKey(vargs);
	return multiKey;
}

template <typename Value, typename ...Keys>
MultiKeyDictionary<Value, Keys...>::MultiKeyDictionary()
{
}

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

template <typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::add(const Value& value, const Keys& ...args)
{
		string multiKey = deConstructVarArgs(args...);
		this->primaryDictionary[multiKey] = value;
}

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

template<typename Value, typename ...Keys>
void MultiKeyDictionary<Value, Keys...>::clear()
{
	this->primaryDictionary.clear();
}
