public class Veiculo {
	private Proprietario proprietario;
	private String placa;
	private String modelo;
	private int ano;
	
	public Veiculo(Proprietario proprietario, String placa, String modelo, int ano) {
		this.proprietario = proprietario;
		this.placa = placa;
		this.modelo = modelo;
		this.ano = ano;
	}

	public Proprietario getProprietario() {
		return this.proprietario;
	}

	public void setProprietario(Proprietario proprietario) {
		this.proprietario = proprietario;
	}

	public String getPlaca() {
		return this.placa;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public String getModelo() {
		return this.modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public int getAno() {
		return this.ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}
}
