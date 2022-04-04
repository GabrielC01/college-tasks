public class Banco {
	public static void main(String args[]) {
		Conta c1 = new Conta("João Batista", "1234-5");
		Conta c2 = new Conta("Paula Leite", "6789-0");

		c1.depositar(50);
		c2.depositar(30);
		c1.depositar(100);
		c2.sacar(10);
		c1.sacar(80);

		System.out.println("Conta #1");
		System.out.println(c1);

		System.out.println();

		System.out.println("Conta #2");
		System.out.println(c2);
	}
} 
