#define DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int month, day, year;
    //array of month names
    string monthNames[12] = {"January", "February", "March",
                                    "April", "May", "June",
                                    "July", "August", "September",
                                    "October", "November", "December"};
public:
    //constructor
    Date(int m = 1, int d = 1, int y = 1970){
        //check invalid input for month
        if(m < 1 || m > 12){
            cout << "ERROR! Month can only be between 1-12!";
            cout << " Now terminating!\n";
            exit(1);
        }

        //check invalid input for day
        if(d < 1 || d > 31){
            cout << "ERROR! Day can only be between 1-31!";
            cout << " Now terminating!\n";
            exit(1);
        }

        month = m;
        day = d;
        year = y;
    }

    //getter functions
    int getMonth(){
        return month;
    }

    int getDay(){
        return day;
    }

    int getYear(){
        return year;
    }

    //setter functions
    void setMonth(int m){
        //check for invalid input
        if(m < 1 || m > 12){
            cout << "ERROR! Month can only be between 1-31!";
            cout << " Now terminating!\n";
            exit(1);
        }
        else{
            month = m;
        }
    }

    void setDay(int d){
        //check for invalid input
        if(d < 1 || d > 31){
            cout << "ERROR! Day can only be between 1-12!";
            cout << " Now terminating!\n";
            exit(1);
        }
        else{
            day = d;
        }
    }

    void setYear(int y){
        year = y;
    }

    //printing functions
    void format1(){
        cout << month << "/" << day << "/" << year;
        cout << endl;
    }

    void format2(){
        //don't forget that index of monthNames array
        //starts from 0
        cout << monthNames[month-1] << " ";
        cout << day << ", " << year;
        cout << endl;
    }

    void format3(){
        //don't forget that index of monthNames array
        //starts from 0
        cout << day << " " << monthNames[month-1];
        cout << " " << year;
        cout << endl;
    }

};

