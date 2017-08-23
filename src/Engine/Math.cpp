#include "Math.h"

#include <cmath>

// ----------------------------------------------------------------------
float min(float a, float b)
{
	return a<b?a:b;
}

// ----------------------------------------------------------------------
float max(float a, float b)
{
	return a>b?a:b;
}

// ----------------------------------------------------------------------
float clamp(float f, float mi, float ma)
{
	return min( max(f, mi), ma);
}

// ----------------------------------------------------------------------
float mix(float a, float b, float t)
{
	return a + (b-a)*t;
}

// ----------------------------------------------------------------------
float frac(float f)
{
    return f - std::floor(f);
}

// ----------------------------------------------------------------------
float hash(float x, float y)
{
    return std::abs(frac( std::sin( x * 87.13542254 + y * 12.746126465 ) * 34.459136953 ));
}

// ----------------------------------------------------------------------
float noise(float x, float y, float freq)
{
	float xi = std::floor(x * freq);
	float yi = std::floor(y * freq);
	
	float xf = frac(x * freq);
	float yf = frac(y * freq);
	
	float v0 = hash( (xi)/freq, (yi)/freq );
	float v1 = hash( (xi+1)/freq, (yi)/freq );
	
	float v2 = hash( (xi)/freq, (yi+1)/freq );
	float v3 = hash( (xi+1)/freq, (yi+1)/freq );
	
	float v01 = mix(v0,v1,xf);
	float v23 = mix(v2,v3,xf);
	
	return mix(v01,v23,yf);
}

// ----------------------------------------------------------------------
float fractal(float x, float y, float freq)
{
	float f = freq;
	float intensity = 0.7;
	float total = 0.0;
	unsigned int octaves = 6;
	
	float result = 0.0;
	
	for(unsigned int i=0; i<octaves; ++i)
	{
		result += noise(x, y, f) * intensity;
		
		total += intensity;
		intensity *= 0.5;
		f *= 2.0;
	}
	
	return result / total;
}