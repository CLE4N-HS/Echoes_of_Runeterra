uniform vec2 lightPosition;
uniform float lightRadius;
uniform float lightIntensity;

void main()
{
    vec2 fragCoord = gl_FragCoord.xy;

    float distance = length(fragCoord - lightPosition);
    

    if (lightIntensity > 0.001 && distance < lightRadius)
    {
        float intensity = 1.0 - smoothstep(0.0, lightRadius, distance);

        float factor = intensity * lightIntensity * 2.0;
        factor = clamp(factor, 0.0, 1.0);

    // 255 174 66
        vec3 color = vec3(1.0 * factor, 1.0 * 174.0 / 255.0 * factor, 1.0 * 66.0 / 255.0 * factor);
        color = clamp(color, 0.0, 0.6);

        gl_FragColor = vec4(color, 1.0 * factor * 0.5);
    }
    else
    {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
    }
}
