public class SaldoInsuficienteException extends Exception {
	Conta conta;

	public SaldoInsuficienteException(Conta conta) {
		super("Limite da conta " + conta.getNumero() + " atingido. " +
			"Operação não efetuada.");
		this.conta = conta;
	}

	public Conta getConta() {
		return this.conta;
	}
}
