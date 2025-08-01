#include <iostream>
#include <cmath>
#include <windows.h>
#include <fstream>
using namespace std;
void savehistory(string operation , double num1 , double num2, double result){
	ofstream file ("calculator_history.txt", ios::app); //Don't delete the prev cal just add new cal at the end of the file
	if (!file.is_open()){
		cout<<"Error: Could not open history file!.... "<<endl;
		return ;
	}
		file <<operation <<" : "<<num1;
		if(num2 !=0 ) file <<" , "<<num2 ;
		file <<" = "<<result <<endl;
		file.close();
	
}
void clearhistory() {
    ofstream file("calculator_history.txt", ios::trunc); //Open this file and truncate (erase) all its contents
    file.close();
    cout << "History cleared successfully!" << endl;
    Sleep(2000);
}


void show_calculator(double currentvalue = 0.0, bool showcurrent = false) {
    system("cls");
    cout<<"-----------------------------------------"<<endl;
    cout<<"--                                     --"<<endl;
    if(showcurrent) {
        cout<<"--     CURRENT VALUE:      "<<currentvalue<<endl;
        cout<<"--                                     --"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    else {
        cout<<"--                                     --"<<endl;
        cout<<"---       SCIENTIFIC  CALCULATOR      ---"<<endl;
        cout<<"--                                     --"<<endl;  
        cout<<"-----------------------------------------"<<endl;
    }
    cout<<"-      +     |      -      |      *     -"<<endl;
    cout<<"-     Add    |    Minus    |  Multiply  -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      /     |      m      |      l     -"<<endl;
    cout<<"-   Divide   |     Mod     |     Log    -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      S     |      C      |      p     -"<<endl;
    cout<<"-    Square  |    Cube     |    Power   -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      s     |      c      |      t     -"<<endl;
    cout<<"-     sin    |     cos     |     tan    -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      i     |      o      |      n     -"<<endl;
    cout<<"-    asin    |    acos     |    atan    -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      !     |      r      |      u     -"<<endl;
    cout<<"-  Factorial |  sq root    | Unit Conv  -"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-      k     |      .      |      h     -"<<endl;
    cout<<"-    Clear   |   close     |   history  -"<<endl;
    cout<<"-----------------------------------------"<<endl;

}

void show_unit_conversions() {
    system("cls");
    int choice;
  
	
    cout<<"-----------------------------------------"<<endl;
    cout<<"--                                     --"<<endl;
    cout<<"--          UNIT CONVERSIONS           --"<<endl;
    cout<<"--                                     --"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"- 1. Celsius to Fahrenheit            -"<<endl;
    cout<<"- 2. Fahrenheit to Celsius            -"<<endl;
    cout<<"- 3. Degrees to Radians               -"<<endl;
    cout<<"- 4. Radians to Degrees              -"<<endl;
    cout<<"- 5. Centimeters to Meters            -"<<endl;
    cout<<"- 6. Meters to Centimeters            -"<<endl;
    cout<<"- 7. Kilograms to Grams               -"<<endl;
    cout<<"- 8. Grams to Kilograms               -"<<endl;
    cout<<"- 0. Back to Calculator               -"<<endl;
    cout<<"-----------------------------------------"<<endl;
do{

   cout << "Enter choice (0-8): ";
    cin >> choice;
    
    if(choice == 0) return;
    
    double value;
    cout << "Enter value: ";
    cin >> value;
    
    double result;
    string conversion_name;
    
    switch(choice) {
        case 1:
            result = (value * 9.0/5) + 32;
            conversion_name = "CONV C to F";
            break;
        case 2:
            result = (value - 32) * 5.0/9;
            conversion_name = "CONV F to C";
            break;
        case 3:
            result = value * (3.1415 / 180);
            conversion_name = "CONV deg to rad";
            break;
        case 4:
            result = value * (180 / 3.1415);
            conversion_name = "CONV rad to deg";
            break;
        case 5:
            result = value / 100.0;
            conversion_name = "CONV cm to m";
            break;
        case 6:
            result = value * 100.0;
            conversion_name = "CONV m to cm";
            break;
        case 7:
            result = value * 1000.0;
            conversion_name = "CONV kg to g";
            break;
        case 8:
            result = value / 1000.0;
            conversion_name = "CONV g to kg";
            break;
        default:
            cout << "Invalid choice!" << endl;
            Sleep(2000);
            return;
    }
    
    cout << value << " to " << result << endl;
    savehistory(conversion_name, value, 0, result);  // num2 is 0 for conversions
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
	}  while (true);
  
}

double calculate_factorial(int n) {
    if(n < 0) return NAN; 
    double result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void showhistory()	{
	system ("cls");
	cout << "-----------------------------------------" << endl;
    cout << "--                                     --"<<endl;
    cout << "--          CALCULATION HISTORY        --" << endl;
    cout << "--                                     --" << endl;
    cout << "-----------------------------------------" << endl;
	ifstream file ("calculator_history.txt");
	string line ;
	bool empty = true ;
	  while (getline(file, line)) {
	  			cout <<endl;
                cout << line << endl;
                empty= false;
            }
            file.close();
        if (empty ) cout <<" No history available ... "<<endl;
	cout << "\nPress 'x' to CLEAR HISTORY  or   Press 'ENTER' to RETURN...";
    char choice;
    cin.ignore(); // Clear  leftover newline
    choice = cin.get();

    if (choice == 'x' || choice == 'X') {
        clearhistory();
    }
			}
	
  
int main() {
    double num1 = 0.0;
    double num2 = 0.0;
    double answer = 0.0;
    char inp = '\n';
    bool use_previous_result = false;
    
    while(inp != '.') {
        if(use_previous_result) {
            show_calculator(answer, true);
            cout<<"Enter operation: ";
            cin>>inp;
            
            if(inp == 'u') {
                show_unit_conversions();
                continue;
            }
            else if (inp == 'h'){
            	showhistory();
            	continue;
           
			}

            else if(inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                num1 = answer;
                cout<<"Enter second number: ";
                cin>>num2;
            }
            else if(inp == 'k') {
                use_previous_result = false;
                continue;
            }
            else if(inp == '.') {
                break;
            }
            else {
                num1 = answer;
            }
        }
        else {
            show_calculator();
            cout<<"Enter operation: ";
            cin>>inp;
            
            if(inp == 'u') {
                show_unit_conversions();
                continue;
            }
            else if(inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                cout<<"Enter first number: ";
                cin>>num1;
                cout<<"Enter second number: ";
                cin>>num2;
            }
            else if(inp == 'k' || inp == '.') {
                if(inp == '.') break;
                continue;
            }
            else {
                cout<<"Enter number: ";
                cin>>num1;
            }
            
            use_previous_result = true;
        }
	string op;
        switch(inp) {
            case '+':  answer = num1 + num2;  op = " ADD " ; break;
            case '-':  answer = num1 - num2;  op = " SUBTRACT " ;  break;
            case '*':  answer = num1 * num2;  op = " MULTIPLY " ; break;
            case '/':
			 if (num2 != 0) answer = num1 / num2;
                else answer = NAN;
                op = " DIVIDE " ; 
                break;
            case 'm':
                if (int(num2) != 0){
                	    answer = int(num1) % int(num2); 	}
               else    
			        answer = NAN;
			  op = " MODULUS " ; 
                break;
            case 'l':
            	if(num1 <=0 )  {   answer= NAN;  }
             else {  answer = log(num1);	 }  
                op = " LOG " ; 
                break;
            case 'S':
                answer = num1 * num1;
                op = " SQUARE " ; 
                break;
            case 'C':
                answer = num1 * num1 * num1;
                op = " CUBE " ; 
                break;
            case 'p':
                answer = pow(num1, num2);
                op = " POWER " ; 
                break;
            case 's':
                answer = sin(num1);
                op = " SIN " ; 
                break;
            case 'c':
                answer = cos(num1);
                op = " COS " ;
                break;
            case 't':
                answer = tan(num1);
                op = " TAN " ;
                break;
            case 'i':
            	cout<<"Enter values between -1 and +1 "<<endl;
                answer = asin(num1);  //inv of sin
               op = " INV SIN " ; 
                break;
            case 'o':
            	cout<<"Enter values between -1 and +1 "<<endl;
                answer = acos(num1);
                op = " INV COS " ; 
                break;
            case 'n':
                answer = atan(num1);
                op = " INV TAN " ;
                break;
            case '!':
                answer = calculate_factorial(int(num1));
                op = " FACTORIAL " ;
                break;
            case 'r':
                answer = sqrt(num1);
                op = " SQR ROOT " ;
                break;
            case 'k':
                use_previous_result = false;
                break;
            case '.':
                break;
            default:
                cout<<"Invalid Operation!!!  "<<endl;
                Sleep(2000);
        }

        if(isnan(answer)) {
            cout<<"Invalid Mathematical Operation!!!  "<<endl;
            Sleep(2000);
            use_previous_result = false;
        }
        else {
            cout<<"Result: "<<answer<<endl;
            savehistory(op , num1, num2, answer);
           // use_previous_result = true;
            Sleep(1000);
        }
    }
    
    return 0;
}
