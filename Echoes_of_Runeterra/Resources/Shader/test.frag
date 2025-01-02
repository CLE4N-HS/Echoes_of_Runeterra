uniform float u_hour; // Game hour (0-24)
uniform sampler2D u_texture; // Texture of the scene

void main() {
    vec4 color = texture2D(u_texture, gl_TexCoord[0].xy);

    // Calculate brightness based on the hour
    float brightness = 0.0;
    if (u_hour < 6.0) {
        brightness = 0.2 + 0.1 * (u_hour / 6.0); // Night to dawn
    } else if (u_hour < 18.0) {
        brightness = 0.3 + 0.7 * ((u_hour - 6.0) / 12.0); // Dawn to day
    } else {
        brightness = 0.3 + 0.1 * ((24.0 - u_hour) / 6.0); // Day to night
    }

    // Apply brightness to the color
    color.rgb *= brightness;

    // Optional: Add a tint for night or dawn
    if (u_hour < 6.0 || u_hour > 18.0) {
        color.rgb += vec3(0.0, 0.0, 0.1) * (1.0 - brightness); // Night tint
    } else if (u_hour < 8.0 || u_hour > 16.0) {
        color.rgb += vec3(0.1, 0.05, 0.0) * (1.0 - brightness); // Dawn/dusk tint
    }

    gl_FragColor = color;
}