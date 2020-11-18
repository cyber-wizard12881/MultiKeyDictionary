using System;
namespace CMultiKeyDictionaryConsumer
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var cmkDictionary = new CoreMultiKeyDictionary.CMultiKeyDictionary())
            {
                cmkDictionary.add(1, "Unity", 0, "Whole");
                cmkDictionary.add(2, "Beta", 3, "Gamma");
                cmkDictionary.add(3, "Gamma", 4, "Delta");
                cmkDictionary.add(4, "Unity", 0, "Whole");
                cmkDictionary.remove("Beta", 3, "Gamma");
                cmkDictionary.remove("Beta", 5, "Gamma");
                int? val1 = (int?)cmkDictionary.get("Gamma", 4, "Delta");
                int? val2 = (int?)cmkDictionary.get("Unity", 0, "Whole");
                int? val3 = (int?)cmkDictionary.get("Unity", 13, "Whole");
                cmkDictionary.print();
                cmkDictionary.clear();
                cmkDictionary.print();
            }
            Console.ReadKey();
        }
    }
}
