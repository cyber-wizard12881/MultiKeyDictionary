#include "pch.h"

#include "CoreMultiKeyDictionary.h"

using namespace CoreMultiKeyDictionary;

void CMultiKeyDictionary::print()
{
	Console::WriteLine("------------Managed Multi-Key Dictionary------------");
	for each (String^ key in this->primaryDictionary->Keys) {
		Object^ value;
		this->primaryDictionary->TryGetValue(key, value);
		Console::WriteLine("Key:" + key + " ; Value:" + value);
	}
	Console::WriteLine("----------------------------------------------------");
}

void CMultiKeyDictionary::add(Object ^value, ... array<Object^> ^args)
{
	String^ compositeKey = String::Join(",", args);
	this->primaryDictionary->TryAdd(compositeKey, value);
}

void CMultiKeyDictionary::remove(...array<Object^>^ args)
{
	String^ compositeKey = String::Join(",", args);
	if(this->primaryDictionary->ContainsKey(compositeKey))
		this->primaryDictionary->Remove(compositeKey);
	else
		Console::WriteLine("Couldn't remove Value for Composite Key " + compositeKey + " in Managed Multi-Key Dictionary as it was not found!!");
}

Object^ CMultiKeyDictionary::get(...array<Object^>^ args)
{
	String^ compositeKey = String::Join(",", args);
	Object^ value;
	bool result= this->primaryDictionary->TryGetValue(compositeKey, value);
	if (result)
		return value;
	else {
		Console::WriteLine("Value not found for Composite Key " + compositeKey + " in Managed Multi-Key Dictionary!!");
		return nullptr;
	}
}

void CMultiKeyDictionary::clear()
{
	this->primaryDictionary->Clear();
}

