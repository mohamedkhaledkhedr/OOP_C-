#include<iostream>
using namespace std;
class Time{
private:
    int hour;
    int minute;
    string am_or_pm;

public:
    Time(){         ///default constructor
        hour=0;
        minute=0;
        const string &am_or_pm = " ";

    }
    Time(int h, int m, string &am_or_pm):hour(h), minute(m){
            if (am_or_pm == "AM"||am_or_pm == "am" && hour == 12)
                      hour = 0;
            if (am_or_pm == "PM"||am_or_pm == "pm" && hour != 12)
                      hour += 12;
    }
    void print_time24(){
           cout << hour << ':' << minute ;
    }

    void print_time12(){
            if (hour == 0 || hour == 12)
                cout << "12";
            else
                cout << hour % 12;
                cout << ':' << minute %60 ;

            if (hour / 12 == 0)
                cout << " AM";
            else
                cout << " PM";
}
bool operator== (Time &t){
    if(hour==t.hour && minute==t.minute && am_or_pm==t.am_or_pm){
        return true;
    }
    else
        return false;
}
bool operator!= (Time &t){
    return !(hour==t.hour && minute==t.minute && am_or_pm==t.am_or_pm);
}
bool operator> (Time &t){
    if (hour > t.hour || minute > t.minute){
        cout<<endl<< "the first Time > the second Time "<<endl;
        return true;
    }
    else
        return false;
}
bool operator< (Time &t){

    if (hour < t.hour || minute < t.minute){
        cout<<endl<< "the first Time < the second Time "<<endl;
        return true;
    }
    else
        return false;

}


    friend istream& operator>>(istream& in, Time& time);
    friend ostream& operator<<(ostream& out, Time time);
};

istream& operator>>(istream& in, Time& time){
    in>>time.hour;
    in>>time.minute;


    return in;
}
ostream& operator<<(ostream& out, Time time){
    out<<time.hour;
    out<<time.minute;

    return out;
}



int main()
{
    int option;
    cout << "(1. 12 hr format 2. 24 hr format) "<<endl<<endl;
    cout << "Enter the time: ";
    int hour, minute;
    cin >> hour >> minute;
    string am_or_pm;
    cin >> am_or_pm;
    cout<<endl<<endl;

    Time t(hour, minute, am_or_pm);
    t.print_time12();
    cout << '\n';
    t.print_time24();
    cout << '\n';

    cout << "\n\n(1. 12 hr format 2. 24 hr format) "<<endl<<endl;
    cout << "Enter the time: ";
    int hour1, minute1;
    cin >> hour1 >> minute1;
    cin >> am_or_pm;
    cout<<endl<<endl;

    Time s(hour1, minute1, am_or_pm);
    s.print_time12();
    cout << '\n';
    s.print_time24();
    cout << '\n';
    cout<<endl<<endl;
    cout << "Time1 == Time2 ?\n";
    cout << ((t == s) ? "true\n\n" : "false\n\n");
    cout << "Time1 != Time2 ?\n";
    cout << ((t != s)? "true\n\n" : "false\n\n");
    cout << "Time1 > Time2 ?\n";
    cout << ((t > s)? "true\n\n" : "false\n\n");
    cout << "Time1 < Time2 ?\n";
    cout << ((t < s)? "true\n\n" : "false\n\n");



    return 0;
}
