


# To be used with a standard Pycharm virtual environment

from ctypes import cdll, c_ulonglong, c_bool, c_ulong, c_int, Structure, POINTER, byref

# Load DLL
dllObj = cdll.LoadLibrary(r"C:\Users\micro\source\repos\MathLibrary\x64\Debug\MathLibrary.dll")

# Define the C structure matching sampleStructure from MathLibrary.h
class myPyStruct(Structure):           # Structure name does not matter
    _fields_ = [("para333m1",c_int),   # The field name does not matter
                ("param2",c_int)
                ]

# Specify the arguments and return type for int readStruct(sampleStruct * thisSample)
dllObj.readStruct.argtype = POINTER(myPyStruct)
dllObj.readStruct.restype = c_int

# Create an instance of the C structure
pyStruct = myPyStruct()

# Populate the structure
pyStruct.para333m1 = 1000
pyStruct.param2 = 2000

# Steps to debug:
# 0. Place breakpoint at a dll function call
# 1. Run this as a script in debug mode(!)
# 2. In the command window, the process ID
#    e.g.: pydev debugger: process 14620 is connecting
# 3. In Visual Studio menu bar
#         Debug -> Attach to process
#         Attach to -> Select... -> pick both "Native Code" and "Python Code"
#         Scroll down and select Python.exe with the same process ID -> Attach
# 4. In Pycharm, step over the DLL function call and visual studio should hit the break point :)



success = dllObj.readStruct(byref(pyStruct)) # Equivalent to MathClient.cpp ->  int success = readStruct(&myStruct);


# Test code below

dllObj.fibonacci_init.argtype = [c_ulonglong, c_ulonglong]
dllObj.fibonacci_next.restype = c_bool
dllObj.fibonacci_current.restype = c_ulonglong
dllObj.fibonacci_index.restype = c_ulong

print('Hello world!')

dllObj.fibonacci_init(1, 1)

for n in range(0,101):
    print(f"{n} {dllObj.fibonacci_current()}   {dllObj.fibonacci_next()}")

# Check for over flow
print(2971215073 + 1836311903)
