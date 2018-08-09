# CPP
Implemented a simple patient record management system in C++ as console application. The program consists mainly of the Patient class. Each patient has a name, SSN, age, and diagnosis. 

1. The default constructor Patient() should ask the user to enter a name, SSN, age (as integer), and diagnosis (1 -5).
2. The copy constructor should copy all the patient attributes from the copy object.
3. The overloaded constructor Patient(std::string file_line) will accept a string which represents a string line from a file. The file_line string object is comma separated (e.g. John Smith,123-123-1234,39,1). You need to parse the line and initiate the object. You can use stringstream, string find, or strtok to split the string.
4. The method ToFormattedString is used to create a formatted string from a patient object and return it to be printed to the screen. For the previous example in (3), the string should be returned as: John Smith 123-123-1234 39 1
5. The overloaded operator << is a friend function that takes two parameters: an ostream object and a Patient object. It outputs the Patient object as a comma separated line to the stream object.

In addition to the Patient class methods, the file “Patient.cpp” should also implement two
helper functions:
1. read_patients_file: this method will open the file parse and for each line in the file, it
will create a new Patient object by passing the string line from the file to the
appropriate constructor in the Patient class.
2.  main_menu: this method will display a menu with 4 options:
a. Add patient: if this option is selected, then create a new Patient object by
calling the default constructor, add the object to the Patients array, and add
the patient to file object using the overloaded << operator.
b. View patient at specific index: This option will ask the user to enter a valid
index between 0 and patients_count - 1, and then it will call the method
ToFormattedString from the selected object to display it on the screen.
c. View all patients: Loop through all the objects between 0 and patient_count
and for each Patient object call the method ToFormattedString.
d. Exit: just display good bye message and exit the application
