#include <iostream>
#include <filesystem>
#include <string>

int main() {

	std::cout << "Running test ..." << std::endl;

	std::string path = "assignment_testcases";

  std::cout << "Assignment test cases found:" << std::endl;
	for (const auto & entry : std::filesystem::directory_iterator(path)){
        std::cout << entry.path() << std::endl;
	}
	

}
