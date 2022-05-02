public class Main {
	public static void main(String args[]) {
		Cliente cli_1 = new Cliente("111111111-11", "João Batista", 'M', "12345");
		Cliente cli_2 = new Cliente("222222222-22", "Paula Leite", 'F', "67890");

		Conta c1 = new Conta(cli_1);
		Conta c2 = new Conta(cli_2);

		c1.depositar(50);
		c2.depositar(30);
		c1.depositar(100);

		try {
			c2.sacar(10);
		} catch (SaldoInsuficienteException e) {
			System.out.println(e.getMessage());
		}

		try {
			c1.sacar(80);
		} catch (SaldoInsuficienteException e) {
			System.out.println(e.getMessage());
		}

		try {
			c1.transferir(c2, 10);
			c2.transferir(c1, 50);
		} catch (SaldoInsuficienteException e) {
			System.out.println(e.getMessage());
			System.out.println("Saldo atual: " + e.getConta().getSaldo());
		}

		c1.depositar(30);

		try {
			c1.sacar(640);				
		} catch (SaldoInsuficienteException e) {
			System.out.println(e.getMessage());
			System.out.println("Saldo atual: " + e.getConta().getSaldo());
		}

		System.out.println("Conta #1");
		System.out.println(c1);

		System.out.println();

		System.out.println("Conta #2");
		System.out.println(c2);
	}
}
