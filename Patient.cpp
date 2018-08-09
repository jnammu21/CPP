#include "Patient.h"
#include<fstream>
#include<vector>
//ostream & operator<<(ostream &, const Patient &)
//{
//	// TODO: insert return statement here
//}

vector<string> people;

void removeCommaAndCreateAPersonObject(string s,vector<string> &people) {
	std::string delimiter = ",";
	string patient;
	size_t pos = 0;
	std::string token;
	if (s != "") {
		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			patient += token;
			patient += " ";
			s.erase(0, pos + delimiter.length());
		}
		patient += " ";
		patient += s;
		people.push_back(patient);
		patient.clear();
	}
}

void read_patients_file(const string & fname, Patient * patients[], int & patient_count)
{
	ifstream file(fname);
	string value;
	string person;
	string token;
	Patient *p;
	int pos = 0;
	while (file.good())
	{
		getline(file, value, '\n'); 
		person += string(value);
		if (person != "") {
			p = new Patient(person);
			//patients[pos] = new Patient(*p);
			//pos++;
			removeCommaAndCreateAPersonObject(person,people);
			person.clear();
		}

	}
	cout << "loaded " <<people.size()<<" patients record from the file \n";
	
}

void displayMessage() {
	cout << "--------------------------------------\n";
	cout << "          Main Menu                   \n";
	cout << "--------------------------------------\n";
	cout << "1. Add Patient\n";
	cout << "2. View Patient at a specified Index\n";
	cout << "3. View All Patients\n";
	cout << "4. Exit\n";
	cout << "--------------------------------------\n";
	cout << "Select an option:";

}
void viewAllPatients() {
	for (int i = 0; i < people.size(); i++) {
		cout << "--------------------------------------\n";
		cout << people[i]<<"\n";
	}
	cout << "--------------------------------------\n";

	
}
void viewAtAnIndex() {
	int index = 0;
	cout << "Enter an index between 0 and " << people.size()-1<<" : ";
	cin >> index;
	if (index >= people.size()) {
		cout << "You did not enter the right index \n";
	}
	else {
		cout << "--------------------------------------\n";
		cout << people[index] << "\n";
		cout << "--------------------------------------\n";
	}
}
bool checkDiagnosis(int d) {

	if (d > 5) {
		return false;
	}
	else {
		return true;
	}
}
string getNewPatient() {
	string newPatient;
	string name;
	string ssn;
	string age;
	string diagnosis;
	int chance = 0;
	int totalChance = 3;
	cout << "Enter Patient Name \n";
	cin >> name;
	newPatient += name;
	newPatient += ",";
	cout << "Enter Patient SSN \n";
	cin >> ssn;
	newPatient += ssn;
	newPatient += ",";
	cout << "Enter Patient Age \n";
	cin >> age;
	newPatient += age;
	newPatient += ",";
	cout << "Enter Patient Diagnosis \n";
	cin >> diagnosis;
	int diag = stoi(diagnosis);
	while (!checkDiagnosis(diag)) {
		if (chance == totalChance) {
			cout << "Program Exiting \n";
			exit;
		}
		chance++;
		cout << "Enter a number between 1-5\n";
		cout<<"You have "<<totalChance-chance<<" chance left \n";
		cin >> diagnosis;		
	}
	newPatient += diagnosis;
	newPatient += "\n";
	
	return newPatient;

}
void addPatient(const string &file, int & patient_count) {

	int count = patient_count;
	fstream filestr;
	filestr.open(file, fstream::app | fstream::ate);
	string newPatient = getNewPatient();
	people.push_back(newPatient);
	filestr << newPatient;
}
int displayOptions(const string &file, int & patient_count) {

	int selectedOption = 0;
	int count = patient_count;
	displayMessage();

	cin >> selectedOption;
	switch (selectedOption) {
	case 1:addPatient(file,count);
		return 1;
		break;
	case 2:viewAtAnIndex();
		return 2;
		break;
	case 3:viewAllPatients();
		return 3;
		break;
	case 4:
		return 4;
		break;
	default:
		return -1;
		break;
	}

}



void main_menu(const string & fname, Patient * patients[], int & patient_count)
{
	int option = displayOptions(fname,patient_count);
	int count = patient_count;
	Patient *p = new Patient();

	if (option == -1) {
		cout << "Please Enter a Valid option" << endl;
	}
	else if (option == 4) {
		exit;
	}
	else {
		//call main menu here
		main_menu(fname,0,count);
	}

}

Patient::Patient()
{
}

Patient::Patient(const Patient & copy)
{
	this->name = copy.name;
	this->SSN = copy.SSN;
	this->age = copy.age;
	this->diagnosis = copy.diagnosis;
}

Patient::Patient(std::string file_line)
{
	vector<string> details;
	std::string delimiter = ",";
	string patient;
	size_t pos = 0;
	std::string token;
	if (file_line != "") {
		while ((pos = file_line.find(delimiter)) != std::string::npos) {
			token = file_line.substr(0, pos);
			details.push_back(token);
			file_line.erase(0, pos + delimiter.length());
		}
		details.push_back(file_line);
		
		this->name=details.at(0);
		this->SSN = details.at(1);
		this->age =stoi( details.at(2));
		int _diagnosis = stoi(details.at(3));
		this->diagnosis = Diagnosis(_diagnosis);

	}
}

std::string Patient::ToFormattedString()
{
	return std::string();
}
