#pragma once

#include <tuple>
#include <string>
#include <utility>
#include <type_traits>
#include <stdexcept>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/// <summary>
/// The Class to hold information for the Multi-Key Dictionary
/// </summary>
/// <typeparam name="Value">The Value Type for the Multi-Key Dictionary</typeparam>
/// <typeparam name="...Keys">The Heterogeneous Keys Types for the Multi-Key Dictionary</typeparam>
template <typename Value, typename ... Keys> 
class MultiKeyDictionary {
private:
	map<string, Value> primaryDictionary;
public:
	MultiKeyDictionary();
	void print();
	void add(const Value& value, const Keys& ...args);
	void remove(const Keys& ...args);
	Value get(const Keys& ...args);
	void clear();
};

template <typename Type> std::string toString(Type& t);

template <typename Type1, typename Type2> string strConcatenate(const Type1& t1, const Type2& t2, char sep);

template<class ...T>
string deConstructVarArgs(T&& ...args);

/// <summary>
/// Vistor Pattern to Iterate through each of the Variadic Key Types of the Composite Key of the Multi-Key Dictionary
/// </summary>
namespace vargs
{
	/// <summary>
	/// Will visit each of the Key Types forming the Multi-Key
	/// </summary>
	/// <typeparam name="T">The Heterogeneous Key Types</typeparam>
	/// <typeparam name="F">The Function Type to be called .... i.e the Visitor</typeparam>
	/// <param name="t">Key Type parameter</param>
	/// <param name="f">Function Type parameter</param>
	/// <param name="">Integer Sequence to Iterate or Enumerate upto N entries in the Composite Key</param>
	/// <returns>a Composite Key as a String</returns>
	template<typename T, typename F, int... Is>
	string
		for_each_key(T&& t, F f, std::integer_sequence<int, Is...>)
	{
		auto l = { f(std::get<Is>(t))... };
		string s;
		for (auto li : l) {
			s += toString(li);
		}
		return s;
	}	
}

/// <summary>
/// Visitor for each key in the range in the var args tuple
/// </summary>
/// <typeparam name="...Ts">Types for the Variable Arguments</typeparam>
/// <typeparam name="F">Visitor Function Type for the Var Args</typeparam>
/// <param name="t">type parameter for the var args</param>
/// <param name="f">function paramter for the var args visitor</param>
/// <returns>composite key as a string</returns>
template<typename... Ts, typename F>
string
for_each_key_in_tuple(std::tuple<Ts...> const& t, F f)
{
	string multiKey = vargs::for_each_key(t, f, std::make_integer_sequence<int, sizeof...(Ts)>());
	return multiKey;
}

/// <summary>
/// The Visitor function object or functor for the Heterogeneous Keys passed in as var args
/// </summary>
struct vargsFunctor {
	template<typename T>
	string operator ()(T && t) {
		return toString(t) + ",";
	}
};

/// <summary>
/// Generates the Composite Key as a comma separated value string from the heterogeneous Key types passed in
/// </summary>
/// <typeparam name="...T">Heterogeneous Key Types</typeparam>
/// <param name="t">key type parameter</param>
/// <returns>composite key as a string</returns>
template<typename ...T>
string generateCompositeKey(std::tuple<T...>& t) {
	return for_each_key_in_tuple(t, vargsFunctor());
}
