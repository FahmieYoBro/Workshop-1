package exercise7;
import java.util.Scanner;
public class Exercise7 {

	public static void main(String[] args) {
		double weightEarth, weightonMars;
        Scanner sc = new Scanner(System.in);
        System.out.print("Input your weight in kg: ");
        weightEarth = sc.nextDouble();
        weightonMars = (weightEarth/9.81)*3.711;

         System.out.println("Weight at earth: " +weightEarth + "kg");
         System.out.println("Weight at mars: " +String.format("%.2f", weightonMars ) + "kg");
         
        sc.close();
	}

}
