#include <iostream>
#include <string>

using namespace std;

string fixFilename(string filename) {
	size_t found = filename.find_last_of(".");
	if (found > filename.length()) {//no extension
		filename += ".temp";
	}
	else {
		string name = filename.substr(0, found);
		string extension = filename.substr(found);
		extension = extension == ".temp" ? ".tmp" : ".temp";
		filename = name + extension;
	}
	return filename;
}

void getPath(string& drive, string& directory, string& filename) {
	if (drive == "")
		drive = "c:";
	if (directory == "")
		directory = ".\\";
	filename = fixFilename(filename);
}

void input(string& drive, string& directory, string& filename) {
	cout << "Drive:\n";
	getline(std::cin, drive);
	cout << "Directory:\n";
	getline(std::cin, directory);
	cout << "Filename:\n";
	getline(std::cin, filename);
	getPath(drive, directory, filename);
}

void output(string drive, string directory, string filenam) {
	cout << "Drive:\n" << drive << "\n";
	cout << "Directory:\n" << directory << "\n";
	cout << "Filename:\n" << filenam << "\n";
}

int main() {
	string drive, directory, filename;
	input(drive, directory, filename);
	cout << "\n";
	output(drive, directory, filename);
	system("pause");
	return 0;
}