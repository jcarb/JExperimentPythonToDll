// MathClient.cpp : This file calls the MathLibrary DLL
// https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160

#include <iostream>
#include "MathLibrary.h"

/*
Create a client app that uses the DLL

When you create a DLL, think about how client apps may use it.To call the functions or access the data
exported by a DLL, client source code must have the declarations available at compile time.At link time, 
the linker requires information to resolve the function calls or data accesses.A DLL supplies this 
information in an import library, a file that contains information about how to find the functionsand data, 
instead of the actual code.And at run time, the DLL must be available to the client, in a location that 
the operating system can find.

Whether it's your own or from a third-party, your client app project needs several pieces of information 
to use a DLL. It needs to find the headers that declare the DLL exports, the import libraries for the 
linker, and the DLL itself. One solution is to copy all of these files into your client project. For 
third-party DLLs that are unlikely to change while your client is in development, this method may be the 
best way to use them. However, when you also build the DLL, it's better to avoid duplication.If you make a 
local copy of DLL files that are under development, you may accidentally change a header file in one copy 
but not the other, or use an out - of - date library.

To avoid out - of - sync code, we recommend you set the include path in your client project to include 
the DLL header files directly from your DLL project.Also, set the library path in your client project to 
include the DLL import libraries from the DLL project.And finally, copy the built DLL from the DLL 
project into your client build output directory.This step allows your client app to use the same DLL 
code you build.
*/


// 1. Add DLL header to your include path
//    - right click MathClient in solution explorer and go to all configurations
//    - configuration properties -> C/C++ -> general
//    - Edit additional include directories and find the MathLibrary folder that contains the MathLibrary.h file

// 2. Add DLL to dependencies
//    - configuration properties -> Linker -> input -> Additional Dependencies and enter MathLibrary.lib
//    - configuration properties -> Linker -> general -> Additional library directories  and enter: ..\..\MathLibrary\$(IntDir)

// 3. Copy DLL to post build event
//    - Need to copy DLL over
//    - In configuration properties -> build events -> post build event and enter: xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"

/*
struct sampleStruct
{
    int param1;
    int param2;

};
*/


int main()
{
    std::cout << "Hello World!\n";

    sampleStruct myStruct;

    myStruct.Param1 = 1;
    myStruct.Param2 = 2;

    int success = readStruct(&myStruct);
    
    fibonacci_init(1, 1);

    for (int i = 0; i <= 100; i++)
    {
        std::cout << i << "   " << fibonacci_current() << "   " << fibonacci_next() << std::endl;

    }

}

