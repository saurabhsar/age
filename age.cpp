/*
  **********************************************************************

  *  This program is a console age calculator
  *
  *  Copyright (C) 2011   Saurabh Araiyer,  sizzsa(at)gmail(dot)com
  *  http://www.decapsulatingabstraction.blogspot.com/
  *
  *  This program is free software: you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation, either version 3 of the License, or
  *  any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>
  
  **********************************************************************
  */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int validate(unsigned short int , unsigned short int , unsigned short int);
int month(unsigned short int, unsigned short int yyyy=0);

int main()
{
	unsigned short int dd,mm,yyyy;
	unsigned short int p_dd,p_mm,p_yyyy;

l1:
	cout<<"Please enter your date of birth DD MM YYYY (delimiter: space): ";
	cin>>dd>>mm>>yyyy;
	if( validate(dd,mm,yyyy) )
		cout<<dd<<"/"<<mm<<"/"<<yyyy;
	else 
	{
		cout<<"error input !"<<endl;
		goto l1;
		return 1;
	}
	
l2:
	cout<<endl<<"Current date: ";
	cin>>p_dd>>p_mm>>p_yyyy;
	if( validate(p_dd,p_mm,p_yyyy) && p_yyyy > yyyy )
		cout<<p_dd<<"/"<<p_mm<<"/"<<p_yyyy;
	else 
	{
		cout<<"error input !"<<endl;
		goto l2;
		return 1;
	}
	
	/// computing the difference between dates
	
	short int d,m,y;
	y = p_yyyy - yyyy;
	m = p_mm - mm;
	d = p_dd - dd;
	if ( m <= 0 )  //like computing diff between 7 July and 1 May July > May
	{
		y--;
		m += 12;
	}
	if ( d <= 0 ) //similar to the above one, month and day correction
	{
		m--;	
		short int case_month_DOB, case_month_present;
		case_month_DOB = month ( mm , yyyy );
		case_month_present = month ( p_mm , p_yyyy );
	
		if (!case_month_DOB)
			d += 31;
		else switch (case_month_DOB)
		{
			case 1:
				d += 30;
				break;
			case 2:
				d += 28;
				break;
			case 3:
				d += 29;
				break;
		}
	}
	
	/// age computation over
	
	cout<<endl<<"you are "<<y<<" years, "<<m<<" months "<<d<<" days old !";
	return 0;
}

int validate( unsigned short int dd , unsigned short int mm , unsigned short int yyyy)
{
	if ( dd > 31 || dd == 0 || mm == 0  || mm > 12 )
		return 0;
	switch (month (mm , yyyy))
	{
		case 1:
			if ( dd > 30 )
				return 0;
		case 2:
			if ( dd > 28 )
			return 0;
		case 3:
			if ( dd > 29 )
				return 0;
	}
	return 1;
}

int month(unsigned short int mm , unsigned short int yyyy )
{
	if ( mm==4 || mm==6 || mm==9 || mm==11 )
		return 1;
	else if ( mm == 2 )
	{
		if ( yyyy%4 )
			return 2;
		else 
			return 3;  //leap year
	}
	return 0;  //Jan, Mar, May, July, Aug, Oct, Dec, all 31
}
