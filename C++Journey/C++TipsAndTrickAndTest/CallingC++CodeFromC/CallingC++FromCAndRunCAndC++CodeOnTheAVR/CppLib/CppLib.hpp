#ifndef CPPLIB__HPP
#define CPPLIB__HPP

#ifdef __cplusplus
extern "C" {
#endif 
	// Simple C++ Functions 
	int cppAdd(int a, int b);
	float cppAdd(float a, float b);
	int cppSubtract(int a, int b);
	int cppMultiply(int a, int b);
	int cppDevision(int a, int b);

	// C++ Template base Functions 
	/* Add functions */
	int cppAddTemplateBaseInt(int a, int b);
	float cppAddTemplateBaseFloat(float a, float b);
	double cppAddTemplateBaseDouble(double a, double b);
	
	/* Subtract functions */
	int cppSubtractTemplateBaseInt(int a, int b);
	float cppSubtractTemplateBaseFloat(float a, float b);
	double cppSubtractTemplateBaseDouble(double a, double b);

	/* Multiply functions */
	int cppMultiplyTemplateBaseInt(int a, int b);
	float cppMultiplyTemplateBaseFloat(float f, float b);
	double cppMultiplyTemplateBaseDouble(double a, double b);
	
	/* Devision functions */
	int cppDevisionTemplateBaseInt(int a, int b);
	float cppDevisionTemplateBaseFloat(float a, float b);
	double cppDevisionTemplateBaseDouble(double a, double b);

#ifdef __cplusplus
}
#endif 


#endif