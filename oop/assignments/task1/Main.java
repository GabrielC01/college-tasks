public class Main {
	public static void main(String args[]) {
		Candidato c1 = new Candidato("1", "Júlio");
		Candidato c2 = new Candidato("2", "Matias");
		Candidato c3 = new Candidato("3", "Paulo");

		c1.setVotos(2);
		c2.setVotos(2);
		c3.setVotos(2);

		c1.votar();
		c2.votar();
		c3.votar();

		System.out.println(c1);
		System.out.println(c2);
		System.out.println(c3);
	}
}
