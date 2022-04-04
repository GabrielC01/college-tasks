import java.util.Scanner;

public class TriangleAreaOOP {
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);

		double a, b, c;

		a = scn.nextDouble();
		b = scn.nextDouble();
		c = scn.nextDouble();
		Triangle x = new Triangle(a, b, c);
		
		a = scn.nextDouble();
		b = scn.nextDouble();
		c = scn.nextDouble();
		Triangle y = new Triangle(a, b, c);

		System.out.printf("Área do triângulo X: %.2f.\n", x.getArea());
		System.out.printf("Área do triângulo Y: %.2f.\n", y.getArea());

		if (x.getArea() == y.getArea()) {
			System.out.println("ÁREAS IGUAIS.");
		} else {
			if (x.getArea() > y.getArea()) {
				System.out.println("TRIÂNGULO DE MAIOR ÁREA: X.");
			} else {
				System.out.println("TRIÂNGULO DE MAIOR ÁREA: Y.");
			}
		}
	}
}
