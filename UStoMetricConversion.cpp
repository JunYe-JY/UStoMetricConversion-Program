#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

void get_input(int &pounds, double &ounces);

void convert_from_pounds_and_ounces_to_kilograms_and_grams(int pounds, int &kilograms, double ounces, double &grams);

void print_output(int pounds, int kilograms, double ounces, double grams);

int main() {
  int pounds, kilograms;
  double ounces, grams;

  get_input(pounds, ounces);
  convert_from_pounds_and_ounces_to_kilograms_and_grams(pounds, kilograms, ounces, grams);
  print_output(pounds, kilograms, ounces, grams);

  return 0;
}

void get_input(int &pounds, double &ounces) {
  do {
    cout << "Please enter the number of pounds: ";
    cin >> pounds;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (pounds <= 0); 
     
  do {
    cout << "Please enter the number of ounces: ";
    cin >> ounces;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (ounces <= 0 || ounces > 16);
  
}

void convert_from_pounds_and_ounces_to_kilograms_and_grams(int pounds, int &kilograms, double ounces, double &grams)
{
  const int pounds_to_ounces = 16;
  const double pounds_to_kilograms = 0.45359237;
  const int kilograms_to_grams = 1000;

  double total_pounds = pounds + ounces / pounds_to_ounces;
  double total_kilograms = total_pounds * pounds_to_kilograms;
  double total_grams = total_kilograms * kilograms_to_grams;
  kilograms = (int)floor(total_kilograms);
  grams = total_grams - kilograms * kilograms_to_grams;
}

void print_output(int pounds, int kilograms, double ounces, double grams){
  cout << "-------------------------------------------------------------------------------------------" << endl;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(8);
  cout << pounds << " pounds and " << ounces << " ounces convert to \n"
    << kilograms << " kilograms and " << grams << " grams" << endl;
  cout << "-------------------------------------------------------------------------------------------" << endl;
}
