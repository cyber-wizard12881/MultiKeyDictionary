#pragma once

using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// Namespace for the .NET Framework Multi-Key Dictionary
/// </summary>
namespace NetMultiKeyDictionary {
	/// <summary>
	/// The class that represents the .NET Framework Multi-Key Dictionary ... hence the prefix 'N'
	/// </summary>
	public ref class NMultiKeyDictionary
	{
		Dictionary<String^, Object^> ^primaryDictionary;
	public:
		NMultiKeyDictionary() {
			this->primaryDictionary = gcnew Dictionary<String^, Object^>();
		}
		~NMultiKeyDictionary() {
			this->!NMultiKeyDictionary();
		}
		!NMultiKeyDictionary() {
			delete this->primaryDictionary;
		}
		void print();
		void add(Object ^value, ... array<Object^> ^args);
		void remove(... array<Object^>^ args);
		Object^ get(... array<Object^>^ args);
		void clear();
	};
}
