public class Conta {
	private static int prox_num = 1;
	private final double LIMITE_TOTAL = 500;

	private String numero;
	private Cliente titular;
	private double saldo;
	private double saldoEspecial;

	public Conta(Cliente titular) {
		this.titular = titular;
		this.numero = String.valueOf(prox_num++);
		this.saldo = 0;
		this.saldoEspecial = this.LIMITE_TOTAL;
	}

	public void depositar(double valor) {
		this.saldo += valor;
	}

	public void sacar(double valor) throws SaldoInsuficienteException {
		if (saldo >= valor) {
			this.saldo -= valor;
		} else if (saldoEspecial >= valor){
			this.saldoEspecial -= valor;
		} else {
			throw new SaldoInsuficienteException(this);
		}
	}

	public void transferir(Conta destino, double valor) throws SaldoInsuficienteException {
		this.sacar(valor);
		destino.depositar(valor);
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

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public double getSaldo() {
		return this.saldo;
	}

	public int getProximoNumero() {
		return this.prox_num;
	}

	public String toString() {
		return "Numero: " + this.numero +
			" | Titular: " + this.titular.getCpf() +
			" | Saldo..: " + this.saldo +
			" | Limite total: " + this.LIMITE_TOTAL +
			" | Limite disponivel: " + this.saldoEspecial;
	}
}
