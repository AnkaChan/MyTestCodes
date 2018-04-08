#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

std::string standardSlash(std::string oPath) {
	std::replace(oPath.begin(), oPath.end(), '\\', '/');
	return oPath;
}

struct FileParts
{
	std::string path;
	std::string name;
	std::string ext;
};

FileParts fileparts(std::string filename)
{
	std::replace(filename.begin(), filename.end(), '\\', '/'); // replace all '\' to '/', fuck Microsophtte

	int idx0 = filename.rfind("/");

	int idx1 = filename.rfind(".");

	FileParts fp;
	fp.path = filename.substr(0, idx0 + 1);
	fp.name = filename.substr(idx0 + 1, idx1 - idx0 - 1);
	if (idx1 != -1) {
		fp.ext = filename.substr(idx1);
	}
	else
	{
		fp.ext = "";
	}

	return fp;
}

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv) {
	std::string name(".C");

	FileParts fp = fileparts(name);

	cout << fp.path << std::endl;
	cout << fp.name << std::endl;
	cout << fp.ext << std::endl;

	getchar();
}