import java.util.LinkedList;
public class Element {
	private String name;
	private int atomicNumber;
	public String atomicSymbol;
	private LinkedList<Isotope> isotopes = new LinkedList<>();
	/**
	 * Used to construct an Element object containing isotopes
	 * @param n
	 * @param aN
	 * @param aS
	 * @param i
	 */
	public Element(String n, int aN, String aS, LinkedList<Isotope> i) {
		name = n;
		atomicNumber = aN;
		atomicSymbol = aS;
		isotopes = i;
	}
	/**
	 * Used to construct an Element object containing no isotopes
	 * @param n
	 * @param aN
	 * @param aS
	 */
	public Element(String n, int aN, String aS) {
		name = n;
		atomicNumber = aN;
		atomicSymbol = aS;
	}
	/**
	 * Used to display an Element object
	 * @return the display for an element object
	 */
	public String toString() {
		String num = "" + atomicNumber;
		String result = "";
		//if there are isotopes for this Element, print the display accordingly
		if(isotopes.size() > 0) {
			result = String.format("%-20s%-20s%-20s\n%-20s%-20s%-20s\n\n%-20s%-20s%-20s%-20s%-20s%-20s\n\n",
				"Element", "Atomic Symbol", "Atomic Number", name, atomicSymbol, num, "Isotope", "Mass (amu)", "Abundance (%)", 
				"Half-Life", "Mean-Life (s)", "Energy (MeV)");
			//for each Isotope in this object, display the Isotope accordingly
			for(Isotope i : isotopes)
				result += i.toString();
		}
		//if there are no isotopes for this Element, print the display accordingly
		else {
			result = String.format("%-20s%-20s%-20s\n\nThis Element does not have any isotopes\n\n", name, atomicSymbol, num);
		}
		return result;
	}
}
