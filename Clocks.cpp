#include <bits/stdc++.h>
#include <time.h>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int hour_24[24], hour_12[24], minute[60], second[60];

int hr24 , hr12 , minu , sec ;

bool end = false;

void waitToQuit(int time)
{
    clock_t endWait;
    bool noInput = true;
    endWait = clock() + time;
    while (clock() <= endWait && noInput)
    {
        if (kbhit())
        {
            end = true;
            noInput = false;
        }
    }
}

void stringToInt(string str)
{
    int hr = 0;
    hr += str[1] - 48;
    hr += (str[0] - 48) * 10;
    hr24 = hr;

    int m = 0;
    m += str[4] - 48;
    m += (str[3] - 48) * 10;
    minu = m;

    int s = 0;
    s += str[7] - 48;
    s += (str[6] - 48) * 10;
    sec = s;
}

int main()
{
    system("CLS");
    hour_12[0] = 12;
    for (int index = 1; index < 24; index++)      // Filling hour index 
    {
        hour_24[index] = index;
        if (index > 12)
        {
            hour_12[index] = index - 12;
        }
        else
        {
            hour_12[index] = index;
        }
    }

    for (int index = 0; index < 60; index++)      // Filling minute and second index
    {
        minute[index] = index;
        second[index] = index;
    }

    time_t timetoday;      				
    time(&timetoday);
    string str = asctime(localtime(&timetoday));

    str = str.substr(11, 17);

    stringToInt(str);

    int hour_index = 0, min_index = 0, sec_index = 0;
    while (hour_24[hour_index] != hr24)
    {
        hour_index++;
    }
    
    while (minute[min_index] != minu)
    {
        min_index++;
    }
    
    while (second[sec_index] != sec)
    {
        sec_index++;
    }
    

    bool Exit = false;
    while (Exit != true)
    {
    	string meridiam = "A M";
        system("CLS");
        if (sec_index == 59)
        	{
            	sec_index = 0;

            	if (min_index == 59)
            	{
                	min_index = 0;

                	if (hour_index == 23)
                    	hour_index = 0;
               	 	else
                    	hour_index++;
            	}
            	else
                	min_index++;
        	}
        	else
            	sec_index++;
            	
        cout<<"\n\n\n\t\t**************************\t\t**************************\n";
        cout<<"\t\t*      12-Hour Clock     *\t\t*      24-Hour Clock     *\n";
        cout<<"\t\t*      "<< ((hour_index >0 && hour_index<10 || hour_index>12 && hour_index<22 ) ? "0" : "");
        cout << hour_12[hour_index] << ":";
        if(hour_index>=12){
			meridiam = "P M";
		}
		cout<<((min_index < 10 ) ? "0" : ""); 
		cout<< minute[min_index] << ":" ;
		cout<<((sec_index < 10 ) ? "0" : "");
		cout<< second[sec_index]<<" "<<meridiam;
		cout<<"      *\t\t*        ";
		cout<< ((hour_index < 10 ) ? "0" : "");
        cout<< hour_24[hour_index] << ":" ;
        cout<<((min_index < 10 ) ? "0" : ""); 
		cout<< minute[min_index] << ":";
		cout<<((sec_index < 10 ) ? "0" : "");
		cout << second[sec_index]<<"        *" << "\n";
        cout<<"\t\t**************************\t\t**************************\n";
        end = false;
        waitToQuit(980);

        if (end)
        {
            int user_input;
            system("CLS");
            cout << "\n\n\n\t\t\t\t**************************\n";
            cout << "\t\t\t\t* 1-Add One Hour         *\n";
            cout << "\t\t\t\t* 2-Add One Minute       *\n";
            cout << "\t\t\t\t* 3-Add One Second       *\n";
            cout << "\t\t\t\t* 4-Exit Program         *\n";
            cout << "\t\t\t\t**************************";
            
            cin >> user_input;
            switch (user_input)
            {
            case 1:
            {
                if (hour_index == 23)
                    hour_index = 0;
                else
                    hour_index++;
                break;
            }
            case 2:
            {
                if (min_index == 59)
                {
                    min_index = 0;

                    if (hour_index == 23)
                        hour_index = 0;
                    else
                        hour_index++;
                }
                else
                    min_index++;
                break;
            }
            case 3:
            {
                if (sec_index == 59)
                {
                    sec_index = 0;

                    if (min_index == 59)
                    {
                        min_index = 0;

                        if (hour_index == 23)
                            hour_index = 0;
                        else
                            hour_index++;
                    }
                    else
                        min_index++;
                }
                else
                    sec_index++;
                break;
            }
            case 4:
            {
                Exit = true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    return 0;
}

