#include <cstdlib>
#include <exception>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;



int main(int argc, char* argv[]){

	try{
		int tree_depth = std::stoi(argv[1]);
		std::cout<<"Tree depth: "<< tree_depth << "\n";

	} 
	catch (const std::exception& e){
		std::cerr << "no argumets given, expected 1";
		std::exit(EXIT_FAILURE);
	}
	for (const auto& entry : fs::directory_iterator("..")) {
		if (entry.is_directory()){
			std::cout << "├────" << entry.path().filename().string() << std::endl;
		}
	}
	
}
