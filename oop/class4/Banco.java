public class Banco {
	public static void main(String args[]) {
		Cliente cli_1 = new Cliente("123-4", "Pedro", 'M', "(1) 123-456");
		Cliente cli_2 = new Cliente("567-8", "Paulo", 'M', "(1) 567-890");

		Conta c1 = new Conta(cli_1);
		Conta c2 = new Conta(cli_2);

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
