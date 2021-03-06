#include "readFromFile.hpp"
using namespace std;

inline std::string file_to_string(const std::string & filename) {
    std::ifstream text(filename);
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

inline std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
}
