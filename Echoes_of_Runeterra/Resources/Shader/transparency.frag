uniform vec2 u_pos;
uniform float u_radius;
uniform float u_intensity;
uniform sampler2D u_texture;

void main() {

    vec2 fragCoord = gl_FragCoord.xy / vec2(textureSize(u_texture, 0)); // Normalize coordinates
    vec4 pixel = texture2D(u_texture, fragCoord);

    float distance = length(fragCoord * vec2(1920, 1080) - u_pos);
    float intensity = max(0.0, 1.0 - (distance / u_radius));

    gl_FragColor = vec4(pixel.rgb * (1.0 + intensity * u_intensity), 0.0);
    
   // vec2 fragCoord = gl_FragCoord.xy; // Fragment position in screen coordinates
   //
   // // Convert screen coordinates to texture coordinates (normalized)
   // vec2 texCoords = fragCoord / vec2(textureSize(u_texture, 0));
   //
   // // Sample the texture at the current fragment's texture coordinates
   // vec4 pixel = texture2D(u_texture, texCoords);
   //
   // // Calculate distance from the light position
   // float distance = length(fragCoord - u_pos);
   //
   // if (distance < u_radius) {
   //     // Calculate light intensity based on distance
   //     float intensity = 1.0 - (distance / u_radius);
   //
   //     // Apply the intensity to the pixel color
   //     gl_FragColor = vec4(pixel.rgb * (1.0 + intensity * u_intensity), pixel.a);
   // } else {
   //     gl_FragColor = pixel; // No effect outside the radius
   // }


    //vec2 fragCoord = gl_FragCoord.xy;
    //
    //vec4 pixel = texture2D(u_texture, fragCoord);
    //
    //float distance = length(fragCoord - u_pos);
    //
    //if (distance < u_radius)
    //{
    //    //float intensity = 1.0 - smoothstep(0.0, u_radius, distance);
    //
    //    gl_FragColor = vec4(vec3(pixel.rgb), u_intensity);
    //}
    //else
    //{
    //    gl_FragColor = vec4(pixel);
    //}
}