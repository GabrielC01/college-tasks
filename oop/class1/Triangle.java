public class Triangle {
	private double a;
	private double b;
	private double c;
	private double p;
	private double area;

	public Triangle(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.p = (this.a + this.b + this.c) / 2;
		this.area = Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}

	public double getA() {
		return this.a;
	}

	public double getB() {
		return this.b;
	}

	public double getC() {
		return this.c;
	}

	public double getArea() {
		return this.area;
	}
}
