#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <string>

static const std::ios_base::iostate FailMask = std::ios_base::eofbit | std::ios_base::badbit;

void  ClearLine(std::istream &input_stream)
{
  input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::ios_base::iostate  HandleBadStream(std::istream &input_stream)
{
  std::ios_base::iostate state = input_stream.rdstate();

  if (input_stream.eof())
  {
    return state;
  }
  else if (input_stream.fail())
  {
    std::cerr << "Invalid input. Please try again: ";
    input_stream.clear();
    ClearLine(input_stream);
  }
  else if (input_stream.bad())
  {
    std::cout << "Fatal error" << std::endl;
  }
  return state;
}

template <typename T>
int GetInput(T &n, std::ios_base::fmtflags flags)
{
  while (true)
  {
    std::cin >> std::setiosflags(flags) >> n;
    if (std::cin.good())
      break;
    else if ((HandleBadStream(std::cin) & FailMask) > 0)
      return EXIT_FAILURE;
  }
  ClearLine(std::cin);
  return EXIT_SUCCESS;
}

int main() {
  char indicator;
  const std::string prompt = "Enter a number as integer or float: ";

  std::cout << prompt;
  std::cin >> indicator;
  if (indicator == 'f')
  {
    float value;

    GetInput(value, std::ios_base::floatfield | std::ios_base::showpoint);
    std::cout << "float: " << value << std::endl;
  }
  else
  {
    int value;

    std::cin.putback(indicator);
    GetInput(value, std::ios_base::basefield | std::ios_base::showbase);
    std::cout << "integer: " << value << std::endl;
  }

  return 0;
}