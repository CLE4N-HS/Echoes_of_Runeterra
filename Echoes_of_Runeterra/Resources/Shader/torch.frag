uniform vec2 lightPosition;  // Position of the light in screen coordinates
uniform float lightRadius;   // Radius of the light effect
uniform sampler2D texture;   // The texture sampler

void main() {

    vec2 fragCoord = gl_FragCoord.xy;
    
   // Sample the texture at the current fragment's position
    vec4 texColor = texture2D(texture, fragCoord);

    // Calculate the distance from the given position (light) to the current fragment
    float distance = length(fragCoord - lightPosition);

    // If the distance is smaller than the threshold, make the fragment white
    if (distance < lightRadius) {
        gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0); // White color
    } else {
        gl_FragColor = texColor; // Use the texture color
    }
}
