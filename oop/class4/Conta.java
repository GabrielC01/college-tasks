public class Conta {
	private static int prox_num = 1;

	private String numero;
	private Cliente titular;
	private double saldo;

	public Conta(Cliente titular)	{
		this.titular = titular;
		this.numero = String.valueOf(prox_num++);
		this.saldo = 0;
	}

	public void depositar(double valor) {
		this.saldo += valor;
	}

	public void sacar(double valor) {
		this.saldo -= valor;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}
	
	public String getNumero() {
		return this.numero;
	}

	public void setTitular(Cliente titular) {
		this.titular = titular;
	}

	public Cliente getTitular() {
		return this.titular;
	}

	public double getSaldo() {
		return this.saldo;
	}

	public String toString() {
		return "Numero.: " + this.getNumero() +
			" | Titular: " + this.titular.getNome() +
			" | Saldo..: " + this.getSaldo();
	}
}
