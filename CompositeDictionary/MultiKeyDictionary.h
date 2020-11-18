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

namespace vargs
{
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

template<typename... Ts, typename F>
string
for_each_key_in_tuple(std::tuple<Ts...> const& t, F f)
{
	string multiKey = vargs::for_each_key(t, f, std::make_integer_sequence<int, sizeof...(Ts)>());
	return multiKey;
}

struct vargsFunctor {
	template<typename T>
	string operator ()(T && t) {
		return toString(t) + ",";
	}
};

template<typename ...T>
string generateCompositeKey(std::tuple<T...>& t) {
	return for_each_key_in_tuple(t, vargsFunctor());
}
