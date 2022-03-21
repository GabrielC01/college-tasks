import java.util.Scanner;
public class TriangleArea {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		double a = scn.nextDouble();
		double b = scn.nextDouble();
		double c = scn.nextDouble();
		
		double p = (a + b + c) / 2;
		
		double area = Math.sqrt(p * (p-a) * (p-b) * (p-c));
		
		System.out.printf("Area do triangulo A: %.4f\n", area);
	}
}
