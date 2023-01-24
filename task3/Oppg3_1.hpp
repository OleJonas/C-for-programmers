#include <string>

using namespace std;

const double tax = 1.5;

class Commodity {
  public:
    Commodity(const string &name, int id, double price);
    const string &get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(int units) const;
    void set_price(double new_price);
    double get_price_with_sales_tax(int units) const;
  private:
   string name;
   int id;
   double price;
};

Commodity::Commodity(const string &name, int id, double price) : 
    name(name), id(id), price(price) {}

const string &Commodity::get_name() const{
  return name;
}

int Commodity::get_id() const{
  return id;
}

double Commodity::get_price() const{
  return price;
}

double Commodity::get_price(int units) const{
  return units*price;
}

void Commodity::set_price(double new_price){
  price = new_price;
}

double Commodity::get_price_with_sales_tax(int units) const{
    return units*price*tax;
}