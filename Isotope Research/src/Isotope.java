
public class Isotope {
	private String halfLife;
	private String meanLife;
	private double energy = 0;
	private String name;
	private int mass;
	private double abundance = 0;
	/**
	 * Used to construct an unstable or metastable Isotope object
	 * @param n
	 * @param m
	 * @param hL
	 * @param mL
	 * @param e
	 */
	public Isotope(String n, int m, String hL, String mL, double e) {
		name = n;
		mass = m;
		halfLife = hL;
		meanLife = mL;
		energy = e;
	}
	/**
	 * Used to construct a stable Isotope object
	 * @param n
	 * @param m
	 * @param a
	 */
	public Isotope(String n, int m, double a) {
		name = n;
		mass = m;
		abundance = a;
	}
	/**
	 * Used to display the Isotope object
	 * @return a display for an Isotope object
	 */
	public String toString() {
		String stability = "";
		String result = "";
		String massFormat = "";
		String energyFormat = "";
		//Checks whether or not the object is metastable and prints out accordingly
		if(name.contains("m")) {
			stability = "metastable";
			massFormat += mass;
			energyFormat += energy;
			result = String.format("%-20s%-20s%-20s%-20s%-20s%-20s\n\n", name, massFormat, stability, halfLife, meanLife, energy);
		}
		//If there is an energy, the the object must be unstable so print out the information accordingly
		else if(energy != 0) {
			stability = "unstable";
			massFormat += mass;
			energyFormat += energy;
			result = String.format("%-20s%-20s%-20s%-20s%-20s%-20s\n\n", name, massFormat, stability, halfLife, meanLife, energy);
		}
		//In any other case, the the object must be stable so print out the information accordingly
		else {
			stability += abundance;
			massFormat += mass;
			result = String.format("%-20s%-20s%-20s%-20s\n\n", name, massFormat, stability, "stable");
		}
		return result;
	}
}
