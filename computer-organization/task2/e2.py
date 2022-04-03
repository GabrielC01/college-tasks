# Program to invert an array and
# sum its even index elements.

array = [1, 2, 3, 4, 5, 6, 7]

sum = 0
for i in range(len(array)):
    array.insert(i, array.pop())
    sum += array[i] if i == 0 or i % 2 == 0 else 0

print("Vetor invertido: " + str(array))
print("Soma dos elementos de indice par: " + str(sum))
