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
		double meanLife = 0;
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
	turns the desired double num into a string that is correctly formated
*/
string scientificNotation(double num){
	int counter = 0;
	if(num == 0) return format(20, "0");
	//if the number is greater than 100,000 make a string that displays it as scientific notation (e.g. 1.23e10)
	if(num >= 100000){
		while(num > 10){
			num /= 10;
			counter++;
		}
		return format(20, to_string(num).substr(0,5).append("e").append(to_string(counter)));
	}
	//if the number is less than 0.0001 make a string that displays it as scientific notation (e.g. 1.23e-10)
	else if(num <= 0.001 && num != 0){
		while(num < 0){
			num *= 10;
			counter++;
		}
		return format(20, to_string(num).substr(0,5).append("e-").append(to_string(counter)));
	}
	string toReturn = format(20, to_string(num).substr(0,6));
	if(num >= 10000)
		return toReturn.substr(0, 5);
	return toReturn;
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
			energyFormat = format(20, to_string(isotope.energy).substr(0, 5));
			string halfLife = format(20, isotope.halfLife);
			string meanLife = scientificNotation(isotope.meanLife);
			result = result.append(name).append(massFormat).append(stability).append(halfLife).append(meanLife);
		}
		//If there is an energy, the the object must be unstable so print out the information accordingly
		else if(isotope.abundance == 0) {
			stability = format(20, "unstable");
			massFormat = format(20, to_string(isotope.mass));
			energyFormat = format(20, to_string(isotope.energy).substr(0, 5));
			string halfLife = format(20, isotope.halfLife);
			string meanLife = scientificNotation(isotope.meanLife);
			result = result.append(name).append(massFormat).append(stability).append(halfLife).append(meanLife);
		}
		//In any other case, the the object must be stable so print out the information accordingly
		else {
			stability = format(20, to_string(isotope.abundance).substr(0, 6));
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
								format(20, "Mean-Life (s)")).append("\n\n");		
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
			result = elementDisplay.append(name).append(symbol).append(num).append("\n\n").append("This element does not have any isotopes with valuable information\n");	
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
Isotope makeIsotope(string name, int mass, string halfLife, double meanLife, double energy){
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
	vector<Isotope> hList = {makeIsotope("H1", 1, 99.985), makeIsotope("H2", 2, 0.0125), 
					makeIsotope("H3", 3, "12.33 y", 561400000, 0.018591), makeIsotope("H4", 4, "0", 0, 23.5)};
	elements[0] = makeElement("Hydrogen", 1, "H", hList);
	//Helium
	vector<Isotope> heList = { makeIsotope("He3", 3, 0.000137), makeIsotope("He4", 4, 99.999863), 
					makeIsotope("He5", 5, "< 1.00 ms", 0, 0.6), makeIsotope("He6", 6, "806.7 ms", 1.164, 3.5078)};
	elements[1] = makeElement("Helium", 2, "He", heList);
	//Lithium
	vector<Isotope> liList = {makeIsotope("Li5", 5, "< 1.00 ms", 0, 1.5), makeIsotope("Li6", 6, 7.5), makeIsotope("Li7", 7, 92.5),
    				makeIsotope("Li8", 8, "838 ms", 1.209, 16.0045), makeIsotope("Li9", 9, "178.3 ms", 0.2572, 13.6063)};
	elements[2] = makeElement("Lithium", 3, "Li", liList);
	//Beryllium
	vector<Isotope> beList = {makeIsotope("Be8", 8, "< 1.00 ms", 0, 0.0000068), makeIsotope("Be9", 9, 100), 
					makeIsotope("Be10", 10, "1.51e6 y", 68750000000000, 0.5558),makeIsotope("Be11", 11, "13.81 s", 19.92, 11.506)};
	elements[3] = makeElement("Beryllium", 4, "Be", beList);
	//Boron
	vector<Isotope> bList = {makeIsotope("B9", 9, "< 1.00 ms", 0, 0.00054), makeIsotope("B10", 10, 19.9), makeIsotope("B11", 11, 80.1),
    				makeIsotope("B12", 12, "20.20 ms", 0.02914, 13.3689), makeIsotope("B13", 13, "17.36 ms", 0.025, 13.4372)};
	elements[4] = makeElement("Boron", 5, "B", bList);
	//Carbon
	vector<Isotope> cList = {makeIsotope("C11", 11, "20.39 m", 1765, 1.9825), makeIsotope("C12", 12, 98.9), makeIsotope("C13", 13, 1.1),
    				makeIsotope("C14", 14, "5730 y", 260900000000, 0.156475), makeIsotope("C15", 15, "2.449 s", 3.533, 9.7717)};
	elements[5] = makeElement("Carbon", 6, "C", cList);
	//Nitrogen
	vector<Isotope> nList = {makeIsotope("N13", 13, "9.965 m", 862.6, 2.2204), makeIsotope("N14", 14, 99.634), makeIsotope("N15", 15, 0.366),
    				makeIsotope("N16", 16, "7.13 s", 10.3, 10.42), makeIsotope("N17", 17, "4.173 s", 6.02, 8.68)};
	elements[6] = makeElement("Nitrogen", 7, "N", nList);
	//Oxygen
	vector<Isotope> oList = {makeIsotope("O15", 15, "122.24 s", 176.36, 2.7539), makeIsotope("O16", 16, 99.762), makeIsotope("O17", 17, 0.038),
    				makeIsotope("O18", 18, 0.2), makeIsotope("O19", 19, "26.91 s", 38.83, 4.821), makeIsotope("O20", 20, "13.51 s", 19.49, 3.8143)};
	elements[7] = makeElement("Oxygen", 8, "O", oList);
	//Flourine
	vector<Isotope> fList = {makeIsotope("F18", 18, "109.77 m", 9501.9, 1.6555), makeIsotope("F19", 19, 100), makeIsotope("F20", 20, "11.00 s", 15.87, 7.02453),
    				makeIsotope("F21", 21, "4.23 s", 6.103, 5.6841)};
	elements[8] = makeElement("Flourine", 9, "F", fList);
	//Neon
	vector<Isotope> neList = {makeIsotope("Ne19", 19, "17.22 s", 24.84, 3.2385), makeIsotope("Ne20", 20, 90.48), makeIsotope("Ne21", 21, 0.27),
    				makeIsotope("Ne22", 22, 9.25), makeIsotope("Ne23", 23, "37.24 s", 53.73, 4.37584), makeIsotope("Ne24", 24, "3.38 m", 293, 2.47)};
	elements[9] = makeElement("Neon", 10, "Ne", neList);
	//Sodium
	vector<Isotope> naList = {makeIsotope("Na22", 22, "2.6019 y", 118460000, 2.8422), makeIsotope("Na23", 23, 100), 
					makeIsotope("Na24", 24, "14.9590 h", 77692.6, 5.51578), makeIsotope("Na24m", 24, "20.20 ms", 0.02914, 5.51578), 
					makeIsotope("Na25", 25, "59.10 s", 85.26, 3.8353)};
	elements[10] = makeElement("Sodium", 11, "Na", naList);
	//Magnesium
	vector<Isotope> mgList = {makeIsotope("Mg23", 23, "11.317 s", 16.327, 4.0568), makeIsotope("Mg24", 24, 78.99), makeIsotope("Mg25", 25, 10),
    				makeIsotope("Mg26", 26, 11.01), makeIsotope("Mg27", 27, "9.458 m", 818.7, 2.61033), makeIsotope("Mg28", 28, "20.91 h", 108600, 1.8318)};
	elements[11] = makeElement("Magnesium", 12, "Mg",mgList);
	//Aluminum
	vector<Isotope> alList = {makeIsotope("Al26", 26, "7.17e5 y", 32600000000000, 4.00414), makeIsotope("Al26m", 26, "6.3452 s", 9.1542, 4.00414),
    				makeIsotope("Al27", 27, 100), makeIsotope("Al28", 28, "2.2414 m", 194.02, 4.64224), makeIsotope("Al29", 29, "6.56 m", 568, 3.6795)};
	elements[12] = makeElement("Aluminum", 13, "Al", alList);
	//Silicon
	vector<Isotope> siList = {makeIsotope("Si27", 27, "4.16 s", 6.002, 4.8124), makeIsotope("Si28", 28, 92.23), makeIsotope("Si29", 29, 4.67),
    				makeIsotope("Si30", 30, 3.1), makeIsotope("Si31", 31, "157.3 m", 13590, 1.49203), makeIsotope("Si32", 32, "150 y", 6830000000, 0.2245)};
	elements[13] = makeElement("Silicon", 14, "Si",siList);
	//Phosphorus
	vector<Isotope> pList = { makeIsotope("P30", 30, "2.498 m", 216.2, 4232.3), makeIsotope("P31", 31, 100),
	        		makeIsotope("P32", 32, "14.262 d", 1777700, 1.71066), makeIsotope("P33", 33, "25.34 d", 3159000, 0.2485) };
	elements[14] = makeElement("Phosphorus", 15, "P",pList);
	//Sulfur
	vector<Isotope> sList = { makeIsotope("S31", 31, "2.572 s", 3.711, 5.3961), makeIsotope("S32", 32, 95.02), 
					makeIsotope("S33", 33, 0.75), makeIsotope("S34", 34, 4.21),
        			makeIsotope("S35", 35, "87.32 d", 10880000, 0.16714), makeIsotope("S36", 36, 0.02),
					makeIsotope("S37", 37, "5.05 m", 437, 4.8653), makeIsotope("S38", 38, "170.3 m", 14740, 2.937) };
	elements[15] = makeElement("Sulfur", 16, "S",sList);
	//Chlorine
	vector<Isotope> clList = { makeIsotope("Cl34", 34, "1.5264 s", 2.2021, 5.49128), makeIsotope("Cl34m", 34, "32.00 m", 2770, 5.49128),
        			makeIsotope("Cl35", 35, 75.77), makeIsotope("Cl36", 36, "3.01e5 y", 13704000000000, 1.85067),
        			makeIsotope("Cl37", 37, 24.23), makeIsotope("Cl38", 38, "37.24 m", 3224, 4.9168),
        			makeIsotope("Cl38m", 38, "715 ms", 1.03, 0), makeIsotope("Cl39", 39, "55.6 m", 4813, 3.441) };
	elements[17 - 1] = makeElement("Chlorine", 17, "Cl", clList);
	//Argon
	vector<Isotope> arList = { makeIsotope("Ar35", 35, "1.775 s", 2.561, 5.9653), makeIsotope("Ar36", 36, 0.337),
        			makeIsotope("Ar37", 37, "35.04 d", 4368000, 0.8135), makeIsotope("Ar38", 38, 0.063),
         			makeIsotope("Ar39", 39, "269 y", 12250000000, 0.565), makeIsotope("Ar40", 40, 99.6),
        			makeIsotope("Ar41", 41, "109.34 m", 9465, 2.4916), makeIsotope("Ar42", 42, "32.9 y", 1498000000, 0.599) };
	elements[18 - 1] = makeElement("Argon", 18, "Ar", arList);
	//Potassium
	vector<Isotope> kList = { makeIsotope("K38", 38, "7.636 m", 661, 5.9131), makeIsotope("K38m", 38, "923.9 ms", 1.333, 5.9131),
        			makeIsotope("K39", 39, 93.2581), makeIsotope("K40", 40, 0.0117),
        			makeIsotope("K41", 41, 6.7302), makeIsotope("K42", 42, "12.360 h", 64194, 3.5254),
        			makeIsotope("K43", 43, "22.3 h", 115800, 1.815) };
	elements[19 - 1] = makeElement("Potassium", 19, "K", kList);
	//Calcium
	vector<Isotope> caList = { makeIsotope("Ca39", 39, "859.6 ms", 1.24, 6.5306), makeIsotope("Ca40", 40, 96.941),
        			makeIsotope("Ca41", 41, "1.03e5 y", 4690000000000, 0.4214), makeIsotope("Ca42", 42, 0.647),
        			makeIsotope("Ca43", 43, 0.135), makeIsotope("Ca44", 44, 2.086),
        			makeIsotope("Ca45", 45, "162.61 d", 20269000, 0.2568), makeIsotope("Ca46", 46, 0.004),
        			makeIsotope("Ca47", 47, "4.536 d", 565400, 1.9919), makeIsotope("Ca48", 48, 0.187),
        			makeIsotope("Ca49", 49, "8.718 m", 754.6, 0.5262), makeIsotope("Ca50", 50, "13.9 s", 20.1, 4.966) };
	elements[20 - 1] = makeElement("Calcium", 20, "Ca", caList);
	//Scandium
	vector<Isotope> scList = { makeIsotope("Sc44", 44, "3.927 h", 20396, 3.6533), makeIsotope("Sc44m", 44, "58.6 h", 302800, 3.6533),
        			makeIsotope("Sc45", 45, 100), makeIsotope("Sc45m", 45, "318 ms", 0.459, 0),
        			makeIsotope("Sc46", 46, "83.79 d", 10440000, 2.3667), makeIsotope("Sc46m", 46, "18.75 s", 27.05, 2.3667),
        			makeIsotope("Sc47", 47, "3.3492 d", 417474, 0.6001) };
	elements[21 - 1] = makeElement("Scandium", 21, "Sc", scList);
	//Titanium
	vector<Isotope> tiList = { makeIsotope("Ti45", 45, "184.8 m", 15997, 2.0624), makeIsotope("Ti46", 46, 8),
        			makeIsotope("Ti47", 47, 7.3), makeIsotope("Ti48", 48, 73.8),
        			makeIsotope("Ti49", 49, 5.5), makeIsotope("Ti50", 50, 5.4),
        			makeIsotope("Ti51", 51, "5.76 m", 499, 2.4706), makeIsotope("Ti52", 52, "1.7 m", 147, 1.937) };
	elements[22 - 1] = makeElement("Titanium", 22, "Ti", tiList);
	//Vanadium
	vector<Isotope> vList = { makeIsotope("V49", 49, "330 d", 41100000, 0.6019), makeIsotope("V50", 50, 0.25),
        			makeIsotope("V51", 51, 99.75), makeIsotope("V52", 52, "3.743 m", 324, 3.9754),
        			makeIsotope("V53", 53, "1.61 m", 139, 3.436) };
	elements[23 - 1] = makeElement("Vanadium", 23, "V", vList);
	//Chromium
	vector<Isotope> crList = { makeIsotope("Cr49", 49, "42.3 m", 3662, 2.631), makeIsotope("Cr50", 50, 4.345),
        			makeIsotope("Cr51", 51, "27.7025 d", 3453085, 0.75273), makeIsotope("Cr52", 52, 83.789),
        			makeIsotope("Cr53", 53, 9.501), makeIsotope("Cr54", 54, 2.365),
        			makeIsotope("Cr55", 55, "3.497 m", 302.7, 2.6031), makeIsotope("Cr56", 56, "5.94 m", 514, 1.617) };
	elements[24 - 1] = makeElement("Chromium", 24, "Cr", crList);
	//Manganese
	vector<Isotope> mnList = { makeIsotope("Mn54", 54, "312.3 d", 38930000, 2.0742), makeIsotope("Mn55", 55, 100),
        			makeIsotope("Mn56", 56, "2.5785 h", 13392, 3.695), makeIsotope("Mn57", 57, "85.4 s", 123, 2.691) };
	elements[25 - 1] = makeElement("Manganese", 25, "Mn", mnList);
	//Iron
	vector<Isotope> feList = { makeIsotope("Fe53", 53, "8.51 m", 737, 3.7424), makeIsotope("Fe53m", 53, "2.58 m", 223, 3.7424),
        			makeIsotope("Fe54", 54, 5.8), makeIsotope("Fe55", 55, "2.73 y", 124000000, 0.23138),
        			makeIsotope("Fe56", 56, 91.72), makeIsotope("Fe57", 57, 2.2),
        			makeIsotope("Fe58", 58, 0.28), makeIsotope("Fe59", 59, "44.503 d", 5547248, 1.5652),
        			makeIsotope("Fe60", 60, "1.5e6 y", 68000000000000, 0.237) };
	elements[26 - 1] = makeElement("Iron", 26, "Fe", feList);
	//Cobalt
	vector<Isotope> coList = { makeIsotope("Co58", 58, "70.86 d", 8833000, 2.3074), makeIsotope("Co58m", 58, "9.04 h", 46951, 2.3074),
        			makeIsotope("Co59", 59, 100), makeIsotope("Co60", 60, "5.2714 y", 239996000, 2.8329),
        			makeIsotope("Co60m", 60, "10.467 m", 906.04, 2.8329), makeIsotope("Co61", 61, "1.650 h", 8570, 1.3217) };
	elements[27 - 1] = makeElement("Cobalt", 27, "Co", coList);
	//Nickel
	vector<Isotope> niList = { makeIsotope("Ni57", 57, "35.60 h", 184896, 3.264), makeIsotope("Ni58", 58, 68.077),
        			makeIsotope("Ni59", 59, "7.6e4 y", 3500000000000, 1.0725), makeIsotope("Ni60", 60, 26.223),
        			makeIsotope("Ni61", 61, 1.14), makeIsotope("Ni62", 62, 3.634),
        			makeIsotope("Ni63", 63, "100.1 y", 4557000000, 0.066945), makeIsotope("Ni64", 64, 0.926),
        			makeIsotope("Ni65", 65, "2.5172 h", 13074, 2.1371), makeIsotope("Ni66", 66, "54.6 h", 284000, 0.226) };
	elements[28 - 1] = makeElement("Nickel", 28, "Ni", niList);
	//Copper
	vector<Isotope> cuList = { makeIsotope("Cu62", 62, "9.74 m", 843, 3.948), makeIsotope("Cu63", 63, 69.17),
        			makeIsotope("Cu64", 64, "12.700 h", 65960, 2.2538), makeIsotope("Cu65", 65, 30.83),
        			makeIsotope("Cu66", 66, "5.120 m", 443.2, 2.642), makeIsotope("Cu67", 67, "61.83 h", 321127, 0.577) };
	elements[29 - 1] = makeElement("Copper", 29, "Cu", cuList);
	//Zinc
	vector<Isotope> znList = { makeIsotope("Zn63", 63, "38.47 m", 3330, 3.3669), makeIsotope("Zn64", 64, 48.6),
        			makeIsotope("Zn65", 65, "244.26 d", 30447000, 1.3519), makeIsotope("Zn66", 66, 27.9),
        			makeIsotope("Zn67", 67, 4.1), makeIsotope("Zn68", 68, 18.8),
        			makeIsotope("Zn69", 69, "56.4 m", 4882, 0.906), makeIsotope("Zn69m", 69, "13.76 h", 71465, 0.906),
        			makeIsotope("Zn70", 70, 0.6), makeIsotope("Zn71", 71, "2.45 m", 212, 2.815),
        			makeIsotope("Zn71m", 71, "3.96 h", 20567, 2.815), makeIsotope("Zn72", 72, "1.94 d", 242000, 0.458) };
	elements[30 - 1] = makeElement("Zinc", 30, "Zn", znList);
	//Gallium
	vector<Isotope> gaList = { makeIsotope("Ga68", 68, "67.629 m", 5854.1, 2.9211), makeIsotope("Ga69", 69, 60.108),
        			makeIsotope("Ga70", 70, "21.14 m", 1830, 2.3107), makeIsotope("Ga71", 71, 39.892),
        			makeIsotope("Ga72", 72, "14.10 h", 73231, 3.9991), makeIsotope("Ga72m", 72, "39.68 ms", 0.05725, 3.9991),
        			makeIsotope("Ga73", 73, "4.86 h", 25241, 1.593) };
	elements[31 - 1] = makeElement("Gallium", 31, "Ga", gaList);
	//Germanium
	vector<Isotope> geList = { makeIsotope("Ge69", 69, "39.05 h", 203000, 2.2273), makeIsotope("Ge70", 70, 21.23),
        			makeIsotope("Ge71", 71, "11.43 d", 1425000, 0.2319), makeIsotope("Ge71m", 71, "20.40 ms", 0.02943, 0.2319),
        			makeIsotope("Ge72", 72, 27.66), makeIsotope("Ge73", 73, 7.73),
        			makeIsotope("Ge73m", 73, "0.499 s", 0.72, 0), makeIsotope("Ge74", 74, 35.94),
        			makeIsotope("Ge75", 75, "82.78 m", 7166, 1.7156), makeIsotope("Ge75m", 75, "47.7 s", 68.8, 1.7156),
        			makeIsotope("Ge76", 76, 7.44), makeIsotope("Ge77", 77, "11.30 h", 58689, 2.702),
        			makeIsotope("Ge77m", 77, "52.9 s", 76.3, 2.702), makeIsotope("Ge78", 78, "88.0 m", 7617, 0.954) };
	elements[32 - 1] = makeElement("Germanium", 32, "Ge", geList);
	//Arsenic
	vector<Isotope> asList = { makeIsotope("As74", 74, "17.77 d", 2215000, 3.9154), makeIsotope("As75", 75, 100),
        			makeIsotope("As75m", 75, "16.79 ms", 0.02422, 0), makeIsotope("As76", 76, "1.0778 d", 134347, 2.962),
        			makeIsotope("As77", 77, "38.83 h", 201671, 0.6829) };
	elements[33 - 1] = makeElement("Arsenic", 33, "As", asList);
	//Selenium
	vector<Isotope> seList = { makeIsotope("Se73", 73, "7.15 h", 37100, 2.74), makeIsotope("Se73m", 73, "39.8 m", 3445, 2.74),
        			makeIsotope("Se74", 74, 0.89), makeIsotope("Se75", 75, "119.779 d", 14930300, 0.8636),
        			makeIsotope("Se76", 76, 9.36), makeIsotope("Se77", 77, 7.63),
        			makeIsotope("Se77m", 77, "17.36 s", 25.05, 0), makeIsotope("Se78", 78, 23.78),
        			makeIsotope("Se79", 79, "1.13e6 y", 51400000000000, 0.151), makeIsotope("Se79m", 79, "3.92 m", 339, 0.151),
        			makeIsotope("Se80", 80, 49.61), makeIsotope("Se81", 81, "18.45 m", 1597, 1.585),
        			makeIsotope("Se81m", 81, "57.28 m", 4958, 1.585), makeIsotope("Se82", 82, 8.73),
        			makeIsotope("Se83", 83, "22.3 m", 1930, 3.669), makeIsotope("Se83m", 83, "70.1 s", 101, 3.669),
        			makeIsotope("Se84", 84, "3.10 m", 268, 1.827) };
	elements[34 - 1] = makeElement("Selenium", 34, "Se", seList);
	//Bromine
	vector<Isotope> brList = { makeIsotope("Br78", 78, "6.46 m", 559, 3.574), makeIsotope("Br78m", 78, "119.2 us", 0.000172, 3.574),
        			makeIsotope("Br79", 79, 50.69), makeIsotope("Br79m", 79, "4.86 s", 7.01, 0),
        			makeIsotope("Br80", 80, "17.68 m", 1530, 3.8746), makeIsotope("Br80m", 80, "4.4205 h", 22959, 0),
        			makeIsotope("Br81", 81, 49.31), makeIsotope("Br82", 82, "35.30 h", 183300, 3.0926),
        			makeIsotope("Br82m", 82, "6.13 m", 531, 3.0926), makeIsotope("Br83", 83, "2.40 h", 12500, 0.973) };
	elements[35 - 1] = makeElement("Bromine", 35, "Br", brList);
	//Krypton
	vector<Isotope> krList = { makeIsotope("Kr77", 77, "74.4 m", 6440, 3.063), makeIsotope("Kr78", 78, 0.35),
        			makeIsotope("Kr79", 79, "35.04 h", 181990, 1.626), makeIsotope("Kr79m", 79, "50 s", 72, 1.626),
        			makeIsotope("Kr80", 80, 2.25), makeIsotope("Kr81", 81, "2.29e5 y", 10400000000000, 0.2807),
        			makeIsotope("Kr81m", 81, "13.10 s", 18.9, 0.2807), makeIsotope("Kr82", 82, 11.6),
           			makeIsotope("Kr83", 83, 11.5), makeIsotope("Kr83m", 83, "1.83 h", 9504, 0),
    				makeIsotope("Kr84", 84, 57), makeIsotope("Kr85", 85, "10.756 y", 489699000, 0.6871),
        			makeIsotope("Kr85m", 85, "4.480 h", 23268, 0.6871), makeIsotope("Kr86", 86, 17.3),
        			makeIsotope("Kr87", 87, "76.3 m", 6605, 3.885), makeIsotope("Kr88", 88, "2.84 h", 14750, 2.914) };
	elements[36 - 1] = makeElement("Krypton", 36, "Kr", krList);
	//Rubidium
	vector<Isotope> rbList = { makeIsotope("Rb84", 84, "32.77 d", 4085000, 3.5749), makeIsotope("Rb84m", 84, "20.26 m", 1754, 0),
        			makeIsotope("Rb85", 85, 72.165), makeIsotope("Rb86", 86, "18.631 d", 2322333, 6.9602),
        			makeIsotope("Rb86m", 86, "1.017 m", 88.03, 0), makeIsotope("Rb87", 87, 27.835),
        			makeIsotope("Rb88", 88, "17.78 m", 1539, 5.313), makeIsotope("Rb89", 89, "15.15 m", 1311, 4.496) };
	elements[37 - 1] = makeElement("Rubidium", 37, "Rb", rbList);
	//Strontium
	vector<Isotope> srList = { makeIsotope("Sr83", 83, "32.41 h", 168300, 2.276), makeIsotope("Sr83m", 83, "4.95 s", 7.14, 2.276),
        			makeIsotope("Sr84", 84, 0.56), makeIsotope("Sr85", 85, "64.84 d", 8082000, 1.065),
        			makeIsotope("Sr85m", 85, "67.63 m", 5854, 1.065), makeIsotope("Sr86", 86, 9.86),
        			makeIsotope("Sr87", 87, 7), makeIsotope("Sr87m", 87, "2.803 h", 14558, 0),
        			makeIsotope("Sr88", 88, 82.58), makeIsotope("Sr89", 89, "50.53 d", 6299000, 1.4951),
        			makeIsotope("Sr90", 90, "28.79 y", 1311000000, 0.546) };
	elements[38 - 1] = makeElement("Strontium", 38, "Sr", srList);
	//Yttrium
	vector<Isotope> yList = { makeIsotope("Y88", 88, "106.65 d", 13294, 3.6226), makeIsotope("Y88m", 88, "13.9 ms", 0.0201, 3.6226),
        			makeIsotope("Y89", 89, 100), makeIsotope("Y89m", 89, "16.06 s", 23.17, 0),
        			makeIsotope("Y90", 90, "64.00 h", 332400, 2.2801), makeIsotope("Y90m", 90, "3.19 h", 16600, 0),
					makeIsotope("Y91", 91, "58.51 d", 7293000, 1.5448), makeIsotope("Y91m", 91, "49.71 m", 4303, 0) };
	elements[39 - 1] = makeElement("Yttrium", 39, "Y", yList);
	//Zirconium
	vector<Isotope> zrList = { makeIsotope("Zr89", 89, "78.41 h", 407200, 2.8327), makeIsotope("Zr89m", 89, "4.18 m", 362, 2.8327),
        			makeIsotope("Zr90", 90, 51.45), makeIsotope("Zr90m", 90, "809.2 ms", 1.167, 0),
        			makeIsotope("Zr91", 91, 11.22), makeIsotope("Zr92", 92, 17.15),
        			makeIsotope("Zr93", 93, "1.53e6 y", 69657000000000, 0.0914), makeIsotope("Zr94", 94, 17.38),
        			makeIsotope("Zr95", 95, "64.02 d", 7980000, 1.1248), makeIsotope("Zr96", 96, 2.8),
        			makeIsotope("Zr97", 97, "16.91 h", 87826, 2.6581), makeIsotope("Zr98", 98, "30.7 s", 44.3, 2.25) };
	elements[40 - 1] = makeElement("Zirconium", 40, "Zr", zrList);
	//Niobium
	vector<Isotope> nbList = { makeIsotope("Nb92", 92, "3.47e7 y", 1580000000000000, 2.3626), makeIsotope("Nb92m", 92, "10.15 d", 1265000, 2.0056),
        			makeIsotope("Nb93", 93, 100), makeIsotope("Nb93m", 93, "16.13 y", 734400000, 0),
        			makeIsotope("Nb94", 94, "2.03e4 y", 924000000000, 2.0454), makeIsotope("Nb94m", 94, "6.263 m", 542.1, 2.0454),
        			makeIsotope("Nb95", 95, "34.975 d", 4359600, 0.9256), makeIsotope("Nb95m", 95, "86.6 h", 449800, 0.9256) };
	elements[41 - 1] = makeElement("Niobium", 41, "Nb", nbList);
	//Molybdenum
	vector<Isotope> moList = { makeIsotope("Mo91", 91, "15.49 m", 1341, 4.434), makeIsotope("Mo91m", 91, "65.0 s", 93.8, 4.434),
        			makeIsotope("Mo92", 92, 14.84), makeIsotope("Mo93", 93, "4.00e3 y", 182000000000, 0.405),
        			makeIsotope("Mo93m", 93, "6.85 h", 35600, 0.405), makeIsotope("Mo94", 94, 9.25),
        			makeIsotope("Mo95", 95, 15.92), makeIsotope("Mo96", 96, 16.68),
        			makeIsotope("Mo97", 97, 9.55), makeIsotope("Mo98", 98, 24.13),
        			makeIsotope("Mo99", 99, "65.94 h", 342500, 1.3572), makeIsotope("Mo100", 100, 9.63),
        			makeIsotope("Mo101", 101, "14.61 m", 1265, 2.824), makeIsotope("Mo102", 102, "11.30 m", 978.1, 1.01) };
	elements[42 - 1] = makeElement("Molybdenum", 42, "Mo", moList);
	//Technetium
	elements[43 - 1] = makeElement("Technetium", 43, "Tc");
	//Ruthenium
	vector<Isotope> ruList = { makeIsotope("Ru95", 95, "1.64 h", 8518, 2.567), makeIsotope("Ru96", 96, 5.52),
        			makeIsotope("Ru97", 97, "2.83 d", 353000, 1.108), makeIsotope("Ru98", 98, 1.88),
        			makeIsotope("Ru99", 99, 12.7), makeIsotope("Ru100", 100, 12.6),
        			makeIsotope("Ru101", 101, 17), makeIsotope("Ru102", 102, 31.6),
        			makeIsotope("Ru103", 103, "39.25 d", 4892000, 0.7634), makeIsotope("Ru103m", 103, "1.69 ms", 0.00244, 0.7634),
        			makeIsotope("Ru104", 104, 18.7), makeIsotope("Ru105", 105, "4.44 h", 23100, 1.971),
        			makeIsotope("Ru106", 106, "1.02 y", 46400000, 0.0394) };
	elements[44 - 1] = makeElement("Ruthenium", 44, "Ru", ruList);
	//Rhodium
	vector<Isotope> rhList = { makeIsotope("Rh102", 102, "207 d", 25800000, 3.474), makeIsotope("Rh102m", 102, "2.9 y", 132000000, 2.323),
        			makeIsotope("Rh103", 103, 100), makeIsotope("Rh103m", 103, "56.12 m", 4858, 0),
        			makeIsotope("Rh104", 104, "42.30 s", 61.03, 3.582), makeIsotope("Rh104m", 104, "4.34 m", 376, 2.441),
        			makeIsotope("Rh105", 105, "35.36 h", 183600, 5.667), makeIsotope("Rh105m", 105, "45 s", 65, 5.667) };
	elements[45 - 1] = makeElement("Rhodium", 45, "Rh", rhList);
	//Palladium
	vector<Isotope> pdList = { makeIsotope("Pd101", 101, "8.47 h", 43990, 1.98), makeIsotope("Pd102", 102, 1.02),
        			makeIsotope("Pd103", 103, "16.991 d", 2117900, 0.5431), makeIsotope("Pd104", 104, 11.14),
        			makeIsotope("Pd105", 105, 22.33), makeIsotope("Pd106", 106, 27.33),
        			makeIsotope("Pd107", 107, "6.50e6 y", 296000000000000, 0.033), makeIsotope("Pd107m", 107, "21.3 s", 30.7, 0.033),
        			makeIsotope("Pd108", 108, 26.46), makeIsotope("Pd109", 109, "13.7012 h", 71160, 1.1159),
        			makeIsotope("Pd109m", 109, "4.696 m", 406.5, 1.1159), makeIsotope("Pd110", 110, 11.72),
           			makeIsotope("Pd111", 111, "23.40 m", 2026, 2.188), makeIsotope("Pd111m", 111, "5.5 h", 28600, 2.188),
        			makeIsotope("Pd112", 112, "21.04 h", 109300, 0.288) };
	elements[46 - 1] = makeElement("Palladium", 46, "Pd", pdList);
	//Silver
	vector<Isotope> agList = { makeIsotope("Ag106", 106, "23.96 m", 2074, 3.159), makeIsotope("Ag106m", 106, "8.28 d", 1030000, 2.965),
        			makeIsotope("Ag107", 107, 51.839), makeIsotope("Ag107m", 107, "44.3 s", 63.9, 0),
        			makeIsotope("Ag108", 108, "2.38 m", 205, 3.567), makeIsotope("Ag108m", 108, "418 y", 19030000000, 1.918),
        			makeIsotope("Ag109", 109, 48.161), makeIsotope("Ag109m", 109, "39.6 s", 57.1, 0),
        			makeIsotope("Ag110", 110, "24.56 s", 35.43, 3.7842), makeIsotope("Ag110m", 110, "249.79 d", 31136000, 2.8922),
        			makeIsotope("Ag111", 111, "7.45 d", 929000, 1.0368), makeIsotope("Ag111m", 111, "64.8 s", 93.5, 1.0368) };
	elements[47 - 1] = makeElement("Silver", 47, "Ag", agList);
	//Cadmium
	vector<Isotope> cdList = { makeIsotope("Cd105", 105, "55.50 m", 4804, 2.738), makeIsotope("Cd106", 106, 1.25),
        			makeIsotope("Cd107", 107, "6.50 h", 33800, 1.417), makeIsotope("Cd108", 108, 0.89),
        			makeIsotope("Cd109", 109, "1.26 y", 57400000, 0.214), makeIsotope("Cd110", 110, 12.49),
        			makeIsotope("Cd111", 111, 12.8), makeIsotope("Cd111m", 111, "48.54 m", 4202, 0),
        			makeIsotope("Cd112", 112, 24.13), makeIsotope("Cd113", 113, 12.22),
        			makeIsotope("Cd113m", 113, "14.1 y", 642000000, 0), makeIsotope("Cd114", 114, 28.73),
        			makeIsotope("Cd115", 115, "2.23 d", 278000, 1.446), makeIsotope("Cd115m", 115, "44.6 d", 5560000, 1.446),
        			makeIsotope("Cd116", 116, 7.49), makeIsotope("Cd117", 117, "2.49 h", 12900, 2.517),
        			makeIsotope("Cd117m", 117, "3.36 h", 17500, 2.517), makeIsotope("Cd118", 118, "50.30 m", 4354, 0.521) };
	elements[48 - 1] = makeElement("Cadmium", 48, "Cd", cdList);
	//Indium
	vector<Isotope> inList = { makeIsotope("In112", 112, "14.88 m", 1288, 3.25), makeIsotope("In112m", 112, "20.56 m", 1780, 0),
        			makeIsotope("In113", 113, 4.3), makeIsotope("In113m", 113, "1.6582 h", 8612.2, 0),
        			makeIsotope("In114", 114, "1.20 m", 104, 3.4407), makeIsotope("In114m", 114, "49.51 d", 6171000, 1.452),
        			makeIsotope("In114m2", 114, "43.1 ms", 0.0622, 0), makeIsotope("In115", 115, 95.7),
        			makeIsotope("In115m", 115, "4.486 h", 23299, 0), makeIsotope("In116", 116, "14.10 s", 20.34, 3.275),
        			makeIsotope("In116m", 116, "54.29 m", 4699, 0), makeIsotope("In116m2", 116, "2.18 s", 3.15, 0),
        			makeIsotope("In117", 117, "43.20 m", 3739, 1.455), makeIsotope("In117m", 117, "116.2 m", 10060, 1.455) };
	elements[49 - 1] = makeElement("Indium", 49, "In", inList);
	//Tin
	vector<Isotope> snList = { makeIsotope("Sn111", 111, "35.30 m", 3056, 2.445), makeIsotope("Sn112", 112, 0.97),
        			makeIsotope("Sn113", 113, "115.09 d", 14346000, 1.036), makeIsotope("Sn113m", 113, "21.4 m", 1852, 1.036),
        			makeIsotope("Sn114", 114, 0.65), makeIsotope("Sn115", 115, 0.34),
        			makeIsotope("Sn116", 116, 14.53), makeIsotope("Sn117", 117, 7.68),
        			makeIsotope("Sn117m", 117, "13.60 d", 1695000, 0), makeIsotope("Sn118", 118, 24.23),
        			makeIsotope("Sn119", 119, 8.59), makeIsotope("Sn119m", 119, "293.1 d", 36530000, 0),
        			makeIsotope("Sn120", 120, 32.59), makeIsotope("Sn121", 121, "27.06 h", 140500, 0.3901),
        			makeIsotope("Sn121m", 121, "55 y", 2500000000, 0.3901), makeIsotope("Sn122", 122, 4.63),
        			makeIsotope("Sn123", 123, "129.20 d", 16105000, 1.403), makeIsotope("Sn123m", 123, "40.06 m", 3468, 1.403),
        			makeIsotope("Sn124", 124, 5.79), makeIsotope("Sn125", 125, "9.64 d", 1202000, 2.363),
        			makeIsotope("Sn125m", 125, "9.52 m", 824, 2.363), makeIsotope("Sn126", 126, "1e5 y", 4550000000000, 0.378) };
	elements[50 - 1] = makeElement("Tin", 50, "Sn", snList);
	//Antimony
	vector<Isotope> sbList = { makeIsotope("Sb120", 120, "15.89 m", 1375, 2681), makeIsotope("Sb120m", 120, "5.76 d", 718000, 2681),
        			makeIsotope("Sb121", 121, 57.36), makeIsotope("Sb122", 122, "2.72 d", 339000, 3.5985),
        			makeIsotope("Sb122m", 122, "4.191 m", 362.8, 0), makeIsotope("Sb123", 123, 42.64),
        			makeIsotope("Sb124", 124, "60.20 d", 7504000, 2.9045), makeIsotope("Sb124m", 124, "93 s", 134, 2.9045),
        			makeIsotope("Sb124m2", 124, "20.2 m", 1749, 0), makeIsotope("Sb125", 125, "2.76 y", 126000000, 0.7667) };
	elements[51 - 1] = makeElement("Antimony", 51, "Sb", sbList);
	//Tellurium
	vector<Isotope> teList = { makeIsotope("Te119", 119, "16.03 h", 83260, 2.293), makeIsotope("Te119m", 119, "4.70 d", 586000, 2.293),
        			makeIsotope("Te120", 120, 0.096), makeIsotope("Te121", 121, "16.78 d", 2092000, 1.036),
        			makeIsotope("Te121m", 121, "154 d", 19200000, 1.036), makeIsotope("Te122", 122, 2.603),
        			makeIsotope("Te123", 123, 0.908), makeIsotope("Te123m", 123, "119.7 d", 14920000, 0),
        			makeIsotope("Te124", 124, 4.816), makeIsotope("Te125", 125, 7.139),
        			makeIsotope("Te125m", 125, "57.40 d", 7155000, 0), makeIsotope("Te126", 126, 18.95),
        			makeIsotope("Te127", 127, "9.35 h", 48600, 0.698), makeIsotope("Te127m", 127, "109 d", 13600000, 0.698),
        			makeIsotope("Te128", 128, 31.69), makeIsotope("Te129", 129, "69.6 m", 6025, 1.498),
        			makeIsotope("Te129m", 129, "33.6 d", 4190000, 1.498), makeIsotope("Te130", 130, 33.8),
        			makeIsotope("Te131", 131, "25.00 m", 2164, 2.2335), makeIsotope("Te131m", 131, "30 h", 156000, 2.2335),
        			makeIsotope("Te132", 132, "3.204 d", 399400, 0.493) };
	elements[52 - 1] = makeElement("Tellurium", 52, "Te", teList);
	//Iodine
	vector<Isotope> iList = { makeIsotope("I126", 126, "13.11 d", 1634000, 3.413), makeIsotope("I127", 127, 100),
        			makeIsotope("I128", 128, "24.99 m", 2163, 3.371),
        			makeIsotope("I129", 129, "1.57e7 y", 715000000000000, 0.194) };
	elements[53 - 1] = makeElement("Iodine", 53, "I", iList);
	//Xenon
	vector<Isotope> xeList = { makeIsotope("Xe123", 123, "2.08 h", 10803, 2.676), makeIsotope("Xe124", 124, 0.1),
        			makeIsotope("Xe125", 125, "16.90 h", 87774, 1.653), makeIsotope("Xe125m", 125, "57 s", 82, 0),
        			makeIsotope("Xe126", 126, 0.09), makeIsotope("Xe127", 127, "36.34 d", 4530000, 0.6624),
        			makeIsotope("Xe127m", 127, "69.2 s", 99.8, 0), makeIsotope("Xe128", 128, 1.91),
        			makeIsotope("Xe129", 129, 26.4), makeIsotope("Xe129m", 129, "8.88 d", 1110000, 0),
        			makeIsotope("Xe130", 130, 4.1), makeIsotope("Xe131", 131, 21.2),
        			makeIsotope("Xe131m", 131, "11.84 d", 1476000, 0), makeIsotope("Xe132", 132, 26.9),
        			makeIsotope("Xe132m", 132, "8.39 ms", 0.0121, 0), makeIsotope("Xe133", 133, "5.243 d", 653500, 0.4274),
        			makeIsotope("Xe133m", 133, "2.19 d", 273000, 0), makeIsotope("Xe134", 134, 10.4),
        			makeIsotope("Xe134m", 134, "290 ms", 0.418, 0), makeIsotope("Xe135", 135, "9.14 h", 47500, 1.151),
        			makeIsotope("Xe135m", 135, "15.29 m", 1324, 0), makeIsotope("Xe136", 136, 8.9),
        			makeIsotope("Xe137", 137, "3.818 m", 330.5, 4.173), makeIsotope("Xe138", 138, "14.08 m", 1219, 2.774) };
	elements[54 - 1] = makeElement("Xenon", 54, "Xe", xeList);
	//Cesium
	vector<Isotope> csList = { makeIsotope("Cs132", 132, "6.479 d", 807600, 3.3985), makeIsotope("Cs133", 133, 100),
        			makeIsotope("Cs134", 134, "2.0648 y", 94006000, 3.2877), makeIsotope("Cs134m", 134, "2.903 h", 15077, 0),
        			makeIsotope("Cs135", 135, "2.30e6 y", 104700000000000, 0.2693), makeIsotope("Cs135m", 135, "53 m", 4588, 0) };
	elements[55 - 1] = makeElement("Cesium", 55, "Cs", csList);
	//Barium
	vector<Isotope> baList = { makeIsotope("Ba129", 129, "2.23 h", 11600, 2.432), makeIsotope("Ba129m", 129, "2.16 h", 11200, 0),
        			makeIsotope("Ba130", 130, 0.106), makeIsotope("Ba130m", 130, "11 ms", 0.016, 0),
        			makeIsotope("Ba131", 131, "11.50 d", 1433000, 1.37), makeIsotope("Ba131m", 131, "14.6 m", 1264, 0),
        			makeIsotope("Ba132", 132, 0.101), makeIsotope("Ba133", 133, "10.51 y", 478500000, 0.5174),
        			makeIsotope("Ba133m", 133, "38.9 h", 200500, 0), makeIsotope("Ba134", 134, 2.417),
        			makeIsotope("Ba134m", 134, "2.63 us", 0.00000379, 0), makeIsotope("Ba135", 135, 6.592),
        			makeIsotope("Ba135m", 135, "28.7 h", 149000, 0), makeIsotope("Ba136", 136, 7.854),
        			makeIsotope("Ba136m", 136, "0.3084 s", 0.4449, 0), makeIsotope("Ba137", 137, 11.23),
        			makeIsotope("Ba137m", 137, "2.552 m", 220.9, 0), makeIsotope("Ba138", 138, 71.7),
        			makeIsotope("Ba139", 139, "83.06 h", 431400, 2.317), makeIsotope("Ba140", 140, "12.752 d", 1589500, 1.05) };
	elements[56 - 1] = makeElement("Barium", 56, "Ba", baList);
	//Lanthanum
	vector<Isotope> laList = { makeIsotope("La137", 137, "6.00e4 y", 2730000000000, 0.6), makeIsotope("La138", 138, 0.0902),
        			makeIsotope("La139", 139, 99.9098), makeIsotope("La140", 140, "1.6781 d", 209173, 3.7619),
        			makeIsotope("La141", 141, "3.92 h", 20400, 2.502) };
	elements[57 - 1] = makeElement("Lanthanum", 57, "La",laList);
	//Cerium
	vector<Isotope> ceList = { makeIsotope("Ce135", 135, "17.70 h", 91929, 2.026), makeIsotope("Ce135m", 135, "20 s", 29, 0),
        			makeIsotope("Ce136", 136, 0.19), makeIsotope("Ce137", 137, "9.00 h", 46700, 1.2221),
        			makeIsotope("Ce137m", 137, "34.4 h", 179000, 0), makeIsotope("Ce138", 138, 0.25),
           			makeIsotope("Ce138m", 138, "8.65 ms", 0.0125, 0), makeIsotope("Ce139", 139, "137.64 d", 17157000, 0.278),
        			makeIsotope("Ce139m", 139, "54.8 s", 79.1, 0), makeIsotope("Ce140", 140, 88.48),
        			makeIsotope("Ce141", 141, "32.501 d", 4051200, 0.5807), makeIsotope("Ce142", 142, 11.08),
        			makeIsotope("Ce143", 143, "33.039 h", 171595, 1.4614), makeIsotope("Ce144", 144, "284.893 d", 35504900, 0.3187) };
    elements[58 - 1] = makeElement("Cerium", 58, "Ce", ceList);
	vector<Isotope> prList = { makeIsotope("Pr140", 140, "3.39 m", 293, 3.388), makeIsotope("Pr141", 141, 100),
        			makeIsotope("Pr142", 142, "19.12 h", 99303, 2.9075), makeIsotope("Pr142m", 142, "14.6 m", 1264, 0),
        			makeIsotope("Pr143", 143, "13.57 d", 1691000, 0.9339) };
	elements[59 - 1] = makeElement("Praseodymium", 59, "Pr", prList);
	//Neodymium
	vector<Isotope> ndList = { makeIsotope("Nd141", 141, "2.49 h", 12900, 1.823), makeIsotope("Nd141m", 141, "62.0 s", 89.4, 0),
        			makeIsotope("Nd142", 142, 27.13), makeIsotope("Nd143", 143, 12.18), makeIsotope("Nd144", 144, 23.8),
        			makeIsotope("Nd145", 145, 8.3), makeIsotope("Nd146", 146, 17.19), makeIsotope("Nd147", 147, "10.98 d", 1369000, 0.896),
        			makeIsotope("Nd148", 148, 5.76), makeIsotope("Nd149", 149, "1.728 h", 8975, 1.691),
        			makeIsotope("Nd150", 150, 5.64), makeIsotope("Nd151", 151, "12.44 m", 1077, 2.442),
        			makeIsotope("Nd152", 152, "11.40 m", 986.8, 1.11) };
	elements[60 - 1] = makeElement("Neodymium", 60, "Nd", ndList);
	//Promethium
	elements[61 - 1] = makeElement("Promethium", 61, "Pm");
	//Samarium
	vector<Isotope> smList = { makeIsotope("Sm143", 143, "8.83 m", 764, 3.443), makeIsotope("Sm134m", 143, "66 s", 95, 0),
        			makeIsotope("Sm143m2", 143, "30 ms", 0.043, 0), makeIsotope("Sm144", 144, 3.1),
        			makeIsotope("Sm145", 145, "340.00 d", 42381000, 6.164), makeIsotope("Sm146", 146, "1.03e8 y", 4690000000000000, 2.529),
        			makeIsotope("Sm147", 147, 15), makeIsotope("Sm148", 148, 11.3),
        			makeIsotope("Sm149", 149, 13.8), makeIsotope("Sm150", 150, 7.4),
        			makeIsotope("Sm151", 151, "90.0 y", 4098000000, 0.0767), makeIsotope("Sm152", 152, 26.7),
        			makeIsotope("Sm153", 153, "46.284 h", 240385, 0.8082), makeIsotope("Sm153m", 153, "10.6 ms", 0.0153, 0),
        			makeIsotope("Sm154", 154, 22.7), makeIsotope("Sm155", 155, "22.30 m", 1930, 1.6269),
        			makeIsotope("Sm156", 156, "9.40 h", 48800, 0.722) };
	elements[62 - 1] = makeElement("Samarium", 62, "Sm", smList);
	//Europium
	vector<Isotope> euList = { makeIsotope("Eu150", 150, "36.9 y", 1680000000, 2.261), makeIsotope("Eu150m", 150, "12.8 h", 66500, 3.232),
        			makeIsotope("Eu151", 151, 47.8), makeIsotope("Eu152", 152, "13.537 y", 616310000, 3.6931),
        			makeIsotope("Eu152m", 152, "9.3116 h", 48362, 3.6931), makeIsotope("Eu152m2", 152, "96 m", 8300, 0),
        			makeIsotope("Eu153", 153, 52.2), makeIsotope("Eu154", 154, "8.593 y", 391200000, 2.6857),
        			makeIsotope("Eu154m", 154, "46.3 m", 4008, 0), makeIsotope("Eu155", 155, "4.7611 y", 216760000, 0.2521) };
	elements[63 - 1] = makeElement("Europium", 63, "Eu", euList);
	//Gadolinium
	vector<Isotope> gdList = { makeIsotope("Gd151", 151, "124 d", 15500000, 3.117), makeIsotope("Gd152", 152, 0.2),
        			makeIsotope("Gd153", 153, "240.40 d", 29966000, 0.4844), makeIsotope("Gd154", 154, 2.18),
        			makeIsotope("Gd155", 155, 14.8), makeIsotope("Gd155m", 155, "31.97 ms", 0.04612, 0),
        			makeIsotope("Gd156", 156, 20.47), makeIsotope("Gd157", 157, 15.65), makeIsotope("Gd158", 158, 24.84),
        			makeIsotope("Gd159", 159, "18.479 h", 95974, 0.9706), makeIsotope("Gd160", 160, 21.86),
        			makeIsotope("Gd161", 161, "3.66 m", 317, 1.9556), makeIsotope("Gd162", 162, "8.40 m", 727, 1.394) };
	elements[64 - 1] = makeElement("Gadolinium", 64, "Gd", gdList);
	//Terbium
	vector<Isotope> tbList = { makeIsotope("Tb158", 158, "180 y", 8195000000, 2.1567), makeIsotope("Tb158m", 158, "10.70 s", 15.44, 2.1567),
        			makeIsotope("Tn159", 159, 100), makeIsotope("Tb160", 160, "72.30 d", 9012, 1.8353),
        			makeIsotope("Tb161", 161, "6.88 d", 858000, 0.5931) };
	elements[65 - 1] = makeElement("Terbium", 65, "Tb", tbList);
	//Dysprosium
	vector<Isotope> dyList = { makeIsotope("Dy155", 155, "9.90 h", 51400, 2.0945), makeIsotope("Dy156", 156, 0.06),
        			makeIsotope("Dy157", 157, "8.14 h", 42300, 1.341), makeIsotope("Dy157m", 157, "21.6 ms", 0.0312, 0),
        			makeIsotope("Dy158", 158, 0.1), makeIsotope("Dy159", 159, "144.40 d", 17999000, 0.3656),
        			makeIsotope("Dy160", 160, 2.34), makeIsotope("Dy161", 161, 18.9), makeIsotope("Dy162", 162, 25.5),
        			makeIsotope("Dy163", 163, 24.9), makeIsotope("Dy164", 164, 28.2),
        			makeIsotope("Dy165", 165, "2.334 h", 12122, 1.2861), makeIsotope("Dy165m", 165, "1.257 m", 108.8, 0),
        			makeIsotope("Dy166", 166, "81.6 h", 424000, 0.4862) };
	elements[66 - 1] = makeElement("Dysprosium", 66, "Dy", dyList);
	//Holmium
	vector<Isotope> hoList = { makeIsotope("Ho164", 164, "29.00 m", 2510, 0.9868), makeIsotope("Ho164m", 164, "37.5 m", 3246, 0),
        			makeIsotope("Ho165", 165, 100), makeIsotope("Ho166", 166, "26.83 h", 139300, 1.8549),
        			makeIsotope("Ho166m", 166, "1200 y", 54600000000, 0), makeIsotope("Ho167", 167, "3.10 h", 16100, 1.007) };
	elements[67 - 1] = makeElement("Holmium", 67, "Ho", hoList);
	//Erbium
	vector<Isotope> erList = { makeIsotope("Er161", 161, "3.21 h", 16700, 2.002), makeIsotope("Er162", 162, 0.14),
        			makeIsotope("Er163", 163, "1.25 h", 6492, 1.21), makeIsotope("Er164", 164, 1.61),
        			makeIsotope("Er165", 165, "10.36 h", 53807, 0.376), makeIsotope("Er166", 166, 33.6),
        			makeIsotope("Er167", 167, 22.95), makeIsotope("Er167m", 167, "2.269 s", 3.273, 0),
        			makeIsotope("Er168", 168, 26.8), makeIsotope("Er169", 169, "9.4 d", 1200000, 0.3511),
        			makeIsotope("Er170", 170, 14.9), makeIsotope("Er171", 171, "7.516 h", 39036, 1.4905),
        			makeIsotope("Er172", 172, "49.3 h", 256000, 0.891) };
	elements[68 - 1] = makeElement("Erbium", 68, "Er", erList);
	//Thulium
	vector<Isotope> tmList = { makeIsotope("Tm168", 168, "93.10 d", 11605, 1.9361),
        			makeIsotope("Tm169", 169, 100),
        			makeIsotope("Tm170", 170, "128.60 d", 16030000, 1.2824),
        			makeIsotope("Tm171", 171, "1.92 y", 87400000, 0.0964) };
	elements[69 - 1] = makeElement("Thulium", 69, "Tm", tmList);
	//Ytterbium
	vector<Isotope> ybList = { makeIsotope("Yb167", 167, "17.50 m", 1515, 1.954), makeIsotope("Yb168", 168, 0.13),
        			makeIsotope("Yb169", 169, "32.026 d", 3992000, 0.909), makeIsotope("Yb169m", 169, "46 s", 66, 0),
        			makeIsotope("Yb170", 170, 3.05), makeIsotope("Yb171", 171, 14.3),
        			makeIsotope("Yb171m", 171, "5.25 ms", 0.00757, 0), makeIsotope("Yb172", 172, 21.9),
        			makeIsotope("Yb173", 173, 16.12), makeIsotope("Yb174", 174, 31.8),
        			makeIsotope("Yb175", 175, "4.185 d", 521700, 0.47), makeIsotope("Yb175m", 175, "68.2 ms", 0.0984, 0),
        			makeIsotope("Yb176", 176, 12.7), makeIsotope("Yb176m", 176, "11.4 s", 16.5, 0),
        			makeIsotope("Yb177", 177, "1.911 h", 9925, 1.3992), makeIsotope("Yb177m", 177, "6.41 s", 9.25, 0),
        			makeIsotope("Yb178", 178, "74 m", 6400, 0.654) };
	elements[70 - 1] = makeElement("Ytterbium", 70, "Yb", ybList);
	//Lutetium
	vector<Isotope> luList = { makeIsotope("Lu174", 174, "3.31 y", 151000000, 1.3743), makeIsotope("Lu174m", 174, "142 d", 17700000, 1.3743),
        			makeIsotope("Lu175", 175, 97.41), makeIsotope("Lu176", 176, 2.59),
        			makeIsotope("Lu176m", 176, "3.635 h", 18879, 0), makeIsotope("Lu177", 177, "6.734 d", 839400, 0.4983),
        			makeIsotope("Lu177m", 177, "160.4 d", 19990000, 0), makeIsotope("Lu178", 178, "28.40 m", 2458, 2.0992),
        			makeIsotope("Lu178m", 178, "23.1 m", 2000, 0) };
	elements[71 - 1] = makeElement("Lutetium", 71, "Lu", luList);
	//Hafnium
	vector<Isotope> hfList = { makeIsotope("Hf173", 173, "23.60 h", 122600, 1.61), makeIsotope("Hf174", 174, 0.162),
           			makeIsotope("Hf175", 175, "70.00 d", 8725000, 0.6847), makeIsotope("Hf176", 176, 5.206),
        			makeIsotope("Hf177", 177, 18.606), makeIsotope("Hf177m", 177, "1.08 s", 1.56, 0),
        			makeIsotope("Hf177m2", 177, "51.4 m", 4449, 0), makeIsotope("Hf178", 178, 27.297),
        			makeIsotope("Hf178m", 178, "4.0 s", 5.8, 0), makeIsotope("Hf178m2", 178, "31 y", 1400000000, 0),
        			makeIsotope("Hf179", 179, 13.629), makeIsotope("Hf179m", 179, "18.67 s", 26.94, 0),
        			makeIsotope("Hf179m2", 179, "25.05 d", 3122000, 0), makeIsotope("Hf180", 180, 35.1),
    				makeIsotope("Hf180m", 180, "5.5 h", 29000, 0), makeIsotope("Hf181", 181, "42.39 d", 5284000, 1.027),
        			makeIsotope("Hf182", 182, "9e6 y", 410000000000000, 0.373), makeIsotope("Hf182m", 182, "61.5 m", 5324, 0) };
	elements[72 - 1] = makeElement("Hafnium", 72, "Hf", hfList);
	//Tantalum
	vector<Isotope> taList = { makeIsotope("Ta179", 179, "1.82 y", 82900000, 0.111), makeIsotope("Ta179m", 179, "9.0 ms", 0.013, 0),
        			makeIsotope("Ta179m2", 179, "52 ms", 0.075, 0), makeIsotope("Ta180", 180, "8.152 h", 42339, 0),
        			makeIsotope("Ta180m", 180, 0.012), makeIsotope("Ta181", 181, 99.988),
        			makeIsotope("Ta182", 182, "114.43 d", 14264000, 1.8135), makeIsotope("Ta182m", 182, "283 ms", 0.408, 0),
        			makeIsotope("Ta182m2", 182, "15.84 m", 1371, 0), makeIsotope("Ta183", 183, "5.10 d", 636000, 1.07) };
	elements[73 - 1] = makeElement("Tantalum", 73, "Ta", taList);
	//Tungsten
	vector<Isotope> wList = { makeIsotope("W179", 179, "37.05 m", 3207, 1.06), makeIsotope("W179m", 179, "6.40 m", 554, 1.06),
        			makeIsotope("W180", 180, 0.13), makeIsotope("W180m", 180, "5.47 ms", 0.00789, 0),
        			makeIsotope("W181", 181, "121.20 d", 15107000, 0.188), makeIsotope("W182", 182, 26.3),
        			makeIsotope("W183", 183, 14.3), makeIsotope("W183m", 183, "5.2 s", 7.5, 0),
        			makeIsotope("W184", 184, 30.67), makeIsotope("W185", 185, "75.10 d", 9361000, 0.433),
        			makeIsotope("W185m", 185, "1.67 m", 145, 0), makeIsotope("W186", 186, 28.6),
        			makeIsotope("W187", 187, "23.72 h", 123200, 1.3112), makeIsotope("W188", 188, "69.4 d", 8650000, 0.349) };
	elements[74 - 1] = makeElement("Tungsten", 74, "W", wList);
	//Rhenium
	vector<Isotope> reList = { makeIsotope("Re184", 184, "38.0 d", 4740000, 1.483), makeIsotope("Re184m", 184, "169 d", 21100000, 1.483),
        			makeIsotope("Re185", 185, 37.4), makeIsotope("Re186", 186, "3.7183 d", 463482, 1.5881),
        			makeIsotope("Re186m", 186, "2.0e5 y", 9110000000000, 0), makeIsotope("Re187", 187, 62.6),
        			makeIsotope("Re188", 188, "17.005 h", 88319, 2.1204), makeIsotope("Re188m", 188, "18.6 m", 1610, 0),
        			makeIsotope("Re189", 189, "24.3 h", 126000, 1.009) };
	elements[75 - 1] = makeElement("Rhenium", 75, "Re", reList);
	//Osmium
	vector<Isotope> osList = { makeIsotope("Os183", 183, "13.00 h", 67518, 2.13), makeIsotope("Os183m", 183, "9.9 h", 51000, 2.13),
        			makeIsotope("Os184", 184, 0.02), makeIsotope("Os185", 185, "93.60 d", 11670000, 1.0128),
        			makeIsotope("Os186", 186, 1.58), makeIsotope("Os187", 187, 1.6), makeIsotope("Os188", 188, 13.3),
        			makeIsotope("Os189", 189, 16.1), makeIsotope("Os189m", 189, "5.8 h", 30000, 0),
        			makeIsotope("Os190", 190, 26.4), makeIsotope("Os190m", 190, "9.9 m", 860, 0),
        			makeIsotope("Os191", 191, "15.40 d", 1920000, 0.3137), makeIsotope("Os191m", 191, "13.10 h", 68037, 0),
        			makeIsotope("Os192", 192, 41), makeIsotope("Os192m", 192, "5.9 s", 8.5, 0),
        			makeIsotope("Os193", 193, "30.11 h", 156400, 1.1405), makeIsotope("Os194", 194, "6.00 y", 273000000, 0.0966) };
	elements[76 - 1] = makeElement("Osmium", 76, "Os", osList);
	//Iridium
	vector<Isotope> irList = { makeIsotope("Ir190", 190, "11.78 d", 1468000, 2.62), makeIsotope("Ir190m", 190, "1.2 h", 6200, 0),
        			makeIsotope("Ir190m2", 190, "3.25 h", 16900, 2), makeIsotope("Ir191", 191, 37.3),
        			makeIsotope("Ir191m", 191, "4.94 s", 7.13, 0), makeIsotope("Ir191m2", 191, "5.5 s", 7.93, 0),
        			makeIsotope("Ir192", 192, "73.831 d", 9203000, 2.5059), makeIsotope("Ir192m", 192, "1.45 m", 126, 1.4597),
        			makeIsotope("Ir192m2", 192, "21 y", 956000000, 0), makeIsotope("Ir193", 193, 62.7),
					makeIsotope("Ir193m", 193, "10.53 d", 1313000, 0), makeIsotope("Ir194", 194, "19.28 h", 100100, 0),
					makeIsotope("Ir194m", 194, "31.85 ms", 0.04595, 0), makeIsotope("Ir194m2", 194, "171 d", 21300000, 0),
					makeIsotope("Ir193m", 195, "2.5 h", 13000, 0), makeIsotope("Ir195m", 195, "3.8 h", 20000, 0)};
	elements[77 - 1] = makeElement("Iridium", 77, "Ir", irList);
	//Platinum
	vector<Isotope> ptList = { makeIsotope("Pt189", 189, "10.87 h", 56456, 1.971), makeIsotope("Pt190", 190, 0.01),
        			makeIsotope("Pt191", 191, "2.802 d", 349300, 1.019), makeIsotope("Pt192", 192, 0.79),
        			makeIsotope("Pt193", 193, "50.0 y", 2280000000, 0.0566), makeIsotope("Pt193m", 193, "4.33 d", 540000, 0),
        			makeIsotope("Pt194", 194, 32.9), makeIsotope("Pt195", 195, 33.8),
        			makeIsotope("Pt195m", 195, "4.02 d", 501000, 0), makeIsotope("Pt196", 196, 25.3),
        			makeIsotope("Pt197", 197, "19.8915 h", 103311, 0.7189), makeIsotope("Pt197m", 197, "95.41 m", 8259, 0.7189),
        			makeIsotope("Pt198", 198, 7.2), makeIsotope("Pt199", 199, "30.8 m", 2670, 0), 
					makeIsotope("Pt199m", 199, "13.6 s", 19.6, 0), makeIsotope("Pt200", 200, "12.5 h", 64900, 0)};
	elements[78 - 1] = makeElement("Platinum", 78, "Pt", ptList);
	//Gold
	vector<Isotope> auList = { makeIsotope("Au196", 196, "6.183 d", 770700, 2.192), makeIsotope("Au196m", 196, "8.1 s", 12, 0),
        			makeIsotope("Au196m2", 196, "9.6 h", 49900, 0), makeIsotope("Au197", 197, 100),
        			makeIsotope("Au197m", 197, "7.73 s", 11.2, 0), makeIsotope("Au198", 198, "2.69517 d", 335950, 1.3725),
        			makeIsotope("Au198m", 198, "2.27 d", 283000, 0), makeIsotope("Au199", 199, "3.139 d", 391300, 0.4523) };
	elements[79 - 1] = makeElement("Gold", 79, "Au", auList);
	//Mercury
	vector<Isotope> hgList = { makeIsotope("Hg195", 195, "9.9 h", 51000, 1.51), makeIsotope("Hg195m", 195, "41.6 h", 216000, 1.51),
        			makeIsotope("Hg196", 196, 0.15), makeIsotope("Hg197", 197, "64.14 h", 333100, 0.6),
        			makeIsotope("Hg197m", 197, "23.8 h", 59400, 0.6), makeIsotope("Hg198", 198, 9.97),
        			makeIsotope("Hg199", 199, 16.87), makeIsotope("Hg199m", 199, "42.6 m", 3688, 0),
        			makeIsotope("Hg200", 200, 23.1), makeIsotope("Hg201", 201, 13.18),
        			makeIsotope("Hg202", 202, 29.86), makeIsotope("Hg203", 203, "46.612 d", 5810132, 0.4918),
        			makeIsotope("Hg204", 204, 6.87), makeIsotope("Hg205", 205, "5.2 m", 450, 1.531),
        			makeIsotope("Hg205m", 205, "1.10 ms", 0.0016, 0), makeIsotope("Hg206", 206, "8.15 m", 705, 1.307) };
	elements[80 - 1] = makeElement("Mercury", 80, "Hg", hgList);
	//Thallium
	vector<Isotope> tlList = { makeIsotope("Tl202", 202, "12.23 d", 1524000, 1.365), makeIsotope("Tl202m", 202, "572 us", 0.000825, 0),
        			makeIsotope("Tl203", 203, 29.524), makeIsotope("Tl204", 204, "3.78 y", 172000000, 1.11122),
        			makeIsotope("Tl205", 205, 70.476), makeIsotope("Tl206", 206, "4.199 m", 363.5, 1.5335),
        			makeIsotope("Tl206m", 206, "3.74 m", 324, 0), makeIsotope("Tl207", 207, "4.77 m", 413, 1.423),
        			makeIsotope("Tl207m", 207, "1.33 s", 1.92, 1.423) };
	elements[81 - 1] = makeElement("Thallium", 81, "Tl", tlList);
	//Lead
	vector<Isotope> pbList = { makeIsotope("Pb203", 203, "51.873 h", 269413, 0.975), makeIsotope("Pb203m", 203, "6.3 s", 9.1, 0),
        			makeIsotope("Pb203m2", 203, "0.48 s", 0.69, 0), makeIsotope("Pb204", 204, 1.4),
        			makeIsotope("Pb204m", 204, "67.2 m", 5817, 0), makeIsotope("Pb205", 205, "1.53e7 y", 697000000000000, 0.0511),
        			makeIsotope("Pb205m", 205, "5.54 ms", 0.00799, 0), makeIsotope("Pb206", 206, 24.1),
        			makeIsotope("Pb207", 207, 22.1), makeIsotope("Pb207m", 207, "0.805 s", 1.161, 0),
        			makeIsotope("Pb208", 208, 52.4), makeIsotope("Pb209", 209, "3.253 h", 16895, 0.6442),
        			makeIsotope("Pb210", 210, "22.3 y", 1020000000, 3.8555) };
	elements[82 - 1] = makeElement("Lead", 82, "Pb", pbList);
	//Bismuth
	vector<Isotope> biList = { makeIsotope("Bi208", 208, "3.68e5 y", 16800000000000, 2.8791), makeIsotope("Bi208m", 208, "2.58 ms", 0.00372, 0),
        			makeIsotope("Bi209", 209, 100), makeIsotope("Bi210", 210, "5.013 d", 624900, 7.9126),
        			makeIsotope("Bi210m", 210, "3.04e6 y", 138000000000000, 5.036), makeIsotope("Bi211", 211, "2.14 m", 185, 7.329) };
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
	vector<Isotope> thList = {makeIsotope("Th231", 231, "25.52 h", 132500, 4.6028), makeIsotope("Th232", 232, 100),
        			makeIsotope("Th233", 233, "22.3 m", 1930, 1.2451), makeIsotope("Th234", 234, "24.10 d", 3004000, 0.273) };
	elements[90 - 1] = makeElement("Thorium", 90, "Th", thList);
	//Protactinium
	vector<Isotope> paList = { makeIsotope("Pa230", 230, "17.40 d", 2169000, 7.313), makeIsotope("Pa231", 231, 100),
           			makeIsotope("Pa232", 232, "1.31 d", 163000, 1.832), makeIsotope("Pa233", 233, "26.967 d", 3361406, 0.5701) };
	elements[90] = makeElement("Protactinium", 91, "Pa", paList);
	//Uranium
	vector<Isotope> uList = { makeIsotope("U234", 234, "2.455e5 y", 30610000000000, 0),
        			makeIsotope("U235", 235, 0.72), makeIsotope("U235m", 235, "25 m", 2164, 0),
        			makeIsotope("U236", 236, "2.342e7 y", 1066000000000000, 4.572), makeIsotope("U237", 237, "6.75 d", 841000, 0.5186),
        			makeIsotope("U238", 238, 99.2745), makeIsotope("U238m", 238, "225 ns", 0, 0),
        			makeIsotope("U238m2", 238, ">1 ns", 0, 0), makeIsotope("U239", 239, "23.45 m", 2030, 1.2635),
        			makeIsotope("U240", 240, "14.10 h", 73231, 0.388) };
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