public class Candidato {
	private String numero;
	private String nome;
	private int votos;

	public Candidato(String numero, String nome) {
		this.numero = numero;
		this.nome = nome;
		this.votos = 0;
	}

	public void votar() {
		this.votos++;
	}

	public String getNumero() {
		return this.numero;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}

	public String getNome() {
		return this.nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getVotos() {
		return this.votos;
	}

	public void setVotos(int votos) {
		this.votos = votos;
	}

	public String toString() {
		return "Nome: " + this.getNome() +
			"\t| Nº. de votos: " + this.getVotos();
	}
}
