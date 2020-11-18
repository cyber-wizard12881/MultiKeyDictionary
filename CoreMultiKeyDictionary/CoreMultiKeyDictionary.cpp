#include "pch.h"

#include "CoreMultiKeyDictionary.h"

using namespace CoreMultiKeyDictionary;

/// <summary>
/// Prints all the elements or entries of the .NET Core Multi-Key Dictionary to the Console in a prettified way
/// </summary>
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

/// <summary>
/// Tries to Add an entry to the .NET Core Multi-Key Dictionary
/// Updates the Value if the Keys match for the Value being inserted
/// </summary>
/// <param name="value">The Value for the .NET Core Multi-Key Dictionary</param>
/// <param name="args">The Heterogeneous Composite Key for the .NET Core Multi-Key Dictionary</param>
void CMultiKeyDictionary::add(Object ^value, ... array<Object^> ^args)
{
	String^ compositeKey = String::Join(",", args);
	this->primaryDictionary->TryAdd(compositeKey, value);
}

/// <summary>
/// Removes an entry from the .NET Core Multi-Key Dictionary if it's Key exists ... 
/// else
/// throws an error message on screen
/// </summary>
/// <param name="args"></param>
void CMultiKeyDictionary::remove(...array<Object^>^ args)
{
	String^ compositeKey = String::Join(",", args);
	if(this->primaryDictionary->ContainsKey(compositeKey))
		this->primaryDictionary->Remove(compositeKey);
	else
		Console::WriteLine("Couldn't remove Value for Composite Key " + compositeKey + " in Managed Multi-Key Dictionary as it was not found!!");
}

/// <summary>
/// Tries to Get a Value for the Composite Multi-Key specified from the .NET Core Multi-Key Dictionary
/// else
/// Returns a Null Pointer if none is found in the Dictionary
/// </summary>
/// <param name="args">the Heterogeneous Composite Keys forming the Multi-Key</param>
/// <returns>The Value stored corresponding to the Composite Multi-Key in the .NET Core Multi-Key Dictionary</returns>
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

/// <summary>
/// Removes All entries or key-values from the .NET Core Multi-Key Dictionary
/// </summary>
void CMultiKeyDictionary::clear()
{
	this->primaryDictionary->Clear();
}

