/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2024 AUTHOR,AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    function1

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// void = null return

// function overloading... two instances of the same function
 
/*
void area_rect(label x, label y)
{
    label area;
    area = x*y;
    Info<<"The area is: " << area << endl;
}


void area_rect(scalar x, scalar y)
{
    scalar area;
    area = x*y;
    Info<<"The area is: " << area << endl;
}
*/

template <class T>
T area_rect(T x, T y)
{
    scalar area;
    area = x*y;
    return area;
}



int main(int argc, char *argv[])
{
    label a = 6.0, b = 3.2; 
    scalar a1 = 6.0, b1 = 3.2; 
    scalar a2 = 7.3, b2 = 5; 
    float a3 = 21.4, b3 = 54.0;
    // area_rect(a, b);
    // area_rect(a1, b1);

    Info<<"The area is: "<< area_rect(a,b) << endl;
    Info<<"The area is: "<< area_rect(a1,b1)<< endl;
    Info<<"The area is: "<< area_rect(a2,b2)<< endl;
    Info<<"The area is: "<< area_rect(a3,b3)<< endl;
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
