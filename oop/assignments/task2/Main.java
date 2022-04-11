public class Main {
	public static void main(String args[]) {
		Proprietario p1 = new Proprietario("1234-5", "Matheus Aguiar", 'M', "(1) 123-456");
		Proprietario p2 = new Proprietario("5678-9", "Sara Lima", 'F', "(2) 456-789");
		Proprietario p3 = new Proprietario("5749-8", "Augusto Cesar", 'M', "(3) 567-789");

		Veiculo v1_1 = new Veiculo(p1, "abc-123", "Celta", 2007);
		Veiculo v1_2 = new Veiculo(p1, "edf-456", "Prisma", 2008);
		Veiculo v2 = new Veiculo(p2, "xfc-789", "Biz", 2000);
		Veiculo v3 = new Veiculo(p3, "epx-274", "Fusca", 1996);

		System.out.printf("Proprietario: %s	- Veiculo: %s,\t %d\n", v1_1.getProprietario().getNome(), v1_1.getModelo(), v1_1.getAno());
		System.out.printf("Proprietario: %s	- Veiculo: %s,\t %d\n", v1_2.getProprietario().getNome(), v1_2.getModelo(), v1_2.getAno());
		System.out.printf("Proprietario: %s	\t- Veiculo: %s,\t\t %d\n", v2.getProprietario().getNome(), v2.getModelo(), v2.getAno());
		System.out.printf("Proprietario: %s	- Veiculo: %s,\t %d\n", v3.getProprietario().getNome(), v3.getModelo(), v3.getAno());
	}
}
