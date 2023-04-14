#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <map>
#include <string>

namespace tools {
bool isValidDate(std::string& date);
float stringStreamToFloat(std::stringstream& ss);
void skipLine(std::ifstream& ifs);
void printDatabase(std::map<std::string, float>& database);

class invalidFloat : std::exception {
 public:
  invalidFloat();
  ~invalidFloat() throw();
};

}  // namespace tools

#endif