'' Program to invert an array and
'' sum its even index elements.

Dim array(0 To 6) As Byte = {1, 2, 3, 4, 5, 6, 7}
Dim aux As Byte
Dim j As Byte = UBound(array)
Dim sum As Byte = 0

For i As Byte = 0 To UBound(array) / 2
	aux = array(i)
	array(i) = array(j)
	array(j) = aux
	j -= 1
Next i

For i As Byte = 0 To UBound(array)
    If i = 0 Or i Mod 2 = 0 Then sum += array(i)
Next i

Print "Vetor invertido: [";
For i As Byte = 0 To UBound(array)
    Print array(i);
Next i
Print " ]"
Print "Soma dos elemento de indice par: "; sums
