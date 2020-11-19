# MultiKeyDictionary
A Utility Data Structure that can hold multiple keys for a value written in C++ &amp; exposed to be consumed in .NET

## What is a Multi-Key Dictionary? <br>
We all know that a regular standard (normal) Dictionary consists of a <Key,Value> Pair. <br>
for eg. (1, "Unity") or (0, "Whole") <br>
How about extending the Key which is a single value to that which has say 2 values?<br>
Here's what I mean ..... <br>
for eg. (1, "Uno", "Unity") where the Key clearly is (1, "Uno") & the Value "Unity" <br>
If we extend this thinking to 3 or 4 or may be more .... keys of different data types .... i.e. a Tuple perhaps ..... what would you get? <br>
That's what is called a Multi-Key Dictionary. <br>
for eg. (1, "Uno", "First", 1.0f, "Pratham", "Unity") ....
where the key, which actually is a composite key ... or a Multi-key is ...  (1, "Uno", "First", 1.0f, "Pratham") & the Value "Unity"! <br>

## Does this look familiar?
If you've worked with (Relational) Databases, you may relate this kind of a Structure to a Table, where the table could have a Primary Key or a Composite Key. <br>
Now that you know That.....

## What's the use of this?
Such a Data Structure .... i.e the Multi-Key Dictionary can be a very useful and handy one where you may need to associate a value with a group of Keys and not just one! <br>
Consider a hypothetical Smart Catalog in an E-Commerce Site .... if you want to be smart and able to search your basket based on the filters of SKUs, Ratings, Genre etc. from the Catalog Offerings you may end up writing a lot of complex code! <br>
That's where a Multi-Key Dictionary comes handy .... <br>
Just pass in <SKU, Rating, Genre, Name> as the Key to the Item & it's Price as the Value! ..... <br>
i.e for eg. (12345678, 9, "Book", "The Complete Engineer", $26) <br>
Wow! Isn't that amazing! ... I am sure there's more that you can do with such a Data Structure! <br>

## So, How have I implemented this?
When posed with a task of creating a complex data structure, you need to be clear with the approach. <br>
My approach is simple and based on the facts below: <br>
1. Take in variable number of arguments for forming the Composite or Multi-Key.
2. Convert them to Strings first.
3. Concatenate them with commas to get a composite but single unique string.
4. Take a simple <String, Object> based backing store ... which could be your simple regular Dictionary or Map data Structure.
5. Take in the Value & then store the Composite Key & Value pair in the backing store.
6. Write the same operations such as add(), remove(), get(), clear() & print() as wrappers around the simple Dictionary, with caveats adhering to the same principle discussed above!
<br>
Note: As C++ doesn't permit any arguments or parameters after the variadic ones, you need to change the standard conventions of passing the Value as the first argument to the add, get, or remove methods discussed above! <br>
So now if I want to insert the following .... <br>
```
(12345678, 9, "Book", "The Complete Engineer", $26)
```
<br>
I would do something like the following .... <br>
```
mkDictionary->add($26, 12345678, 9, "Book", "The Complete Engineer")
```
<br>
to make it work with slightly new conventions! <br>

## Overview of the Code

### Organization of this Repository/Solution(s):
1. CompositeDictionary ---> a C++ based Implementation of the Multi-Key Dictionary using Templates & Variadic Arguments.
2. CoreMultiKeyDictionary ---> a C++/CLI based Implementation of the .NET Core 5.0 based Multi-Key Dictionary.
3. CoreCompositeDictionaryConsumer ---> a .NET Core 5.0 C# based Consumer of the Library mentioned above.
4. NetMultiKeyDictionary ---> a C++/CLI based Implementation of the .NET Framework based Multi-Key Dictionary.
5. NetMultiKeyDictionaryConsumer ---> a .NET Framework VB.NET based Consumer of the Library mentioned above.


### How to get it up & running?
Open the following in Visual Studio 2019 or Visual Studio Code .... <br>
1. CompositeDictionary ===> Clean and Build the Solution & Run it! See the output for yourself! And then go through the code! The output is pretty verbose & the code well documented.
2. CoreCompositeDictionaryConsumer ===> Clean and Build the Solution & Run it! See the output for yourself! And then go through the code! The output is pretty verbose & the code well documented.
3. NetMultiKeyDictionaryConsumer ===> Clean and Build the Solution & Run it! See the output for yourself! And then go through the code! The output is pretty verbose & the code well documented.
<br>
Note: You may have to install the Workloads for C++ Desktop Development, C++/CLI & .NET Core Interop.

### CompositeDictionary Solution :
I started this pet project by making use of 3 main things that C++ had to offer .... <br>
1. Templates
2. Variadic parameters/arguments & the
3. Visitor Pattern
<br>

*To Create the Dictionary do the following*
```
  MultiKeyDictionary<int, string, int , string> mkDictionary;
```

*To Add an Item to it do something like the following:* <br>
```
   mkDictionary.add(1, "Unity", 0, "Whole");
   mkDictionary.add(2, "Beta", 3, "Gamma");
   mkDictionary.add(3, "Gamma", 4, "Delta");
```

*To Remove an Item do the following*
```
  mkDictionary.remove("Beta", 3, "Gamma");
```

*To Fetch an Item do the following*
```
  int val1 = mkDictionary.get("Gamma", 4, "Delta");
```

*To Print the Contents of the Dictionary at any point in time do the following*
```
  mkDictionary.print();
```

### CoreCompositeDictionaryConsumer Solution :
As I tried to port the above to .NET, I soon realized that the templates that I had used in Std. C++ were Compile Time Constructs & They were not going to work like Generics in the .NET world which are Run-Time entities!! <br>
Awww!! .... So what do I do? <br>
Simple .... <br>
Drop the Templates & Bring in Generics!
<br>

*To Create the Dictionary do the following*
```
using (var cmkDictionary = new CoreMultiKeyDictionary.CMultiKeyDictionary())
          {
             ....
          }
```

*To Add an Item to it do something like the following:* <br>
```
   cmkDictionary.add(1, "Unity", 0, "Whole");
```

*To Remove an Item do the following*
```
  cmkDictionary.remove("Beta", 3, "Gamma");
```

*To Fetch an Item do the following*
```
  int? val1 = (int?)cmkDictionary.get("Gamma", 4, "Delta");
```

*To Print the Contents of the Dictionary at any point in time do the following*
```
   cmkDictionary.print();
```

### NetMultiKeyDictionaryConsumer Solution :
The Only Difference between this and the above one is the tricky TryAdd() method which is not present in .NET Framework, but there in .NET Core 5.0. <br>
So, what did I do? <br>
Replaced the new TryAdd() with the Obsolete Existing Add() and Removed the key and re-inserted in the case of add() with the updated value. <br>
Note: the add() in all the above examples are upserts()!!
<br>

*To Create the Dictionary do the following*
```
  Using nmkDictionary As New NMultiKeyDictionary()
```

*To Add an Item to it do something like the following:* <br>
```
   nmkDictionary.add(1, "Unity", 0, "Whole")
```

*To Remove an Item do the following*
```
  nmkDictionary.remove("Beta", 3, "Gamma")
```

*To Fetch an Item do the following*
```
  Dim val1 As Integer? = nmkDictionary.get("Gamma", 4, "Delta")
```

*To Print the Contents of the Dictionary at any point in time do the following*
```
   nmkDictionary.print()
```

### Things TO DO :
If you've reached here ... and have gone through all of the above ... then only thing is to Read the Code & go through the Comments in the Code .... and not feel hesitant to download, compile & run the following on your Systems!
<br>
If not ... then Please Clone this repository and Run the Samples as mentioned in the description above!!! <br>
<u>Note</u>: Reason out why the code has been written in that way... what constraints & design decisions were taken, what patterns were used etc. <br>
But don't feel hesitant to challenge the above!
Feel free to make improvements at your end as you may find fit!

## Further Improvements
This Implementation by no means is a complete one.... <br>
There's scope to make it Thread Safe, MultiThreaded & more Optimized! Would love to see it scale with the size of Data as well...!!!
What's more ... you can come up with a list of features to add on to a data structure like this....!!!  

## CONCLUSION
Would love to see you guys use it and enhance it on your own at your end! <br>
Like it is said ....  <i>"To be a good Pro-grammer you must think in code before you write!!!" </i>
<br>
Thank You! <br>
Happy Coding!! <br>

:-)
