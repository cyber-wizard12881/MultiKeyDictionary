Imports NetMultiKeyDictionary
Module NMkDictionaryModule

    Sub Main()
        Using nmkDictionary As New NMultiKeyDictionary()
            nmkDictionary.add(1, "Unity", 0, "Whole")
            nmkDictionary.add(2, "Beta", 3, "Gamma")
            nmkDictionary.add(3, "Gamma", 4, "Delta")
            nmkDictionary.add(4, "Unity", 0, "Whole")
            nmkDictionary.remove("Beta", 3, "Gamma")
            nmkDictionary.remove("Beta", 5, "Gamma")
            Dim val1 As Integer? = nmkDictionary.get("Gamma", 4, "Delta")
            Dim val2 As Integer? = nmkDictionary.get("Unity", 0, "Whole")
            Dim val3 As Integer? = nmkDictionary.get("Unity", 13, "Whole")
            nmkDictionary.print()
            nmkDictionary.clear()
            nmkDictionary.print()
            Console.ReadKey()
        End Using
    End Sub

End Module
