#include <string>
#include <iostream>
#include "cxxopts.hpp"
using std::cout;
using std::endl;
int main(int argc, char ** argv) {
	bool compile = false;
	bool outPutCorrs = false;
	std::string corrOutName;
	cxxopts::Options options("TestCxxopts", "App to test the usage of cxxopts");
	options.add_options()
		("f,file", "File", cxxopts::value<std::string>())
		("c,correspondences", "File", cxxopts::value<std::string>());
	std::string fileName;
	
	try
	{
		auto result = options.parse(argc, argv);
		fileName = result["f"].as<std::string>();
		if (result.count("c"))
		{
			outPutCorrs = true;
			corrOutName = result["c"].as<std::string>();
		}
	}
	catch (const cxxopts::OptionException& e)
	{
		std::cout << "error parsing options: " << e.what() << std::endl;
		cout << options.help();
		exit(1);
	}
	cout << fileName << endl;
	cout << outPutCorrs << endl;
	if (outPutCorrs)
	{
		cout << corrOutName << endl;
	}

}