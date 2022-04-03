// Program to invert an array and
// sum its even index elements.

public class E2 {
	public static void main(String args[]) {
		byte[] array = {1, 2, 3, 4, 5, 6, 7};	
		byte aux, sum = 0, lastIndex = (byte)(array.length - 1);	

		for (byte i = lastIndex, j = 0; i >= lastIndex / 2; i--, j++) {
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}

		for (byte i = 0; i <= lastIndex; i++)
			sum += (i % 2 == 0) ? array[i] : 0;

		System.out.printf("Vetor invertido: [ ");
		for (byte i : array) System.out.printf("%d ", i);
		System.out.printf("]\nSoma dos elementos de indice par: %d\n", sum);
	}
}
