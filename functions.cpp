#include <bits/stdc++.h>
#include "functions.h"
using namespace std;

// functions definitions

int constant=-1;

void display()
{
	cout<<"****************************************************************************"<<endl;
    cout<<"\t\tNumerical Computing Methods to Solve NON_Linear Equations"<<endl;
    cout<<"****************************************************************************"<<endl;

    cout<<"Functions\t\t\tPress Key\n\n";
    cout<<"Polynomial\t\t\t1"<<endl;
    cout<<"Transendental\t\t\t2"<<endl;

    cout<<"\nExit\t\t\t\t0"<<endl;
}

double getFuncValue(double xi)
{
	double ans= (1/exp(xi)) - xi;
	ans=getNuminfourDecimal(ans);
	return( ans );
}
double getFuncDerivValue(double xi)
{
	return( -(1/exp(xi)) - 1);
}

double getNewValue(double xi)
{
	double ans= xi - ( getFuncValue(xi) / getFuncDerivValue(xi) );

	ans=getNuminfourDecimal(ans);

	return(ans);
}

void showInterval()
{
	cout<<"Real root lies between [0,1]"<<endl;
	cout<<"f(0) = "<<getFuncValue(0)<<endl;
	cout<<"f(1) = "<<getFuncValue(1)<<endl;
}

bool checkValue(double xi)
{
	if(xi >=0 && xi<= 1 )
	{
		return true;
	}
	return false;
}

void newtonRaphson(double xi)
{
    cout<<"\n\nNewton Raphson Method"<<endl;
    cout<<"**********************\n";


	int i=0;
	cout<<"\n\ni\t\txi\t\txi+1\n";

	for(i=0; i>=0; i++)
	{
		cout<<i<<"\t\t"<<xi<<"\t\t"<<getNewValue(xi)<<endl;
		xi=getNewValue(xi);
		if( xi == getNewValue(xi) )
		{
			break;
		}
	}

	cout<<i+1<<"\t\t"<<xi<<"\t\t"<<getNewValue(xi)<<endl;
	cout<<"\nSo Therefore Real Root of f(x)= e^-x -X is : "<<xi;
}

// Below function is from https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
float getNuminfourDecimal(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =37.6716    for rounding off value
    // then type cast to int so value is 3766
    // then divided by 100 so the value converted into 37.66
    float value = (int)(var * 10000 + .5);
    return (float)value / 10000;
}

double getNewSecantValue(double xi, double prev)
{
	double ans=0.0;
	ans= xi - ( (xi - prev) / ( getFuncValue(xi)  - getFuncValue(prev) ) ) * getFuncValue(xi);
	ans=getNuminfourDecimal(ans);

	return ans;
}

void secantMethod(double xi)
{
    cout<<"\n\nSecant Method"<<endl;
    cout<<"**********************\n";

	int i=0;
    double prev=0.0, temp=0.0;
	cout<<"\n\ni\t\txi\t\txi+1\n";

	for(i=0; i>=0; i++)
	{
		cout<<i<<"\t\t"<<xi<<"\t\t"<<getNewSecantValue( xi,  prev)<<endl;
		temp=prev;
		prev=xi;
		xi=getNewSecantValue( xi,  temp);

		if( xi == getNewSecantValue( xi,  temp) )
		{
			break;
		}
	}

	cout<<i+1<<"\t\t"<<xi<<"\t\t"<<getNewSecantValue( xi,  temp)<<endl;
	cout<<"So Therefore Real Root of f(x)= e^-x -X is : "<<xi;
}

double getCValue(double a, double b)
{
	double ans = (a + b  )  / 2;
	ans=getNuminfourDecimal(ans);

	return ans;
}

void bisectionMethod()
{
    cout<<"Bisection Method"<<endl;
    cout<<"**********************\n";

	double error=0.0001;
	double a=0, b=1, c=0;
    double temp=0.0;

	cout<<"i\ta\tb\tf(a)\tf(b)\tc\tf(c)\n";
	for(int i=0; i>=0; i++)
	{
		c=getCValue( a,  b);
        temp=abs(getFuncValue(c));
		cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<getFuncValue(a)<<"\t"<<getFuncValue(b)<<"\t"<<c<<"\t"<<temp<<endl;
        //abs( getFuncValue(c) ) == error || abs( getFuncValue(c) ) == 0
        //
		if( fabs(temp - error) <= 0.001 * fabs(temp) )
		{

			cout<<"\nSo Therefore Real Root of f(x)= e^-x -X is : "<<c<<endl;
			break;
		}
		else if( (getFuncValue(c) * getFuncValue(b)) < 0 )
		{
			a=c;
		}
		else if( (getFuncValue(a) * getFuncValue(c)) < 0  )
		{
			b=c;
		}


	}

}

double getCFalsiValue(double a, double b)
{
	double ans = ( a*getFuncValue(b) - b*getFuncValue(a) ) / (getFuncValue(b) - getFuncValue(a) );

	ans=getNuminfourDecimal(ans);
	return ans;
}

void regularFalsiMethod()
{
    cout<<"\nRegular_Falsi Method"<<endl;
    cout<<"**********************\n";


	double error=0.0001;
	double a=0, b=1, c=0;
    double temp=0.0;

	cout<<"i\ta\tb\tf(a)\tf(b)\tc\tf(c)\n";
	for(int i=0; i>=0; i++)
	{
		c=getCFalsiValue( a,  b);
        temp=abs(getFuncValue(c));
		cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<getFuncValue(a)<<"\t"<<getFuncValue(b)<<"\t"<<c<<"\t"<<temp<<endl;

		if( fabs(temp - error) <= 0.001 * fabs(temp) )
		{

			cout<<"\nSo Therefore Real Root of f(x)= e^-x -X is : "<<c<<endl;
			break;
		}
		else if( (getFuncValue(c) * getFuncValue(b)) < 0 )
		{
			a=c;
		}
		else if( (getFuncValue(a) * getFuncValue(c)) < 0  )
		{
			b=c;
		}

	}

    cout<<"\nFixed Point Iteration Method"<<endl;
    cout<<"**********************\n";

}

double getGofX(double xi)
{
	double ans = 1 / (exp(xi) );

	ans= getNuminfourDecimal(ans);
	return (ans);
}

void fixedPointIter(double xi)
{
	int i=0;
	double temp=0.0, previous=0.0;
	cout<<"\n\ni\txi\tg(x)=e^-x\tError\n";

	for(int i=0; i>=0; i++)
	{
	    previous=xi;
		temp=getNuminfourDecimal( abs(getGofX( xi) - xi)  );
		cout<<i<<"\t"<<xi<<"\t"<<getGofX( xi)<<"\t\t"<<temp<<endl;
		xi=getGofX( xi);

		if( temp == 0.0001 )
		{
			break;
		}

	}

	//cout<<i+1<<"\t"<<xi<<"\t"<<getGofX(xi)<<endl;
	cout<<"\nSo Therefore Real Root of f(x)= e^-x is : "<<previous;
}

void display2()
{

    cout<<"****************************************************************************"<<endl;
    cout<<"\t\tNumerical Computing Methods to Solve NON_Linear Equations"<<endl;
    cout<<"****************************************************************************"<<endl;

}

void Polynomial(int degree)
{
    int size=degree;
    int coefficients[size];
    int power[size];

    for(int i=0; i<size; i++)
    {
        coefficients[i] = degree;
        power[i]=degree;
        degree -- ;
    }

    cout<<"Function is f(x)= ";

    for(int i=0; i<size; i++)
    {
        cout<<coefficients[i]<<"x^"<<power[i]<<"+";
    }

    cout<<"("<<constant<<")"<<endl;

    cout<<"Real Root lies between interval[0,1]"<<endl;

    bisectionForPoly( coefficients,  power, size);
    regularFalsiForPoly( coefficients,  power, size);

    double xi=0.0;

    cout<<"Enter Guess Value in Between [0,1] : ";
    cin>>xi;

    fixedPointIter( xi,  coefficients,  power, size);

    newtonRaphsonForPoly( xi, coefficients,  power,  size);

    secantMethodForPoly( xi,  coefficients,  power,  size);


}

double getPolyFuncValue(double xi, int coefficients[], int power[], int size)
{
    double ans=0.0;

    for(int i=0; i<size; i++)
    {
        ans=coefficients[i]*pow(xi, power[i])+ans;
    }

    ans=getNuminfourDecimal(ans);

    return (ans-1);
}

void bisectionForPoly(int coefficients[], int power[], int size)
{
   cout<<"Bisection Method"<<endl;
    cout<<"**********************\n";

	double error=0.0002;
	double a=0, b=1, c=0;
    double temp=0.0;

	cout<<"i\ta\tb\tf(a)\tf(b)\tc\tf(c)\n";
	for(int i=0; i>=0; i++)
	{


		c=getCValue( a,  b);
        temp=abs(getPolyFuncValue( c,coefficients, power, size));
		cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<getPolyFuncValue( a,coefficients, power, size)<<"\t"<<getPolyFuncValue( b,coefficients, power, size)<<"\t"<<c<<"\t"<<temp<<endl;

        //abs( getPolyFuncValue( c,coefficients, power, size) ) == error || abs( getPolyFuncValue( c,coefficients, power, size) ) == 0
        //fabs(temp - error) <= 0.001 * fabs(temp)
		if( temp<=error  )
		{
            //Write to print f(x)
			cout<<"\nSo Therefore Real Root of f(x) is : "<<c<<endl;
			break;
		}
		else if( (getPolyFuncValue( c,coefficients, power, size) * getPolyFuncValue( b,coefficients, power, size)) < 0 )
		{
			a=c;
		}
		else if( (getPolyFuncValue( a,coefficients, power, size) * getPolyFuncValue( c,coefficients, power, size)) < 0  )
		{
			b=c;
		}
	}

}

void regularFalsiForPoly(int coefficients[], int power[], int size)
{

    cout<<"\nRegular_Falsi Method"<<endl;
    cout<<"**********************\n";

    double error=0.0011;
	double a=0, b=1, c=0;
    double temp=0.0;
    double previous=10;

	cout<<"i\ta\tb\tf(a)\tf(b)\tc\tf(c)\n";
	for(int i=0; i>=0; i++)
	{
	    if(i!=0)
        {
            previous=c;
        }

		c=getCFalsiValueForPoly( a,  b,  coefficients,  power,  size);

        temp=abs(getPolyFuncValue( c,coefficients, power, size));
		cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<getPolyFuncValue( a,coefficients, power, size)<<"\t"<<getPolyFuncValue( b,coefficients, power, size)<<"\t"<<c<<"\t"<<temp<<endl;

		if( temp<=error || c==previous)
		{
            //Write to print f(x)
			cout<<"\nSo Therefore Real Root of f(x) is : "<<c<<endl;
			break;
		}
		else if( (getPolyFuncValue( c,coefficients, power, size) * getPolyFuncValue( b,coefficients, power, size)) < 0 )
		{
			a=c;
		}
		else if( (getPolyFuncValue( a,coefficients, power, size) * getPolyFuncValue( c,coefficients, power, size)) < 0  )
		{
			b=c;
		}
	}


    cout<<"\nFixed Point Iteration Method"<<endl;
    cout<<"**********************\n";

}

double getCFalsiValueForPoly(double a, double b, int coefficients[], int power[], int size)
{

    double ans = ( a*getPolyFuncValue(b,  coefficients,  power,  size) - b*getPolyFuncValue(a,  coefficients,  power,  size) ) / (getPolyFuncValue(b,  coefficients,  power,  size) - getPolyFuncValue(a,  coefficients,  power,  size)) ;

	ans=getNuminfourDecimal(ans);
	return ans;
}

double getGofXForPoly(double x, int coefficients[], int power[], int size)
{
    double ans=0.0;

    for(int i=0; i<size-1; i++)
    {
        ans=  (-coefficients[i] * pow(x,power[i]) ) + ans ;
    }
    //ans=getNuminfourDecimal(ans);
    return (1+ans);
}

void fixedPointIter(double xi, int coefficients[], int power[], int size)
{
    int i=0;
	double temp=0.0, previous=0.0;
	cout<<"\n\ni\txi\tg(x)\n";
    double gofx=0.0;
    double error=0.01;

	for(int i=0; i<11; i++)
	{
	    gofx=getGofXForPoly( xi,  coefficients, power,  size);
	    previous=xi;
		//temp=getNuminfourDecimal( abs(gofx - xi)  );
		//gofx=getNuminfourDecimal(gofx);
		cout<<i<<"\t"<<xi<<"\t   "<<gofx<<endl;
		xi=gofx;

		if( abs(gofx) <=error || abs(gofx) == previous )
		{
			break;
		}

	}

	//cout<<i+1<<"\t"<<xi<<"\t"<<getGofX(xi)<<endl;
	cout<<"\nSo Therefore Real Root of f(x) does not exist : "<<previous;
}

double getPolyFuncDerivValue(double xi, int coefficients[], int power[], int size)
{
    double ans=0.0;

    for(int i=0; i<size; i++)
    {
            ans= (coefficients[i] * power[i] ) * pow(xi, (power[i] - 1)) + ans;
    }

    ans=getNuminfourDecimal(ans);
    return (ans);
}

void newtonRaphsonForPoly(double xi, int coefficients[], int power[], int size)
{

cout<<"\n\nNewton Raphson Method"<<endl;
    cout<<"**********************\n";


	int i=0;
	cout<<"\n\ni\t\txi\t\txi+1\n";

    double newValue=getNewValueForPoly( xi,  coefficients,  power,  size);

	for(i=0; i>=0; i++)
	{
		cout<<i<<"\t\t"<<xi<<"\t\t"<<newValue<<endl;
		xi=newValue;
		if( (xi == newValue) )
		{
			break;
		}
	}

	cout<<i+1<<"\t\t"<<xi<<"\t\t"<<newValue<<endl;
	cout<<"\nSo Therefore Real Root of f(x) is : "<<xi;

}

double getNewValueForPoly(double xi, int coefficients[], int power[], int size)
{

    double funcV=getPolyFuncValue( xi,  coefficients,  power,  size);
    double funcDeriv=getPolyFuncDerivValue( xi, coefficients,  power,  size);

    double ans= xi - ( funcV / funcDeriv );

	ans=getNuminfourDecimal(ans);

	return(ans);
}


double getNewSecantValueForPoly(double xi, int coefficients[], int power[], int size, double prev)
{
    double ans=0.0;
    double funcV=getPolyFuncValue( xi,  coefficients,  power,  size);
    double funcPreV=getPolyFuncValue( prev,  coefficients,  power,  size);

	ans= xi - ( (xi - prev) / ( funcV  - funcPreV ) ) * funcV;
	ans=getNuminfourDecimal(ans);

	return ans;
}

void secantMethodForPoly(double xi, int coefficients[], int power[], int size)
{
    cout<<"\n\nSecant Method"<<endl;
    cout<<"**********************\n";

	int i=0;
    double prev=0.0, temp=0.0;
	cout<<"\n\ni\t\txi\t\txi+1\n";

	for(i=0; i>=0; i++)
	{
		cout<<i<<"\t\t"<<xi<<"\t\t"<<getNewSecantValueForPoly( xi,  coefficients,  power,  size,  prev)<<endl;
		temp=prev;
		prev=xi;
		xi=getNewSecantValueForPoly( xi,  coefficients,  power,  size,  temp);

		if( xi == getNewSecantValueForPoly( xi,  coefficients,  power,  size,  temp) )
		{
			break;
		}
	}

	cout<<i+1<<"\t\t"<<xi<<"\t\t"<<getNewSecantValueForPoly( xi,  coefficients,  power,  size,  temp)<<endl;
	cout<<"So Therefore Real Root of f(x) is : "<<xi;
}

void displayKey()
{
    cout<<"\n\n\nPress\t\tOperation"<<endl;
    cout<<"3\t\tTo Go Back"<<endl;
    cout<<"0\t\tTo Exit"<<endl;
}
