#include <iostream>
#include <string>
#include <memory>


/* This class represents a person with basic mailing information:
 * Name, address, city, zip code
 */
class Person {
protected:
	// Personal information fields
	std::string firstName;
	std::string lastName;
	std::string address;
	std::string city;
	std::string zip;
	// Parameterized constructor initializes attributes
	Person(std::string fn, std::string ln, std::string adr, std::string cty, std::string z)
	    : firstName(fn), lastName(ln), address(adr), city(cty), zip(z) {}

// Begin public methods
public:
    // Factory method to create a person object with attribute fields
	static std::unique_ptr<Person> createPerson(const std::string& fn, const std::string& ln,
	                                        const std::string& adr, const std::string& cty,
	                                        const std::string& z) {
	    return std::unique_ptr<Person>(new Person(fn, ln, adr, cty, z));
	}


    // Getter methods for individual attributes
	std::string getFirstName() const {
		return firstName;
	}

	std::string getLastName() const {
		return lastName;
	}

	std::string getAddress() const {
		return address;
	}

	std::string getCity() const {
		return city;
	}

	std::string getZip() const {
		return zip;
	}
    // Getter method for all attributes. Returns formatted string using all attributes
	std::string getAll() const {
	    return firstName + " " + lastName + ", " + address + ", " + city + ", " + zip;
	}

};


int main(int argc, char **argv) {
	// Creation of a person object
	std::unique_ptr<Person> person0 = Person::createPerson("Ongo", "Gablogian", "544 Mateo Street" , "Los Angeles", "90013");

	// Display person information
	std::cout << person0->getAll() << std::endl;

}