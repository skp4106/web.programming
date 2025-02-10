// Pick up any one of the functions and start editing if you feel necessary
/* Issues with the code
1 not a good application of inheritance
2 no polymorphism
3 no file handling
4 functions ae not well thought
5 complete plagarism */
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class person {
protected:
  string name;
  int phoneNo;
};

class shop : public person {
protected:
  int pCode;
  float price;
  string pName;
  float dis;

public:
  void menu();         // Main Menu
  void admin();        // Menu For the Admin
  void buyer();        // Menu For the Buyer
  void add();          // Add Products in the Store
  void edit();         // Edit Number of Products in the Store
  void remove();       // Remove Products in the Store
  void enterDetails(); // Enter User Details(Name and Phone Number)
  void diplayList();   // Enter the Products available for the Customer to buy
  void buy(); // Function for the Customer to add products to the cart and later
              // buy it
  void receipt(); // Print a receipt for all the products bought

  // Add any function if required
};

void shop ::menu() {
m:
  int choice;

  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|             Retail Management Menu                 |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|____________________________________________________|\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     1)Admin                                        |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     2)Buyer                                        |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     3)Exit                                         |\n";
  cout << "\t\t\t\t|____________________________________________________|\n";

  cout << "\t\t\t\t Please select option(1-3): ";
  cin >> choice;

  switch (choice) {
  case 1: {
    admin();
    break;
  }

  case 2: {
    buyer();
    break;
  }

  case 3: {
    exit(0);
  }

  default: {
    cout << "\t\t\t\t Please Enter a valid option. ";
  }
  }

  goto m;
}

void shop ::admin() {
m:
  int choice;
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\n\n\t\t\t     Admin Menu\n";
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t    1)Add the Product\n";
  cout << "\t\t\t    2)Modify the Product\n";
  cout << "\t\t\t    3)Delete the Product\n";
  cout << "\t\t\t    4)Back to main menu\n";

  cout << "\t\t\t\t Please select option(1-4): ";
  cin >> choice;

  switch (choice) {
  case 1: {
    add();
    break;
  }

  case 2: {
    edit();
    break;
  }

  case 3: {
    remove();
    break;
  }
  case 4: {
    menu();
  }

  default: {
    cout << "\t\t\t\t Please Enter a valid option. ";
  }
  }

  goto m;
}
void shop::buyer() {
m:
  int choice;
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\n\n\t\t\t     Buyer Menu\n";
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t    1)Buy the Product\n";
  cout << "\t\t\t    2)Back to main menu\n";

  cout << "\t\t\t\t Please select option(1-2): ";
  cin >> choice;
  switch (choice) {
  case 1: {
    receipt();
    break;
  }

  case 2: {
    menu();
    break;
  }

  default: {
    cout << "\t\t\t\t Please Enter a valid option. ";
  }
  }
  goto m;
}

void shop ::add() {
  fstream data;
  int c;
  int token = 0;
  float p;
  float d;
  string n;

  cout << "\n\n\t\t\t Add New Product";
  cout << "\n\n\t Product code of the product";
  cin >> pCode;
  cout << "\n\n\t  Name of the product ";
  cin >> pName;
  cout << "\n\n\t Price of the product";
  cin >> price;
  cout << "\n\n\t Discount on product";
  cin >> dis;

  data.open("database.txt", ios::in);

  if (!data) {
    data.open("database.txt", ios::app | ios::out);
  }
}

void shop::edit() {
  fstream data, data1;
  int pKey;
  int token = 0;
  int c;
  float p;
  float d;
  string n;
  cout << "\nt\t\t Modify the Record";
  cout << "\nt\t\t Product code";

  cin >> pKey;
  data.open("database.txt", ios::in);
  if (!data) {
    cout << "\n\nFile does not exist!";
  } else {
    data1.open("database1.txt", ios::app | ios::out);
    data >> pCode >> pName >> price >> dis;
    while (!data.eof()) {
      if (pKey == pCode) {
        cout << "\n\t\t Product new code:";
        cin >> c;
        cout << "\n\t\t Name of the product:";
        cin >> n;
        cout << "\n\t\t price";
        cin >> p;
        cout << "\n\t\t Discount";
        cin >> d;
        data1 << " " << c << " " << n << " " << p << " " << d << " " << endl;
        cout << "\n\n\t\t Record edited";
        token++;
      } else {
        data1 << " " << pCode << " " << pName << " " << price << " " << dis
              << endl;
      }
      data >> pCode >> pName >> price >> dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");
    if (token == 0) {
      cout << "\n\n Record not fount sorry";
    }
  }
}

void shop ::receipt() {
  int arrPcode[100];
  int arrPQuantity[100];
  int counter = 0;
  float amount = 0;
  int bProducts;
  cout << "kindly enter the total no of different products";
  cin >> bProducts;

  for (int i = 0; i < bProducts; i++) {
    cout << "enter product code";
    cin >> arrPcode[i];
    cout << "enter product quantity";
    cin >> arrPQuantity[i];
  }
  for (int i = 0; i < bProducts; i++) {
    if (arrPcode[i] == pCode[i]) {
      amount = amount + arrPQuantity[i] * price;
    }
  }
  cout << "\n\n\t\t\t\t  RECEIPT";
  cout << "=================================================";
  cout << "\n\n\t\t\t\t\t\t\t\t";
  cout << "\n\n\n";
  auto currentTime =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << "Time and Date: " << std::ctime(&currentTime);
  cout << "\n\n\n";

  cout << "\t\t  SNO.  \t\t  PRODUCT  \t\t  QUANTITY                \t\t  "
          "PRICE\n\n";

  for (int i = 0; i <= bProducts; i++) {
    cout << " \t\t " << i + 1 << "  \t\t  " << pName << " \t\t "
         << arrPQuantity[i] << " \t\t " << arrPQuantity[i] * price << "\n";
  }
  cout << "\n\n";
  cout << "\t\t"
       << "Your total amount is:  " << amount;
}

int main() {
  shop s;
  s.menu();
  return 0;
}
