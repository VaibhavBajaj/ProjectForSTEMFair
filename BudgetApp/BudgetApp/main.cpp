/*
 TODO:
 -- Enter income tax
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]){
    
    string ans, name;
    double income, foodExp, rentExp = 0, electricExp = 0, waterExp, bill, totalExp, budgetPerWeek, savings;
    int i;
    cout << "Hello! What is your name?" << endl;
    cin >> name;
    cout << "Welcome, " << name << " to the STEM fair budget app" << endl;
    cout << "Please answer a few questions regarding your financial situation" << endl;
    // Income expenditure
    cout << "Begin by entering your annual income." << endl;
    cin >> income;
    // Food expenditure
    cout << "What are your estimated expenses on food each week in dollars?" << endl;
    cin >> foodExp;
    foodExp *= 52;
    // Rent expenditure
    cout << "Do you pay rent for the property you reside in? Please answer in a simple Yes or No." << endl;
   while (true) {
       cin >> ans;
       // Convert ans to lowercase using ASCII values
       for (i=0; i < ans.length(); i++) {
           if(int(ans[i]) <= 90)
               ans[i] += 32;
       }
       if(ans == "yes" || ans == "no")
           break;
       else
           cout << "Please enter Yes or No to answer the question" << endl;
    }
    if(ans == "yes") {
        cout << "What is the cost of rent?" << endl;
        cin >> bill;
        rentExp = bill * 12;
    }
    // Electricity expenditure
    cout << "What is your electric bill for the past three months?" << endl;
    for ( i = 0; i < 3; i++ ) {
        cin >> bill;
        electricExp += bill;
    }
    electricExp *= 4;
    
    // Water expenditure
    cout << "What is your water bill for the past three months?" << endl;
    for ( i = 0; i < 3; i++ ) {
        cin >> bill;
        waterExp += bill;
    }
    waterExp*= 4;
    // Total expenditure
    totalExp = waterExp + electricExp + rentExp + foodExp;
    cout << "Your total expenditure is " << totalExp << endl;
    
    if (totalExp > income) {
        cout << "Sir, you are incurring a loss of " << (totalExp - income) / 12 << " each month. I recommend you look into ways of reducing the cost of your water, food, rent and electricity. Your budget per week for luxuries is 0." << endl;
    }
    else {
        // Savings
        cout << "Considering that you have " << income - totalExp << "money left for the year, how much would you like to save anually?" << endl;
        while (true) {
            cin >> savings;
            if( savings > income - totalExp)
                cout << "You seem to spend too much on water, food, rent and electricity to be able to save so much. Please enter a realistic savings considering the amount of money you have left for the year." << endl;
            else
                break;
        }
        // Average budget per week
        budgetPerWeek = (income - totalExp - savings) / 52;
        cout << "You may spend upto " << budgetPerWeek << " each week for luxuries such as going out for dinner, watching a movie or whatever other ways you have fun. Good day, " << name << endl;
    }
    return 0;
}
