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
    ex2

Description

\*---------------------------------------------------------------------------*/

// #include "fvCFD.H"
#include "dictionary.H"
#include "Vector.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

using namespace Foam;

int main(int argc, char *argv[])
{
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    // Constructor Concept

    //dictionary(const fileName &name);
    dictionary dict1 ("file1");

    Info<<"First constructor: "<< dict1 <<endl;

    //void add (const keyType&, const string&, bool overwrite=false);

    dict1.add("myValue", "zero", true);
    Info<<"After adding a string: "<< dict1 <<endl;

    /*
    dictionary	(
    const fileName & 	name,
    const dictionary & 	parentDict,
    Istream & 	is,
    bool 	keepHeader = false
    );
     */

     // Give a file name, then give a parent dictionary, and then Istream

         // Istream is an abstract class.
         // 1. You can't create an abstract class.
         // 2. You can either create a pointer or reference.
         // 3. In an abstract class, there will be at least one method whose value will be equal to 0 (virtual funct = 0).
         // 4. This is used to tell how the subclasses should be defined.

    Istream& is = dict1.lookup("myValue");

    dictionary dict2 ("file2", dict1, is);

    Info << "Second constructor: " << dict2 << endl;

    // Construct top-level dictionary from Istream,
    // reading entries until EOF
    //dictionary(Istream&);

    dictionary dict3 (is);

    Info << "Third constructor: " << dict3 << endl;

    // Construct as copy given the parent dictionary
    // dictionary(const dictionary& parentDict, const dictionary& [THESE VALUES WILL BE COPIED!]);

    dictionary dict4(dict1, dict1);

    Info << "Fourth constructor: " << dict4 << endl;

    dictionary dict5(dict2);

    Info << "Fifth constructor: " << dict5 << endl;

    // Member functions
        // optionally overwrite an existing entry
        // void add(const keyType&, const word&, bool overwrite=false);
        word myname = "Jacob";
        dict2.add("myValue2", myname, true);

        Info << "dict 2 first modification: " << dict2 << endl;

        // optionally overwrite an existing entry
        // void add(const keyType&, const scalar, bool overwrite=false);

        label val = 123;
        dict2.add("myValue3", val, true);

        Info << "dict 2 second modification: " << dict2 << endl;

        // Add a scalar entry
        // optionally overwrite an existing entry
        // void add(const keyType&, const scalar, bool overwrite=false);

        scalar val2 = 123.123452314;
        dict2.add("myValue4", val2, true);

        Info << "dict 2 third modification: " << dict2 << endl;

        // Add a dictionary entry
        // optionally merge with an existing sub-dictionary
        // void add(const keytype&, const dictionary&, bool mergeEntry = false);


        dict2.add("myValue5", dict1, true);

        Info << "dict 2 fourth modification: " << dict2 << endl;

        // Add a T entry
        // optionally overwrite an existing entry
        /*
        template<class T>
        void add(const keyType&, const T&, bool overwrite=false);
         */

        Foam::Vector v1(0, 0.1, 0.2);

        dict2.add<Foam::Vector>("myValue6", v1, true);

        Info << "dict 2 fifth modification: " << dict2 << endl;

    return 0;
}


// ************************************************************************* //
