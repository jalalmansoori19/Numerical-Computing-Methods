#include <bits/stdc++.h>
#include "functions.cpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {

	double xi=0.0;
    int key=0;
    int funcKey=0;

	display();
/*
	showInterval();

	cout<<"Enter Guess Value in Between [0,1] : ";
	cin>>xi;
*/
	//newtonRaphson(xi);
	//secantMethod(xi);
	//bisectionMethod();
	//regularFalsiMethod();
	//fixedPointIter(xi);

    cout<<"\n\nEnter Key and Press Enter : ";
    cin>>key;

    switch(key)
    {
        case(1):
        {
                int degree=0;
                system("cls");
                display2();

                cout<<"Enter Degree of Polynomial Function : ";
                cin>>degree;

                Polynomial(degree);

                displayKey();

                int key=0;
                cout<<"\n\nEnter Key  and Press   Enter: ";
                cin>>key;

                if(key == 3)
                {
                    system("cls");
                   main(argc,  argv);
                }
                else if(key == 0)
                {
                    exit(0);
                }
                else
                {
                    cout<<"Invalid Key";
                }


                break;
        }

        case(2):
        {
                system("cls");
                display2();

                bisectionMethod();
                regularFalsiMethod();

                cout<<"Enter Guess Value in Between [0,1] : ";
                cin>>xi;

                fixedPointIter(xi);
                newtonRaphson(xi);
                secantMethod(xi);

                displayKey();

                int key=0;
                cout<<"\n\nEnter Key  and Press   Enter: ";
                cin>>key;

                if(key == 3)
                {
                    system("cls");
                   main(argc,  argv);
                }
                else if(key == 0)
                {
                    exit(0);
                }
                else
                {
                    cout<<"Invalid Key";
                }

                break;
        }

        case(0):
        {
                exit(0);
                break;
        }

    }


	return 0;
}
