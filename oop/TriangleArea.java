/* Program to calculate the area of two triangles, x and y,
 * and print which one has the larger area. */

import java.util.Scanner;
public class TriangleArea {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		// Triangle x
		double[] x = new double[3];
		x[0] = scn.nextDouble();
		x[1] = scn.nextDouble();
		x[2] = scn.nextDouble();

		// Triangle y
		double[] y = new double[3];
		y[0] = scn.nextDouble();
		y[1] = scn.nextDouble();
		y[2] = scn.nextDouble();

		// x perimeter
		double xPerimeter = (x[0] + x[1] + x[2]) / 2;

		// x area
		double xArea = Math.sqrt(xPerimeter * (xPerimeter - x[0]) * (xPerimeter - x[1]) * (xPerimeter - x[2]));

		// y perimeter
		double yPerimeter = (y[0] + y[1] + y[2]) / 2;

		// y area
		double yArea = Math.sqrt(yPerimeter * (yPerimeter - y[0]) * (yPerimeter - y[1]) * (yPerimeter - y[2]));
		
		// Print both areas
		System.out.printf("X area: %.4f\n", xArea);
		System.out.printf("Y area: %.4f\n", yArea);
		// Print which one has the largest area
		if (xArea > yArea) {
			System.out.print("Triangle X has the largest area.\n");
		} else {
			if (yArea > xArea) {
				System.out.print("Triangle Y has the largest area.\n");
			} else {
				System.out.print("Both triangles have the same area value.\n");
			}
		}
	}
}
