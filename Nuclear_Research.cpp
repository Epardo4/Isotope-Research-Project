#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
	Class to define an isotope
*/
class Isotope{
	public:
		string halfLife;
		string meanLife;
		double energy = 0;
		string name;
		int mass = 0;
		double abundance = 0;
};
/*
	Class to define an element
*/
class Element{
	public:
		vector<Isotope> isotopes;
		string name;
		int atomicNumber;
		string atomicSymbol;
};
/*
	Formats input so that way it takes up amount number of characters
	format(10, "Hello") would return "Hello     "
*/
string format(int amount, string input){
	int size = input.size();
	int toFormat = amount - size;
	for(int i = 0; i < toFormat; i++)
		input.append(" ");
	return input;
}
/*
	returns a string to display the isotope class
*/
string toString(Isotope isotope){
		string stability = "";
		string name = format(20, isotope.name);
		string result = "";
		string massFormat = "";
		string energyFormat = "";
		//Checks whether or not the object is metastable and prints out accordingly
		int toFind = isotope.name.find('m');
		if(toFind >= 0 && toFind < 6) {
			stability = format(20, "metastable");
			massFormat = format(20, to_string(isotope.mass));
			energyFormat = format(20, to_string(isotope.energy).substr(0 , 5));
			string halfLife = format(20, isotope.halfLife);
			string meanLife = format(20, isotope.meanLife);
			result = result.append(name).append(massFormat).append(stability).append(halfLife).append(meanLife).append(energyFormat);
		}
		//If there is an energy, the the object must be unstable so print out the information accordingly
		else if(isotope.energy != 0) {
			stability = format(20, "unstable");
			massFormat = format(20, to_string(isotope.mass));
			energyFormat = format(20, to_string(isotope.energy).substr(0, 5));
			string halfLife = format(20, isotope.halfLife);
			string meanLife = format(20, isotope.meanLife);
			result = result.append(name).append(massFormat).append(stability).append(halfLife).append(meanLife).append(energyFormat);
		}
		//In any other case, the the object must be stable so print out the information accordingly
		else {
			stability = format(20, to_string(isotope.abundance).substr(0, 5));
			massFormat = format(20, to_string(isotope.mass));
			result = result.append(name).append(massFormat).append(stability).append("stable");		
		}
		//Add two new lines to result
		result = result.append("\n\n");
		return result;
}
/*
	returns a string to display the element class
*/
string toString(Element element){
		string num = format(20, to_string(element.atomicNumber));
		string result = "";
		string elementDisplay = format(20, "Element").append(format(20, "Atomic Symbol")).append(format(20, "Atomic Number")).append("\n");
		string name = format(20, element.name);
		string isotopeDisplay = format(20, "Isotope").append(format(20, "Mass (amu)")).append(format(20, "Abundance (%)")).append(format(20, "Half-Life")).append(
								format(20, "Mean-Life (s)")).append(format(20, "Energy (MeV)")).append("\n\n");		
		string symbol = format(20, element.atomicSymbol);
		//if there are isotopes for this Element, print the display accordingly
		if(element.isotopes.size() > 0) {
			result = elementDisplay.append(name).append(symbol).append(num).append("\n\n").append(isotopeDisplay);
			//for each Isotope in this object, display the Isotope accordingly
			for(int i = 0; i < element.isotopes.size(); i++)
				result = result.append(toString(element.isotopes[i]));
		}
		//if there are no isotopes for this Element, print the display accordingly
		else {
			result = elementDisplay.append(name).append(symbol).append(num).append("\n\n").append("This element does not have any isotopes\n");	
		}
		return result;
}
/*
	returns a new input string that is to lower case
*/
string toLower(string input){
	string output = "";
	for(int i = 0; i < input.size(); i++)
		output += tolower(input.at(i));
	return output;
}
/*
	searches every Element in elements for the desired element using the atomic symbol as input
*/
Element search(string input, Element elements[]){
	for(int i = 0; i < 118; i++)
		if(toLower(input).compare(toLower(elements[i].atomicSymbol)) == 0) return elements[i];
	Element toReturn;
	//set the atomic number to -1 so the code knows this was not a valid atomic symbol
	toReturn.atomicNumber = -1;
	cout << "Not a valid atomic symbol or atomic number.\n";
	return toReturn;
}
/*
	Acts as a constructor for the Element class
	Constructs an Element with no isotopes
*/
Element makeElement(string name, int atomicNumber, string atomicSymbol){
	Element element;
	element.name = name;
	element.atomicNumber = atomicNumber;
	element.atomicSymbol = atomicSymbol;
	return element;
}
/*
	Acts as a constructor for the Element class
	Constructs an Element with isotopes
*/
Element makeElement(string name, int atomicNumber, string atomicSymbol, vector<Isotope> isotopes){
	Element element;
	element.name = name;
	element.atomicNumber = atomicNumber;
	element.atomicSymbol = atomicSymbol;
	element.isotopes = isotopes;
	return element;
}
/*
	Acts as a constructor for the Isotope class
	Constructs an unstable or metastable isotope
*/
Isotope makeIsotope(string name, int mass, string halfLife, string meanLife, double energy){
	Isotope isotope;
	isotope.name = name;
	isotope.mass = mass;
	isotope.halfLife = halfLife;
	isotope.meanLife = meanLife;
	isotope.energy = energy;
	return isotope;
}
/*
	Acts as a constructor for the Isotope class
	Constructs a stable isotope
*/
Isotope makeIsotope(string name, int mass, double abundance){
	Isotope isotope;
	isotope.name = name;
	isotope.mass = mass;
	isotope.abundance = abundance;
	return isotope;
}
/*
	Searches each character of input for one which is a non-number character, if it finds one, it returns -1
	otherwise, returns the number which input represents 
*/
int tryInt(string input){
	int check = 0;
	int total = 0;
	for(int i = 0; i < input.size(); i++){
		check = input.at(i) - 0;
		//checks the characters by their ascii representation for whether they are numbers
		if(check >= 48 && check <= 57){
			check -= 48;
			total += check * pow(10, input.size() - i - 1); //since it is a number, multiply by 10^(spot in input) and add it to total
		}
		else return -1;
	}
	return total;
}

int main(){
	//Creating the Element array
	Element elements[118];
	//Hydrogen
	vector<Isotope> hList = {makeIsotope("H1", 1, 99.99), makeIsotope("H2", 2, 0.01), 
					makeIsotope("H3", 3, "12.33 y", "5.61e8", 0.018591), makeIsotope("H4", 4, "0", "0", 23.5)};
	elements[0] = makeElement("Hydrogen", 1, "H", hList);
	//Helium
	vector<Isotope> heList = { makeIsotope("He3", 3, "0", "0", 0), makeIsotope("He4", 4, "0", "0", 100), 
					makeIsotope("He5", 5, "< 1.00 ms", "0", 0.6), makeIsotope("He6", 6, "806.7 ms", "1.164", 3.5078)};
	elements[1] = makeElement("Helium", 2, "He", heList);
	//Lithium
	vector<Isotope> liList = {makeIsotope("Li5", 5, "< 1.00 ms", "0", 1.5), makeIsotope("Li6", 6, "7.59", "0", 0), makeIsotope("Li7", 7, "92.41", "0", 0),
    				makeIsotope("Li8", 8, "838 ms", "1.209", 16.0045), makeIsotope("Li9", 9, "178.30 ms", "0.25723", 13.6063)};
	elements[2] = makeElement("Lithium", 3, "Li", liList);
	//Beryllium
	vector<Isotope> beList = {makeIsotope("Be8", 8, "< 1.00 ms", "0", 0.0000068), makeIsotope("Be9", 9, "0", "0", 100), 
					makeIsotope("Be10", 10, "1.51*10^6 y", "6.87 * 10^13", 0.5558),makeIsotope("Be11", 11, "13.81 s", "19.92", 11.506)};
	elements[3] = makeElement("Beryllium", 4, "Be", beList);
	//Boron
	vector<Isotope> bList = {makeIsotope("B9", 9, "< 1.00 ms", "0", 0.00054), makeIsotope("B10", 10, "19.9", "0", 0), makeIsotope("B11", 11, "80.1", "0", 0),
    				makeIsotope("B12", 12, "20.20 ms", "0.02914", 13.3689), makeIsotope("B13", 13, "17.36 ms", "0.02505", 13.4372)};
	elements[4] = makeElement("Boron", 5, "B", bList);
	//Carbon
	vector<Isotope> cList = {makeIsotope("C11", 11, "20.39 m", "1765", 1.9825), makeIsotope("C12", 12, "98.93", "0", 0), makeIsotope("C13", 13, "1.07", "0", 0),
    				makeIsotope("C14", 14, "5730 y", "2.61 * 10^11", 0.156475), makeIsotope("C15", 15, "2.449 s", "3.533", 9.7717)};
	elements[5] = makeElement("Carbon", 6, "C", cList);
	//Nitrogen
	vector<Isotope> nList = {makeIsotope("N13", 13, "9.965 m", "862.6", 2.2204), makeIsotope("N14", 14, "99.64", "0", 0), makeIsotope("N15", 15, "0.36", "0", 0),
    				makeIsotope("N16", 16, "7.13 s", "10.3", 10.42), makeIsotope("N17", 17, "4.173 s", "6.02", 8.68)};
	elements[6] = makeElement("Nitrogen", 7, "N", nList);
	//Oxygen
	vector<Isotope> oList = {makeIsotope("O15", 15, "122.24 s", "176.36", 2.7539), makeIsotope("O16", 16, "99.76", "0", 0), makeIsotope("O17", 17, "0.04", "0", 0),
    				makeIsotope("O18", 18, "0.2", "0", 0), makeIsotope("O19", 19, "26.91 s", "38.82", 4.821), makeIsotope("O20", 20, "13.51 s", "19.49", 3.8143)};
	elements[7] = makeElement("Oxygen", 8, "O", oList);
	//Flourine
	vector<Isotope> fList = {makeIsotope("F18", 18, "109.77 m", "0.15836", 1.6555), makeIsotope("F19", 19, "100", "0", 0), makeIsotope("F20", 20, "11.00 s", "15.87", 7.02453),
    				makeIsotope("F21", 21, "4.158 s", "5.999", 5.6841)};
	elements[8] = makeElement("Flourine", 9, "F", fList);
	//Neon
	vector<Isotope> neList = {makeIsotope("Ne19", 19, "17.22 s", "24.84", 3.2385), makeIsotope("Ne20", 20, "90.48", "0", 0), makeIsotope("Ne21", 21, "0.27", "0", 0),
    				makeIsotope("Ne22", 22, "9.25", "0", 0), makeIsotope("Ne23", 23, "37.24 s", "53.73", 4.37584), makeIsotope("Ne24", 24, "3.38 m", "293", 2.47)};
	elements[9] = makeElement("Neon", 10, "Ne", neList);
	//Sodium
	vector<Isotope> naList = {makeIsotope("Na22", 22, "2.6019 y", "1.1846 * 10^8", 2.8422), makeIsotope("Na23", 23, "100", "0", 0), 
					makeIsotope("Na24", 24, "14.9590 h", "77692.6", 5.51578), makeIsotope("Na24m", 24, "20.20 ms", "0.02914", 5.51578), 
					makeIsotope("Na25", 25, "59.10 s", "85.26", 3.8353)};
	elements[10] = makeElement("Sodium", 11, "Na", naList);
	//Magnesium
	vector<Isotope> mgList = {makeIsotope("Mg23", 23, "11.317 s", "16.327", 4.0568), makeIsotope("Mg24", 24, "78.99", "0", 0), makeIsotope("Mg25", 25, "10", "0", 0),
    				makeIsotope("Mg26", 26, "11.01", "0", 0), makeIsotope("Mg27", 27, "9.458 m", "818.7", 2.61033), makeIsotope("Mg28", 28, "20.91 h", "52180", 1.8318)};
	elements[11] = makeElement("Magnesium", 12, "Mg",mgList);
	//Aluminum
	vector<Isotope> alList = {makeIsotope("Al26", 26, "7.17 * 10^5 y", "3.26 * 10^13", 4.00414), makeIsotope("Al26m", 26, "6.3452 s", "9.1542", 4.00414),
    				makeIsotope("Al27", 27, "100", "0", 0), makeIsotope("Al28", 28, "2.2414 m", "194.02", 4.64224), makeIsotope("Al29", 29, "6.56 m", "568", 3.6795)};
	elements[12] = makeElement("Aluminum", 13, "Al", alList);
	//Silicon
	vector<Isotope> siList = {makeIsotope("Si27", 27, "4.16 s", "6.01", 4.8124), makeIsotope("Si28", 28, "92.23", "0", 0), makeIsotope("Si29", 29, "4.68", "0", 0),
    				makeIsotope("Si30", 30, "3.09", "0", 0), makeIsotope("Si31", 31, "157.3 m", "13620", 1.49203), makeIsotope("Si32", 32, "150 y", "6.83 * 10^9", 0.2245)};
	elements[13] = makeElement("Silicon", 14, "Si",siList);
	//Phosphorus
	vector<Isotope> pList = { makeIsotope("P30", 30, "2.498 m", "216.2", 4232.3), makeIsotope("P31", 31, "100", "0", 0),
	        		makeIsotope("P32", 32, "14.262 d", "1.7777 * 10^6", 1.71066), makeIsotope("P33", 33, "25.34 d", "3159000", 0.2485) };
	elements[14] = makeElement("Phosphorus", 15, "P",pList);
	//Sulfur
	vector<Isotope> sList = { makeIsotope("S31", 31, "2.572 s", "3.711", 5.3961), makeIsotope("S32", 32, "94.99", "0", 0), 
					makeIsotope("S33", 33, "0.75", "0", 0), makeIsotope("S34", 34, "4.25", "0", 0),
        			makeIsotope("S35", 35, "87.32 d", "1.088 * 10^7", 0.16714), makeIsotope("S36", 36, "0.01", "0", 0),
					makeIsotope("S37", 37, "5.05 m", "437", 4.8653), makeIsotope("S38", 38, "170.3 m", "14740", 2.937) };
	elements[15] = makeElement("Sulfur", 16, "S",sList);
	//Chlorine
	vector<Isotope> clList = { makeIsotope("Cl34", 34, "1.5264 s", "2.2021", 5.49128), makeIsotope("Cl34m", 34, "32.00 m", "2770", 5.49128),
        			makeIsotope("Cl35", 35, "75.76", "0", 0), makeIsotope("Cl36", 36, "3.01e5 y", "1.37e13", 1.85067),
        			makeIsotope("Cl37", 37, "24.24", "0", 0), makeIsotope("Cl38", 38, "37.24 m", "3224", 4.9168),
        			makeIsotope("Cl38m", 38, "715 ms", "1.03", 0), makeIsotope("Cl39", 39, "55.6 m", "4813", 3.441) };
	elements[17 - 1] = makeElement("Chlorine", 17, "Cl", clList);
	//Argon
	vector<Isotope> arList = { makeIsotope("Ar35", 35, "1.775 s", "2.561", 5.9653), makeIsotope("Ar36", 36, "0.33", "0", 0),
        			makeIsotope("Ar37", 37, "35.04 d", "4.368e6", 0.8135), makeIsotope("Ar38", 38, "0.06", "0", 0),
         			makeIsotope("Ar39", 39, "269 y", "1.22e10", 0.565), makeIsotope("Ar40", 40, "99.6", "0", 0),
        			makeIsotope("Ar41", 41, "109.34 m", "9464.7", 2.4916), makeIsotope("Ar42", 42, "32.9 y", "1.498e9", 0.599) };
	elements[18 - 1] = makeElement("Argon", 18, "Ar", arList);
	//Potassium
	vector<Isotope> kList = { makeIsotope("K38", 38, "7.636 m", "661", 5.9131), makeIsotope("K38m", 38, "923.9 ms", "1.333", 5.9131),
        			makeIsotope("K39", 39, "93.26", "0", 0), makeIsotope("K40", 40, "0.01", "0", 0),
        			makeIsotope("K41", 41, "6.73", "0", 0), makeIsotope("K42", 42, "12.360 h", "64194", 3.5254),
        			makeIsotope("K43", 43, "22.3 h", "115000", 1.815) };
	elements[19 - 1] = makeElement("Potassium", 19, "K", kList);
	//Calcium
	vector<Isotope> caList = { makeIsotope("Ca39", 39, "859.6 ms", "1.24", 6.5306), makeIsotope("Ca40", 40, "96.94", "0", 0),
        			makeIsotope("Ca41", 41, "1.03e5 y", "4.69e12", 0.4214), makeIsotope("Ca42", 42, "0.65", "0", 0),
        			makeIsotope("Ca43", 43, "0.14", "0", 0), makeIsotope("Ca44", 44, "2.09", "0", 0),
        			makeIsotope("Ca45", 45, "162.61 d", "2.0269e7", 0.2568), makeIsotope("Ca46", 46, "0", "0", 0),
        			makeIsotope("Ca47", 47, "4.536 d", "5.654e5", 1.9919), makeIsotope("Ca48", 48, "0.19", "0", 0),
        			makeIsotope("Ca49", 49, "8.718 m", "362.6", 0.5262), makeIsotope("Ca50", 50, "13.9 s", "20.1", 4.966) };
	elements[20 - 1] = makeElement("Calcium", 20, "Ca", caList);
	//Scandium
	vector<Isotope> scList = { makeIsotope("Sc44", 44, "3.927 h", "20396", 3.6533), makeIsotope("Sc44m", 44, "58.6 h", "3.04e5", 3.6533),
        			makeIsotope("Sc45", 45, "100", "0", 0), makeIsotope("Sc45m", 45, "318 ms", "0.459", 0),
        			makeIsotope("Sc46", 46, "83.79 d", "1.044e7", 2.3667), makeIsotope("Sc46m", 46, "18.75 s", "27.05", 2.3667),
        			makeIsotope("Sc47", 47, "3.35 d", "4.17e5", 0.6001) };
	elements[21 - 1] = makeElement("Scandium", 21, "Sc", scList);
	//Titanium
	vector<Isotope> tiList = { makeIsotope("Ti45", 45, "184.8 m", "15997", 2.0624), makeIsotope("Ti46", 46, "8.25", "0", 0),
        			makeIsotope("Ti47", 47, "7.44", "0", 0), makeIsotope("Ti48", 48, "73.72", "0", 0),
        			makeIsotope("Ti49", 49, "5.41", "0", 0), makeIsotope("Ti50", 50, "5.18", "0", 0),
        			makeIsotope("Ti51", 51, "5.76 m", "499", 2.4706), makeIsotope("Ti52", 52, "1.7 m", "147", 1.937) };
	elements[22 - 1] = makeElement("Titanium", 22, "Ti", tiList);
	//Vanadium
	vector<Isotope> vList = { makeIsotope("V49", 49, "330 d", "4.1e7", 0.6019), makeIsotope("V50", 50, "0.25", "0", 0),
        			makeIsotope("V51", 51, "99.75", "0", 0), makeIsotope("V52", 52, "3.743 m", "324", 3.9754),
        			makeIsotope("V53", 53, "1.61 m", "139", 3.436) };
	elements[23 - 1] = makeElement("Vanadium", 23, "V", vList);
	//Chromium
	vector<Isotope> crList = { makeIsotope("Cr49", 49, "42.3 m", "3662", 2.631), makeIsotope("Cr50", 50, "4.34", "0", 0),
        			makeIsotope("Cr51", 51, "27.7025 d", "3453084", 0.75273), makeIsotope("Cr52", 52, "83.79", "0", 0),
        			makeIsotope("Cr53", 53, "9.5", "0", 0), makeIsotope("Cr54", 54, "2.37", "0", 0),
        			makeIsotope("Cr55", 55, "3.497 m", "302.7", 2.6031), makeIsotope("Cr56", 56, "5.94 m", "614", 1.617) };
	elements[24 - 1] = makeElement("Chromium", 24, "Cr", crList);
	//Manganese
	vector<Isotope> mnList = { makeIsotope("Mn54", 54, "312.3 d", "3.892e7", 2.0742), makeIsotope("Mn55", 55, "100", "0", 0),
        			makeIsotope("Mn56", 56, "2.5785 h", "13391", 3.695), makeIsotope("Mn57", 57, "85.4 s", "123", 2.691) };
	elements[25 - 1] = makeElement("Manganese", 25, "Mn", mnList);
	//Iron
	vector<Isotope> feList = { makeIsotope("Fe53", 53, "8.51 m", "737", 3.7424), makeIsotope("Fe53m", 53, "2.58 m", "223", 3.7424),
        			makeIsotope("Fe54", 54, "5.84", "0", 0), makeIsotope("Fe55", 55, "2.73 y", "1.24e8", 0.23138),
        			makeIsotope("Fe56", 56, "91.75", "0", 0), makeIsotope("Fe57", 57, "2.12", "0", 0),
        			makeIsotope("Fe58", 58, "0.28", "0", 0), makeIsotope("Fe59", 59, "44.503 d", "5547247", 1.5652),
        			makeIsotope("Fe60", 60, "1.5e6 y", "6.8e13", 0.237) };
	elements[26 - 1] = makeElement("Iron", 26, "Fe", feList);
	//Cobalt
	vector<Isotope> coList = { makeIsotope("Co58", 58, "70.86 d", "8832647", 2.3074), makeIsotope("Co58m", 58, "9.04 h", "46951", 2.3074),
        			makeIsotope("Co59", 59, "100", "0", 0), makeIsotope("Co60", 60, "5.2714 y", "2.39996e8", 2.8329),
        			makeIsotope("Co60m", 60, "10.467 m", "906.04", 2.8329), makeIsotope("Co61", 61, "1.650 h", "8570", 1.3217) };
	elements[27 - 1] = makeElement("Cobalt", 27, "Co", coList);
	//Nickel
	vector<Isotope> niList = { makeIsotope("Ni57", 57, "35.60 h", "184895", 3.264), makeIsotope("Ni58", 58, "68.08", "0", 0),
        			makeIsotope("Ni59", 59, "7.6e4 y", "9.5e12", 1.0725), makeIsotope("Ni60", 60, "26.22", "0", 0),
        			makeIsotope("Ni61", 61, "1.14", "0", 0), makeIsotope("Ni62", 62, "3.63", "0", 0),
        			makeIsotope("Ni63", 63, "100.1 y", "4.557e9", 0.066945), makeIsotope("Ni64", 64, "0.93", "0", 0),
        			makeIsotope("Ni65", 65, "2.5172 h", "13074", 2.1371), makeIsotope("Ni66", 66, "54.6 h", "2.84e5", 0.226) };
	elements[28 - 1] = makeElement("Nickel", 28, "Ni", niList);
	//Copper
	vector<Isotope> cuList = { makeIsotope("Cu62", 62, "9.74 m", "843", 3.948), makeIsotope("Cu63", 63, "69.15", "0", 0),
        			makeIsotope("Cu64", 64, "12.700 h", "65960", 2.2538), makeIsotope("Cu65", 65, "30.85", "0", 0),
        			makeIsotope("Cu66", 66, "5.120 m", "443.2", 2.642), makeIsotope("Cu67", 67, "61.83 h", "321127", 0.577) };
	elements[29 - 1] = makeElement("Copper", 29, "Cu", cuList);
	//Zinc
	vector<Isotope> znList = { makeIsotope("Zn63", 63, "38.47 m", "3330", 3.3669), makeIsotope("Zn64", 64, "49.17", "0", 0),
        			makeIsotope("Zn65", 65, "244.26 d", "3.0447e7", 1.3519), makeIsotope("Zn66", 66, "27.73", "0", 0),
        			makeIsotope("Zn67", 67, "4.04", "0", 0), makeIsotope("Zn68", 68, "18.45", "0", 0),
        			makeIsotope("Zn69", 69, "56.4 m", "4882", 0.906), makeIsotope("Zn69m", 69, "13.76 h", "71465", 0.906),
        			makeIsotope("Zn70", 70, "0.61", "0", 0), makeIsotope("Zn71", 71, "2.45 m", "212", 2.815),
        			makeIsotope("Zn71m", 71, "3.96 h", "20567", 2.815), makeIsotope("Zn72", 72, "1.94 d", "2.42e5", 0.458) };
	elements[30 - 1] = makeElement("Zinc", 30, "Zn", znList);
	//Gallium
	vector<Isotope> gaList = { makeIsotope("Ga68", 68, "67.629 m", "5854.1", 2.9211), makeIsotope("Ga69", 69, "60.11", "0", 0),
        			makeIsotope("Ga70", 70, "21.14 m", "1830", 2.3107), makeIsotope("Ga71", 71, "39.89", "0", 0),
        			makeIsotope("Ga72", 72, "14.10 h", "73231", 3.9991), makeIsotope("Ga72m", 72, "39.68 ms", "0.05725", 3.9991),
        			makeIsotope("Ga73", 73, "4.86 h", "25241", 1.593) };
	elements[31 - 1] = makeElement("Gallium", 31, "Ga", gaList);
	//Germanium
	vector<Isotope> geList = { makeIsotope("Ge69", 69, "39.05 h", "2.028e5", 2.2273), makeIsotope("Ge70", 70, "20.52", "0", 0),
        			makeIsotope("Ge71", 71, "11.43 d", "1.425e6", 0.2319), makeIsotope("Ge71m", 71, "20.40 ms", "0.02943", 0.2319),
        			makeIsotope("Ge72", 72, "27.45", "0", 0), makeIsotope("Ge73", 73, "7.76", "0", 0),
        			makeIsotope("Ge73m", 73, "0.499 s", "0.72", 0), makeIsotope("Ge74", 74, "36.52", "0", 0),
        			makeIsotope("Ge75", 75, "82.78 m", "7166", 1.7156), makeIsotope("Ge75m", 75, "47.7 s", "68.8", 1.7156),
        			makeIsotope("Ge76", 76, "7.75", "0", 0), makeIsotope("Ge77", 77, "11.30 h", "58689", 2.702),
        			makeIsotope("Ge77m", 77, "52.9 s", "76.3", 2.702), makeIsotope("Ge78", 78, "88.0 m", "7617", 0.954) };
	elements[32 - 1] = makeElement("Germanium", 32, "Ge", geList);
	//Arsenic
	vector<Isotope> asList = { makeIsotope("As74", 74, "17.77 d", "2.215e6", 3.9154), makeIsotope("As75", 75, "100", "0", 0),
        			makeIsotope("As75m", 75, "16.79 ms", "0.02379", 0), makeIsotope("As76", 76, "1.0778 d", "134347", 2.962),
        			makeIsotope("As77", 77, "38.83 h", "201671", 0.6829) };
	elements[33 - 1] = makeElement("Arsenic", 33, "As", asList);
	//Selenium
	vector<Isotope> seList = { makeIsotope("Se73", 73, "7.15 h", "3.71e4", 2.74), makeIsotope("Se73m", 73, "39.8 m", "3445", 2.74),
        			makeIsotope("Se74", 74, "0.86", "0", 0), makeIsotope("Se75", 75, "119.779 d", "1.493e7", 0.8636),
        			makeIsotope("Se76", 76, "9.23", "0", 0), makeIsotope("Se77", 77, "7.6", "0", 0),
        			makeIsotope("Se77m", 77, "17.36 s", "25.05", 0), makeIsotope("Se78", 78, "23.69", "0", 0),
        			makeIsotope("Se79", 79, "1.13e6 y", "2.47e13", 0.151), makeIsotope("Se79m", 79, "3.92 m", "339", 0.151),
        			makeIsotope("Se80", 80, "49.8", "0", 0), makeIsotope("Se81", 81, "18.45 m", "1597", 1.585),
        			makeIsotope("Se81m", 81, "57.28 m", "4958", 1.585), makeIsotope("Se82", 82, "8.82", "0", 0),
        			makeIsotope("Se83", 83, "22.3 m", "1930", 3.669), makeIsotope("Se83m", 83, "70.1 s", "101", 3.669),
        			makeIsotope("Se84", 84, "3.10 m", "268", 1.827) };
	elements[34 - 1] = makeElement("Selenium", 34, "Se", seList);
	//Bromine
	vector<Isotope> brList = { makeIsotope("Br78", 78, "6.46 m", "559", 3.574), makeIsotope("Br78m", 78, "119.2 us", "0.000172", 3.574),
        			makeIsotope("Br79", 79, "50.69", "0", 0), makeIsotope("Br79m", 79, "4.86 s", "7.01", 0),
        			makeIsotope("Br80", 80, "17.68 m", "1530", 3.8746), makeIsotope("Br80m", 80, "4.4205 h", "22959", 0),
        			makeIsotope("Br81", 81, "49.31", "0", 0), makeIsotope("Br82", 82, "35.30 h", "1.833e5", 3.0926),
        			makeIsotope("Br82m", 82, "6.13 m", "531", 3.0926), makeIsotope("Br83", 83, "2.40 h", "1.25e4", 0.973) };
	elements[35 - 1] = makeElement("Bromine", 35, "Br", brList);
	//Krypton
	vector<Isotope> krList = { makeIsotope("Kr77", 77, "74.4 m", "6440", 3.063), makeIsotope("Kr78", 78, "0.35", "0", 0),
        			makeIsotope("Kr79", 79, "35.04 h", "8.744e4", 1.626), makeIsotope("Kr79m", 79, "50 s", "72", 1.626),
        			makeIsotope("Kr80", 80, "2.29", "0", 0), makeIsotope("Kr81", 81, "2.29e5 y", "1.04e13", 0.2807),
        			makeIsotope("Kr81m", 81, "13.10 s", "18.9", 0.2807), makeIsotope("Kr82", 82, "11.59", "0", 0),
           			makeIsotope("Kr83", 83, "11.5", "0", 0), makeIsotope("Kr83m", 83, "1.83 h", "9504", 0),
    				makeIsotope("Kr84", 84, "56.99", "0", 0), makeIsotope("Kr85", 85, "10.756 y", "489699", 0.6871),
        			makeIsotope("Kr85m", 85, "4.480 h", "2.327e4", 0.6871), makeIsotope("Kr86", 86, "17.28", "0", 0),
        			makeIsotope("Kr87", 87, "76.3 m", "3173", 3.885), makeIsotope("Kr88", 88, "2.84 h", "1.48e4", 2.914) };
	elements[36 - 1] = makeElement("Krypton", 36, "Kr", krList);
	//Rubidium
	vector<Isotope> rbList = { makeIsotope("Rb84", 84, "32.77 d", "4.085e6", 3.5749), makeIsotope("Rb84m", 84, "20.26 m", "1754", 0),
        			makeIsotope("Rb85", 85, "72.17", "0", 0), makeIsotope("Rb86", 86, "18.631 d", "2.3223e9", 6.9602),
        			makeIsotope("Rb86m", 86, "1.017 m", "88.03", 0), makeIsotope("Rb87", 87, "27.83", "0", 0),
        			makeIsotope("Rb88", 88, "17.78 m", "1539", 5.313), makeIsotope("Rb89", 89, "15.15 m", "1311", 4.496) };
	elements[37 - 1] = makeElement("Rubidium", 37, "Rb", rbList);
	//Strontium
	vector<Isotope> srList = { makeIsotope("Sr83", 83, "32.41 h", "1.683e5", 2.276), makeIsotope("Sr83m", 83, "4.95 s", "7.14", 2.276),
        			makeIsotope("Sr84", 84, "0.56", "0", 0), makeIsotope("Sr85", 85, "64.84 d", "8.082e6", 1.065),
        			makeIsotope("Sr85m", 85, "67.63 m", "5854", 1.065), makeIsotope("Sr86", 86, "9.86", "0", 0),
        			makeIsotope("Sr87", 87, "7", "0", 0), makeIsotope("Sr87m", 87, "2.803 h", "14558", 0),
        			makeIsotope("Sr88", 88, "82.58", "0", 0), makeIsotope("Sr89", 89, "50.53 d", "6.299e6", 1.4951),
        			makeIsotope("Sr90", 90, "28.79 y", "1.311e9", 0.546) };
	elements[38 - 1] = makeElement("Strontium", 38, "Sr", srList);
	//Yttrium
	vector<Isotope> yList = { makeIsotope("Y88", 88, "106.65 d", "1.3294e7", 3.6226), makeIsotope("Y88m", 88, "13.9 ms", "0.0201", 3.6226),
        			makeIsotope("Y89", 89, "100", "0", 0), makeIsotope("Y89m", 89, "16.06 s", "23.17", 0),
        			makeIsotope("Y90", 90, "64.00 h", "3.3248e5", 2.2801), makeIsotope("Y91", 91, "58.51 d", "7.293e6", 1.5448),
        			makeIsotope("Y91m", 91, "49.71 m", "4303", 0) };
	elements[39 - 1] = makeElement("Yttrium", 39, "Y", yList);
	//Zirconium
	vector<Isotope> zrList = { makeIsotope("Zr89", 89, "78.41 h", "4.072e5", 2.8327), makeIsotope("Zr89m", 89, "4.18 m", "362", 2.8327),
        			makeIsotope("Zr90", 90, "51.45", "0", 0), makeIsotope("Zr90m", 90, "809.2 ms", "1.167", 0),
        			makeIsotope("Zr91", 91, "11.22", "0", 0), makeIsotope("Zr92", 92, "17.15", "0", 0),
        			makeIsotope("Zr93", 93, "1.53e6 y", "6.97e13", 0.0914), makeIsotope("Zr94", 94, "17.38", "0", 0),
        			makeIsotope("Zr95", 95, "64.02 d", "7.980e6", 1.1248), makeIsotope("Zr96", 96, "2.8", "0", 0),
        			makeIsotope("Zr97", 97, "16.91 h", "87826", 2.6581), makeIsotope("Zr98", 98, "30.7 s", "44.3", 2.25) };
	elements[40 - 1] = makeElement("Zirconium", 40, "Zr", zrList);
	//Niobium
	vector<Isotope> nbList = { makeIsotope("Nb92", 92, "3.47e7 y", "1.58e15", 2.3626), makeIsotope("Nb92m", 92, "10.15 d", "1.265e6", 2.0056),
        			makeIsotope("Nb93", 93, "100", "0", 0), makeIsotope("Nb93m", 93, "16.13 y", "7.344e8", 0),
        			makeIsotope("Nb94", 94, "2.03e4 y", "9.24e11", 2.0454), makeIsotope("Nb94m", 94, "6.263 m", "542.1", 2.0454),
        			makeIsotope("Nb95", 95, "34.975 d", "4.3596e6", 0.9256), makeIsotope("Nb95m", 95, "86.6 h", "4.498e5", 0.9256) };
	elements[41 - 1] = makeElement("Niobium", 41, "Nb", nbList);
	//Molybdenum
	vector<Isotope> moList = { makeIsotope("Mo91", 91, "15.49 m", "1341", 4.434), makeIsotope("Mo91m", 91, "65.0 s", "93.8", 4.434),
        			makeIsotope("Mo92", 92, "14.65", "0", 0), makeIsotope("Mo93", 93, "4.00e3 y", "1.82e11", 0.405),
        			makeIsotope("Mo93m", 93, "6.85 h", "3.56e4", 0.405), makeIsotope("Mo94", 94, "9.19", "0", 0),
        			makeIsotope("Mo95", 95, "15.87", "0", 0), makeIsotope("Mo96", 96, "16.67", "0", 0),
        			makeIsotope("Mo97", 97, "9.58", "0", 0), makeIsotope("Mo98", 98, "24.29", "0", 0),
        			makeIsotope("Mo99", 99, "65.94 h", "3.425e5", 1.3572), makeIsotope("Mo100", 100, "9.74", "0", 0),
        			makeIsotope("Mo101", 101, "14.61 m", "1265", 2.824), makeIsotope("Mo102", 102, "11.30 m", "978.1", 1.01) };
	elements[42 - 1] = makeElement("Molybdenum", 42, "Mo", moList);
	//Technetium
	elements[43 - 1] = makeElement("Technetium", 43, "Tc");
	//Ruthenium
	vector<Isotope> ruList = { makeIsotope("Ru95", 95, "1.64 h", "8.518", 2.567), makeIsotope("Ru96", 96, "5.54", "0", 0),
        			makeIsotope("Ru97", 97, "2.83 d", "3.53e5", 1.108), makeIsotope("Ru98", 98, "1.87", "0", 0),
        			makeIsotope("Ru99", 99, "12.76", "0", 0), makeIsotope("Ru100", 100, "12.6", "0", 0),
        			makeIsotope("Ru101", 101, "17.06", "0", 0), makeIsotope("Ru102", 102, "31.55", "0", 0),
        			makeIsotope("Ru103", 103, "39.25 d", "2.351e5", 0.7634), makeIsotope("Ru103m", 103, "1.69 ms", "0.00244", 0.7634),
        			makeIsotope("Ru104", 104, "18.62", "0", 0), makeIsotope("Ru105", 105, "4.44 h", "2.31e4", 1.971),
        			makeIsotope("Ru106", 106, "1.02 y", "4.64e7", 0.0394) };
	elements[44 - 1] = makeElement("Ruthenium", 44, "Ru", ruList);
	//Rhodium
	vector<Isotope> rhList = { makeIsotope("Rh102", 102, "207.30 d", "1.2415e7", 3.474), makeIsotope("Rh102m", 102, "2.9 y", "1.3e8", 2.323),
        			makeIsotope("Rh103", 103, "100", "0", 0), makeIsotope("Rh103m", 103, "56.12 m", "4858", 0),
        			makeIsotope("Rh104", 104, "42.30 s", "61.03", 3.582), makeIsotope("Rh104m", 104, "4.34 m", "376", 2.441),
        			makeIsotope("Rh105", 105, "1.47 d", "1.83e5", 5.667), makeIsotope("Rh105m", 105, "45 s", "65", 5.667) };
	elements[45 - 1] = makeElement("Rhodium", 45, "Rh", rhList);
	//Palladium
	vector<Isotope> pdList = { makeIsotope("Pd101", 101, "8.47 h", "4.399e4", 1.98), makeIsotope("Pd102", 102, "1.02", "0", 0),
        			makeIsotope("Pd103", 103, "16.99 d", "2.118e6", 0.5431), makeIsotope("Pd104", 104, "11.14", "0", 0),
        			makeIsotope("Pd105", 105, "22.33", "0", 0), makeIsotope("Pd106", 106, "27.33", "0", 0),
        			makeIsotope("Pd107", 107, "6.50e6 y", "2.96e13", 0.033), makeIsotope("Pd107m", 107, "21.3 s", "30.7", 0.033),
        			makeIsotope("Pd108", 108, "26.46", "0", 0), makeIsotope("Pd109", 109, "13.70 h", "3.419e4", 1.1159),
        			makeIsotope("Pd109m", 109, "4.696 m", "406.5", 1.1159), makeIsotope("Pd110", 110, "11.72", "0", 0),
           			makeIsotope("Pd111", 111, "23.40 m", "2026", 2.188), makeIsotope("Pd111m", 111, "5.5 h", "2.9e4", 2.188),
        			makeIsotope("Pd112", 112, "21.04 h", "1.093e5", 0.288) };
	elements[46 - 1] = makeElement("Palladium", 46, "Pd", pdList);
	//Silver
	vector<Isotope> agList = { makeIsotope("Ag106", 106, "23.96 m", "2074", 3.159), makeIsotope("Ag106m", 106, "8.28 d", "1.03e6", 2.965),
        			makeIsotope("Ag107", 107, "51.84", "0", 0), makeIsotope("Ag107m", 107, "44.3 s", "63.9", 0),
        			makeIsotope("Ag108", 108, "2.38 m", "206", 3.567), makeIsotope("Ag108m", 108, "418 y", "1.903e10", 1.918),
        			makeIsotope("Ag109", 109, "48.16", "0", 0), makeIsotope("Ag109m", 109, "39.6 s", "57.1", 0),
        			makeIsotope("Ag110", 110, "24.56 s", "35.43", 3.7842), makeIsotope("Ag110m", 110, "249.79 d", "31136", 2.8922),
        			makeIsotope("Ag111", 111, "7.45 d", "9.29e5", 1.0368), makeIsotope("Ag111m", 111, "64.8 s", "93.5", 1.0368) };
	elements[47 - 1] = makeElement("Silver", 47, "Ag", agList);
	//Cadmium
	vector<Isotope> cdList = { makeIsotope("Cd105", 105, "55.50 m", "4804", 2.738), makeIsotope("Cd106", 106, "1.25", "0", 0),
        			makeIsotope("Cd107", 107, "6.50 h", "3.38e4", 1.417), makeIsotope("Cd108", 108, "0.89", "0", 0),
        			makeIsotope("Cd109", 109, "1.26 y", "5.74e7", 0.214), makeIsotope("Cd110", 110, "12.47", "0", 0),
        			makeIsotope("Cd111", 111, "12.79", "0", 0), makeIsotope("Cd111m", 111, "48.54 m", "4202", 0),
        			makeIsotope("Cd112", 112, "24.11", "0", 0), makeIsotope("Cd113", 113, "12.23", "0", 0),
        			makeIsotope("Cd113m", 113, "14.1 y", "6.42e8", 0), makeIsotope("Cd114", 114, "28.75", "0", 0),
        			makeIsotope("Cd115", 115, "2.23 d", "2.78e5", 1.446), makeIsotope("Cd115m", 115, "44.6 d", "5.56e6", 1.446),
        			makeIsotope("Cd116", 116, "7.51", "0", 0), makeIsotope("Cd117", 117, "2.49 h", "1.28e4", 2.517),
        			makeIsotope("Cd117m", 117, "3.36 h", "1.75e4", 2.517), makeIsotope("Cd118", 118, "50.30 m", "4354", 0.521) };
	elements[48 - 1] = makeElement("Cadmium", 48, "Cd", cdList);
	//Indium
	vector<Isotope> inList = { makeIsotope("In112", 112, "14.88 m", "1288", 3.25), makeIsotope("In112m", 112, "20.56 m", "1780", 0),
        			makeIsotope("In113", 113, "4.28", "0", 0), makeIsotope("In113m", 113, "1.6582 h", "8612.2", 0),
        			makeIsotope("In114", 114, "1.20 m", "104", 3.4407), makeIsotope("In114m", 114, "49.51 d", "6.171e6", 1.452),
        			makeIsotope("In114m2", 114, "43.1 ms", "0.0622", 0), makeIsotope("In115", 115, "95.72", "0", 0),
        			makeIsotope("In115m", 115, "4.486 h", "13299", 0), makeIsotope("In116", 116, "14.10 s", "20.34", 3.275),
        			makeIsotope("In116m", 116, "54.29 m", "4699", 0), makeIsotope("In116m2", 116, "2.18 s", "62.5", 0),
        			makeIsotope("In117", 117, "43.20 m", "3739", 1.455), makeIsotope("In117m", 117, "116.2 m", "1.006e4", 1.455) };
	elements[49 - 1] = makeElement("Indium", 49, "In", inList);
	//Tin
	vector<Isotope> snList = { makeIsotope("Sn111", 111, "35.30 m", "3056", 2.445), makeIsotope("Sn112", 112, "0.97", "0", 0),
        			makeIsotope("Sn113", 113, "115.09 d", "1.4346e7", 1.036), makeIsotope("Sn113m", 113, "21.4 m", "1852", 1.036),
        			makeIsotope("Sn114", 114, "0.66", "0", 0), makeIsotope("Sn115", 115, "0.34", "0", 0),
        			makeIsotope("Sn116", 116, "14.54", "0", 0), makeIsotope("Sn117", 117, "7.68", "0", 0),
        			makeIsotope("Sn117m", 117, "13.60 d", "1.695e6", 0), makeIsotope("Sn118", 118, "24.22", "0", 0),
        			makeIsotope("Sn119", 119, "8.59", "0", 0), makeIsotope("Sn119m", 119, "293.1 d", "3.653e7", 0),
        			makeIsotope("Sn120", 120, "32.58", "0", 0), makeIsotope("Sn121", 121, "1.31 d", "1.36e5", 0.3901),
        			makeIsotope("Sn121m", 121, "55 y", "2.5e9", 0.3901), makeIsotope("Sn122", 122, "4.63", "0", 0),
        			makeIsotope("Sn123", 123, "129.20 d", "1.6105e7", 1.403), makeIsotope("Sn123m", 123, "40.06 m", "3468", 1.403),
        			makeIsotope("Sn124", 124, "5.79", "0", 0), makeIsotope("Sn125", 125, "9.64 d", "1.202e6", 2.363),
        			makeIsotope("Sn125m", 125, "9.52 m", "824", 2.363), makeIsotope("Sn126", 126, "2.30e5 y", "1.05e10", 0.378) };
	elements[50 - 1] = makeElement("Tin", 50, "Sn", snList);
	//Antimony
	vector<Isotope> sbList = { makeIsotope("Sb120", 120, "15.89 m", "1375", 2681), makeIsotope("Sb120m", 120, "5.76 d", "7.18e5", 2681),
        			makeIsotope("Sb121", 121, "57.21", "0", 0), makeIsotope("Sb122", 122, "2.72 d", "3.39e5", 3.5985),
        			makeIsotope("Sb122m", 122, "4.191 m", "362.8", 0), makeIsotope("Sb123", 123, "42.79", "0", 0),
        			makeIsotope("Sb124", 124, "60.20 d", "7.504e6", 2.9045), makeIsotope("Sb124m", 124, "93 s", "134", 2.9045),
        			makeIsotope("Sb124m2", 124, "20.2 m", "1749", 0), makeIsotope("Sb125", 125, "2.76 y", "1.25e8", 0.7667) };
	elements[51 - 1] = makeElement("Antimony", 51, "Sb", sbList);
	//Tellurium
	vector<Isotope> teList = { makeIsotope("Te119", 119, "16.05 h", "8.336e4", 2.293), makeIsotope("Te119m", 119, "4.70 d", "5.86e5", 2.293),
        			makeIsotope("Te120", 120, "0.09", "0", 0), makeIsotope("Te121", 121, "19.17 d", "2.39e6", 1.036),
        			makeIsotope("Te121m", 121, "154 d", "1.92e7", 1.036), makeIsotope("Te122", 122, "2.55", "0", 0),
        			makeIsotope("Te123", 123, "0.89", "0", 0), makeIsotope("Te123m", 123, "119.7 d", "1.492e7", 0),
        			makeIsotope("Te124", 124, "4.74", "0", 0), makeIsotope("Te125", 125, "7.07", "0", 0),
        			makeIsotope("Te125m", 125, "57.40 d", "7.155e6", 0), makeIsotope("Te126", 126, "18.84", "0", 0),
        			makeIsotope("Te127", 127, "9.35 h", "4.86e4", 0.698), makeIsotope("Te127m", 127, "109 d", "1.36e7", 0.698),
        			makeIsotope("Te128", 128, "31.74", "0", 0), makeIsotope("Te129", 129, "1.16 h", "6025", 1.498),
        			makeIsotope("Te129m", 129, "33.6 d", "4.19e6", 1.498), makeIsotope("Te130", 130, "34.08", "0", 0),
        			makeIsotope("Te131", 131, "25.00 m", "2164", 2.2335), makeIsotope("Te131m", 131, "30 h", "1.6e5", 2.2335),
        			makeIsotope("Te132", 132, "3.20 d", "3.999e5", 0.493) };
	elements[52 - 1] = makeElement("Tellurium", 52, "Te", teList);
	//Iodine
	vector<Isotope> iList = { makeIsotope("I126", 126, "13.11 d", "1.634e6", 3.413), makeIsotope("I127", 127, 100),
        			makeIsotope("I128", 128, "24.99 m", "2164", 3.371),
        			makeIsotope("I129", 129, "1.57e7 y", "7.15e14", 0.194) };
	elements[53 - 1] = makeElement("Iodine", 53, "I", iList);
	//Xenon
	vector<Isotope> xeList = { makeIsotope("Xe123", 123, "2.08 h", "10.8e4", 2.676), makeIsotope("Xe124", 124, 0.1),
        			makeIsotope("Xe125", 125, "16.90 h", "87773", 1.653), makeIsotope("Xe125m", 125, "57 s", "82", 0),
        			makeIsotope("Xe126", 126, 0.09), makeIsotope("Xe127", 127, "36.34 d", "4.53e6", 0.6624),
        			makeIsotope("Xe127m", 127, "69.2 s", "99.8", 0), makeIsotope("Xe128", 128, 1.91),
        			makeIsotope("Xe129", 129, 26.4), makeIsotope("Xe129m", 129, "8.88 d", "1.11e6", 0),
        			makeIsotope("Xe130", 130, 4.07), makeIsotope("Xe131", 131, 21.23),
        			makeIsotope("Xe131m", 131, "11.84 d", "1.476e6", 0), makeIsotope("Xe132", 132, 26.91),
        			makeIsotope("Xe132m", 132, "8.39 ms", "0.0121", 0), makeIsotope("Xe133", 133, "5.243 d", "6.5358e5", 0.4274),
        			makeIsotope("Xe133m", 133, "2.19 d", "2.73e5", 0), makeIsotope("Xe134", 134, 10.44),
        			makeIsotope("Xe134m", 134, "290 ms", "0.418", 0), makeIsotope("Xe135", 135, "9.14 h", "", 1.151),
        			makeIsotope("Xe135m", 135, "15.29 m", "1324", 0), makeIsotope("Xe136", 136, 8.86),
        			makeIsotope("Xe137", 137, "3.818 m", "330.5", 4.173), makeIsotope("Xe138", 138, "14.08 m", "1219", 2.774) };
	elements[54 - 1] = makeElement("Xenon", 54, "Xe", xeList);
	//Cesium
	vector<Isotope> csList = { makeIsotope("Cs132", 132, "6.479 d", "8.076e5", 3.3985), makeIsotope("Cs133", 133, 100),
        			makeIsotope("Cs134", 134, "2.0648 y", "9.4006e7", 3.2877), makeIsotope("Cs134m", 134, "2.903 h", "3.619e5", 0),
        			makeIsotope("Cs135", 135, "2.30e6 y", "1.05e14", 0.2693), makeIsotope("Cs135m", 135, "53 m", "4588", 0) };
	elements[55 - 1] = makeElement("Cesium", 55, "Cs", csList);
	//Barium
	vector<Isotope> baList = { makeIsotope("Ba129", 129, "2.23 h", "1.16e4", 2.432), makeIsotope("Ba129m", 129, "2.16 h", "1.12e4", 0),
        			makeIsotope("Ba130", 130, 0.11), makeIsotope("Ba130m", 130, "11 ms", "0.016", 0),
        			makeIsotope("Ba131", 131, "11.50 d", "1.433e6", 1.37), makeIsotope("Ba131m", 131, "14.6 m", "1264", 0),
        			makeIsotope("Ba132", 132, 0.1), makeIsotope("Ba133", 133, "10.51 y", "4.785e8", 0.5174),
        			makeIsotope("Ba133m", 133, "38.9 h", "2.02e5", 0), makeIsotope("Ba134", 134, 2.42),
        			makeIsotope("Ba134m", 134, "2.63 us", "3.79e-6", 0), makeIsotope("Ba135", 135, 6.59),
        			makeIsotope("Ba135m", 135, "28.7 h", "1.49e5", 0), makeIsotope("Ba136", 136, 7.85),
        			makeIsotope("Ba136m", 136, "0.3084 s", "0.4449", 0), makeIsotope("Ba137", 137, 11.23),
        			makeIsotope("Ba137m", 137, "2.552 m", "220.9", 0), makeIsotope("Ba138", 138, 71.7),
        			makeIsotope("Ba139", 139, "83.06 h", "4.314e5", 2.317), makeIsotope("Ba140", 140, "12.752 d", "1.5895e6", 1.05) };
	elements[56 - 1] = makeElement("Barium", 56, "Ba", baList);
	//Lanthanum
	vector<Isotope> laList = { makeIsotope("La137", 137, "6.00e4 y", "2.73e12", 0.6), makeIsotope("La138", 138, 0.09),
        			makeIsotope("La139", 139, 99.91), makeIsotope("La140", 140, "1.6781 d", "209173", 3.7619),
        			makeIsotope("La141", 141, "3.92 h", "2.04e4", 2.502) };
	elements[57 - 1] = makeElement("Lanthanum", 57, "La",laList);
	//Cerium
	vector<Isotope> ceList = { makeIsotope("Ce135", 135, "17.70 h", "91928", 2.026), makeIsotope("Ce135m", 135, "20 s", "29", 0),
        			makeIsotope("Ce136", 136, 0.19), makeIsotope("Ce137", 137, "9.00 h", "4.678e4", 1.2221),
        			makeIsotope("La137m", 137, "34.4 h", "1.79e5", 0), makeIsotope("Ce138", 138, 0.25),
           			makeIsotope("La138m", 138, "8.65 ms", "0.0125", 0), makeIsotope("Ce139", 139, "137.64 d", "1.7157e7", 0.278),
        			makeIsotope("La139m", 139, "54.8 s", "79.1", 0), makeIsotope("Ce140", 140, 88.45),
        			makeIsotope("Ce141", 141, "32.501 d", "4.0512e6", 0.5807), makeIsotope("Ce142", 142, 11.11),
        			makeIsotope("Ce143", 143, "33.039 h", "171595", 1.4614), makeIsotope("Ce144", 144, "284.893 d", "3.55116e8", 0.3187) };
	vector<Isotope> prList = { makeIsotope("Pr140", 140, "3.39 m", "293", 3.388), makeIsotope("Pr141", 141, 100),
        			makeIsotope("Pr142", 142, "19.12 h", "99303", 2.9075), makeIsotope("Pr142m", 142, "14.6 m", "1264", 0),
        			makeIsotope("Pr143", 143, "13.57 d", "1.691e6", 0.9339) };
	elements[59 - 1] = makeElement("Praseodymium", 59, "Pr", prList);
	//Neodymium
	vector<Isotope> ndList = { makeIsotope("Nd141", 141, "2.49 h", "1.29e4", 1.823), makeIsotope("Nd141m", 141, "62.0 s", "89.4", 0),
        			makeIsotope("Nd142", 142, 27.15), makeIsotope("Nd143", 143, 12.17), makeIsotope("Nd144", 144, 23.8),
        			makeIsotope("Nd145", 145, 8.29), makeIsotope("Nd146", 146, 17.19), makeIsotope("Nd147", 147, "10.98 d", "1.369e6", 0.896),
        			makeIsotope("Nd148", 148, 5.76), makeIsotope("Nd149", 149, "1.728 h", "8975", 1.691),
        			makeIsotope("Nd150", 150, 5.64), makeIsotope("Nd151", 151, "12.44 m", "1077", 2.442),
        			makeIsotope("Nd152", 152, "11.40 m", "98680", 1.11) };
	elements[60 - 1] = makeElement("Neodymium", 60, "Nd", ndList);
	//Promethium
	elements[61 - 1] = makeElement("Promethium", 61, "Pm");
	//Samarium
	vector<Isotope> smList = { makeIsotope("Sm143", 143, "8.83 m", "764", 3.443), makeIsotope("Sm134m", 143, "66 s", "95", 0),
        			makeIsotope("Sm143m2", 143, "30 ms", "0.043", 0), makeIsotope("Sm144", 144, 3.08),
        			makeIsotope("Sm145", 145, "340.00 d", "4.2381e7", 6.164), makeIsotope("Sm146", 146, "1.03e8 y", "4.69e15", 2.529),
        			makeIsotope("Sm147", 147, 15), makeIsotope("Sm148", 148, 11.25),
        			makeIsotope("Sm149", 149, 13.82), makeIsotope("Sm150", 150, 7.37),
        			makeIsotope("Sm151", 151, "90.0 y", "4.098e6", 0.0767), makeIsotope("Sm152", 152, 26.74),
        			makeIsotope("Sm153", 153, "46.284 h", "240385", 0.8082), makeIsotope("Sm153m", 153, "10.6 ms", "0.0153", 0),
        			makeIsotope("Sm154", 154, 22.74), makeIsotope("Sm155", 155, "22.30 m", "1930", 1.6269),
        			makeIsotope("Sm156", 156, "9.40 h", "4.88e4", 0.722) };
	elements[62 - 1] = makeElement("Samarium", 62, "Sm", smList);
	//Europium
	vector<Isotope> euList = { makeIsotope("Eu150", 150, "36.9 y", "1.68e9", 2.261), makeIsotope("Eu150m", 150, "12.8 h", "6.65e4", 3.232),
        			makeIsotope("Eu151", 151, 47.81), makeIsotope("Eu152", 152, "13.537 y", "6.16e5", 3.6931),
        			makeIsotope("Eu152m", 152, "9.3116 h", "48362", 3.6931), makeIsotope("Eu152m2", 152, "96 m", "8.3e3", 0),
        			makeIsotope("Eu153", 153, 52.19), makeIsotope("Eu154", 154, "8.593 y", "3.912e8", 2.6857),
        			makeIsotope("Eu154m", 154, "46.3 m", "4008", 0), makeIsotope("Eu155", 155, "4.7611 y", "2.1676e12", 0.2521) };
	elements[63 - 1] = makeElement("Europium", 63, "Eu", euList);
	//Gadolinium
	vector<Isotope> gdList = { makeIsotope("Gd151", 151, "124 d", "1.55e8", 3.117), makeIsotope("Gd152", 152, 0.2),
        			makeIsotope("Gd153", 153, "240.40 d", "2.9966e7", 0.4844), makeIsotope("Gd154", 154, 2.18),
        			makeIsotope("Gd155", 155, 12.8), makeIsotope("Gd155m", 155, "31.97 ms", "0.04612", 0),
        			makeIsotope("Gd156", 156, 20.47), makeIsotope("Gd157", 157, 15.65), makeIsotope("Gd158", 158, 24.84),
        			makeIsotope("Gd159", 159, "18.479 h", "95974", 0.9706), makeIsotope("Gd160", 160, 21.86),
        			makeIsotope("Gd161", 161, "3.66 m", "316", 1.9556), makeIsotope("Gd162", 162, "8.40 m", "727", 1.394) };
	elements[64 - 1] = makeElement("Gadolinium", 64, "Gd", gdList);
	//Terbium
	vector<Isotope> tbList = { makeIsotope("Tb158", 158, "180 y", "8.2e9", 2.1567), makeIsotope("Tb158m", 158, "10.70 s", "15.44", 2.1567),
        			makeIsotope("Tn159", 159, 100), makeIsotope("Tb160", 160, "72.30 d", "9012", 1.8353),
        			makeIsotope("Tb161", 161, "6.88 d", "8.58e5", 0.5931) };
	elements[65 - 1] = makeElement("Terbium", 65, "Tb", tbList);
	//Dysprosium
	vector<Isotope> dyList = { makeIsotope("Dy155", 155, "9.90 h", "5.14e4", 2.0945), makeIsotope("Dy156", 156, 0.06),
        			makeIsotope("Dy157", 157, "8.14 h", "4.23e4", 1.341), makeIsotope("Dy157m", 157, "21.6 ms", "0.0312", 0),
        			makeIsotope("Dy158", 158, 0.1), makeIsotope("Dy159", 159, "144.40 d", "1.7999e7", 0.3656),
        			makeIsotope("Dy160", 160, 2.33), makeIsotope("Dy161", 161, 18.89), makeIsotope("Dy162", 162, 25.48),
        			makeIsotope("Dy163", 163, 24.9), makeIsotope("Dy164", 164, 28.26),
        			makeIsotope("Dy165", 165, "2.334 h", "12122", 1.2861), makeIsotope("Dy165m", 165, "1.257 m", "108.8", 0),
        			makeIsotope("Dy166", 166, "81.6 h", "4.24e5", 0.4862) };
	elements[66 - 1] = makeElement("Dysprosium", 66, "Dy", dyList);
	//Holmium
	vector<Isotope> hoList = { makeIsotope("Ho164", 164, "29.00 m", "2510", 0.9868), makeIsotope("Ho164m", 164, "37.5 m", "3246", 0),
        			makeIsotope("Ho165", 165, 100), makeIsotope("Ho166", 166, "26.83 h", "1.393e5", 1.8549),
        			makeIsotope("Ho166m", 166, "1200 y", "5.46e10", 0), makeIsotope("Ho167", 167, "3.10 h", "1.61e4", 1.007) };
	elements[67 - 1] = makeElement("Holmium", 67, "Ho", hoList);
	//Erbium
	vector<Isotope> erList = { makeIsotope("Er161", 161, "3.21 h", "1.67e4", 2.002), makeIsotope("Er162", 162, 0.14),
        			makeIsotope("Er163", 163, "1.25 h", "6492", 1.21), makeIsotope("Er164", 164, 1.6),
        			makeIsotope("Er165", 165, "10.36 h", "53807", 0.376), makeIsotope("Er166", 166, 33.5),
        			makeIsotope("Er167", 167, 22.87), makeIsotope("Er167m", 167, "2.269 s", "3.273", 0),
        			makeIsotope("Er168", 168, 26.98), makeIsotope("Er169", 169, "9.4 d", "1.2e6", 0.3511),
        			makeIsotope("Er170", 170, 14.91), makeIsotope("Er171", 171, "7.516 h", "39035", 1.4905),
        			makeIsotope("Er172", 172, "49.3 h", "2.56e5", 0.891) };
	elements[68 - 1] = makeElement("Erbium", 68, "Er", erList);
	//Thulium
	vector<Isotope> tmList = { makeIsotope("Tm168", 168, "93.10 d", "11605", 1.9361),
        			makeIsotope("Tm169", 169, 100),
        			makeIsotope("Tm170", 170, "128.60 d", "1.603e7", 1.2824),
        			makeIsotope("Tm171", 171, "1.92 y", "8.74e7", 0.0964) };
	elements[69 - 1] = makeElement("Thulium", 69, "Tm", tmList);
	//Ytterbium
	vector<Isotope> ybList = { makeIsotope("Yb167", 167, "17.50 m", "1515", 1.954), makeIsotope("Yb168", 168, 0.12),
        			makeIsotope("Yb169", 169, "32.026 d", "3.992e6", 0.909), makeIsotope("Yb169m", 169, "46 s", "66", 0),
        			makeIsotope("Yb170", 170, 2.98), makeIsotope("Yb171", 171, 14.09),
        			makeIsotope("Yb171m", 171, "5.25 ms", "0.00757", 0), makeIsotope("Yb172", 172, 21.69),
        			makeIsotope("Yb173", 173, 16.1), makeIsotope("Yb174", 174, 32.02),
        			makeIsotope("Yb175", 175, "4.185 d", "5.247e5", 0.47), makeIsotope("Yb175m", 175, "68.2 ms", "0.0984", 0),
        			makeIsotope("Yb176", 176, 12.99), makeIsotope("Yb176m", 176, "11.4 s", "16.5", 0),
        			makeIsotope("Yb177", 177, "1.911 h", "9925", 1.3992), makeIsotope("Yb177m", 177, "6.41 s", "9.25", 0),
        			makeIsotope("Yb178", 178, "74 m", "6.4e3", 0.654) };
	elements[70 - 1] = makeElement("Ytterbium", 70, "Yb", ybList);
	//Lutetium
	vector<Isotope> luList = { makeIsotope("Lu174", 174, "3.31 y", "1.51e8", 1.3743), makeIsotope("Lu174m", 174, "142 d", "1.77e7", 1.3743),
        			makeIsotope("Lu175", 175, 97.4), makeIsotope("Lu176", 176, 2.6),
        			makeIsotope("Lu176m", 176, "3.635 h", "18879", 0), makeIsotope("Lu177", 177, "6.734 d", "8.394e5", 0.4983),
        			makeIsotope("Lu177m", 177, "160.4 d", "1.999e7", 0), makeIsotope("Lu178", 178, "28.40 m", "2458", 2.0992),
        			makeIsotope("Lu178m", 178, "23.1 m", "2000", 0) };
	elements[71 - 1] = makeElement("Lutetium", 71, "Lu", luList);
	//Hafnium
	vector<Isotope> hfList = { makeIsotope("Hf173", 173, "23.60 h", "1.226e5", 1.61), makeIsotope("Hf174", 174, 0.16),
           			makeIsotope("Hf175", 175, "70.00 d", "8.725e6", 0.6847), makeIsotope("Hf176", 176, 5.26),
        			makeIsotope("Hf177", 177, 18.6), makeIsotope("Hf177m", 177, "1.08 s", "1.56", 0),
        			makeIsotope("Hf177m2", 177, "51.4 m", "4449", 0), makeIsotope("Hf178", 178, 27.28),
        			makeIsotope("Hf178m", 178, "4.0 s", "5.8", 0), makeIsotope("Hf178m2", 178, "31 y", "1.4e9", 0),
        			makeIsotope("Hf179", 179, 13.62), makeIsotope("Hf179m", 179, "18.67 s", "26.94", 0),
        			makeIsotope("Hf179m2", 179, "25.05 d", "3.122e6", 0), makeIsotope("Hf180", 180, 35.08),
    				makeIsotope("Hf180m", 180, "5.5 h", "2.9e4", 0), makeIsotope("Hf181", 181, "42.39 d", "5.284e4", 1.027),
        			makeIsotope("Hf182", 182, "9e6 y", "4e14", 0.373), makeIsotope("Hf182m", 182, "61.5 m", "5324", 0) };
	elements[72 - 1] = makeElement("Hafnium", 72, "Hf", hfList);
	//Tantalum
	vector<Isotope> taList = { makeIsotope("Ta179", 179, "1.82 y", "8.29e7", 0.111), makeIsotope("Ta179m", 179, "9.0 ms", "0.013", 0),
        			makeIsotope("Ta179m2", 179, "52 ms", "0.075", 0), makeIsotope("Ta180", 180, 0.01),
        			makeIsotope("Ta180m", 180, ">1.2e15 y", "", 0), makeIsotope("Ta181", 181, 99.99),
        			makeIsotope("Ta182", 182, "114.43 d", "1.4264e7", 1.8135), makeIsotope("Ta182m", 182, "283 ms", "0.408", 0),
        			makeIsotope("Ta182m2", 182, "15.84 m", "1371", 0), makeIsotope("Ta183", 183, "5.10 d", "6.36e5", 1.07) };
	elements[73 - 1] = makeElement("Tantalum", 73, "Ta", taList);
	//Tungsten
	vector<Isotope> wList = { makeIsotope("W179", 179, "37.05 m", "4.328", 1.06), makeIsotope("W179m", 179, "6.40 m", "554", 1.06),
        			makeIsotope("W180", 180, 0.12), makeIsotope("W180m", 180, "5.47 ms", "0.00789", 0),
        			makeIsotope("W181", 181, "121.20 d", "1.5107e7", 0.188), makeIsotope("W182", 182, 26.5),
        			makeIsotope("W183", 183, 14.31), makeIsotope("W183m", 183, ">1.1e17 y", "", 0),
        			makeIsotope("W184", 184, 30.64), makeIsotope("W185", 185, "75.10 d", "1.56e6", 0.433),
        			makeIsotope("W185m", 185, "1.67 m", "145", 0), makeIsotope("W186", 186, 28.43),
        			makeIsotope("W187", 187, "23.72 h", "1.232e5", 1.3112), makeIsotope("W188", 188, "69.4 d", "8.65e6", 0.349) };
	elements[74 - 1] = makeElement("Tungsten", 74, "W", wList);
	//Rhenium
	vector<Isotope> reList = { makeIsotope("Re184", 184, "38.0 d", "4.74e6", 1.483), makeIsotope("Re184m", 184, "169 d", "2.11e7", 1.483),
        			makeIsotope("Re185", 185, 37.4), makeIsotope("Re186", 186, "3.7183 d", "463481", 1.5881),
        			makeIsotope("Re186m", 186, "2.0e5 y", "9.1e12", 0), makeIsotope("Re187", 187, 62.6),
        			makeIsotope("Re188", 188, "17.005 h", "88319", 2.1204), makeIsotope("Re188m", 188, "18.6 m", "1610", 0),
        			makeIsotope("Re189", 189, "24.3 h", "1.26e5", 1.009) };
	elements[75 - 1] = makeElement("Rhenium", 75, "Re", reList);
	//Osmium
	vector<Isotope> osList = { makeIsotope("Os183", 183, "13.00 h", "67518", 2.13), makeIsotope("Os183m", 183, "9.9 h", "5.1e4", 2.13),
        			makeIsotope("Os184", 184, 0.02), makeIsotope("Os185", 185, "93.60 d", "1.167e7", 1.0128),
        			makeIsotope("Os186", 186, 1.59), makeIsotope("Os187", 187, 1.96), makeIsotope("Os188", 188, 13.24),
        			makeIsotope("Os189", 189, 16.15), makeIsotope("Os189m", 189, "5.8 h", "3e4", 0),
        			makeIsotope("Os190", 190, 26.26), makeIsotope("Os190m", 190, "9.9 m", "860", 0),
        			makeIsotope("Os191", 191, "15.40 d", "1.92e6", 0.3137), makeIsotope("Os191m", 191, "13.10 h", "68037", 0),
        			makeIsotope("Os192", 192, 40.78), makeIsotope("Os192m", 192, "5.9 s", "8.1", 0),
        			makeIsotope("Os193", 193, "30.11 h", "1.564e5", 1.1405), makeIsotope("Os194", 194, "6.00 y", "2.73e8", 0.0966) };
	elements[76 - 1] = makeElement("Osmium", 76, "Os", osList);
	//Iridium
	vector<Isotope> irList = { makeIsotope("Ir190", 190, "11.78 d", "1.468e6", 2.62), makeIsotope("Ir190m", 190, "1.2 h", "6.2e3", 0),
        			makeIsotope("Ir190m2", 190, "3.25 h", "1.69e4", 2), makeIsotope("Ir191", 191, 37.3),
        			makeIsotope("Ir191m", 191, "4.94 s", "7.13", 0), makeIsotope("Ir191m2", 191, "5.5 s", "7.93", 0),
        			makeIsotope("Ir192", 192, "73.831 d", "9.2029e6", 2.5059), makeIsotope("Ir192m", 192, "1.45 m", "126", 1.4597),
        			makeIsotope("Ir192m2", 192, "21 y", "9.6e8", 0), makeIsotope("Ir193", 193, 62.7) };
	elements[77 - 1] = makeElement("Iridium", 77, "Ir", irList);
	//Platinum
	vector<Isotope> ptList = { makeIsotope("Pt189", 189, "10.87 h", "56456", 1.971), makeIsotope("Pt190", 190, 0.01),
        			makeIsotope("Pt191", 191, "2.802 d", "3.493e5", 1.019), makeIsotope("Pt192", 192, 0.78),
        			makeIsotope("Pt193", 193, "50.0 y", "2.28e9", 0.0566), makeIsotope("Pt193m", 193, "4.33 d", "5.40e5", 0),
        			makeIsotope("Pt194", 194, 32.86), makeIsotope("Pt195", 195, 33.77),
        			makeIsotope("Pt195m", 195, "4.02 d", "5.01e5", 0), makeIsotope("Pt196", 196, 25.21),
        			makeIsotope("Pt197", 197, "19.8915 h", "103311", 0.7189), makeIsotope("Pt197m", 197, "95.41 m", "8259", 0.7189),
        			makeIsotope("Pt198", 198, 7.36) };
	elements[78 - 1] = makeElement("Platinum", 78, "Pt", ptList);
	//Gold
	vector<Isotope> auList = { makeIsotope("Au196", 196, "6.183 d", "7.707e5", 2.192), makeIsotope("Au196m", 196, "8.1 s", "12", 0),
        			makeIsotope("Au196m2", 196, "9.6 h", "4.8e4", 0), makeIsotope("Au197", 197, 100),
        			makeIsotope("Au197m", 197, "7.73 s", "11.2", 0), makeIsotope("Au198", 198, "2.69517 d", "335950", 1.3725),
        			makeIsotope("Au198m", 198, "2.27 d", "2.83e5", 0), makeIsotope("Au199", 199, "3.139 d", "3.913e5", 0.4523) };
	elements[79 - 1] = makeElement("Gold", 79, "Au", auList);
	//Mercury
	vector<Isotope> hgList = { makeIsotope("Hg195", 195, "9.9 h", "5.1e4", 1.51), makeIsotope("Hg195m", 195, "41.6 h", "2.16e5", 1.51),
        			makeIsotope("Hg196", 196, 0.15), makeIsotope("Hg197", 197, "64.14 h", "3.331e5", 0.6),
        			makeIsotope("Hg197m", 197, "23.8 h", "1.24e5", 0.6), makeIsotope("Hg198", 198, 10.04),
        			makeIsotope("Hg199", 199, 16.94), makeIsotope("Hg199m", 199, "42.6 m", "3688", 0),
        			makeIsotope("Hg200", 200, 23.14), makeIsotope("Hg201", 201, 13.17),
        			makeIsotope("Hg202", 202, 29.74), makeIsotope("Hg203", 203, "46.612 d", "5810132", 0.4918),
        			makeIsotope("Hg204", 204, 6.82), makeIsotope("Hg205", 205, "5.2 m", "450", 1.531),
        			makeIsotope("Hg205m", 205, "1.10 ms", "0.0016", 0), makeIsotope("Hg206", 206, "8.15 m", "705", 1.307) };
	elements[80 - 1] = makeElement("Mercury", 80, "Hg", hgList);
	//Thallium
	vector<Isotope> tlList = { makeIsotope("Tl202", 202, "12.23 d", "1.524e6", 1.365), makeIsotope("Tl202m", 202, "572 us", "0.000396", 0),
        			makeIsotope("Tl203", 203, 29.52), makeIsotope("Tl204", 204, "3.78 y", "1.72e8", 1.11122),
        			makeIsotope("Tl205", 205, 70.48), makeIsotope("Tl206", 206, "4.199 m", "363", 1.5335),
        			makeIsotope("Tl206m", 206, "3.74 m", "324", 0), makeIsotope("Tl207", 207, "4.77 m", "413", 1.423),
        			makeIsotope("Tl207m", 207, "1.33 s", "1.92", 1.423) };
	elements[81 - 1] = makeElement("Thallium", 81, "Tl", tlList);
	//Lead
	vector<Isotope> pbList = { makeIsotope("Pb203", 203, "51.873 h", "269413", 0.975), makeIsotope("Pb203m", 203, "6.3 s", "9.1", 0),
        			makeIsotope("Pb203m2", 203, "0.48 s", "0.69", 0), makeIsotope("Pb204", 204, 1.4),
        			makeIsotope("Pb204m", 204, "67.2 m", "5817", 0), makeIsotope("Pb205", 205, "1.53e7 y", "6.97e14", 0.0511),
        			makeIsotope("Pb205m", 205, "5.54 ms", "0.00799", 0), makeIsotope("Pb206", 206, 24.1),
        			makeIsotope("Pb207", 207, 22.1), makeIsotope("Pb207m", 207, "0.805 s", "1.161", 0),
        			makeIsotope("Pb208", 208, 52.4), makeIsotope("Pb209", 209, "3.253 h", "16895", 0.6442),
        			makeIsotope("Pb210", 210, "22.3 y", "1.02e9", 3.8555) };
	elements[82 - 1] = makeElement("Lead", 82, "Pb", pbList);
	//Bismuth
	vector<Isotope> biList = { makeIsotope("Bi208", 208, "3.68e5 y", "1.68e13", 2.8791), makeIsotope("Bi208m", 208, "2.58 ms", "0.00368", 0),
        			makeIsotope("Bi209", 209, 100), makeIsotope("Bi210", 210, "5.013 d", "6.249e5", 7.9126),
        			makeIsotope("Bi210m", 210, "3.04e6 y", "1.38e14", 5.036), makeIsotope("Bi211", 211, "2.14 m", "185", 7.329) };
	elements[83 - 1] = makeElement("Bismuth", 83, "Bi");
	// Polonium
	elements[84 - 1] = makeElement("Polonium", 84, "Po");
	// Astatine
	elements[85 - 1] = makeElement("Astatine", 85, "At");
	// Radon
	elements[86 - 1] = makeElement("Radon", 86, "Rn");
	// Francium
	elements[87 - 1] = makeElement("Francium", 87, "Fr");
	// Radium
	elements[88 - 1] = makeElement("Radium", 88, "Ra");
	// Actinium
	elements[89 - 1] = makeElement("Actinium", 89, "Ac");		
	//Thorium
	vector<Isotope> thList = { makeIsotope("Th229", 229, "7340 y", "3.34e11", 5.1676), makeIsotope("Th230", 230, 0.02),
        			makeIsotope("Th231", 231, "25.52 h", "1.33e5", 4.6028), makeIsotope("Th232", 232, 99.98),
        			makeIsotope("Th233", 233, "22.3 m", "1930", 1.2451), makeIsotope("Th234", 234, "24.10 d", "3.004e6", 0.273) };
	elements[90 - 1] = makeElement("Thorium", 90, "Th", thList);
	//Protactinium
	vector<Isotope> paList = { makeIsotope("Pa230", 230, "17.40 d", "2.069e6", 7.313), makeIsotope("Pa231", 231, 100),
           			makeIsotope("Pa232", 232, "1.31 d", "1.63e5", 1.832), makeIsotope("Pa233", 233, "26.967 d", "3361406", 0.5701) };
	elements[90] = makeElement("Protactinium", 91, "Pa", paList);
	//Uranium
	vector<Isotope> uList = { makeIsotope("U233", 233, "1.592e5 y", "7.248e12", 4.9086), makeIsotope("U234", 234, 0.01),
        			makeIsotope("U235", 235, 0.72), makeIsotope("U235m", 235, "25 m", "2164", 0),
        			makeIsotope("U236", 236, "2.342e7 y", "1.102e8", 4.572), makeIsotope("U237", 237, "6.75 d", "8.41e5", 0.5186),
        			makeIsotope("U238", 238, 99.27), makeIsotope("U238m", 238, "225 ns", "", 0),
        			makeIsotope("U238m2", 238, ">1 ns", "", 0), makeIsotope("U239", 239, "23.45 m", "2030", 1.2635),
        			makeIsotope("U240", 240, "14.10 h", "73231", 0.388) };
	elements[92 - 1] = makeElement("Uranium", 92, "U", uList);
	// Neptunium
	elements[93 - 1] = makeElement("Neptunium", 93, "Np");
	// Plutonium
	elements[94 - 1] = makeElement("Plutonium", 94, "Pu");
	// Americium
	elements[95 - 1] = makeElement("Americium", 95, "Am");
	// Curium
	elements[96 - 1] = makeElement("Curium", 96, "Cm");
	// Berkelium
	elements[97 - 1] = makeElement("Berkelium", 97, "Bk");
	// Californium
	elements[98 - 1] = makeElement("Californium", 98, "Cf");
	// Einsteinium
	elements[99 - 1] = makeElement("Einsteinium", 99, "Es");
	// Fermium
	elements[100 - 1] = makeElement("Fermium", 100, "Fm");
	// Mendelevium
	elements[101 - 1] = makeElement("Mendelevium", 101, "Md");
	// Nobelium
	elements[102 - 1] = makeElement("Nobelium", 102, "No");
	// Lawrencium
	elements[103 - 1] = makeElement("Lawrencium", 103, "Lr");
	// Rutherfordium
	elements[104 - 1] = makeElement("Rutherfordium", 104, "Rf");
	// Dubnium
	elements[105 - 1] = makeElement("Dubnium", 105, "Db");
	// Seaborgium
	elements[106 - 1] = makeElement("Seaborgium", 106, "Sg");
	// Bohrium
	elements[107 - 1] = makeElement("Bohrium", 107, "Bh");
	// Hassium
	elements[108 - 1] = makeElement("Hassium", 108, "Hs");
	// Meitnerium
	elements[109 - 1] = makeElement("Meitnerium", 109, "Mt");
	// Darmstadtium
	elements[110 - 1] = makeElement("Darmstadtium", 110, "Ds");
	// Roentgenium
	elements[111 - 1] = makeElement("Roentgenium", 111, "Rg");
	// Copernicium
	elements[112 - 1] = makeElement("Copernicium", 112, "Cn");
	// Nihonium
	elements[113 - 1] = makeElement("Nihonium", 113, "Nh");
	// Flerovium
	elements[114 - 1] = makeElement("Flerovium", 114, "Fl");
	// Moscovium
	elements[115 - 1] = makeElement("Moscovium", 115, "Mc");
	// Livermorium
	elements[116 - 1] = makeElement("Livermorium", 116, "Lv");
	// Tennessine
	elements[117 - 1] = makeElement("Tennessine", 117, "Ts");
	// Oganesson
	elements[118 - 1] = makeElement("Oganesson", 118, "Og");
	
	

	
	//continues to ask for user input until 0 is entered at which point, the program returns 0 and exits
	string display = "Enter an atomic number or symbol or press '0' to exit.\n";
	cout << display;
	string input;
	cin >> input;
	Element element;
	int num = 0;
	while(input.compare("0") != 0){
		num = tryInt(input);
		//if the input was a number under 118, access that element of the array (num - 1)
		if(num > 0 && num <= 118)
			element = elements[num - 1];
		else 
			element = search(input, elements); //in every other case, the input must have been invalid, or an atomic symbol so search accordingly
		if(element.atomicNumber > 0) 
			cout << toString(element);
		cout << display;
		cin >> input;
	}
	return 0;
}