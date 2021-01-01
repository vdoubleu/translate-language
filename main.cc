#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

std::string replaceInLine(std::string line, std::unordered_map<std::string, std::string> &m) {
  std::string newLine = line;
  for (const auto mapping: m) {
    size_t index = 0;
    std::string toReplace = mapping.first;
    std::string replaceWith = mapping.second;

    while ((index = newLine.find(toReplace, index)) != std::string::npos) {
        newLine.replace(index, toReplace.length(), replaceWith);
        index += toReplace.length();
    }
  }

  return newLine;
}

std::vector<std::string> getFile(std::istream &f) {
  std::string currLine;
  std::vector<std::string> lines {};
  while (getline(f, currLine)) {
    lines.push_back(currLine);
  }
  return lines;
}

std::unordered_map<std::string, std::string> getMapping(std::istream &f) {
  std::string currLine;
  std::unordered_map<std::string, std::string> outMap {};
  while (getline(f, currLine)) {
    size_t pos = currLine.find(" ");

    if (pos == std::string::npos) {
      std::cerr << "invalid translate file, missing space seperator\n";
      throw;
    }

    std::string toReplace = currLine.substr(0, pos);
    std::string replaceWith = currLine.substr(pos + 1, currLine.length() - (pos + 1));

    outMap[toReplace] = replaceWith;
  }

  return outMap;
}

int main(int argc, char *argv[]) {
  // an example command call to translate would be:
  // tr <targetFile> <translateFile>

  // checks number of arguments is 3
  if (argc != 3) {
    std::cerr << "invalid number of arguments, call must follow this pattern: tr <translateFile> <targetFiles ...>\n";
    return 1;
  }

  std::ifstream translateF { argv[1] }; // second index is translate file
  std::unordered_map<std::string, std::string> translationMapping = getMapping(translateF);

  std::ifstream targetF { argv[2] }; // first index is target file
  std::vector<std::string> lines = getFile(targetF);

  std::vector<std::string> outVector {};
  for (std::string l : lines) {
    outVector.push_back(replaceInLine(l, translationMapping));
  }

  std::ofstream targetFOut { argv[1] };
  for (std::string l : outVector) {
    targetFOut << l << std::endl;;
  }
  
  return 0;
}
