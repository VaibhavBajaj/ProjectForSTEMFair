// Updated on September 30, 2016 by Osato-san and Vaibhav

#include <iostream>
using namespace std;

class reader {
    double inputDouble;
    string inputStr;
    public:
    //only accepts double
    double doubleOnly() {
        bool valid = true;
        int pointCount = 0;
        getline(cin, inputStr);
        for (int i = 0; i < inputStr.length(); i++) {
            if(inputStr[i] == '.') {
                pointCount++;
                if(pointCount >= 2) {
                    valid = false;
                    break;
                }
            }
            else if(!(inputStr[i] >= '0' && inputStr[i] <= '9'))
            {
                valid = false;
                break;
            }
        }
        if(!valid) {
            cout << "Please enter a valid number" << endl;
            inputDouble = doubleOnly();
        }
        else
        {
            inputDouble = stod(inputStr);
        }
        return inputDouble;
    }
    //converts to lowercase
    string stringInLower() {
        getline(cin, inputStr);
        // Convert s to lowercase using ASCII values
        for (int i = 0; i < inputStr.length(); i++) {
            if(int(inputStr[i]) <= 90)
                inputStr[i] += 32;
        }
        return inputStr;
    }
};

int main() {
    string ans, name;
    double income, foodExp, rentExp = 0, electricExp = 0, waterExp, totalExp, savings, utilitiesExp = 0, loanExp = 0, tuitionExp = 0, bookExp = 0, lifeInsurance = 0, healthInsurance = 0, petrolExpenditure = 0, taxiExpenditure = 0, carInsurance = 0;
    bool isRentComposite = false;
    reader input;
    cout << "Hello! What is your name?" << endl;
    getline(cin, name);
    cout << "Welcome, " << name << " to the STEM fair budget app."<< endl << "Please give a few deatils regarding your financial situation: " << endl;
    
    /*~~~~INPUTING VALUES~~~~*/
    // Income expenditure
    cout << "Begin by entering your annual income." << endl;
    income = input.doubleOnly();
    // Food expenditure
    cout << "What are your estimated expenses on food each month in dollars?" << endl;
    foodExp = input.doubleOnly() * 12;
    // Rent expenditure
    cout << "Do you pay rent for the property you reside in? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while(!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if(ans == "yes") {
        cout << "What is the cost of your monthly rent?" << endl;
        rentExp = input.doubleOnly() * 12;
        cout << "Does this include both electricity and water bills? Please answer in a simple Yes or No." << endl;
        ans = input.stringInLower();
        while(!(ans == "yes" || ans == "no"))
        {
            cout << "Please enter Yes or No: ";
            ans = input.stringInLower();
        }
        if(ans == "yes") {
            isRentComposite = true;
        }
    }
    if(!isRentComposite)
    {
        // Electricity expenditure
        cout << "What has your electric bill been for the past three months?" << endl;
        for (int i = 0; i < 3; i++ ) {
            cout << "Month " << i + 1 << ": ";
            electricExp += input.doubleOnly() * 4;
        }
        // Water expenditure
        cout << "What is your water bill for the past three months?" << endl;
        for (int i = 0; i < 3; i++ ) {
            cout << "Month " << i + 1 << ": ";
            waterExp += input.doubleOnly() * 4;
        }
    }
    // Phone expenditure
    cout << "Do you have a phone plan, internet plan, or cable plan? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while(!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if(ans == "yes") {
        cout << "How much do you pay on these plans monthly?" << endl;
        utilitiesExp = input.doubleOnly();
        utilitiesExp *= 12;
    }
    // School expenditure
    cout << "Are you a college student? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while (!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if (ans == "yes") {
        cout << "How much did you pay, out of pocket, for college tuition this year?" << endl;
        tuitionExp = input.doubleOnly();
        cout << "And how much do you pay for books every year?" << endl;
        bookExp = input.doubleOnly();
    }
    // Health Insurance Expenditure
    cout << "Do you have health insurance? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while (!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if (ans == "yes") {
        cout << "How much is your monthly health insurance payment?" << endl;
        healthInsurance = input.doubleOnly() * 12;
    }
    // Life Insurance Expenditure
    cout << "Do you have Life insurance? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while (!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if (ans == "yes") {
        cout << "How much is your monthly life insurance payment?" << endl;
        lifeInsurance = input.doubleOnly() * 12;
    }
    //Petrol and Car Insurance
    cout << "Do you own a car? Please answer in a simple Yes or No." << endl;
    ans = input.stringInLower();
    while (!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if (ans == "yes") {
        cout << "How much do you spend monthly on petrol? Please answer in a simple Yes or No." << endl;
        petrolExpenditure = input.doubleOnly() * 12;
        cout << "Do  you have car insurance?" << endl;
        ans = input.stringInLower();
        while (!(ans == "yes" || ans == "no"))
        {
            cout << "Please enter Yes or No: ";
            ans = input.stringInLower();
        }
        if (ans == "yes") {
            cout<< "How much do you pay monthly for the car insurance?" << endl;
            carInsurance = input.doubleOnly() * 12;
        }
    }
    else {
        cout << "How much do you spend monthly on uber, taxi or bicycle maintenance?" << endl;
        taxiExpenditure = input.doubleOnly() * 12;
    }
    // Loans Expenditure
    cout << "Do you have any loans you need to pay off? Please type Yes or No" << endl;
    ans = input.stringInLower();
    while(!(ans == "yes" || ans == "no"))
    {
        cout << "Please enter Yes or No: ";
        ans = input.stringInLower();
    }
    if(ans == "yes") {
        cout << "How much do you pay on your loans per month?" << endl;
        loanExp = input.doubleOnly();
        loanExp *= 12;
    }
    // Total expenditure
    totalExp = waterExp + electricExp + rentExp + foodExp + utilitiesExp + loanExp + tuitionExp + bookExp + lifeInsurance + healthInsurance + petrolExpenditure + taxiExpenditure + carInsurance;
    cout << "Your total expenditure is $" << totalExp << "." << endl;
    if (totalExp > income) {
        cout << name << ", you are incurring a loss of $" << (totalExp - income) << " annually. I recommend that you look into ways of reducing the cost of your water, food, rent and electricity. You should save try to save at least $" << (totalExp - income) / 12 << " each month."<< endl << "Good day, " << name << endl;
        
    }
    else {
        // Savings
        cout << "Considering that you have $" << income - totalExp << " left for the year, how much would you like to save anually?" << endl;
        savings = input.doubleOnly();
        while (savings > income - totalExp) {
            cout << "You seem to spend too much on water, food, rent and electricity to be able to save so much. Please enter a realistic savings considering the amount of money you have left for the year." << endl;
            savings = input.doubleOnly();
        }
        // Average budget per week
        cout << endl << "You may spend up to $" << (income - totalExp - savings) / 52 << " each week for luxuries such as going out for dinner, watching a movie or whatever other ways you have fun. Good day, " << name << endl;
    }
    return 0;
}
