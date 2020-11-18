#include "NetMultiKeyDictionary.h"

using namespace NetMultiKeyDictionary;

/// <summary>
/// Prints all the Entries i.e CompositeKey-Value pairs in the .NET Framework Multi-Key Dictionary
/// in a prettified way on the Console 
/// </summary>
void NMultiKeyDictionary::print()
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
/// Adds an entry in the .NET Framework Multi-Key Dictionary
/// Does so, by Removing any existing entry & then adding a new One
/// The above is due to the lack of TryAdd() method in the .NET Framework 
/// which was added later on in .NET Core 5.0 
/// </summary>
/// <param name="value">The Value to be added in the .NET Framework Multi-Key Dictionary</param>
/// <param name="args">The Heterogeneous Multi-Keys forming the Composite Key to be added in the .NET Framework 
/// Multi-Key Dictionary</param>
void NMultiKeyDictionary::add(Object ^value, ... array<Object^> ^args)
{
	String^ compositeKey = String::Join(",", args);
	if (this->primaryDictionary->ContainsKey(compositeKey))
		this->primaryDictionary->Remove(compositeKey);
	this->primaryDictionary->Add(compositeKey, value);
}

/// <summary>
/// Removes an entry from the .NET Framework Multi-Key Dictionary
/// if it exists
/// else
/// throws a message on the screen (console)
/// </summary>
/// <param name="args">The Heterogeneous Multi-Key that you wish to remove from the .NET Framework Multi-
/// Key Dictionary</param>
void NMultiKeyDictionary::remove(...array<Object^>^ args)
{
	String^ compositeKey = String::Join(",", args);
	if(this->primaryDictionary->ContainsKey(compositeKey))
		this->primaryDictionary->Remove(compositeKey);
	else
		Console::WriteLine("Couldn't remove Value for Composite Key " + compositeKey + " in Managed Multi-Key Dictionary as it was not found!!");
}

/// <summary>
/// Tries to get a Value based on the Heterogeneous Multi-Key passed in
/// Returns a value if found
/// else
/// Throws a message on the Screen (Console) and returns a Null Pointer instead
/// </summary>
/// <param name="args">The Heterogeneous Multi-Key to be retrieved from the .NET Framework Multi-Key Dictionary</param>
/// <returns>The associated Value of the Multi-Key
/// OR
/// Null in case the Multi-Key is not found in the Dictionary</returns>
Object^ NMultiKeyDictionary::get(...array<Object^>^ args)
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
/// Removes All (clears) entries from the .NET Framework Multi-Key Dictionary
/// </summary>
void NMultiKeyDictionary::clear()
{
	this->primaryDictionary->Clear();
}

