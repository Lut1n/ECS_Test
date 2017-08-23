varying vec3 frag_position;

float hash(vec3 xyz)
{
    return fract( sin(dot(xyz, vec3(23.515348, 17.32189, 87.65691234)) * 31.138866) );
}

float noise(vec3 xyz, float freq)
{
    vec3 xyz_i = floor(xyz * freq);
    vec3 xyz_f = fract(xyz * freq);
    
    float v0 = hash( (xyz_i+vec3(0.0,0.0,0.0))/freq );
    float v1 = hash( (xyz_i+vec3(1.0,0.0,0.0))/freq );
    float v2 = hash( (xyz_i+vec3(0.0,1.0,0.0))/freq );
    float v3 = hash( (xyz_i+vec3(1.0,1.0,0.0))/freq );
    
    float v01 = mix(v0,v1,xyz_f.x);
    float v23 = mix(v2,v3,xyz_f.x);
    
    return mix(v01,v23,xyz_f.y);
}

float fractal(vec3 xyz, float freq)
{
    float f = freq;
    float intensity = 0.7;
    float total = 0.0;
    unsigned int octave = 6;
    
    float result = 0.0;
    for(unsigned int i=0; i<octave; ++i)
    {
        result += noise(xyz, f) * intensity;
        
        total += intensity;
        intensity *= 0.5;
        f *= 2.0;
    }
    
    return result / total;
}

void main()
{	
	gl_FragColor = gl_Color;
    gl_FragColor.xyz *= fractal(frag_position, 2.0);
}