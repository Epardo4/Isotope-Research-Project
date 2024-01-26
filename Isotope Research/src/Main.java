import java.util.Scanner;
import java.util.LinkedList;
public class Main {
	public static void main(String[] args) {
		Element[] elements = new Element[118]; //This is an array containing 118 of the Element classes
		
		//Filling in the array
		
		//This program contains LinkedLists which are like arrays, but can easily be appended, each list contains
		//the Isotopes for each Element
		
		//Hydrogen
		LinkedList<Isotope> hList = new LinkedList<>();
		hList.add(new Isotope("H1", 1, 99.99));
		hList.add(new Isotope("H2", 2, 0.01));
		hList.add(new Isotope("H3", 3, "12.33 y", "5.61e8", 0.018591));
		hList.add(new Isotope("H4", 4, "0", "0", 23.5));
		elements[0] = new Element("Hydrogen", 1, "H", hList);
		//Helium
		LinkedList<Isotope> heList = new LinkedList<>();
		heList.add(new Isotope("He3", 3, 0));
		heList.add(new Isotope("He4", 4, 100));
		heList.add(new Isotope("He5", 5, "< 1.00 ms", "0", 0.6));
		heList.add(new Isotope("He6", 6, "806.7 ms", "1.164", 3.5078));
		elements[1] = new Element("Helium", 2, "He", heList);
		//Lithium
		LinkedList<Isotope> liList = new LinkedList<>();
		liList.add(new Isotope("Li5", 5, "< 1.00 ms", "0", 1.5));
		liList.add(new Isotope("Li6", 6, 7.59));
		liList.add(new Isotope("Li7", 7, 92.41));
		liList.add(new Isotope("Li8", 8, "838 ms", "1.209", 16.0045));
		liList.add(new Isotope("Li9", 9, "178.30 ms", "0.25723", 13.6063));
		elements[2] = new Element("Lithium", 3, "Li", liList);
		//Beryllium
		LinkedList<Isotope> beList = new LinkedList<>();
		beList.add(new Isotope("Be8", 8, "< 1.00 ms", "0", 0.0000068));
		beList.add(new Isotope("Be9", 9, 100));
		beList.add(new Isotope("Be10", 10, "1.51*10^6 y", "6.87 * 10^13", 0.5558));
		beList.add(new Isotope("Be11", 11, "13.81 s", "19.92", 11.506));
		elements[3] = new Element("Beryllium", 4, "Be", beList);
		//Boron
		LinkedList<Isotope> bList = new LinkedList<>();
		bList.add(new Isotope("B9", 9, "< 1.00 ms", "0", 0.00054));
		bList.add(new Isotope("B10", 10, 19.9));
		bList.add(new Isotope("B11", 11, 80.1));
		bList.add(new Isotope("B12", 12, "20.20 ms", "0.02914", 13.3689));
		bList.add(new Isotope("B13", 13, "17.36 ms", "0.02505", 13.4372));
		elements[4] = new Element("Boron", 5, "B", bList);
		//Carbon
		LinkedList<Isotope> cList = new LinkedList<>();
		cList.add(new Isotope("C11", 11, "20.39 m", "1765", 1.9825));
		cList.add(new Isotope("C12", 12, 98.93));
		cList.add(new Isotope("C13", 13, 1.07));
		cList.add(new Isotope("C14", 14, "5730 y", "2.61 * 10^11", 0.156475));
		cList.add(new Isotope("C15", 15, "2.449 s", "3.533", 9.7717));
		elements[5] = new Element("Carbon", 6, "C", cList);
		//Nitrogen
		LinkedList<Isotope> nList = new LinkedList<>();
		nList.add(new Isotope("N13", 13, "9.965 m", "862.6", 2.2204));
		nList.add(new Isotope("N14", 14, 99.64));
		nList.add(new Isotope("N15", 15, 0.36));
		nList.add(new Isotope("N16", 16, "7.13 s", "10.3", 10.42));
		nList.add(new Isotope("N17", 17, "4.173 s", "6.02", 8.68));
		elements[6] = new Element("Nitrogen", 7, "N", nList);
		//Oxygen
		LinkedList<Isotope> oList = new LinkedList<>();
		oList.add(new Isotope("O15", 15, "122.24 s", "176.36", 2.7539));
		oList.add(new Isotope("O16", 16, 99.76));
		oList.add(new Isotope("O17", 17, 0.04));
		oList.add(new Isotope("O18", 18, 0.2));
		oList.add(new Isotope("O19", 19, "26.91 s", "38.82", 4.821));
		oList.add(new Isotope("O20", 20, "13.51 s", "19.49", 3.8143));
		elements[7] = new Element("Oxygen", 8, "O", oList);
		//Flourine
		LinkedList<Isotope> fList = new LinkedList<>();
		fList.add(new Isotope("F18", 18, "109.77 m", "0.15836", 1.6555));
		fList.add(new Isotope("F19", 19, 100));
		fList.add(new Isotope("F20", 20, "11.00 s", "15.87", 7.02453));
		fList.add(new Isotope("F21", 21, "4.158 s", "5.999", 5.6841));
		elements[8] = new Element("Flourine", 9, "F", fList);
		//Neon
		LinkedList<Isotope> neList = new LinkedList<>();
		neList.add(new Isotope("Ne19", 19, "17.22 s", "24.84", 3.2385));
		neList.add(new Isotope("Ne20", 20, 90.48));
		neList.add(new Isotope("Ne21", 21, 0.27));
		neList.add(new Isotope("Ne22", 22, 9.25));
		neList.add(new Isotope("Ne23", 23, "37.24 s", "53.73", 4.37584));
		neList.add(new Isotope("Ne24", 24, "3.38 m", "293", 2.47));
		elements[9] = new Element("Neon", 10, "Ne", neList);
		//Sodium
		LinkedList<Isotope> naList = new LinkedList<>();
		naList.add(new Isotope("Na22", 22, "2.6019 y", "1.1846 * 10^8", 2.8422));
		naList.add(new Isotope("Na23", 23, 100));
		naList.add(new Isotope("Na24", 24, "14.9590 h", "77692.6", 5.51578));
		naList.add(new Isotope("Na24m", 24, "20.20 ms", "0.02914", 5.51578));
		naList.add(new Isotope("Na25", 25, "59.10 s", "85.26", 3.8353));
		elements[10] = new Element("Sodium", 11, "Na", naList);
		LinkedList<Isotope> mgList = new LinkedList<>();
		//Magnesium
		mgList.add(new Isotope("Mg23", 23, "11.317 s", "16.327", 4.0568));
		mgList.add(new Isotope("Mg24", 24, 78.99));
		mgList.add(new Isotope("Mg25", 25, 10));
		mgList.add(new Isotope("Mg26", 26, 11.01));
		mgList.add(new Isotope("Mg27", 27, "9.458 m", "818.7", 2.61033));
		mgList.add(new Isotope("Mg28", 28, "20.91 h", "52180", 1.8318));
		elements[11] = new Element("Magnesium", 12, "Mg",mgList);
		//Aluminum
		LinkedList<Isotope> alList = new LinkedList<>();
		alList.add(new Isotope("Al26", 26, "7.17 * 10^5 y", "3.26 * 10^13", 4.00414));
		alList.add(new Isotope("Al26m", 26, "6.3452 s", "9.1542", 4.00414));
		alList.add(new Isotope("Al27", 27, 100));
		alList.add(new Isotope("Al28", 28, "2.2414 m", "194.02", 4.64224));
		alList.add(new Isotope("Al29", 29, "6.56 m", "568", 3.6795));
		elements[12] = new Element("Aluminum", 13, "Al",alList);
		//Silicon
		LinkedList<Isotope> siList = new LinkedList<>();
		siList.add(new Isotope("Si27", 27, "4.16 s", "6.01", 4.8124));
		siList.add(new Isotope("Si28", 28, 92.23));
		siList.add(new Isotope("Si29", 29, 4.68));
		siList.add(new Isotope("Si30", 30, 3.09));
		siList.add(new Isotope("Si31", 31, "157.3 m", "13620", 1.49203));
		siList.add(new Isotope("Si32", 32, "150 y", "6.83 * 10^9", 0.2245));
		elements[13] = new Element("Silicon", 14, "Si",siList);
		//Phosphorus
		LinkedList<Isotope> pList = new LinkedList<>();
		pList.add(new Isotope("P30", 30, "2.498 m", "216.2", 4232.3));
		pList.add(new Isotope("P31", 31, 100));
		pList.add(new Isotope("P32", 32, "14.262 d", "1.7777 * 10^6", 1.71066));
		pList.add(new Isotope("P33", 33, "25.34 d", "3159000", 0.2485));
		elements[14] = new Element("Phosphorus", 15, "P",pList);
		//Sulfur
		LinkedList<Isotope> sList = new LinkedList<>();
		sList.add(new Isotope("S31", 31, "2.572 s", "3.711", 5.3961));
		sList.add(new Isotope("S32", 32, 94.99));
		sList.add(new Isotope("S33", 33, 0.75));
		sList.add(new Isotope("S34", 34, 4.25));
		sList.add(new Isotope("S35", 35, "87.32 d", "1.088 * 10^7", 0.16714));
		sList.add(new Isotope("S36", 36, 0.01));
		sList.add(new Isotope("S37", 37, "5.05 m", "437", 4.8653));
		sList.add(new Isotope("S38", 38, "170.3 m", "14740", 2.937));
		elements[15] = new Element("Sulfur", 16, "S",sList);
		//Chlorine
		LinkedList<Isotope> clList = new LinkedList<>();
		clList.add(new Isotope("Cl34", 34, "1.5264 s", "2.2021", 5.49128));
		clList.add(new Isotope("Cl34m", 34, "32.00 m", "2770", 5.49128));
		clList.add(new Isotope("Cl35", 35, 75.76));
		clList.add(new Isotope("Cl36", 36, "3.01e5 y", "1.37e13", 1.85067));
		clList.add(new Isotope("Cl37", 37, 24.24));
		clList.add(new Isotope("Cl38", 38, "37.24 m", "3224", 4.9168));
		clList.add(new Isotope("Cl38m", 38, "715 ms", "1.03", 0));
		clList.add(new Isotope("Cl39", 39, "55.6 m", "4813", 3.441));
		elements[17 - 1] = new Element("Chlorine", 17, "Cl", clList);
		//Argon
		LinkedList<Isotope> arList = new LinkedList<>();
		arList.add(new Isotope("Ar35", 35, "1.775 s", "2.561", 5.9653));
		arList.add(new Isotope("Ar36", 36, 0.33));
		arList.add(new Isotope("Ar37", 37, "35.04 d", "4.368e6", 0.8135));
		arList.add(new Isotope("Ar38", 38, 0.06));
		arList.add(new Isotope("Ar39", 39, "269 y", "1.22e10", 0.565));
		arList.add(new Isotope("Ar40", 40, 99.6));
		arList.add(new Isotope("Ar41", 41, "109.34 m", "9464.7", 2.4916));
		arList.add(new Isotope("Ar42", 42, "32.9 y", "1.498e9", 0.599));
		elements[18 - 1] = new Element("Argon", 18, "Ar", arList);
		//Potassium
		LinkedList<Isotope> kList = new LinkedList<>();
		kList.add(new Isotope("K38", 38, "7.636 m", "661", 5.9131));
		kList.add(new Isotope("K38m", 38, "923.9 ms", "1.333", 5.9131));
		kList.add(new Isotope("K39", 39, 93.26));
		kList.add(new Isotope("K40", 40, 0.01));
		kList.add(new Isotope("K41", 41, 6.73));
		kList.add(new Isotope("K42", 42, "12.360 h", "64194", 3.5254));
		kList.add(new Isotope("K43", 43, "22.3 h", "115000", 1.815));
		elements[19 - 1] = new Element("Potassium", 19, "K", kList);
		//Calcium
		LinkedList<Isotope> caList = new LinkedList<>();
		caList.add(new Isotope("Ca39", 39, "859.6 ms", "1.24", 6.5306));
		caList.add(new Isotope("Ca40", 40, 96.94));
		caList.add(new Isotope("Ca41", 41, "1.03e5 y", "4.69e12", 0.4214));
		caList.add(new Isotope("Ca42", 42, 0.65));
		caList.add(new Isotope("Ca43", 43, 0.14));
		caList.add(new Isotope("Ca44", 44, 2.09));
		caList.add(new Isotope("Ca45", 45, "162.61 d", "2.0269e7", 0.2568));
		caList.add(new Isotope("Ca46", 46, 0));
		caList.add(new Isotope("Ca47", 47, "4.536 d", "5.654e5", 1.9919));
		caList.add(new Isotope("Ca48", 48, 0.19));
		caList.add(new Isotope("Ca49", 49, "8.718 m", "362.6", 0.5262));
		caList.add(new Isotope("Ca50", 50, "13.9 s", "20.1", 4.966));
		elements[20 - 1] = new Element("Calcium", 20, "Ca", caList);
		//Scandium
		LinkedList<Isotope> scList = new LinkedList<>();
		scList.add(new Isotope("Sc44", 44, "3.927 h", "20396", 3.6533));
		scList.add(new Isotope("Sc44m", 44, "58.6 h", "3.04e5", 3.6533));
		scList.add(new Isotope("Sc45", 45, 100));
		scList.add(new Isotope("Sc45m", 45, "318 ms", "0.459", 0));
		scList.add(new Isotope("Sc46", 46, "83.79 d", "1.044e7", 2.3667));
		scList.add(new Isotope("Sc46m", 46, "18.75 s", "27.05", 2.3667));
		scList.add(new Isotope("Sc47", 47, "3.35 d", "4.17e5", 0.6001));
		elements[21 - 1] = new Element("Scandium", 21, "Sc", scList);
		//Titanium
		LinkedList<Isotope> tiList = new LinkedList<>();
		tiList.add(new Isotope("Ti45", 45, "184.8 m", "15997", 2.0624));
		tiList.add(new Isotope("Ti46", 46, 8.25));
		tiList.add(new Isotope("Ti47", 47, 7.44));
		tiList.add(new Isotope("Ti48", 48, 73.72));
		tiList.add(new Isotope("Ti49", 49, 5.41));
		tiList.add(new Isotope("Ti50", 50, 5.18));
		tiList.add(new Isotope("Ti51", 51, "5.76 m", "499", 2.4706));
		tiList.add(new Isotope("Ti52", 52, "1.7 m", "147", 1.937));
		elements[22 - 1] = new Element("Titanium", 22, "Ti", tiList);
		//Vanadium
		LinkedList<Isotope> vList = new LinkedList<>();
		vList.add(new Isotope("V49", 49, "330 d", "4.1e7", 0.6019));
		vList.add(new Isotope("V50", 50, 0.25));
		vList.add(new Isotope("V51", 51, 99.75));
		vList.add(new Isotope("V52", 52, "3.743 m", "324", 3.9754));
		vList.add(new Isotope("V53", 53, "1.61 m", "139", 3.436));
		elements[23 - 1] = new Element("Vanadium", 23, "V", vList);
		//Chromium
		LinkedList<Isotope> crList = new LinkedList<>();
		crList.add(new Isotope("Cr49", 49, "42.3 m", "3662", 2.631));
		crList.add(new Isotope("Cr50", 50, 4.34));
		crList.add(new Isotope("Cr51", 51, "27.7025 d", "3453084", 0.75273));
		crList.add(new Isotope("Cr52", 52, 83.79));
		crList.add(new Isotope("Cr53", 53, 9.5));
		crList.add(new Isotope("Cr54", 54, 2.37));
		crList.add(new Isotope("Cr55", 55, "3.497 m", "302.7", 2.6031));
		crList.add(new Isotope("Cr56", 56, "5.94 m", "614", 1.617));
		elements[24 - 1] = new Element("Chromium", 24, "Cr", crList);
		//Manganese
		LinkedList<Isotope> mnList = new LinkedList<>();
		mnList.add(new Isotope("Mn54", 54, "312.3 d", "3.892e7", 2.0742));
		mnList.add(new Isotope("Mn55", 55, 100));
		mnList.add(new Isotope("Mn56", 56, "2.5785 h", "13391", 3.695));
		mnList.add(new Isotope("Mn57", 57, "85.4 s", "123", 2.691));
		elements[25 - 1] = new Element("Manganese", 25, "Mn", mnList);
		//Iron
		LinkedList<Isotope> feList = new LinkedList<>();
		feList.add(new Isotope("Fe53", 53, "8.51 m", "737", 3.7424));
		feList.add(new Isotope("Fe53m", 53, "2.58 m", "223", 3.7424));
		feList.add(new Isotope("Fe54", 54, 5.84));
		feList.add(new Isotope("Fe55", 55, "2.73 y", "1.24e8", 0.23138));
		feList.add(new Isotope("Fe56", 56, 91.75));
		feList.add(new Isotope("Fe57", 57, 2.12));
		feList.add(new Isotope("Fe58", 58, 0.28));
		feList.add(new Isotope("Fe59", 59, "44.503 d", "5547247", 1.5652));
		feList.add(new Isotope("Fe60", 60, "1.5e6 y", "6.8e13", 0.237));
		elements[26 - 1] = new Element("Iron", 26, "Fe", feList);
		//Cobalt
		LinkedList<Isotope> coList = new LinkedList<>();
		coList.add(new Isotope("Co58", 58, "70.86 d", "8832647", 2.3074));
		coList.add(new Isotope("Co58m", 58, "9.04 h", "46951", 2.3074));
		coList.add(new Isotope("Co59", 59, 100));
		coList.add(new Isotope("Co60", 60, "5.2714 y", "2.39996e8", 2.8329));
		coList.add(new Isotope("Co60m", 60, "10.467 m", "906.04", 2.8329));
		coList.add(new Isotope("Co61", 61, "1.650 h", "8570", 1.3217));
		elements[27 - 1] = new Element("Cobalt", 27, "Co", coList);
		//Nickel
		LinkedList<Isotope> niList = new LinkedList<>();
		niList.add(new Isotope("Ni57", 57, "35.60 h", "184895", 3.264));
		niList.add(new Isotope("Ni58", 58, 68.08));
		niList.add(new Isotope("Ni59", 59, "7.6e4 y", "9.5e12", 1.0725));
		niList.add(new Isotope("Ni60", 60, 26.22));
		niList.add(new Isotope("Ni61", 61, 1.14));
		niList.add(new Isotope("Ni62", 62, 3.63));
		niList.add(new Isotope("Ni63", 63, "100.1 y", "4.557e9", 0.066945));
		niList.add(new Isotope("Ni64", 64, 0.93));
		niList.add(new Isotope("Ni65", 65, "2.5172 h", "13074", 2.1371));
		niList.add(new Isotope("Ni66", 66, "54.6 h", "2.84e5", 0.226));
		elements[28 - 1] = new Element("Nickel", 28, "Ni", niList);
		//Copper
		LinkedList<Isotope> cuList = new LinkedList<>();
		cuList.add(new Isotope("Cu62", 62, "9.74 m", "843", 3.948));
		cuList.add(new Isotope("Cu63", 63, 69.15));
		cuList.add(new Isotope("Cu64", 64, "12.700 h", "65960", 2.2538));
		cuList.add(new Isotope("Cu65", 65, 30.85));
		cuList.add(new Isotope("Cu66", 66, "5.120 m", "443.2", 2.642));
		cuList.add(new Isotope("Cu67", 67, "61.83 h", "321127", 0.577));
		elements[29 - 1] = new Element("Copper", 29, "Cu", cuList);
		//Zinc
		LinkedList<Isotope> znList = new LinkedList<>();
		znList.add(new Isotope("Zn63", 63, "38.47 m", "3330", 3.3669));
		znList.add(new Isotope("Zn64", 64, 49.17));
		znList.add(new Isotope("Zn65", 65, "244.26 d", "3.0447e7", 1.3519));
		znList.add(new Isotope("Zn66", 66, 27.73));
		znList.add(new Isotope("Zn67", 67, 4.04));
		znList.add(new Isotope("Zn68", 68, 18.45));
		znList.add(new Isotope("Zn69", 69, "56.4 m", "4882", 0.906));
		znList.add(new Isotope("Zn69m", 69, "13.76 h", "71465", 0.906));
		znList.add(new Isotope("Zn70", 70, 0.61));
		znList.add(new Isotope("Zn71", 71, "2.45 m", "212", 2.815));
		znList.add(new Isotope("Zn71m", 71, "3.96 h", "20567", 2.815));
		znList.add(new Isotope("Zn72", 72, "1.94 d", "2.42e5", 0.458));
		elements[30 - 1] = new Element("Zinc", 30, "Zn", znList);
		//Gallium
		LinkedList<Isotope> gaList = new LinkedList<>();
		gaList.add(new Isotope("Ga68", 68, "67.629 m", "5854.1", 2.9211));
		gaList.add(new Isotope("Ga69", 69, 60.11));
		gaList.add(new Isotope("Ga70", 70, "21.14 m", "1830", 2.3107));
		gaList.add(new Isotope("Ga71", 71, 39.89));
		gaList.add(new Isotope("Ga72", 72, "14.10 h", "73231", 3.9991));
		gaList.add(new Isotope("Ga72m", 72, "39.68 ms", "0.05725", 3.9991));
		gaList.add(new Isotope("Ga73", 73, "4.86 h", "25241", 1.593));
		elements[31 - 1] = new Element("Gallium", 31, "Ga", gaList);
		//Germanium
		LinkedList<Isotope> geList = new LinkedList<>();
		geList.add(new Isotope("Ge69", 69, "39.05 h", "2.028e5", 2.2273));
		geList.add(new Isotope("Ge70", 70, 20.52));
		geList.add(new Isotope("Ge71", 71, "11.43 d", "1.425e6", 0.2319));
		geList.add(new Isotope("Ge71m", 71, "20.40 ms", "0.02943", 0.2319));
		geList.add(new Isotope("Ge72", 72, 27.45));
		geList.add(new Isotope("Ge73", 73, 7.76));
		geList.add(new Isotope("Ge73m", 73, "0.499 s", "0.72", 0));
		geList.add(new Isotope("Ge74", 74, 36.52));
		geList.add(new Isotope("Ge75", 75, "82.78 m", "7166", 1.7156));
		geList.add(new Isotope("Ge75m", 75, "47.7 s", "68.8", 1.7156));
		geList.add(new Isotope("Ge76", 76, 7.75));
		geList.add(new Isotope("Ge77", 77, "11.30 h", "58689", 2.702));
		geList.add(new Isotope("Ge77m", 77, "52.9 s", "76.3", 2.702));
		geList.add(new Isotope("Ge78", 78, "88.0 m", "7617", 0.954));
		elements[32 - 1] = new Element("Germanium", 32, "Ge", geList);
		//Arsenic
		LinkedList<Isotope> asList = new LinkedList<>();
		asList.add(new Isotope("As74", 74, "17.77 d", "2.215e6", 3.9154));
		asList.add(new Isotope("As75", 75, 100));
		asList.add(new Isotope("As75m", 75, "16.79 ms", "0.02379", 0));
		asList.add(new Isotope("As76", 76, "1.0778 d", "134347", 2.962));
		asList.add(new Isotope("As77", 77, "38.83 h", "201671", 0.6829));
		elements[33 - 1] = new Element("Arsenic", 33, "As", asList);
		//Selenium
		LinkedList<Isotope> seList = new LinkedList<>();
		seList.add(new Isotope("Se73", 73, "7.15 h", "3.71e4", 2.74));
		seList.add(new Isotope("Se73m", 73, "39.8 m", "3445", 2.74));
		seList.add(new Isotope("Se74", 74, 0.86));
		seList.add(new Isotope("Se75", 75, "119.779 d", "1.493e7", 0.8636));
		seList.add(new Isotope("Se76", 76, 9.23));
		seList.add(new Isotope("Se77", 77, 7.6));
		seList.add(new Isotope("Se77m", 77, "17.36 s", "25.05", 0));
		seList.add(new Isotope("Se78", 78, 23.69));
		seList.add(new Isotope("Se79", 79, "1.13e6 y", "2.47e13", 0.151));
		seList.add(new Isotope("Se79m", 79, "3.92 m", "339", 0.151));
		seList.add(new Isotope("Se80", 80, 49.8));
		seList.add(new Isotope("Se81", 81, "18.45 m", "1597", 1.585));
		seList.add(new Isotope("Se81m", 81, "57.28 m", "4958", 1.585));
		seList.add(new Isotope("Se82", 82, 8.82));
		seList.add(new Isotope("Se83", 83, "22.3 m", "1930", 3.669));
		seList.add(new Isotope("Se83m", 83, "70.1 s", "101", 3.669));
		seList.add(new Isotope("Se84", 84, "3.10 m", "268", 1.827));
		elements[34 - 1] = new Element("Selenium", 34, "Se", seList);
		//Bromine
		LinkedList<Isotope> brList = new LinkedList<>();
		brList.add(new Isotope("Br78", 78, "6.46 m", "559", 3.574));
		brList.add(new Isotope("Br78m", 78, "119.2 us", "0.000172", 3.574));
		brList.add(new Isotope("Br79", 79, 50.69));
		brList.add(new Isotope("Br79m", 79, "4.86 s", "7.01", 0));
		brList.add(new Isotope("Br80", 80, "17.68 m", "1530", 3.8746));
		brList.add(new Isotope("Br80m", 80, "4.4205 h", "22959", 0));
		brList.add(new Isotope("Br81", 81, 49.31));
		brList.add(new Isotope("Br82", 82, "35.30 h", "1.833e5", 3.0926));
		brList.add(new Isotope("Br82m", 82, "6.13 m", "531", 3.0926));
		brList.add(new Isotope("Br83", 83, "2.40 h", "1.25e4", 0.973));
		elements[35 - 1] = new Element("Bromine", 35, "Br", brList);
		//Krypton
		LinkedList<Isotope> krList = new LinkedList<>();
		krList.add(new Isotope("Kr77", 77, "74.4 m", "6440", 3.063));
		krList.add(new Isotope("Kr78", 78, 0.35));
		krList.add(new Isotope("Kr79", 79, "35.04 h", "8.744e4", 1.626));
		krList.add(new Isotope("Kr79m", 79, "50 s", "72", 1.626));
		krList.add(new Isotope("Kr80", 80, 2.29));
		krList.add(new Isotope("Kr81", 81, "2.29e5 y", "1.04e13", 0.2807));
		krList.add(new Isotope("Kr81m", 81, "13.10 s", "18.9", 0.2807));
		krList.add(new Isotope("Kr82", 82, 11.59));
		krList.add(new Isotope("Kr83", 83, 11.5));
		krList.add(new Isotope("Kr83m", 83, "1.83 h", "9504", 0));
		krList.add(new Isotope("Kr84", 84, 56.99));
		krList.add(new Isotope("Kr85", 85, "10.756 y", "489699", 0.6871));
		krList.add(new Isotope("Kr85m", 85, "4.480 h", "2.327e4", 0.6871));
		krList.add(new Isotope("Kr86", 86, 17.28));
		krList.add(new Isotope("Kr87", 87, "76.3 m", "3173", 3.885));
		krList.add(new Isotope("Kr88", 88, "2.84 h", "1.48e4", 2.914));
		elements[36 - 1] = new Element("Krypton", 36, "Kr", krList);
		//Rubidium
		LinkedList<Isotope> rbList = new LinkedList<>();
		rbList.add(new Isotope("Rb84", 84, "32.77 d", "4.085e6", 3.5749));
		rbList.add(new Isotope("Rb84m", 84, "20.26 m", "1754", 0));
		rbList.add(new Isotope("Rb85", 85, 72.17));
		rbList.add(new Isotope("Rb86", 86, "18.631 d", "2.3223e9", 6.9602));
		rbList.add(new Isotope("Rb86m", 86, "1.017 m", "88.03", 0));
		rbList.add(new Isotope("Rb87", 87, 27.83));
		rbList.add(new Isotope("Rb88", 88, "17.78 m", "1539", 5.313));
		rbList.add(new Isotope("Rb89", 89, "15.15 m", "1311", 4.496));
		elements[37 - 1] = new Element("Rubidium", 37, "Rb", rbList);
		//Strontium
		LinkedList<Isotope> srList = new LinkedList<>();
		srList.add(new Isotope("Sr83", 83, "32.41 h", "1.683e5", 2.276));
		srList.add(new Isotope("Sr83m", 83, "4.95 s", "7.14", 2.276));
		srList.add(new Isotope("Sr84", 84, 0.56));
		srList.add(new Isotope("Sr85", 85, "64.84 d", "8.082e6", 1.065));
		srList.add(new Isotope("Sr85m", 85, "67.63 m", "5854", 1.065));
		srList.add(new Isotope("Sr86", 86, 9.86));
		srList.add(new Isotope("Sr87", 87, 7));
		srList.add(new Isotope("Sr87m", 87, "2.803 h", "14558", 0));
		srList.add(new Isotope("Sr88", 88, 82.58));
		srList.add(new Isotope("Sr89", 89, "50.53 d", "6.299e6", 1.4951));
		srList.add(new Isotope("Sr90", 90, "28.79 y", "1.311e9", 0.546));
		elements[38 - 1] = new Element("Strontium", 38, "Sr", srList);
		//Yttrium
		LinkedList<Isotope> yList = new LinkedList<>();
		yList.add(new Isotope("Y88", 88, "106.65 d", "1.3294e7", 3.6226));
		yList.add(new Isotope("Y88m", 88, "13.9 ms", "0.0201", 3.6226));
		yList.add(new Isotope("Y89", 89, 100));
		yList.add(new Isotope("Y89m", 89, "16.06 s", "23.17", 0));
		yList.add(new Isotope("Y90", 90, "64.00 h", "3.3248e5", 2.2801));
		yList.add(new Isotope("Y91", 91, "58.51 d", "7.293e6", 1.5448));
		yList.add(new Isotope("Y91m", 91, "49.71 m", "4303", 0));
		elements[39 - 1] = new Element("Yttrium", 39, "Y", yList);
		//Zirconium
		LinkedList<Isotope> zrList = new LinkedList<>();
		zrList.add(new Isotope("Zr89", 89, "78.41 h", "4.072e5", 2.8327));
		zrList.add(new Isotope("Zr89m", 89, "4.18 m", "362", 2.8327));
		zrList.add(new Isotope("Zr90", 90, 51.45));
		zrList.add(new Isotope("Zr90m", 90, "809.2 ms", "1.167", 0));
		zrList.add(new Isotope("Zr91", 91, 11.22));
		zrList.add(new Isotope("Zr92", 92, 17.15));
		zrList.add(new Isotope("Zr93", 93, "1.53e6 y", "6.97e13", 0.0914));
		zrList.add(new Isotope("Zr94", 94, 17.38));
		zrList.add(new Isotope("Zr95", 95, "64.02 d", "7.980e6", 1.1248));
		zrList.add(new Isotope("Zr96", 96, 2.8));
		zrList.add(new Isotope("Zr97", 97, "16.91 h", "87826", 2.6581));
		zrList.add(new Isotope("Zr98", 98, "30.7 s", "44.3", 2.25));
		elements[40 - 1] = new Element("Zirconium", 40, "Zr", zrList);
		//Niobium
		LinkedList<Isotope> nbList = new LinkedList<>();
		nbList.add(new Isotope("Nb92", 92, "3.47e7 y", "1.58e15", 2.3626));
		nbList.add(new Isotope("Nb92m", 92, "10.15 d", "1.265e6", 2.0056));
		nbList.add(new Isotope("Nb93", 93, 100));
		nbList.add(new Isotope("Nb93m", 93, "16.13 y", "7.344e8", 0));
		nbList.add(new Isotope("Nb94", 94, "2.03e4 y", "9.24e11", 2.0454));
		nbList.add(new Isotope("Nb94m", 94, "6.263 m", "542.1", 2.0454));
		nbList.add(new Isotope("Nb95", 95, "34.975 d", "4.3596e6", 0.9256));
		nbList.add(new Isotope("Nb95m", 95, "86.6 h", "4.498e5", 0.9256));
		elements[41 - 1] = new Element("Niobium", 41, "Nb", nbList);
		//Molybdenum
		LinkedList<Isotope> moList = new LinkedList<>();
		moList.add(new Isotope("Mo91", 91, "15.49 m", "1341", 4.434));
		moList.add(new Isotope("Mo91m", 91, "65.0 s", "93.8", 4.434));
		moList.add(new Isotope("Mo92", 92, 14.65));
		moList.add(new Isotope("Mo93", 93, "4.00e3 y", "1.82e11", 0.405));
		moList.add(new Isotope("Mo93m", 93, "6.85 h", "3.56e4", 0.405));
		moList.add(new Isotope("Mo94", 94, 9.19));
		moList.add(new Isotope("Mo95", 95, 15.87));
		moList.add(new Isotope("Mo96", 96, 16.67));
		moList.add(new Isotope("Mo97", 97, 9.58));
		moList.add(new Isotope("Mo98", 98, 24.29));
		moList.add(new Isotope("Mo99", 99, "65.94 h", "3.425e5", 1.3572));
		moList.add(new Isotope("Mo100", 100, 9.74));
		moList.add(new Isotope("Mo101", 101, "14.61 m", "1265", 2.824));
		moList.add(new Isotope("Mo102", 102, "11.30 m", "978.1", 1.01));
		elements[42 - 1] = new Element("Molybdenum", 42, "Mo", moList);
		//Technetium
		elements[43 - 1] = new Element("Technetium", 43, "Tc");
		//Ruthenium
		LinkedList<Isotope> ruList = new LinkedList<>();
		ruList.add(new Isotope("Ru95", 95, "1.64 h", "8.518", 2.567));
		ruList.add(new Isotope("Ru96", 96, 5.54));
		ruList.add(new Isotope("Ru97", 97, "2.83 d", "3.53e5", 1.108));
		ruList.add(new Isotope("Ru98", 98, 1.87));
		ruList.add(new Isotope("Ru99", 99, 12.76));
		ruList.add(new Isotope("Ru100", 100, 12.6));
		ruList.add(new Isotope("Ru101", 101, 17.06));
		ruList.add(new Isotope("Ru102", 102, 31.55));
		ruList.add(new Isotope("Ru103", 103, "39.25 d", "2.351e5", 0.7634));
		ruList.add(new Isotope("Ru103m", 103, "1.69 ms", "0.00244", 0.7634));
		ruList.add(new Isotope("Ru104", 104, 18.62));
		ruList.add(new Isotope("Ru105", 105, "4.44 h", "2.31e4", 1.971));
		ruList.add(new Isotope("Ru106", 106, "1.02 y", "4.64e7", 0.0394));
		elements[44 - 1] = new Element("Ruthenium", 44, "Ru", ruList);
		//Rhodium
		LinkedList<Isotope> rhList = new LinkedList<>();
		rhList.add(new Isotope("Rh102", 102, "207.30 d", "1.2415e7", 3.474));
		rhList.add(new Isotope("Rh102m", 102, "2.9 y", "1.3e8", 2.323));
		rhList.add(new Isotope("Rh103", 103, 100));
		rhList.add(new Isotope("Rh103m", 103, "56.12 m", "4858", 0));
		rhList.add(new Isotope("Rh104", 104, "42.30 s", "61.03", 3.582));
		rhList.add(new Isotope("Rh104m", 104, "4.34 m", "376", 2.441));
		rhList.add(new Isotope("Rh105", 105, "1.47 d", "1.83e5", 5.667));
		rhList.add(new Isotope("Rh105m", 105, "45 s", "65", 5.667));
		elements[45 - 1] = new Element("Rhodium", 45, "Rh", rhList);
		//Palladium
		LinkedList<Isotope> pdList = new LinkedList<>();
		pdList.add(new Isotope("Pd101", 101, "8.47 h", "4.399e4", 1.98));
		pdList.add(new Isotope("Pd102", 102, 1.02));
		pdList.add(new Isotope("Pd103", 103, "16.99 d", "2.118e6", 0.5431));
		pdList.add(new Isotope("Pd104", 104, 11.14));
		pdList.add(new Isotope("Pd105", 105, 22.33));
		pdList.add(new Isotope("Pd106", 106, 27.33));
		pdList.add(new Isotope("Pd107", 107, "6.50e6 y", "2.96e13", 0.033));
		pdList.add(new Isotope("Pd107m", 107, "21.3 s", "30.7", 0.033));
		pdList.add(new Isotope("Pd108", 108, 26.46));
		pdList.add(new Isotope("Pd109", 109, "13.70 h", "3.419e4", 1.1159));
		pdList.add(new Isotope("Pd109m", 109, "4.696 m", "406.5", 1.1159));
		pdList.add(new Isotope("Pd110", 110, 11.72));
		pdList.add(new Isotope("Pd111", 111, "23.40 m", "2026", 2.188));
		pdList.add(new Isotope("Pd111m", 111, "5.5 h", "2.9e4", 2.188));
		pdList.add(new Isotope("Pd112", 112, "21.04 h", "1.093e5", 0.288));
		elements[46 - 1] = new Element("Palladium", 46, "Pd", pdList);
		//Silver
		LinkedList<Isotope> agList = new LinkedList<>();
		agList.add(new Isotope("Ag106", 106, "23.96 m", "2074", 3.159));
		agList.add(new Isotope("Ag106m", 106, "8.28 d", "1.03e6", 2.965));
		agList.add(new Isotope("Ag107", 107, 51.84));
		agList.add(new Isotope("Ag107m", 107, "44.3 s", "63.9", 0));
		agList.add(new Isotope("Ag108", 108, "2.38 m", "206", 3.567));
		agList.add(new Isotope("Ag108m", 108, "418 y", "1.903e10", 1.918));
		agList.add(new Isotope("Ag109", 109, 48.16));
		agList.add(new Isotope("Ag109m", 109, "39.6 s", "57.1", 0));
		agList.add(new Isotope("Ag110", 110, "24.56 s", "35.43", 3.7842));
		agList.add(new Isotope("Ag110m", 110, "249.79 d", "31136", 2.8922));
		agList.add(new Isotope("Ag111", 111, "7.45 d", "9.29e5", 1.0368));
		agList.add(new Isotope("Ag111m", 111, "64.8 s", "93.5", 1.0368));
		elements[47 - 1] = new Element("Silver", 47, "Ag", agList);
		//Cadmium
		LinkedList<Isotope> cdList = new LinkedList<>();
		cdList.add(new Isotope("Cd105", 105, "55.50 m", "4804", 2.738));
		cdList.add(new Isotope("Cd106", 106, 1.25));
		cdList.add(new Isotope("Cd107", 107, "6.50 h", "3.38e4", 1.417));
		cdList.add(new Isotope("Cd108", 108, 0.89));
		cdList.add(new Isotope("Cd109", 109, "1.26 y", "5.74e7", 0.214));
		cdList.add(new Isotope("Cd110", 110, 12.47));
		cdList.add(new Isotope("Cd111", 111, 12.79));
		cdList.add(new Isotope("Cd111m", 111, "48.54 m", "4202", 0));
		cdList.add(new Isotope("Cd112", 112, 24.11));
		cdList.add(new Isotope("Cd113", 113, 12.23));
		cdList.add(new Isotope("Cd113m", 113, "14.1 y", "6.42e8", 0));
		cdList.add(new Isotope("Cd114", 114, 28.75));
		cdList.add(new Isotope("Cd115", 115, "2.23 d", "2.78e5", 1.446));
		cdList.add(new Isotope("Cd115m", 115, "44.6 d", "5.56e6", 1.446));
		cdList.add(new Isotope("Cd116", 116, 7.51));
		cdList.add(new Isotope("Cd117", 117, "2.49 h", "1.28e4", 2.517));
		cdList.add(new Isotope("Cd117m", 117, "3.36 h", "1.75e4", 2.517));
		cdList.add(new Isotope("Cd118", 118, "50.30 m", "4354", 0.521));
		elements[48 - 1] = new Element("Cadmium", 48, "Cd", cdList);
		//Indium
		LinkedList<Isotope> inList = new LinkedList<>();
		inList.add(new Isotope("In112", 112, "14.88 m", "1288", 3.25));
		inList.add(new Isotope("In112m", 112, "20.56 m", "1780", 0));
		inList.add(new Isotope("In113", 113, 4.28));
		inList.add(new Isotope("In113m", 113, "1.6582 h", "8612.2", 0));
		inList.add(new Isotope("In114", 114, "1.20 m", "104", 3.4407));
		inList.add(new Isotope("In114m", 114, "49.51 d", "6.171e6", 1.452));
		inList.add(new Isotope("In114m2", 114, "43.1 ms", "0.0622", 0));
		inList.add(new Isotope("In115", 115, 95.72));
		inList.add(new Isotope("In115m", 115, "4.486 h", "13299", 0));
		inList.add(new Isotope("In116", 116, "14.10 s", "20.34", 3.275));
		inList.add(new Isotope("In116m", 116, "54.29 m", "4699", 0));
		inList.add(new Isotope("In116m2", 116, "2.18 s", "62.5", 0));
		inList.add(new Isotope("In117", 117, "43.20 m", "3739", 1.455));
		inList.add(new Isotope("In117m", 117, "116.2 m", "1.006e4", 1.455));
		elements[49 - 1] = new Element("Indium", 49, "In", inList);
		//Tin
		LinkedList<Isotope> snList = new LinkedList<>();
		snList.add(new Isotope("Sn111", 111, "35.30 m", "3056", 2.445));
		snList.add(new Isotope("Sn112", 112, 0.97));
		snList.add(new Isotope("Sn113", 113, "115.09 d", "1.4346e7", 1.036));
		snList.add(new Isotope("Sn113m", 113, "21.4 m", "1852", 1.036));
		snList.add(new Isotope("Sn114", 114, 0.66));
		snList.add(new Isotope("Sn115", 115, 0.34));
		snList.add(new Isotope("Sn116", 116, 14.54));
		snList.add(new Isotope("Sn117", 117, 7.68));
		snList.add(new Isotope("Sn117m", 117, "13.60 d", "1.695e6", 0));
		snList.add(new Isotope("Sn118", 118, 24.22));
		snList.add(new Isotope("Sn119", 119, 8.59));
		snList.add(new Isotope("Sn119m", 119, "293.1 d", "3.653e7", 0));
		snList.add(new Isotope("Sn120", 120, 32.58));
		snList.add(new Isotope("Sn121", 121, "1.31 d", "1.36e5", 0.3901));
		snList.add(new Isotope("Sn121m", 121, "55 y", "2.5e9", 0.3901));
		snList.add(new Isotope("Sn122", 122, 4.63));
		snList.add(new Isotope("Sn123", 123, "129.20 d", "1.6105e7", 1.403));
		snList.add(new Isotope("Sn123m", 123, "40.06 m", "3468", 1.403));
		snList.add(new Isotope("Sn124", 124, 5.79));
		snList.add(new Isotope("Sn125", 125, "9.64 d", "1.202e6", 2.363));
		snList.add(new Isotope("Sn125m", 125, "9.52 m", "824", 2.363));
		snList.add(new Isotope("Sn126", 126, "2.30e5 y", "1.05e10", 0.378));
		elements[50 - 1] = new Element("Tin", 50, "Sn", snList);
		//Antimony
		LinkedList<Isotope> sbList = new LinkedList<>();
		sbList.add(new Isotope("Sb120", 120, "15.89 m", "1375", 2681));
		sbList.add(new Isotope("Sb120m", 120, "5.76 d", "7.18e5", 2681));
		sbList.add(new Isotope("Sb121", 121, 57.21));
		sbList.add(new Isotope("Sb122", 122, "2.72 d", "3.39e5", 3.5985));
		sbList.add(new Isotope("Sb122m", 122, "4.191 m", "362.8", 0));
		sbList.add(new Isotope("Sb123", 123, 42.79));
		sbList.add(new Isotope("Sb124", 124, "60.20 d", "7.504e6", 2.9045));
		sbList.add(new Isotope("Sb124m", 124, "93 s", "134", 2.9045));
		sbList.add(new Isotope("Sb124m2", 124, "20.2 m", "1749", 0));
		sbList.add(new Isotope("Sb125", 125, "2.76 y", "1.25e8", 0.7667));
		elements[51 - 1] = new Element("Antimony", 51, "Sb", sbList);
		//Tellurium
		LinkedList<Isotope> teList = new LinkedList<>();
		teList.add(new Isotope("Te119", 119, "16.05 h", "8.336 * 10^4", 2.293));
		teList.add(new Isotope("Te119m", 119, "4.70 d", "5.86 * 10^5", 2.293));
		teList.add(new Isotope("Te120", 120, 0.09));
		teList.add(new Isotope("Te121", 121, "19.17 d", "2.39 * 10^6", 1.036));
		teList.add(new Isotope("Te121m", 121, "154 d", "1.92 * 10^7", 1.036));
		teList.add(new Isotope("Te122", 122, 2.55));
		teList.add(new Isotope("Te123", 123, 0.89));
		teList.add(new Isotope("Te123m", 123, "119.7 d", "1.492 * 10^7", 0));
		teList.add(new Isotope("Te124", 124, 4.74));
		teList.add(new Isotope("Te125", 125, 7.07));
		teList.add(new Isotope("Te125m", 125, "57.40 d", "7.155 * 10^6", 0));
		teList.add(new Isotope("Te126", 126, 18.84));
		teList.add(new Isotope("Te127", 127, "9.35 h", "4.86 * 10^4", 0.698));
		teList.add(new Isotope("Te127m", 127, "109 d", "1.36 * 10^7", 0.698));
		teList.add(new Isotope("Te128", 128, 31.74));
		teList.add(new Isotope("Te129", 129, "1.16 h", "6025", 1.498));
		teList.add(new Isotope("Te129m", 129, "33.6 d", "4.19 * 10^6", 1.498));
		teList.add(new Isotope("Te130", 130, 34.08));
		teList.add(new Isotope("Te131", 131, "25.00 m", "2164", 2.2335));
		teList.add(new Isotope("Te131m", 131, "30 h", "1.6 * 10^5", 2.2335));
		teList.add(new Isotope("Te132", 132, "3.20 d", "3.999 * 10^5", 0.493));
		elements[52 - 1] = new Element("Tellurium", 52, "Te", teList);
		//Iodine
		LinkedList<Isotope> iList = new LinkedList<>();
		iList.add(new Isotope("I126", 126, "13.11 d", "1.634 * 10^6", 3.413));
		iList.add(new Isotope("I127", 127, 100));
		iList.add(new Isotope("I128", 128, "24.99 m", "2164", 3.371));
		iList.add(new Isotope("I129", 129, "1.57 * 10^7 y", "7.15 * 10^14", 0.194));
		elements[53 - 1] = new Element("Iodine", 53, "I", iList);
		//Xenon
		LinkedList<Isotope> xeList = new LinkedList<>();
		xeList.add(new Isotope("Xe123", 123, "2.08 h", "10.8e4", 2.676));
		xeList.add(new Isotope("Xe124", 124, 0.1));
		xeList.add(new Isotope("Xe125", 125, "16.90 h", "87773", 1.653));
		xeList.add(new Isotope("Xe125m", 125, "57 s", "82", 0));
		xeList.add(new Isotope("Xe126", 126, 0.09));
		xeList.add(new Isotope("Xe127", 127, "36.34 d", "4.53e6", 0.6624));
		xeList.add(new Isotope("Xe127m", 127, "69.2 s", "99.8", 0));
		xeList.add(new Isotope("Xe128", 128, 1.91));
		xeList.add(new Isotope("Xe129", 129, 26.4));
		xeList.add(new Isotope("Xe129m", 129, "8.88 d", "1.11e6", 0));
		xeList.add(new Isotope("Xe130", 130, 4.07));
		xeList.add(new Isotope("Xe131", 131, 21.23));
		xeList.add(new Isotope("Xe131m", 131, "11.84 d", "1.476e6", 0));
		xeList.add(new Isotope("Xe132", 132, 26.91));
		xeList.add(new Isotope("Xe132m", 132, "8.39 ms", "0.0121", 0));
		xeList.add(new Isotope("Xe133", 133, "5.243 d", "6.5358e5", 0.4274));
		xeList.add(new Isotope("Xe133m", 133, "2.19 d", "2.73e5", 0));
		xeList.add(new Isotope("Xe134", 134, 10.44));
		xeList.add(new Isotope("Xe134m", 134, "290 ms", "0.418", 0));
		xeList.add(new Isotope("Xe135", 135, "9.14 h", "", 1.151));
		xeList.add(new Isotope("Xe135m", 135, "15.29 m", "1324", 0));
		xeList.add(new Isotope("Xe136", 136, 8.86));
		xeList.add(new Isotope("Xe137", 137, "3.818 m", "330.5", 4.173));
		xeList.add(new Isotope("Xe138", 138, "14.08 m", "1219", 2.774));
		elements[54 - 1] = new Element("Xenon", 54, "Xe", xeList);
		//Cesium
		LinkedList<Isotope> csList = new LinkedList<>();
		csList.add(new Isotope("Cs132", 132, "6.479 d", "8.076e5", 3.3985));
		csList.add(new Isotope("Cs133", 133, 100));
		csList.add(new Isotope("Cs134", 134, "2.0648 y", "9.4006e7", 3.2877));
		csList.add(new Isotope("Cs134m", 134, "2.903 h", "3.619e5", 0));
		csList.add(new Isotope("Cs135", 135, "2.30e6 y", "1.05e14", 0.2693));
		csList.add(new Isotope("Cs135m", 135, "53 m", "4588", 0));
		elements[55 - 1] = new Element("Cesium", 55, "Cs", csList);
		//Barium
		LinkedList<Isotope> baList = new LinkedList<>();
		baList.add(new Isotope("Ba129", 129, "2.23 h", "1.16e4", 2.432));
		baList.add(new Isotope("Ba129m", 129, "2.16 h", "1.12e4", 0));
		baList.add(new Isotope("Ba130", 130, 0.11));
		baList.add(new Isotope("Ba130m", 130, "11 ms", "0.016", 0));
		baList.add(new Isotope("Ba131", 131, "11.50 d", "1.433e6", 1.37));
		baList.add(new Isotope("Ba131m", 131, "14.6 m", "1264", 0));
		baList.add(new Isotope("Ba132", 132, 0.1));
		baList.add(new Isotope("Ba133", 133, "10.51 y", "4.785e8", 0.5174));
		baList.add(new Isotope("Ba133m", 133, "38.9 h", "2.02e5", 0));
		baList.add(new Isotope("Ba134", 134, 2.42));
		baList.add(new Isotope("Ba134m", 134, "2.63 us", "3.79e-6", 0));
		baList.add(new Isotope("Ba135", 135, 6.59));
		baList.add(new Isotope("Ba135m", 135, "28.7 h", "1.49e5", 0));
		baList.add(new Isotope("Ba136", 136, 7.85));
		baList.add(new Isotope("Ba136m", 136, "0.3084 s", "0.4449", 0));
		baList.add(new Isotope("Ba137", 137, 11.23));
		baList.add(new Isotope("Ba137m", 137, "2.552 m", "220.9", 0));
		baList.add(new Isotope("Ba138", 138, 71.7));
		baList.add(new Isotope("Ba139", 139, "83.06 h", "4.314e5", 2.317));
		baList.add(new Isotope("Ba140", 140, "12.752 d", "1.5895e6", 1.05));
		elements[56 - 1] = new Element("Barium", 56, "Ba", baList);
		//Lanthanum
		LinkedList<Isotope> laList = new LinkedList<>();
		laList.add(new Isotope("La137", 137, "6.00e4 y", "2.73e12", 0.6));
		laList.add(new Isotope("La138", 138, 0.09));
		laList.add(new Isotope("La139", 139, 99.91));
		laList.add(new Isotope("La140", 140, "1.6781 d", "209173", 3.7619));
		laList.add(new Isotope("La141", 141, "3.92 h", "2.04e4", 2.502));
		elements[57 - 1] = new Element("Lanthanum", 57, "La",laList);
		//Cerium
		LinkedList<Isotope> ceList = new LinkedList<>();
		ceList.add(new Isotope("Ce135", 135, "17.70 h", "91928", 2.026));
		ceList.add(new Isotope("Ce135m", 135, "20 s", "29", 0));
		ceList.add(new Isotope("Ce136", 136, 0.19));
		ceList.add(new Isotope("Ce137", 137, "9.00 h", "4.678e4", 1.2221));
		ceList.add(new Isotope("La137m", 137, "34.4 h", "1.79e5", 0));
		ceList.add(new Isotope("Ce138", 138, 0.25));
		ceList.add(new Isotope("La138m", 138, "8.65 ms", "0.0125", 0));
		ceList.add(new Isotope("Ce139", 139, "137.64 d", "1.7157e7", 0.278));
		ceList.add(new Isotope("La139m", 139, "54.8 s", "79.1", 0));
		ceList.add(new Isotope("Ce140", 140, 88.45));
		ceList.add(new Isotope("Ce141", 141, "32.501 d", "4.0512e6", 0.5807));
		ceList.add(new Isotope("Ce142", 142, 11.11));
		ceList.add(new Isotope("Ce143", 143, "33.039 h", "171595", 1.4614));
		ceList.add(new Isotope("Ce144", 144, "284.893 d", "3.55116e8", 0.3187));
		elements[58 - 1] = new Element("Cerium", 58, "Ce", ceList);
		//Praseodymium
		LinkedList<Isotope> prList = new LinkedList<>();
		prList.add(new Isotope("Pr140", 140, "3.39 m", "293", 3.388));
		prList.add(new Isotope("Pr141", 141, 100));
		prList.add(new Isotope("Pr142", 142, "19.12 h", "99303", 2.9075));
		prList.add(new Isotope("Pr142m", 142, "14.6 m", "1264", 0));
		prList.add(new Isotope("Pr143", 143, "13.57 d", "1.691e6", 0.9339));
		elements[59 - 1] = new Element("Praseodymium", 59, "Pr", prList);
		//Neodymium
		LinkedList<Isotope> ndList = new LinkedList<>();
		ndList.add(new Isotope("Nd141", 141, "2.49 h", "1.29e4", 1.823));
		ndList.add(new Isotope("Nd141m", 141, "62.0 s", "89.4", 0));
		ndList.add(new Isotope("Nd142", 142, 27.15));
		ndList.add(new Isotope("Nd143", 143, 12.17));
		ndList.add(new Isotope("Nd144", 144, 23.8));
		ndList.add(new Isotope("Nd145", 145, 8.29));
		ndList.add(new Isotope("Nd146", 146, 17.19));
		ndList.add(new Isotope("Nd147", 147, "10.98 d", "1.369e6", 0.896));
		ndList.add(new Isotope("Nd148", 148, 5.76));
		ndList.add(new Isotope("Nd149", 149, "1.728 h", "8975", 1.691));
		ndList.add(new Isotope("Nd150", 150, 5.64));
		ndList.add(new Isotope("Nd151", 151, "12.44 m", "1077", 2.442));
		ndList.add(new Isotope("Nd152", 152, "11.40 m", "98680", 1.11));
		elements[60 - 1] = new Element("Neodymium", 60, "Nd", ndList);
		//Promethium
		elements[61 - 1] = new Element("Promethium", 61, "Pm");
		//Samarium
		LinkedList<Isotope> smList = new LinkedList<>();
		smList.add(new Isotope("Sm143", 143, "8.83 m", "764", 3.443));
		smList.add(new Isotope("Sm134m", 143, "66 s", "95", 0));
		smList.add(new Isotope("Sm143m2", 143, "30 ms", "0.043", 0));
		smList.add(new Isotope("Sm144", 144, 3.08));
		smList.add(new Isotope("Sm145", 145, "340.00 d", "4.2381e7", 6.164));
		smList.add(new Isotope("Sm146", 146, "1.03e8 y", "4.69e15", 2.529));
		smList.add(new Isotope("Sm147", 147, 15));
		smList.add(new Isotope("Sm148", 148, 11.25));
		smList.add(new Isotope("Sm149", 149, 13.82));
		smList.add(new Isotope("Sm150", 150, 7.37));
		smList.add(new Isotope("Sm151", 151, "90.0 y", "4.098e6", 0.0767));
		smList.add(new Isotope("Sm152", 152, 26.74));
		smList.add(new Isotope("Sm153", 153, "46.284 h", "240385", 0.8082));
		smList.add(new Isotope("Sm153m", 153, "10.6 ms", "0.0153", 0));
		smList.add(new Isotope("Sm154", 154, 22.74));
		smList.add(new Isotope("Sm155", 155, "22.30 m", "1930", 1.6269));
		smList.add(new Isotope("Sm156", 156, "9.40 h", "4.88e4", 0.722));
		elements[62 - 1] = new Element("Samarium", 62, "Sm", smList);
		//Europium
		LinkedList<Isotope> euList = new LinkedList<>();
		euList.add(new Isotope("Eu150", 150, "36.9 y", "1.68e9", 2.261));
		euList.add(new Isotope("Eu150m", 150, "12.8 h", "6.65e4", 3.232));
		euList.add(new Isotope("Eu151", 151, 47.81));
		euList.add(new Isotope("Eu152", 152, "13.537 y", "6.16e5", 3.6931));
		euList.add(new Isotope("Eu152m", 152, "9.3116 h", "48362", 3.6931));
		euList.add(new Isotope("Eu152m2", 152, "96 m", "8.3e3", 0));
		euList.add(new Isotope("Eu153", 153, 52.19));
		euList.add(new Isotope("Eu154", 154, "8.593 y", "3.912e8", 2.6857));
		euList.add(new Isotope("Eu154m", 154, "46.3 m", "4008", 0));
		euList.add(new Isotope("Eu155", 155, "4.7611 y", "2.1676e12", 0.2521));
		elements[63 - 1] = new Element("Europium", 63, "Eu", euList);
		//Gadolinium
		LinkedList<Isotope> gdList = new LinkedList<>();
		gdList.add(new Isotope("Gd151", 151, "124 d", "1.55e8", 3.117));
		gdList.add(new Isotope("Gd152", 152, 0.2));
		gdList.add(new Isotope("Gd153", 153, "240.40 d", "2.9966e7", 0.4844));
		gdList.add(new Isotope("Gd154", 154, 2.18));
		gdList.add(new Isotope("Gd155", 155, 12.8));
		gdList.add(new Isotope("Gd155m", 155, "31.97 ms", "0.04612", 0));
		gdList.add(new Isotope("Gd156", 156, 20.47));
		gdList.add(new Isotope("Gd157", 157, 15.65));
		gdList.add(new Isotope("Gd158", 158, 24.84));
		gdList.add(new Isotope("Gd159", 159, "18.479 h", "95974", 0.9706));
		gdList.add(new Isotope("Gd160", 160, 21.86));
		gdList.add(new Isotope("Gd161", 161, "3.66 m", "316", 1.9556));
		gdList.add(new Isotope("Gd162", 162, "8.40 m", "727", 1.394));
		elements[64 - 1] = new Element("Gadolinium", 64, "Gd", gdList);
		//Terbium
		LinkedList<Isotope> tbList = new LinkedList<>();
		tbList.add(new Isotope("Tb158", 158, "180 y", "8.2e9", 2.1567));
		tbList.add(new Isotope("Tb158m", 158, "10.70 s", "15.44", 2.1567));
		tbList.add(new Isotope("Tn159", 159, 100));
		tbList.add(new Isotope("Tb160", 160, "72.30 d", "9012", 1.8353));
		tbList.add(new Isotope("Tb161", 161, "6.88 d", "8.58e5", 0.5931));
		elements[65 - 1] = new Element("Terbium", 65, "Tb", tbList);
		//Dysprosium
		LinkedList<Isotope> dyList = new LinkedList<>();
		dyList.add(new Isotope("Dy155", 155, "9.90 h", "5.14e4", 2.0945));
		dyList.add(new Isotope("Dy156", 156, 0.06));
		dyList.add(new Isotope("Dy157", 157, "8.14 h", "4.23e4", 1.341));
		dyList.add(new Isotope("Dy157m", 157, "21.6 ms", "0.0312", 0));
		dyList.add(new Isotope("Dy158", 158, 0.1));
		dyList.add(new Isotope("Dy159", 159, "144.40 d", "1.7999e7", 0.3656));
		dyList.add(new Isotope("Dy160", 160, 2.33));
		dyList.add(new Isotope("Dy161", 161, 18.89));
		dyList.add(new Isotope("Dy162", 162, 25.48));
		dyList.add(new Isotope("Dy163", 163, 24.9));
		dyList.add(new Isotope("Dy164", 164, 28.26));
		dyList.add(new Isotope("Dy165", 165, "2.334 h", "12122", 1.2861));
		dyList.add(new Isotope("Dy165m", 165, "1.257 m", "108.8", 0));
		dyList.add(new Isotope("Dy166", 166, "81.6 h", "4.24e5", 0.4862));
		elements[66 - 1] = new Element("Dysprosium", 66, "Dy", dyList);
		//Holmium
		LinkedList<Isotope> hoList = new LinkedList<>();
		hoList.add(new Isotope("Ho164", 164, "29.00 m", "2510", 0.9868));
		hoList.add(new Isotope("Ho164m", 164, "37.5 m", "3246", 0));
		hoList.add(new Isotope("Ho165", 165, 100));
		hoList.add(new Isotope("Ho166", 166, "26.83 h", "1.393e5", 1.8549));
		hoList.add(new Isotope("Ho166m", 166, "1200 y", "5.46e10", 0));
		hoList.add(new Isotope("Ho167", 167, "3.10 h", "1.61e4", 1.007));
		elements[67 - 1] = new Element("Holmium", 67, "Ho", hoList);
		//Erbium
		LinkedList<Isotope> erList = new LinkedList<>();
		erList.add(new Isotope("Er161", 161, "3.21 h", "1.67e4", 2.002));
		erList.add(new Isotope("Er162", 162, 0.14));
		erList.add(new Isotope("Er163", 163, "1.25 h", "6492", 1.21));
		erList.add(new Isotope("Er164", 164, 1.6));
		erList.add(new Isotope("Er165", 165, "10.36 h", "53807", 0.376));
		erList.add(new Isotope("Er166", 166, 33.5));
		erList.add(new Isotope("Er167", 167, 22.87));
		erList.add(new Isotope("Er167m", 167, "2.269 s", "3.273", 0));
		erList.add(new Isotope("Er168", 168, 26.98));
		erList.add(new Isotope("Er169", 169, "9.4 d", "1.2e6", 0.3511));
		erList.add(new Isotope("Er170", 170, 14.91));
		erList.add(new Isotope("Er171", 171, "7.516 h", "39035", 1.4905));
		erList.add(new Isotope("Er172", 172, "49.3 h", "2.56e5", 0.891));
		elements[68 - 1] = new Element("Erbium", 68, "Er", erList);
		//Thulium
		LinkedList<Isotope> tmList = new LinkedList<>();
		tmList.add(new Isotope("Tm168", 168, "93.10 d", "11605", 1.9361));
		tmList.add(new Isotope("Tm169", 169, 100));
		tmList.add(new Isotope("Tm170", 170, "128.60 d", "1.603e7", 1.2824));
		tmList.add(new Isotope("Tm171", 171, "1.92 y", "8.74e7", 0.0964));
		elements[69 - 1] = new Element("Thulium", 69, "Tm", tmList);
		//Ytterbium
		LinkedList<Isotope> ybList = new LinkedList<>();
		ybList.add(new Isotope("Yb167", 167, "17.50 m", "1515", 1.954));
		ybList.add(new Isotope("Yb168", 168, 0.12));
		ybList.add(new Isotope("Yb169", 169, "32.026 d", "3.992e6", 0.909));
		ybList.add(new Isotope("Yb169m", 169, "46 s", "66", 0));
		ybList.add(new Isotope("Yb170", 170, 2.98));
		ybList.add(new Isotope("Yb171", 171, 14.09));
		ybList.add(new Isotope("Yb171m", 171, "5.25 ms", "0.00757", 0));
		ybList.add(new Isotope("Yb172", 172, 21.69));
		ybList.add(new Isotope("Yb173", 173, 16.1));
		ybList.add(new Isotope("Yb174", 174, 32.02));
		ybList.add(new Isotope("Yb175", 175, "4.185 d", "5.247e5", 0.47));
		ybList.add(new Isotope("Yb175m", 175, "68.2 ms", "0.0984", 0));
		ybList.add(new Isotope("Yb176", 176, 12.99));
		ybList.add(new Isotope("Yb176m", 176, "11.4 s", "16.5", 0));
		ybList.add(new Isotope("Yb177", 177, "1.911 h", "9925", 1.3992));
		ybList.add(new Isotope("Yb177m", 177, "6.41 s", "9.25", 0));
		ybList.add(new Isotope("Yb178", 178, "74 m", "6.4e3", 0.654));
		elements[70 - 1] = new Element("Ytterbium", 70, "Yb", ybList);
		//Lutetium
		LinkedList<Isotope> luList = new LinkedList<>();
		luList.add(new Isotope("Lu174", 174, "3.31 y", "1.51e8", 1.3743));
		luList.add(new Isotope("Lu174m", 174, "142 d", "1.77e7", 1.3743));
		luList.add(new Isotope("Lu175", 175, 97.4));
		luList.add(new Isotope("Lu176", 176, 2.6));
		luList.add(new Isotope("Lu176m", 176, "3.635 h", "18879", 0));
		luList.add(new Isotope("Lu177", 177, "6.734 d", "8.394e5", 0.4983));
		luList.add(new Isotope("Lu177m", 177, "160.4 d", "1.999e7", 0));
		luList.add(new Isotope("Lu178", 178, "28.40 m", "2458", 2.0992));
		luList.add(new Isotope("Lu178m", 178, "23.1 m", "2000", 0));
		elements[71 - 1] = new Element("Lutetium", 71, "Lu", luList);
		//Hafnium
		LinkedList<Isotope> hfList = new LinkedList<>();
		hfList.add(new Isotope("Hf173", 173, "23.60 h", "1.226e5", 1.61));
		hfList.add(new Isotope("Hf174", 174, 0.16));
		hfList.add(new Isotope("Hf175", 175, "70.00 d", "8.725e6", 0.6847));
		hfList.add(new Isotope("Hf176", 176, 5.26));
		hfList.add(new Isotope("Hf177", 177, 18.6));
		hfList.add(new Isotope("Hf177m", 177, "1.08 s", "1.56", 0));
		hfList.add(new Isotope("Hf177m2", 177, "51.4 m", "4449", 0));
		hfList.add(new Isotope("Hf178", 178, 27.28));
		hfList.add(new Isotope("Hf178m", 178, "4.0 s", "5.8", 0));
		hfList.add(new Isotope("Hf178m2", 178, "31 y", "1.4e9", 0));
		hfList.add(new Isotope("Hf179", 179, 13.62));
		hfList.add(new Isotope("Hf179m", 179, "18.67 s", "26.94", 0));
		hfList.add(new Isotope("Hf179m2", 179, "25.05 d", "3.122e6", 0));
		hfList.add(new Isotope("Hf180", 180, 35.08));
		hfList.add(new Isotope("Hf180m", 180, "5.5 h", "2.9e4", 0));
		hfList.add(new Isotope("Hf181", 181, "42.39 d", "5.284e4", 1.027));
		hfList.add(new Isotope("Hf182", 182, "9e6 y", "4e14", 0.373));
		hfList.add(new Isotope("Hf182m", 182, "61.5 m", "5324", 0));
		elements[72 - 1] = new Element("Hafnium", 72, "Hf", hfList);
		//Tantalum
		LinkedList<Isotope> taList = new LinkedList<>();
		taList.add(new Isotope("Ta179", 179, "1.82 y", "8.29e7", 0.111));
		taList.add(new Isotope("Ta179m", 179, "9.0 ms", "0.013", 0));
		taList.add(new Isotope("Ta179m2", 179, "52 ms", "0.075", 0));
		taList.add(new Isotope("Ta180", 180, 0.01));
		taList.add(new Isotope("Ta180m", 180, ">1.2e15 y", "", 0));
		taList.add(new Isotope("Ta181", 181, 99.99));
		taList.add(new Isotope("Ta182", 182, "114.43 d", "1.4264e7", 1.8135));
		taList.add(new Isotope("Ta182m", 182, "283 ms", "0.408", 0));
		taList.add(new Isotope("Ta182m2", 182, "15.84 m", "1371", 0));
		taList.add(new Isotope("Ta183", 183, "5.10 d", "6.36e5", 1.07));
		elements[73 - 1] = new Element("Tantalum", 73, "Ta", taList);
		//Tungsten
		LinkedList<Isotope> wList = new LinkedList<>();
		wList.add(new Isotope("W179", 179, "37.05 m", "4.328", 1.06));
		wList.add(new Isotope("W179m", 179, "6.40 m", "554", 1.06));
		wList.add(new Isotope("W180", 180, 0.12));
		wList.add(new Isotope("W180m", 180, "5.47 ms", "0.00789", 0));
		wList.add(new Isotope("W181", 181, "121.20 d", "1.5107e7", 0.188));
		wList.add(new Isotope("W182", 182, 26.5));
		wList.add(new Isotope("W183", 183, 14.31));
		wList.add(new Isotope("W183m", 183, ">1.1e17 y", "", 0));
		wList.add(new Isotope("W184", 184, 30.64));
		wList.add(new Isotope("W185", 185, "75.10 d", "1.56e6", 0.433));
		wList.add(new Isotope("W185m", 185, "1.67 m", "145", 0));
		wList.add(new Isotope("W186", 186, 28.43));
		wList.add(new Isotope("W187", 187, "23.72 h", "1.232e5", 1.3112));
		wList.add(new Isotope("W188", 188, "69.4 d", "8.65e6", 0.349));
		elements[74 - 1] = new Element("Tungsten", 74, "W", wList);
		//Rhenium
		LinkedList<Isotope> reList = new LinkedList<>();
		reList.add(new Isotope("Re184", 184, "38.0 d", "4.74e6", 1.483));
		reList.add(new Isotope("Re184m", 184, "169 d", "2.11e7", 1.483));
		reList.add(new Isotope("Re185", 185, 37.4));
		reList.add(new Isotope("Re186", 186, "3.7183 d", "463481", 1.5881));
		reList.add(new Isotope("Re186m", 186, "2.0e5 y", "9.1e12", 0));
		reList.add(new Isotope("Re187", 187, 62.6));
		reList.add(new Isotope("Re188", 188, "17.005 h", "88319", 2.1204));
		reList.add(new Isotope("Re188m", 188, "18.6 m", "1610", 0));
		reList.add(new Isotope("Re189", 189, "24.3 h", "1.26e5", 1.009));
		elements[75 - 1] = new Element("Rhenium", 75, "Re", reList);
		//Osmium
		LinkedList<Isotope> osList = new LinkedList<>();
		osList.add(new Isotope("Os183", 183, "13.00 h", "67518", 2.13));
		osList.add(new Isotope("Os183m", 183, "9.9 h", "5.1e4", 2.13));
		osList.add(new Isotope("Os184", 184, 0.02));
		osList.add(new Isotope("Os185", 185, "93.60 d", "1.167e7", 1.0128));
		osList.add(new Isotope("Os186", 186, 1.59));
		osList.add(new Isotope("Os187", 187, 1.96));
		osList.add(new Isotope("Os188", 188, 13.24));
		osList.add(new Isotope("Os189", 189, 16.15));
		osList.add(new Isotope("Os189m", 189, "5.8 h", "3e4", 0));
		osList.add(new Isotope("Os190", 190, 26.26));
		osList.add(new Isotope("Os190m", 190, "9.9 m", "860", 0));
		osList.add(new Isotope("Os191", 191, "15.40 d", "1.92e6", 0.3137));
		osList.add(new Isotope("Os191m", 191, "13.10 h", "68037", 0));
		osList.add(new Isotope("Os192", 192, 40.78));
		osList.add(new Isotope("Os192m", 192, "5.9 s", "8.1", 0));
		osList.add(new Isotope("Os193", 193, "30.11 h", "1.564e5", 1.1405));
		osList.add(new Isotope("Os194", 194, "6.00 y", "2.73e8", 0.0966));
		elements[76 - 1] = new Element("Osmium", 76, "Os", osList);
		//Iridium
		LinkedList<Isotope> irList = new LinkedList<>();
		irList.add(new Isotope("Ir190", 190, "11.78 d", "1.468e6", 2.62));
		irList.add(new Isotope("Ir190m", 190, "1.2 h", "6.2e3", 0));
		irList.add(new Isotope("Ir190m2", 190, "3.25 h", "1.69e4", 2));
		irList.add(new Isotope("Ir191", 191, 37.3));
		irList.add(new Isotope("Ir191m", 191, "4.94 s", "7.13", 0));
		irList.add(new Isotope("Ir191m2", 191, "5.5 s", "7.93", 0));
		irList.add(new Isotope("Ir192", 192, "73.831 d", "9.2029e6", 2.5059));
		irList.add(new Isotope("Ir192m", 192, "1.45 m", "126", 1.4597));
		irList.add(new Isotope("Ir192m2", 192, "21 y", "9.6e8", 0));
		irList.add(new Isotope("Ir193", 193, 62.7));
		elements[77 - 1] = new Element("Iridium", 77, "Ir", irList);
		//Platinum
		LinkedList<Isotope> ptList = new LinkedList<>();
		ptList.add(new Isotope("Pt189", 189, "10.87 h", "56456", 1.971));
		ptList.add(new Isotope("Pt190", 190, 0.01));
		ptList.add(new Isotope("Pt191", 191, "2.802 d", "3.493e5", 1.019));
		ptList.add(new Isotope("Pt192", 192, 0.78));
		ptList.add(new Isotope("Pt193", 193, "50.0 y", "2.28e9", 0.0566));
		ptList.add(new Isotope("Pt193m", 193, "4.33 d", "5.40e5", 0));
		ptList.add(new Isotope("Pt194", 194, 32.86));
		ptList.add(new Isotope("Pt195", 195, 33.77));
		ptList.add(new Isotope("Pt195m", 195, "4.02 d", "5.01e5", 0));
		ptList.add(new Isotope("Pt196", 196, 25.21));
		ptList.add(new Isotope("Pt197", 197, "19.8915 h", "103311", 0.7189));
		ptList.add(new Isotope("Pt197m", 197, "95.41 m", "8259", 0.7189));
		ptList.add(new Isotope("Pt198", 198, 7.36));
		elements[78 - 1] = new Element("Platinum", 78, "Pt", ptList);
		//Gold
		LinkedList<Isotope> auList = new LinkedList<>();
		auList.add(new Isotope("Au196", 196, "6.183 d", "7.707e5", 2.192));
		auList.add(new Isotope("Au196m", 196, "8.1 s", "12", 0));
		auList.add(new Isotope("Au196m2", 196, "9.6 h", "4.8e4", 0));
		auList.add(new Isotope("Au197", 197, 100));
		auList.add(new Isotope("Au197m", 197, "7.73 s", "11.2", 0));
		auList.add(new Isotope("Au198", 198, "2.69517 d", "335950", 1.3725));
		auList.add(new Isotope("Au198m", 198, "2.27 d", "2.83e5", 0));
		auList.add(new Isotope("Au199", 199, "3.139 d", "3.913e5", 0.4523));
		elements[79 - 1] = new Element("Gold", 79, "Au", auList);
		//Mercury
		LinkedList<Isotope> hgList = new LinkedList<>();
		hgList.add(new Isotope("Hg195", 195, "9.9 h", "5.1e4", 1.51));
		hgList.add(new Isotope("Hg195m", 195, "41.6 h", "2.16e5", 1.51));
		hgList.add(new Isotope("Hg196", 196, 0.15));
		hgList.add(new Isotope("Hg197", 197, "64.14 h", "3.331e5", 0.6));
		hgList.add(new Isotope("Hg197m", 197, "23.8 h", "1.24e5", 0.6));
		hgList.add(new Isotope("Hg198", 198, 10.04));
		hgList.add(new Isotope("Hg199", 199, 16.94));
		hgList.add(new Isotope("Hg199m", 199, "42.6 m", "3688", 0));
		hgList.add(new Isotope("Hg200", 200, 23.14));
		hgList.add(new Isotope("Hg201", 201, 13.17));
		hgList.add(new Isotope("Hg202", 202, 29.74));
		hgList.add(new Isotope("Hg203", 203, "46.612 d", "5810132", 0.4918));
		hgList.add(new Isotope("Hg204", 204, 6.82));
		hgList.add(new Isotope("Hg205", 205, "5.2 m", "450", 1.531));
		hgList.add(new Isotope("Hg205m", 205, "1.10 ms", "0.0016", 0));
		hgList.add(new Isotope("Hg206", 206, "8.15 m", "705", 1.307));
		elements[80 - 1] = new Element("Mercury", 80, "Hg", hgList);
		//Thallium
		LinkedList<Isotope> tlList = new LinkedList<>();
		tlList.add(new Isotope("Tl202", 202, "12.23 d", "1.524e6", 1.365));
		tlList.add(new Isotope("Tl202m", 202, "572 us", "0.000396", 0));
		tlList.add(new Isotope("Tl203", 203, 29.52));
		tlList.add(new Isotope("Tl204", 204, "3.78 y", "1.72e8", 1.11122));
		tlList.add(new Isotope("Tl205", 205, 70.48));
		tlList.add(new Isotope("Tl206", 206, "4.199 m", "363", 1.5335));
		tlList.add(new Isotope("Tl206m", 206, "3.74 m", "324", 0));
		tlList.add(new Isotope("Tl207", 207, "4.77 m", "413", 1.423));
		tlList.add(new Isotope("Tl207m", 207, "1.33 s", "1.92", 1.423));
		elements[81 - 1] = new Element("Thallium", 81, "Tl", tlList);
		//Lead
		LinkedList<Isotope> pbList = new LinkedList<>();
		pbList.add(new Isotope("Pb203", 203, "51.873 h", "269413", 0.975));
		pbList.add(new Isotope("Pb203m", 203, "6.3 s", "9.1", 0));
		pbList.add(new Isotope("Pb203m2", 203, "0.48 s", "0.69", 0));
		pbList.add(new Isotope("Pb204", 204, 1.4));
		pbList.add(new Isotope("Pb204m", 204, "67.2 m", "5817", 0));
		pbList.add(new Isotope("Pb205", 205, "1.53e7 y", "6.97e14", 0.0511));
		pbList.add(new Isotope("Pb205m", 205, "5.54 ms", "0.00799", 0));
		pbList.add(new Isotope("Pb206", 206, 24.1));
		pbList.add(new Isotope("Pb207", 207, 22.1));
		pbList.add(new Isotope("Pb207m", 207, "0.805 s", "1.161", 0));
		pbList.add(new Isotope("Pb208", 208, 52.4));
		pbList.add(new Isotope("Pb209", 209, "3.253 h", "16895", 0.6442));
		pbList.add(new Isotope("Pb210", 210, "22.3 y", "1.02e9", 3.8555));
		elements[82 - 1] = new Element("Lead", 82, "Pb", pbList);
		//Bismuth
		LinkedList<Isotope> biList = new LinkedList<>();
		biList.add(new Isotope("Bi208", 208, "3.68e5 y", "1.68e13", 2.8791));
		biList.add(new Isotope("Bi208m", 208, "2.58 ms", "0.00368", 0));
		biList.add(new Isotope("Bi209", 209, 100));
		biList.add(new Isotope("Bi210", 210, "5.013 d", "6.249e5", 7.9126));
		biList.add(new Isotope("Bi210m", 210, "3.04e6 y", "1.38e14", 5.036));
		biList.add(new Isotope("Bi211", 211, "2.14 m", "185", 7.329));
		elements[83 - 1] = new Element("Bismuth", 83, "Bi");
		// Polonium
		elements[84 - 1] = new Element("Polonium", 84, "Po");
		// Astatine
		elements[85 - 1] = new Element("Astatine", 85, "At");
		// Radon
		elements[86 - 1] = new Element("Radon", 86, "Rn");
		// Francium
		elements[87 - 1] = new Element("Francium", 87, "Fr");
		// Radium
		elements[88 - 1] = new Element("Radium", 88, "Ra");
		// Actinium
		elements[89 - 1] = new Element("Actinium", 89, "Ac");		
		//Thorium
		LinkedList<Isotope> thList = new LinkedList<>();
		thList.add(new Isotope("Th229", 229, "7340 y", "3.34e11", 5.1676));
		thList.add(new Isotope("Th230", 230, 0.02));
		thList.add(new Isotope("Th231", 231, "25.52 h", "1.33e5", 4.6028));
		thList.add(new Isotope("Th232", 232, 99.98));
		thList.add(new Isotope("Th233", 233, "22.3 m", "1930", 1.2451));
		thList.add(new Isotope("Th234", 234, "24.10 d", "3.004e6", 0.273));
		elements[90 - 1] = new Element("Thorium", 90, "Th", thList);
		//Protactinium
		LinkedList<Isotope> paList = new LinkedList<>();
		paList.add(new Isotope("Pa230", 230, "17.40 d", "2.069e6", 7.313));
		paList.add(new Isotope("Pa231", 231, 100));
		paList.add(new Isotope("Pa232", 232, "1.31 d", "1.63e5", 1.832));
		paList.add(new Isotope("Pa233", 233, "26.967 d", "3361406", 0.5701));
		elements[91 - 1] = new Element("Protactinium", 91, "Pa", paList);
		//Uranium
		LinkedList<Isotope> uList = new LinkedList<>();
		uList.add(new Isotope("U233", 233, "1.592e5 y", "7.248e12", 4.9086));
		uList.add(new Isotope("U234", 234, 0.01));
		uList.add(new Isotope("U235", 235, 0.72));
		uList.add(new Isotope("U235m", 235, "25 m", "2164", 0));
		uList.add(new Isotope("U236", 236, "2.342e7 y", "1.102e8", 4.572));
		uList.add(new Isotope("U237", 237, "6.75 d", "8.41e5", 0.5186));
		uList.add(new Isotope("U238", 238, 99.27));
		uList.add(new Isotope("U238m", 238, "225 ns", "", 0));
		uList.add(new Isotope("U238m2", 238, ">1 ns", "", 0));
		uList.add(new Isotope("U239", 239, "23.45 m", "2030", 1.2635));
		uList.add(new Isotope("U240", 240, "14.10 h", "73231", 0.388));
		elements[92 - 1] = new Element("Uranium", 92, "U", uList);
		// Neptunium
		elements[93 - 1] = new Element("Neptunium", 93, "Np");
		// Plutonium
		elements[94 - 1] = new Element("Plutonium", 94, "Pu");
		// Americium
		elements[95 - 1] = new Element("Americium", 95, "Am");
		// Curium
		elements[96 - 1] = new Element("Curium", 96, "Cm");
		// Berkelium
		elements[97 - 1] = new Element("Berkelium", 97, "Bk");
		// Californium
		elements[98 - 1] = new Element("Californium", 98, "Cf");
		// Einsteinium
		elements[99 - 1] = new Element("Einsteinium", 99, "Es");
		// Fermium
		elements[100 - 1] = new Element("Fermium", 100, "Fm");
		// Mendelevium
		elements[101 - 1] = new Element("Mendelevium", 101, "Md");
		// Nobelium
		elements[102 - 1] = new Element("Nobelium", 102, "No");
		// Lawrencium
		elements[103 - 1] = new Element("Lawrencium", 103, "Lr");
		// Rutherfordium
		elements[104 - 1] = new Element("Rutherfordium", 104, "Rf");
		// Dubnium
		elements[105 - 1] = new Element("Dubnium", 105, "Db");
		// Seaborgium
		elements[106 - 1] = new Element("Seaborgium", 106, "Sg");
		// Bohrium
		elements[107 - 1] = new Element("Bohrium", 107, "Bh");
		// Hassium
		elements[108 - 1] = new Element("Hassium", 108, "Hs");
		// Meitnerium
		elements[109 - 1] = new Element("Meitnerium", 109, "Mt");
		// Darmstadtium
		elements[110 - 1] = new Element("Darmstadtium", 110, "Ds");
		// Roentgenium
		elements[111 - 1] = new Element("Roentgenium", 111, "Rg");
		// Copernicium
		elements[112 - 1] = new Element("Copernicium", 112, "Cn");
		// Nihonium
		elements[113 - 1] = new Element("Nihonium", 113, "Nh");
		// Flerovium
		elements[114 - 1] = new Element("Flerovium", 114, "Fl");
		// Moscovium
		elements[115 - 1] = new Element("Moscovium", 115, "Mc");
		// Livermorium
		elements[116 - 1] = new Element("Livermorium", 116, "Lv");
		// Tennessine
		elements[117 - 1] = new Element("Tennessine", 117, "Ts");
		// Oganesson
		elements[118 - 1] = new Element("Oganesson", 118, "Og");
		

		//Scanners are used to take user input
		
		
		Scanner scanner = new Scanner(System.in);
		//asks for user input as an atomic number or symbol
		String display = "Enter an atomic number or symbol or press '0' to exit.";
		//displays the the above String
		System.out.println(display);
		//takes user input
		String scanned = scanner.next();
		Element element = null;
		//if the user enters 0, the sequence
		while(!scanned.equals("0")) {
			int num = tryInt(scanned);
			//if given a number, make sure that it is valid and then get that number the array elements
			if(num > 0 && num <= 118) {
				num--;
				element = elements[num];
			}
			else if(scanned.equals("0")) break;
			else element = search(scanned, elements);
			//displays the information for the given element
			if(element != null)
				System.out.println(element.toString());
			//asks for user input again
			System.out.println(display);
			//gets user input
			scanned = scanner.next();
		}
	}
	/**
	 * Searches the array of elements based on the input the element's atomic symbol
	 * @param input
	 * @param elements
	 * @return the searched for Element
	 */
	public static Element search(String input, Element[] elements) {
		//for each Element in the array, return the one who's atomic symbol is matched with input
		int i = 0;
		for(Element e : elements) {
			if(e == null) System.out.println(i);
			else if(input.toLowerCase().equals(e.atomicSymbol.toLowerCase())) {
				return e;
			}
			i++;
		}
		System.out.println("Not a valid atomic symbol or number");
		//if nothing was returned yet, display that the input does not match any of the Elements in the array
		return null;
	}
	/**
	 * Converts the input to an integer
	 * @param input
	 * @return a valid integer if the input is an integer or -1 otherwie
	 */
	public static int tryInt(String input) {
		//tries to parse an integer from the String and return it
		try {
			int result = (int)Integer.parseInt(input);
			return result;
		}
		//if trying to parse did not work, return -1
		catch(Exception e) {
			return -1;
		}
	}
}
