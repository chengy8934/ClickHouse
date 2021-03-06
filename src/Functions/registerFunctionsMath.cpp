namespace DB
{

class FunctionFactory;

void registerFunctionE(FunctionFactory & factory);
void registerFunctionPi(FunctionFactory & factory);
void registerFunctionExp(FunctionFactory & factory);
void registerFunctionLog(FunctionFactory & factory);
void registerFunctionExp2(FunctionFactory & factory);
void registerFunctionLog2(FunctionFactory & factory);
void registerFunctionExp10(FunctionFactory & factory);
void registerFunctionLog10(FunctionFactory & factory);
void registerFunctionSqrt(FunctionFactory & factory);
void registerFunctionCbrt(FunctionFactory & factory);
void registerFunctionErf(FunctionFactory & factory);
void registerFunctionErfc(FunctionFactory & factory);
void registerFunctionLGamma(FunctionFactory & factory);
void registerFunctionTGamma(FunctionFactory & factory);
void registerFunctionSin(FunctionFactory & factory);
void registerFunctionCos(FunctionFactory & factory);
void registerFunctionTan(FunctionFactory & factory);
void registerFunctionAsin(FunctionFactory & factory);
void registerFunctionAcos(FunctionFactory & factory);
void registerFunctionAtan(FunctionFactory & factory);
void registerFunctionSigmoid(FunctionFactory & factory);
void registerFunctionTanh(FunctionFactory & factory);
void registerFunctionPow(FunctionFactory & factory);


void registerFunctionsMath(FunctionFactory & factory)
{
    registerFunctionE(factory);
    registerFunctionPi(factory);
    registerFunctionExp(factory);
    registerFunctionLog(factory);
    registerFunctionExp2(factory);
    registerFunctionLog2(factory);
    registerFunctionExp10(factory);
    registerFunctionLog10(factory);
    registerFunctionSqrt(factory);
    registerFunctionCbrt(factory);
    registerFunctionErf(factory);
    registerFunctionErfc(factory);
    registerFunctionLGamma(factory);
    registerFunctionTGamma(factory);
    registerFunctionSin(factory);
    registerFunctionCos(factory);
    registerFunctionTan(factory);
    registerFunctionAsin(factory);
    registerFunctionAcos(factory);
    registerFunctionAtan(factory);
    registerFunctionSigmoid(factory);
    registerFunctionTanh(factory);
    registerFunctionPow(factory);
}

}
