package Exercise8;
import java.util.Scanner;

public class Exercise8 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("How many human you want to calculate?: ");
		int humanCount = sc.nextInt();
		
		HumanList humans = new HumanList();
		Human[] human = new Human[6];
		for(int i = 0;i<humanCount;i++) {
		human[i] = new Human();
		System.out.print("\nhuman weight(in KG) : ");
		double weight = sc.nextDouble();
		human[i].setWeightOnEarth(weight);
		
		WeightConverter weightConverter = new WeightConverter();
		int weightInInt = ((int)(weightConverter.getWeightOnMars(human[i].getWeightOnEarth()*100))+5);
		human[i].setWeightOnMars((double)weightInInt/100);
		
		humans.people.add(human[i]);
		}
		
		//display the weight on earth and weight on mars by using the arrayList
		for(int i = 0;i<humans.people.size();i++) {
			
		System.out.println("\n\n Weight on Earth is : " + humans.people.get(i).getWeightOnEarth() + "KG");
		System.out.println("Weight on Mars is : " + humans.people.get(i).getWeightOnMars()+ "KG");
		}
		sc.close();
	}
	
}


