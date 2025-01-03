uniform vec2 lightPosition;  // Position of the light in screen coordinates
uniform float lightRadius;   // Radius of the light effect
uniform sampler2D texture;

void main() {
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	
	// Use gl_FragCoord to get the current fragment's position
	vec2 fragCoord = gl_FragCoord.xy;
	
	// Calculate the distance from the light source
	float distance = length(fragCoord - lightPosition);
	
	// Create a gradient effect: intensity decreases with distance
	float intensity = 1.0 - smoothstep(0.0, lightRadius, distance);
	
	// Output the light color with intensity applied (white light)
	pixel = vec4(intensity, intensity, intensity, 1.0);
	gl_FragColor = pixel;
}