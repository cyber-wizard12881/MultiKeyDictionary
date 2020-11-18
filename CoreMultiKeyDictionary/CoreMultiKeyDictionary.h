#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace CoreMultiKeyDictionary {
	public ref class CMultiKeyDictionary
	{
		Dictionary<String^, Object^> ^primaryDictionary;
	public:
		CMultiKeyDictionary() {
			this->primaryDictionary = gcnew Dictionary<String^, Object^>();
		}
		~CMultiKeyDictionary() {
			this->!CMultiKeyDictionary();
		}
		!CMultiKeyDictionary() {
			delete this->primaryDictionary;
		}
		void print();
		void add(Object ^value, ... array<Object^> ^args);
		void remove(... array<Object^>^ args);
		Object^ get(... array<Object^>^ args);
		void clear();
	};
}
